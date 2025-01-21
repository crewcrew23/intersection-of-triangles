# Build && Run

### Linux:
```
mkdir build
cd build
cmake ./
make
./main
```

### Windows:
create directory
```
mkdir build
cd build
```
for GCC compiler use
```
cmake -G "MinGW Makefiles" ..
```

for Clang compiler use
```
cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ..
```

```
mingw32-make
./main.exe
```

