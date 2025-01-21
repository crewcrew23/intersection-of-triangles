cmake_minimum_required(VERSION 2.8)

# Название проекта
project(MyProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Установка исполняемого файла
add_executable(main src/main.cpp src/line.cpp src/triangle.cpp src/matrix.cpp)

# Заголовочные файлы
include_directories(${CMAKE_SOURCE_DIR}/include)