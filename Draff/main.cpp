#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
int a[10] = {1,2,3,4,5,6,7,8,9,10};
remove(a,a+10,7);
for(auto e:a)
{
    cout<<e<<endl;
}
return 0;
}