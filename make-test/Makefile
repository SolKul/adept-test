# Specify compiler and flags
CPP = g++
CPPFLAGS = -Wall -O3 -g
# Normal object files to be created
OBJECTS =  main.o
# Object files created with no automatic differentiation
# NO_AD_OBJECTS = algorithm1_noad.o algorithm2_noad.o
# Program name
PROGRAM = my_program
# Include-file location
INCLUDES = -I/usr/local/include
# Library location and name, plus the math library
LIBS = -L/usr/local/lib -lm -ladept
# rpath
RPATH = -Xlinker -rpath -Xlinker /usr/local/lib
# Rule to build the program (typing "make" will use this rule)
$(PROGRAM): $(OBJECTS) $(NO_AD_OBJECTS)
	$(CPP) $(CPPFLAGS) $(OBJECTS) $(NO_AD_OBJECTS) $(LIBS) $(RPATH) -o $(PROGRAM)
# Rule to build a normal object file (used to compile all objects in OBJECTS)
%.o: ../%.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDES) -c $<
# Rule to build a no-automatic-differentiation object (used to compile ones in NO_AD_OBJECTS)
%_noad.o: ../%.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDES) -DADEPT_NO_AUTOMATIC_DIFFERENTIATION -c $< -o $@