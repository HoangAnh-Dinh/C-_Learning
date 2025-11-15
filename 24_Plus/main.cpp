#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class IObserver
{
public:
~IObserver()=default;
virtual void update(string msg)=0;
virtual void unfollow()=0;
};


class Subject
{
private:
Subject(){cout<<"Khoi tao kenh thanh cong"<<endl;}
Subject(const Subject& a)=delete;
Subject& operator=(const Subject& a)=delete;
string msg;
vector<IObserver*> observerList;

public:
static Subject& getInstance()
{
static Subject ins;
return ins;
}
void attach(IObserver* ins)
{
observerList.push_back(ins);
}
void detach(IObserver* ins)
{
observerList.erase(remove(observerList.begin(),observerList.end(),ins),observerList.end());
}
void notify()
{
for(auto* ins:observerList)
{
ins->update(msg);
}
}
void createMsg(string mess)
{
msg = mess;
notify();
}
};

class concreteObserver: public IObserver
{
private:
string name;
Subject* _subject;
public:
concreteObserver(string e_name, Subject* e_subject):name(e_name),_subject(e_subject)
{
_subject->attach(this);
cout<<"Da add client "<<name<<" !"<<endl;
}
void update(string msg)
{
cout<<name<<" nhan duoc thong bao : "<<msg<<endl;
}
void unfollow()
{
_subject->detach(this);
}
};

int main()
{
Subject& VTV1 = Subject::getInstance();
Subject& VTV2 = Subject::getInstance();

IObserver* Nam = new concreteObserver("Nam",&VTV1);
IObserver* Han = new concreteObserver("Han",&VTV1);
IObserver* Hai = new concreteObserver("Hai",&VTV1);
IObserver* Dung = new concreteObserver("Dung",&VTV1);

VTV1.createMsg("Hom nay chieu hoat hinh");

Nam->unfollow();
VTV1.createMsg("Hom nay chieu ca nhac");

Dung->unfollow();
VTV1.createMsg("XXXXXXXXXNo SignalXXXXXXX");

Han->unfollow();
VTV1.createMsg("Hom nay chieu thoi su");


return 0;
}
