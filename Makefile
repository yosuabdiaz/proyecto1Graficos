#Compiler
CC = gcc

#Debug or Release
DEBUG = -g
RELEASE = -O2
EXEC_TYPE = ${RELEASE}

#Compiler options
CFLAGS = -pipe -W -Wall -Wextra -ansi -pedantic-errors ${EXEC_TYPE}

#PATH
PATH_X = 
PATH_OPENGL = 
INCPATH = ${PATH_X} ${PATH_OPENGL}

#FLAGS
FLAGS_X = 
FLAGS_OPENGL = -lGL -lGLU -lglut
OTHER_FLAGS = -lm
LDFLAGS = ${FLAGS_X} ${FLAGS_OPENGL} ${OTHER_FLAGS}

#executable name
EXEC = proyecto1

#list here all the source files
SRC = proyecto1.c
#OBJ files (if sources in c)
OBJ = ${SRC:.c=.o} 

#what we are trying to build
all: $(EXEC)

#linkage
$(EXEC): ${OBJ}
	@echo 
	@echo ================ [Linkeando ...]  ================ 
	@echo

	$(CC) -o $@ $^ $(LDFLAGS)
	@echo
	@echo ================ [progama ${EXEC} compilado exitosamente] ================ 
	@echo


#compile every source files
%.o: %.c
	@echo --------- build [$<] ----------
	$(CC) $(CFLAGS) $(INCPATH) -c $<  -o $@
	@echo OK [$<] - [$@]
	@echo
	
clean: 
	rm -f *.o
	rm -f proyecto1 
	
