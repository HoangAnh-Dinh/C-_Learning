#include<iostream>
#include<map>
#include<string>

int main()
{
std::map<int, std::string> mp;
mp[0] = "Zero";
mp[1] = "One";
mp[2] = "Two";
mp[3] = "Three";
mp.insert({4,"Four"});
mp.erase(4);
//auto it = mp.at(4);
 //   std::cout << "Tim thay: " << it;

for (const auto& p : mp) {
    std::cout << p.first << " -> " << p.second << "\n";
}

return 0;
}