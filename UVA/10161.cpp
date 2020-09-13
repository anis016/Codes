#include<iostream>     
#include<cstdlib>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int n, x, y;
    while(cin >> n)
    {
        if(n == 0)  break;
        
        x = (int)ceil(sqrt(n));
        y = x * x - x + 1;
        
        if(x % 2 == 0)   // even 
        {
            if(n > y)  
				printf("%ld %ld\n", x, x - (n - y));
            else if(n < y)  
				printf("%ld %ld\n", x - (y - n), x);
            else
				printf("%ld %ld\n", x, x);
        }
        else            // odd
        {
            if(n > y)  
				printf("%ld %ld\n", x - (n - y), x );
            else if(n < y)  
				printf("%ld %ld\n", x, x - (y - n));
            else
				printf("%ld %ld\n", x, x);
        }
    }
    
    return 0;
}