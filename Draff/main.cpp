#include <iostream>

int main() {
    int* leak = new int[5];  // Cấp phát nhưng quên delete → leak

    int* no_leak = new int[5];
    delete[] no_leak;        // Giải phóng đúng

    std::cout << "Program is running..." << std::endl;

    return 0; // 'leak' chưa được delete → memory leak
}
