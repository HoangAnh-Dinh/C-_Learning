#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class IObserver
{
public:
virtual ~IObserver()=default;
virtual void Update(std::string msg)=0;
virtual void dettach()=0;
};

class publisher
{
private:
std::vector<IObserver*> observerList;
std::string message;
public:
publisher()
{
std::cout<<"Publisher created"<<std::endl;
}
void attach(IObserver* ins)
{
observerList.push_back(ins);
}
void dettach(IObserver* ins)
{
observerList.erase(remove(observerList.begin(),observerList.end(),ins),observerList.end());
}
void notify()
{
for(auto* a:observerList)
{a->Update(message);}
}
void publish(std::string msg)
{
message = msg;
notify();
}
};
class concreteObserver : public IObserver
{
private:
std::string name;
publisher* subject;
public:
concreteObserver(std::string _name, publisher* _subject):name(_name),subject(_subject)
{
 std::cout<<"Create "<<name<<std::endl;
 subject->attach(this);
}
void Update(std::string msg) override
{
 std::cout<<"Receive msg : "<<msg<<std::endl;
}
void dettach() override
{
 subject->dettach(this);
}
 
};

int main()
{
 publisher* youtube = new publisher();
 IObserver* A = new concreteObserver("HoangAnh",youtube);
 IObserver* B = new concreteObserver("PhuongAnh",youtube);
 IObserver* C = new concreteObserver("Dua",youtube);
 youtube->publish("Let's watch");
 A->dettach();
youtube->publish("Most Impotant thing");
 
 
 return 0;
}