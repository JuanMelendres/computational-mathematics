#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "re.c"

#define NORMAL_COLOR  "\x1B[0m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1b[33m"

/*
Regular expresions:
    *    matches zero or more occurrences
    +    matches one or more occurrences
*/

/*
 @search for regular expression anywhere in a directory and return the list of files
 @param regular expression string
 */
int match(char *regexp, char *text) {
    if (regexp[0] == '\n') {
        exit(0);
    }
    do { //should check if the string is empty
        if (matchhere(regexp, text)) {
            return 1;
        }
    } while(*text++ != '\0');
    return 0;
}

int matchhere(char *regexp, char *text){
    if (regexp[0] == '\0') {
        return 1;
    }
    if (regexp[1] == '*') {
        return matchstar(regexp[0], regexp+2, text);
    }
    if (regexp[1] == '+') {
        return matchplus(regexp[0], regexp+2, text);
    }
    if (regexp[0] == '\0' && regexp[1] == '\0') {
        return *text == '\0';
    }
    if (*text != '\0' && (regexp[0] == *text)) {
        return matchhere(regexp + 1, text + 1);
    }
    return 0;
}

int matchstar(int c, char *regexp, char *text) {
    char *t;
    for (t = text; *t != '\0' && (*t == c); t++)
        ;
    do {        /* a matches zero or more */
        if (matchhere(regexp, t)) {
            return 1;
        }
    } while (t-- > text);
    return 0;
}

int matchplus(int c, char *regexp, char *text){
    int i = 0;
    do { //a matches one or more instances
        if (matchhere(regexp, text)) {
            if (i == 0) {
                i++;
            }
            else {
                return 1;
            }
        }
    } while (*text != '\0' && (*text++ == c));
    return 0;
}

void searchInDirectory(char *regex, char * path){
    DIR * d = opendir(path); // open the path
    if(d == NULL) {
        return; // not able return
    }
    struct dirent * dir; // for the directory entries
    while ((dir = readdir(d)) != NULL) { // able to read somehting from the directory
        if(dir-> d_type != DT_DIR) { // is not directory just print it with blue
            if (match(regex, dir->d_name)){
                printf("\tAccepted File: %s%s\n",YELLOW, dir->d_name);
            }
            //printf("%s\n", YELLOW);
        }
        else {
            //printf("%s\n", NORMAL_COLOR);
            if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".") != 0 && strcmp(dir->d_name,"..") !=0) {
                // is a directory
                printf("Folder: %s%s\n",GREEN, dir->d_name); // print its name in green
                char d_path[255];
                sprintf(d_path, "%s/%s", path, dir->d_name);
                searchInDirectory(regex, d_path); // recall with the new path
            }
        }
    }
    closedir(d); // finally close the directory
}

int main(){
    char *regex;
    gets(regex);
    printf("%s\n", NORMAL_COLOR);
    searchInDirectory(regex, "/Users/juanantoniomelendresvilla/Documents");
    printf("%s\n", NORMAL_COLOR);
    return 0;
}



    // char *regex = "aa*";
    // char *text = "aaaabb";
    // if(match(regex, text)) {
    //     printf("Aceptada!\n");
    // }
    // else {
    //     printf("Rechazada!\n");
    // }