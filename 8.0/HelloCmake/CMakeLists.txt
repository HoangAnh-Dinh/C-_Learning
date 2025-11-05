cmake_minimum_required(VERSION 3.10)
project(Hello_CMake)

set(CMAKE_CXX_STANDARD 17)

# Thêm đường dẫn include để cả app và lib cùng dùng
include_directories(include)

# Tạo thư viện (library)
#add_library(mylib SHARED src/include/mylib.cpp)

add_executable(MyApp src/main.cpp)

add_library(mylib SHARED src/include/mylib.cpp)

# Nối (link) thư viện vào executable
target_link_libraries(MyApp PRIVATE mylib)

target_include_directories(MyApp PRIVATE src/include)