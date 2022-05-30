cmake_minimum_required(VERSION 3.4)

project(Program)

set(SOURCE_FILES
        src/main.cpp)

add_executable(Program ${SOURCE_FILES} )

#Określenie zależności pomiędzy projektami Program i Biblioteka
target_link_libraries(Program Library)
target_include_directories(Program PUBLIC include)

enable_testing()