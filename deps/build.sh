# Compile libjit
cd libjit-0.1.2
sh configure --disable-shared --enable-static --with-pic && make clean && make all
cd ..

# Compile garbage collector
cd gc-7.1
sh configure --enable-threads=pthreads --enable-parallel-mark --disable-shared --enable-static --with-pic --enable-dependency-tracking --enable-cplusplus --disable-gcj-support --disable-java-finalization && make clean && make all
cd ..

# Compile GNU multiprecision library
cd gmp-5.0.1
sh configure --enable-cxx --disable-shared --enable-static --with-pic && make clean && make all
cd ..

cd icu/source
sh configure --disable-shared --enable-static --with-pic && make clean && make all
cd ../..
