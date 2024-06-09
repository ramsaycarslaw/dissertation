# Implementing UNIX with Effects Handlers

Final year project @ The University of Edinbrugh

## Abstract

Algebraic effect handlers first outlined by Plotkin and Prenar allow for a computation to be split into and effect signature and an implementation in the form of handler. Effect handlers allow for programs to be written in an extremely modular fashion by composing multiple effect handlers or having multiple handlers for one effect. This leads to programs that are written in an effect-oriented style where most the core functionality is an effectful computation.
Unix is an operating system created at AT&T’s Bell Labs in 1971 by Ritchie and Kernighan. It features a file system, user space and process management. It has become one of the most widely used operating systems, being licensed in Apple’s macOS and served as the main inspiration for Linux.
This project provides an effect-oriented implementation of Unix based on Daniel Hillerstro ̈m’s toy Unix he outlines in his p.H.D thesis. In this project, Unix is implemented in Unison, a functional language with support for effect handlers. This initial Unison ver- sion of Unix is then extended with more advanced features such as permissions, generic users and environment variables and a better scheduler. Both Unison and effect-oriented programming are analysed with the Unix implementation serving as a sufficiently com- plex program to demonstrate some of the selling points of effect-oriented programming.

