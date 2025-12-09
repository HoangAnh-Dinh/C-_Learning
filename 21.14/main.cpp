#include<iostream>
#include<thread>
#include<future>

void worker(std::promise<int> ins)
{
for(int i = 0;i<10000;i++)
{
for(int j = 0;j<10000;j++){}
}
ins.set_value(56);
}

int main()
{
int result;
std::promise<int> prom;
std::future<int> fu = prom.get_future();
std::thread thrd1(worker,std::move(prom));
result = fu.get();
std::cout<<result;
thrd1.join();
return 0;
}