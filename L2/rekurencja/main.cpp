#include <iostream>

//using namespace std;
int f(int n)
{
    return n;
}
float sum(int n)
{
    if (n > 0)
        return f(n) + sum(n - 1);
    else
        return f(0);
}
int main()
{
    std::cout << sum(10) << std::endl;
    return 0;
}
