SHELL_SRC  = src/shell
SHELL_OBJS = main.o

#CORE_SRC   = src/core
#CORE_OBJS  = 

GC_LIBS  = -Ldeps/gc-7.1/.libs -lgc -lgccpp
JIT_LIBS = -Ldeps/libjit-0.1.2/jit/.libs -ljit 
GMP_LIBS = -Ldeps/gmp-5.0.1/.libs -lgmp

LIBS =  $(GC_LIBS) $(JIT_LIBS) $(GMP_LIBS) -lpthread -ldl
INCLUDES = -Isrc/core -Ideps/gc-7.1/include -Ideps/libjit-0.1.2/include -Ideps/gmp-5.0.1

VPATH = $(SHELL_SRC)

%.o : %.cpp
	g++ -std=c++0x $(INCLUDES) -c -o$@ $< 

all: proton

clean:
	rm -f *.o
	rm -f proton	

proton: $(SHELL_OBJS)
	g++ -oproton  $< $(LIBS)