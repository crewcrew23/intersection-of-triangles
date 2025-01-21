# About 
I tried to do homework from MIPT,
where the input is a set of points as described in text.txt
from which you need to build 2 triangles and
you need to determine whether the triangles intersect and if they intersect, then return the intersection points.

right now the program can determine if triangles intersect (I'm not 100% sure as I haven't tested it properly yet)

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

