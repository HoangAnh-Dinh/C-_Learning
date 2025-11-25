#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void waiter() {
    std::unique_lock<std::mutex> lock(mtx);
    while (!ready) {           // kiểm tra flag trực tiếp, không dùng lambda
        cv.wait(lock);         // wait sẽ unlock mutex và đợi notify
    }
    std::cout << "Thread được thông báo, ready = true\n";
}

void notifier() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;           // set flag
    }
    cv.notify_one();            // báo thread waiter
}

int main() {
    std::thread t1(waiter);
    std::thread t2(notifier);

    t1.join();
    t2.join();
}
