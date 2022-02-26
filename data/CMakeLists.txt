cmake_minimum_required(VERSION 3.1)

project(datasource VERSION 1.5.0 LANGUAGES CXX)

aux_source_directory(. SRC)

file(GLOB INC *.h)

find_package(cpprestsdk CONFIG REQUIRED)
add_library(datasource ${SRC} ${INC})
target_link_libraries(datasource  cpprestsdk::cpprest)
