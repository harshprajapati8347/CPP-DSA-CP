#include <iostream>
using namespace std;
class sum
{
public:
    int n, s = 0;
    void calc();
    void display();
    void calc()
    {
        for (n = 1; n <= 100; n += 2)
            s = s + n;
    }
};
return s;
};
int main()
{
    sum s;
    s.calc();
    s.display();
}