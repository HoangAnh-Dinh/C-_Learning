#include "mylib.h"
#include <iostream>

void print_message(const std::string& msg) {
    std::cout << "[mylib DLL#2] " << msg << std::endl;
}
