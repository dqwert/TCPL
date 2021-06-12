cmake_minimum_required(VERSION 3.14)
project(TCPL C)

set(CMAKE_C_STANDARD 99)

add_executable(chapter01 ch01.c)
add_executable(chapter02 ch02.c)
add_executable(chapter03 ch03.c)
add_executable(chapter04 ch04.c)
add_executable(chapter04_calculator ch04_calculator/calculator.c ch04_calculator/getch.c ch04_calculator/stack.c)
add_executable(chapter04_calculator_reorg ch04_calculator_reorg/calculator.c ch04_calculator_reorg/getch.c ch04_calculator_reorg/stack.c ch04_calculator_reorg/main.c ch04_calculator_reorg/calc.h ch04_calculator_reorg/getop.c)
add_executable(chapter05 ch05.c ch04_calculator/getch.c)
