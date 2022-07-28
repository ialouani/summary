cmake_minimum_required(VERSION 2.8.11)

set(HEADERS
  ./include/lexer.h
  )

message(STATUS "build option is set to " ${CMAKE_BUILD_TYPE})

project(all)
enable_testing()


add_executable(all2 ./src/lexer.c ./tst/test1.c)


