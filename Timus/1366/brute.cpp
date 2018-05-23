
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

const int base = 1000;

std::vector<int> add(std::vector<int>& a, std::vector<int>& b) // Bigint addition
{
    std::vector<int> c;
    int carry = 0;
    a.resize(std::max(a.size(), b.size()), 0);
    b.resize(std::max(a.size(), b.size()), 0);
    for(int i = 0; i < a.size(); i++)
    {
        c.push_back((a[i]+b[i]+carry) % base);
        carry = (a[i]+b[i]+carry)/base;
    }
    if(carry)
        c.push_back(carry);
    return c;
}

std::vector<int> mul(std::vector<int>&& a, int b) // Bigint multiplication by normal int
{
    std::vector<int> c;
    int carry = 0;
    for(int i = 0; i < a.size(); i++)
    {
        c.push_back((a[i]*b+carry) % base);
        carry = (a[i]*b+carry)/base;
    }
    if(carry)
        c.push_back(carry);
    return c;
}

std::string toStr(std::vector<int>& a) // Bigint to string
{
    std::string ret;
    for(int i = a.size()-1; i >= 0; i--)
    {
        std::string s = std::to_string(a[i]);
        ret += (i < a.size()-1 ? std::string(3-s.size(), '0') : "") + s;
    }
    return ret;
}
std::string algo(int n) // As in the header comment
{
    std::vector<int> A[1001];
    A[0] = {1};
    A[1] = {0};
    for(int i = 2; i <= n; i++)
        A[i] = mul(add(A[i-2],A[i-1]), i-1);
    return toStr(A[n]);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << algo(n) << std::endl;
}
