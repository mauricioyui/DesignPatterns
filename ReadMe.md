# DESIGN PATTERNS

This project contains programs written in C++  which demonstrate the use of Design Patterns.

## FILE STRUCTURE

Each directory in the top level directory is a different program.

All the programs have the following directory structure:

* `Root`: contains the main source code of the program;
* `Include`: contains the all the header files;
* `Branch`: contains files with the code for the classes and methods;
* `Build`: this directory is created during compilation and will contain the all the compiled object;
* `Binary`: this directory is created during compilation and will contain the final program;


## COMPILING THE PROGRAMS

In order to compile the `Memento` design patter demonstration program, please install `libncurses`. If you are running in a Debian based distribution you can install it by typing:

<pre>
$ sudo apt install libncurses5-dev libncursesw5-dev 
</pre>

There is a `Makefile` in the top level directory, which enables the compilation of all the programs at once just by typing:

<pre>
$ make
</pre>

In the same way, in the top level directory, to delete all the compiled program and objects at once  just type:

<pre>
$ make clean
</pre>

Every program also has its own `Makefile`. It is also possible to compile and delete all compiled files for each program individually, by typing the same commands used in the top level directory inside the program's directory.
