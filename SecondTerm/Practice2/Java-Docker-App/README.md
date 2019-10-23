# CYK-Algorithm 
The Cocke–Younger–Kasami algorithm (alternatively called CYK, or CKY) is a parsing algorithm for context-free grammars, named after its inventors, John Cocke, Daniel Younger and Tadao Kasami. It employs bottom-up parsing and dynamic programming. 

The standard version of CYK operates only on context-free grammars given in Chomsky normal form (CNF). However any context-free grammar may be transformed to a CNF grammar expressing the same language (Sipser 1997). 

GRAMMAR FILE
------------

The program has to read the grammar as a txt file.

```
S       ----> Start Symbol
a b     ----> Terminal Symbol
S A B C ----> NonTerminal Symbol
S AB BC ----> Productions
A BA a
B CC b
C AB a
```

DOCKER FILE
-----------

You have to change this part on the Docker File:
  
  You have to write the Grammar File and the string to be checked

```
  CMD ["java", "AlgorithmCYK", "grammar.txt", "bbab"]
```

BUILD
-----

```
  - Build:
    * Terminal$ docker build -t java-app . 

  - Run: 
    * Terminal$ docker run java-app

  - Deploy and Run Docker Image:
    * Terminal$ docker run -p 8080:9080 -t java-app

  - Run and :
    * Terminal$ docker run -d -p 8080:9080 -t java-app

  - Shows us what is running:
    * Terminal$ docker ps

  - Stop:
    * Terminal$ docker stop java-app

  - Still there:
    * Terminal$ docker ps -a

  - Restart:
    * Terminal$ docker restart java-app

  - Docker logs:
    * Terminal$ docker exec -it java-app sh
```

EXAMPLE
-------

```
      Terminal$ docker build -t java-app . 
      Terminal$ docker run java-app

      Word: bbab

      G = ({a, b}, {S, A, B, C}, P, S)

      With Productions P as:
      A -> BA | a
      B -> CC | b
      C -> AB | a
      S -> AB | BC

      Applying CYK-Algorithm:

      +-------+-------+-------+-------+
      | b     | b     | a     | b     |
      +-------+-------+-------+-------+
      | B     | B     | A,C   | B     |
      +-------+-------+-------+-------+
      | -     | A,S   | C,S   |
      +-------+-------+-------+
      | A     | C,S   |
      +-------+-------+
      | C,S   |
      +-------+

      The word "bbab" is an element of the CFG G and can be derived from it.
      Derivation Tree: 
      b b a b B B A C B  A S C S A C S C S
```