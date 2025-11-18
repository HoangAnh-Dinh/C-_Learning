#include<iostream>

//Con tro hang va hang con tro


int main()
{
int a = 8;
int c = 10;
int* const b = &a;

a = 15;

std::cout<<" *b = "<<*b;


return 0;
}