cmake_minimum_required(VERSION 3.15)
project(AISD_course)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

# Включаем поддиректории с лабораторными
add_subdirectory(lab1_binTrees)
add_subdirectory(lab2_RBTrees)

# Общая цель для запуска всех тестов
add_custom_target(run_all_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    COMMENT "Running all tests from all labs..."
)

message(STATUS "=========================================")
message(STATUS "Succesfully configured!")
message(STATUS "Labs: lab1_binTrees, lab2_RBTrees")
message(STATUS "=========================================")