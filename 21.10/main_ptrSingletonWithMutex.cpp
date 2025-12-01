#include<iostream>
#include<mutex>
#include<thread>

class singleton
{
private:
singleton(){std::cout<<"singleton created"<<std::endl;}
singleton(singleton& _ins)=delete;
singleton& operator=(singleton& _ins)=delete;
public:
static singleton* ins;
static std::mutex mtx;
static singleton* getInstance()
{
    if(ins==nullptr)
    {
        mtx.lock();
        if(ins==nullptr)
        {
            ins = new singleton();
        }
        mtx.unlock();
    }
    return ins;
}
};

singleton* singleton::ins = nullptr;
std::mutex singleton::mtx;

void createSingleton()
{
    singleton* instance = singleton::getInstance();
    std::cout<<"singleton address : "<<instance<<std::endl;
}

int main()
{   
    std::thread thr1(createSingleton);
    std::thread thr2(createSingleton);

    thr1.join();
    thr2.join();
    return 0;
}
