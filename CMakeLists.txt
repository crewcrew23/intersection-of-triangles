cmake_minimum_required(VERSION 2.8)

# Название проекта
project(Triangle_Interseption)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


SET (CMAKE_C_FLAGS_INIT                "-Wall -std=c11")
SET (CMAKE_C_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

SET (CMAKE_CXX_FLAGS_INIT                "-Wall -std=c++20")
SET (CMAKE_CXX_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

# Установка исполняемого файла
add_executable(main src/main.cpp src/line.cpp src/triangle.cpp src/matrix.cpp src/intersection_check.cpp)
add_executable(tests  tests/e2e_tests.cpp src/line.cpp src/triangle.cpp src/matrix.cpp src/intersection_check.cpp)

# Заголовочные файлы
include_directories(${CMAKE_SOURCE_DIR}/include)
target_link_libraries(tests  ${CMAKE_SOURCE_DIR}/include)