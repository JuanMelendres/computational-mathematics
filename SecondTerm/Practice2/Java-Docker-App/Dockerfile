# OpenJDK JRE
FROM java:8

ENV JAVA_VER 8
VOLUME /tmp

MAINTAINER  Juan Melendres <juan.mele97@gmail.com>

# Copying the code directory to /home/user/hello
COPY . /home/user/hello

# Setting /home/user/hello as our work directory. Means code will reside here
WORKDIR /home/user/hello

RUN javac AlgorithmCYK.java 

EXPOSE 9080

# The application run with this command line you can change the grammar.txt and the string to be checked
# On the README.txt is explained everything
CMD ["java", "AlgorithmCYK", "grammar.txt", "bbab"]  