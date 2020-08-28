from adept 2 documentation

# 2.6 Calling an algorithm with and without automatic differentiation from the same program

## Multiple object files per source file

The third method involves compiling each source file containing functions with adouble arguments
twice. The first time, the code is compiled normally to produce an object file containing compiled
functions including automatic differentiation.
