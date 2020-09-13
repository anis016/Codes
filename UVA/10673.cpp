#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    long n, x, k, a, b, p, q, i;
    
    scanf("%ld", &n);
    while(n--)
    {
        cin >> x >> k;
        
        a = (long)floor((double)x / (double)k);
        b = (long)ceil((double)x / (double)k);
        
        if((a == 0) && (b == 0))
        {
            printf("0 0\n");
            continue;
        }
        else if(b == 0)
        {
            printf("%ld 0\n", x/a);
            continue;
        }
        else if(a == 0)
        {
            printf("0 %ld\n", x/b);
            continue;
        }
        
        i = x / b ;
        
        while(1)
		{
			p = (x - i * b) % a;          /// important any solution is possible.....
			if(p==0)
				break;
            i--;
		}

		cout << (x - i * b) / a << ' ' << i << endl;

    }
    
    return 0;
}