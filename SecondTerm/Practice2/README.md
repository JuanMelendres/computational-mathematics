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

BUILD
-----

```
javac CYK.java
```

RUN
---

```
java CYK <GrammarFile> <String to check>
```

EXAMPLE
-------

```
      Terminal$ javac AlgorithmCYK.java
      Terminal$ java AlgorithmCYK grammar.txt bbab

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