#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // mutex dùng để khóa biến chung
std::mutex mtx2;
int counter = 0;  // biến chung

// Hàm thread: tăng counter 5 lần
void increment(const std::string& name) {
    for (int i = 0; i < 5; i++) {
        mtx2.lock();
        mtx.lock();           // khóa mutex trước khi truy cập counter
        counter++;
        std::cout << name << " increased counter to " << counter << std::endl;
        mtx.unlock();         // mở khóa mutex
        mtx2.unlock();
    }
}

void increment2(const std::string& name) {
    for (int i = 0; i < 5; i++) {
        mtx.lock();
        mtx2.lock();           // khóa mutex trước khi truy cập counter
        counter++;
        std::cout << name << " increased counter to " << counter << std::endl;
        mtx2.unlock();         // mở khóa mutex
        mtx.unlock();
    }
}

#include <iostream>
#include <cstring>

int main() {
    const char* src[1] = {"Hello"}; // 1 phần tử, con trỏ trỏ tới chuỗi
    const char* dst[1];

    // sao chép con trỏ
    std::memcpy(dst, src, sizeof(src));

    // in địa chỉ mà con trỏ trỏ tới
    for(auto a : dst) {
        std::cout << "dst points to address: " << static_cast<const void*>(a)
                  << " -> value: " << a << std::endl;
    }

    for(auto a : src) {
        std::cout << "src points to address: " << static_cast<const void*>(a)
                  << " -> value: " << a << std::endl;
    }

    return 0;
}
