#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // mutex dùng để khóa biến chung
int counter = 0;  // biến chung

void increment(const std::string& name) {
    mtx.lock(); 
    for (int i = 0; i < 5; i++) {
        //mtx.lock();           // khóa mutex trước khi truy cập counter
        counter++;
        std::cout << name << " increased counter to " << counter << std::endl;
        //mtx.unlock();         // mở khóa mutex
    }
}

int main() {
    std::thread t(increment, "Dau nhoi ");
    t.join();

    return 0;
}
