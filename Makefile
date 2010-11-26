SHELL_SRC  = src/shell
SHELL_OBJS = main.o

#CORE_SRC   = src/core
#CORE_OBJS  = 

LIBS = -Ldeps/gc-7.1/.libs  -lgc -lgccpp -lpthread -ldl
INCLUDES = -Isrc/core -Ideps/gc-7.1/include

VPATH = $(SHELL_SRC)

%.o : %.cpp
	g++ $(INCLUDES) -c -o$@ $< 

all: proton

clean:
	rm -f *.o
	rm -f proton
	

proton: $(SHELL_OBJS)
	g++ -oproton  $< $(LIBS)