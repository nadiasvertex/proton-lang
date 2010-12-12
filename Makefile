
SHELL_OBJS = src/shell/main.o
TEST_OBJS  = src/tests/main.o
CORE_OBJS  = src/core/object.o src/core/singletons.o src/core/string.o src/core/protocol.o \
			 src/core/jitter-binops.o src/core/proto-binops.o \
             src/parser/rule.o src/parser/ast.o

GC_LIBS  = -Ldeps/gc-7.1/.libs -lgc -lgccpp
JIT_LIBS = -Ldeps/libjit-0.1.2/jit/.libs -ljit 
GMP_LIBS = -Ldeps/gmp-5.0.1/.libs -lgmp
ICU_LIBS = -Ldeps/icu/source/lib -licuuc -licudata

LIBS =  $(GC_LIBS) $(JIT_LIBS) $(GMP_LIBS) $(ICU_LIBS) -lpthread -ldl
INC_FLAGS = -Isrc/core -Isrc/parser -Ideps/gc-7.1/include -Ideps/libjit-0.1.2/include -Ideps/gmp-5.0.1 -Ideps/icu/source/common -Ideps/icu/source/i18n

%.o : %.cpp
	g++ -g -std=c++0x $(INCLUDES) -c -o$@ $< 

all: proton

binops:
	python src/core/gen_binops.py src/core/proto-binops src/core/jitter-binops src/tests/jit_int_test.h

test_objects: $(TEST_OBJS) $(CORE_OBJS)  
	g++ -g -oproton_test $(TEST_OBJS) $(CORE_OBJS) $(LIBS)
	
shell_objects:  $(SHELL_OBJS) $(CORE_OBJS)
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