#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

class IObserver
{
public:
~IObserver()=default;
virtual void update(std::string msg)=0;
virtual void boFollow() = 0;
};

class subject
{
private:
std::string message;
std::vector<IObserver*> observerList;
public:
void add(IObserver* ins)
{
observerList.push_back(ins);
}
void remove(IObserver* ins)
{
observerList.erase(std::remove(observerList.begin(),observerList.end(),ins) , observerList.end());
}
void notify()
{
	for(auto* ins:observerList)
	{
		ins->update(message);
	}
}
void createMsg(std::string msg)
{
message = msg; 
notify();
}
};

class concreteObserver:public IObserver
{
private:
std::string name;
subject* sub;
public:
concreteObserver(std::string ten, subject* subj):name(ten),sub(subj)
{
sub->add(this);
}

void boFollow() override
{
sub->remove(this);
std::cout<<"Da xoa Mr."<<name<<std::endl;
}

void update(std::string msg) override
{
std::cout<<"Mr."<<name<<" da nhan duoc thong bao : "<<msg<<std::endl;
}

};

int main()
{
subject* Bantin = new subject();
IObserver*A = new concreteObserver("Anh",Bantin);
IObserver*B = new concreteObserver("Khang",Bantin);
IObserver*C = new concreteObserver("Phat",Bantin);

Bantin->createMsg("Xin chao khach VIP");
C->boFollow();

Bantin->createMsg("Xin chao khach #2");
B->boFollow();

Bantin->createMsg("Xin chao Dad");

return 0;
}