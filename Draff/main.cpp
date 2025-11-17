#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void swap(int& a, int& b)
{
a = a^b;
b = a^b;
a = a^b;
}
int main()
{
int a[10] = {7,6,4,5,9,3,1,0,2,10};
int n = sizeof(a)/sizeof(a[0]);
int minIdx = 0;
for(int i = 0; i < n-1; i++)
{
minIdx = i;
for(int j = i+1; j < n-1; j++)
{
 if(a[j]<a[minIdx])
 {
    swap(a[j],a[minIdx]);
 }
}
}

for(auto x:a)
{
 cout<<x<<endl;
}
return 0;
}