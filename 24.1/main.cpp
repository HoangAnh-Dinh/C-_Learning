#include <stdio.h>
#include <iostream>
class cha
{};

class con: public cha
{};

class singleton
{
public:
static singleton& getInstance()
{
	static singleton instance;
	return instance;
}
private:
singleton(){std::cout<<"Singleton Created";}
singleton(singleton& ins)=delete;
singleton& operator= (singleton& ins)=delete;
};

int main()
{
singleton& a = singleton::getInstance();
singleton& b = singleton::getInstance();
return 0;
}