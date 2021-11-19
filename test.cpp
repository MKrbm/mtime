#include <cstdio>
#include <iostream>

int a(void) {
    int i=0,g=0;
    while(i++<100)
    {
        g+=i;
    }
    return g;
}
int b(void) {
    int i=0,g=0;
    while(i++<100)
    {
        g+=i;
    }
    return g;
}

int main()
{
    int iterations = 10;
    while(iterations--)
    {
        a();
        b();

        int i=0,g=0;
        while(i++<1000)
        {
            g+=i;
        }
        std::cout << g << std::endl;

    }

    return 0;
}