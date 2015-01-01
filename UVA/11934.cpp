#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a, b, c, d, l;
    while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &l) && !(a == 0 && b == 0 && c == 0 && d == 0 && l == 0))
    {
        int ans = 0;
        for(int i = 0; i <= l; i++)
        {
            int tmp = a * i * i + b * i + c;
            if (tmp % d == 0) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}