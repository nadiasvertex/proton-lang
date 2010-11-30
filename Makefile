SHELL_SRC  = src/shell
SHELL_OBJS = src/shell/main.o

TEST_SRC   = src/tests
TEST_OBJS  = src/tests/main.o

#CORE_SRC   = src/core
#CORE_OBJS  = 

GC_LIBS  = -Ldeps/gc-7.1/.libs -lgc -lgccpp
JIT_LIBS = -Ldeps/libjit-0.1.2/jit/.libs -ljit 
GMP_LIBS = -Ldeps/gmp-5.0.1/.libs -lgmp
ICU_LIBS = -Ldeps/icu/source/lib -licuuc

LIBS =  $(GC_LIBS) $(JIT_LIBS) $(GMP_LIBS) $(ICU_LIBS) -lpthread -ldl
INC_FLAGS = -Isrc/core -Ideps/gc-7.1/include -Ideps/libjit-0.1.2/include -Ideps/gmp-5.0.1 -Ideps/icu/source/common

%.o : %.cpp
	g++ -g -std=c++0x $(INCLUDES) -c -o$@ $< 

all: proton

binops:
	python src/core/gen_binops.py src/core/proto-binops.h src/core/jitter-binops.h src/tests/jit_int_test.h

test_objects: $(TEST_OBJS)  
	g++ -g -oproton_test  $< $(LIBS)
	
shell_objects:  $(SHELL_OBJS)
	g++ -oproton  $< $(LIBS)

test: INCLUDES = $(INC_FLAGS) -Ideps/igloo
test: binops test_objects
	./proton_test

clean:
	rm -f src/*/*.o
	rm -f proton
	rm -f proton_test	

proton: INCLUDES = $(INC_FLAGS)
proton: binops shell_objects