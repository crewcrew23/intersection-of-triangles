# dependency for run
you need any compiler GCC or Clang, <br/>
instaled Cmake and make,
that all! 


# About 
I tried to do homework from MIPT,<br/>
where the input is a set of points as described in text.txt<br/>
from which you need to build 2 triangles and<br/>
you need to determine whether the triangles intersect and if they intersect, then return the intersection points.<br/>

right now the program can determine if triangles intersect (I'm not 100% sure as I haven't tested it properly yet)

# Use
run the program and enter the dots for the triangles into the terminal<br/>
like that<br/>
```
0 0 0 1 0 1 1 0 0 0 1 0 1 0 1 1 1 1 0 0 1 0 0 0
```
first 12 dots this is dots for sides of triangle 1 <br/>
second 12 dots this is dots for sides of triangle 2<br/>

I'm not sure, but if your input data is outside the -1:1 range the program can probably milk it, but I'm not sure.

# Build && Run

### Linux:
```
mkdir build
cd build
cmake -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ ..
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
# Test
after build, in build dir you can see executabe file tests
