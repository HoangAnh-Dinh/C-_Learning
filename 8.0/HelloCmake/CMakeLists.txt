cmake_minimum_required(VERSION 3.10)
project(HelloCMake)
 
set(CMAKE_CXX_STANDARD 17)

set(libPath src/include)
# ===== Project chinh =====
add_library(add ${libPath}/mylib.cpp)
# ===== Them GoogleTest =====
add_subdirectory(external/googletest/googletest-1.15.0)
 
# ====== Bat flag coverage ======
option(CODE_COVERAGE "Enable coverage reporting" ON)
 
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS ">> Code coverage enabled")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()
#===============================
 
enable_testing()
# ===== Tao target test =====

add_executable(tests tests/test_add.cpp)
target_include_directories(tests PUBLIC ${libPath})

target_link_libraries(tests PRIVATE add gtest_main)
 
include(GoogleTest)
gtest_discover_tests(tests)