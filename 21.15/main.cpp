#include<iostream>
#include<thread>
#include<future>

int sum(int a, int b)
{
for(int i = 0;i<10000;i++)
{
for(int j = 0;j<10000;j++){}
}
return a + b ;
}
void run()
{
std::cout<<"Running...."<<std::endl;
}

int main()
{
int result;
std::future<int> fut = std::async(std::launch::async,sum,3,7);
result = fut.get();
std::future<void> fut2 = std::async(std::launch::deferred,run);
fut2.get();
std::cout<<result<<std::endl;
return 0;
}