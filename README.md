# dependency for run
you need any compiler GCC or Clang
instaled Cmake and make
that all! 


# About 
I tried to do homework from MIPT,
where the input is a set of points as described in text.txt
from which you need to build 2 triangles and
you need to determine whether the triangles intersect and if they intersect, then return the intersection points.

right now the program can determine if triangles intersect (I'm not 100% sure as I haven't tested it properly yet)

# Use
run the program and enter the dots for the triangles into the terminal
like that
```
0 0 0 1 0 1 1 0 0 0 1 0 1 0 1 1 1 1 0 0 1 0 0 0
```
first 6 dots this is dots for sides of triangle 1 
second 6 dots this is dots for sides of triangle 2

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

