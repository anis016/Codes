#include<stdio.h>
#include<string.h>
#define MAX 10000000
typedef long long LL;

LL jack[MAX];

int main()
{
    LL jak, jil, i;
    
    while(scanf("%lld %lld", &jak, &jil) == 2)
    {
        if(!jak && !jil)
             break;
             
        for(i = 0; i < jak; i++)
        {
            int x;
            scanf("%lld", &x);
          
            jack[x] = 1;
        }
    
        int counter = 0;
        for(i = 0; i < jil; i++)
        {
            int x;
            scanf("%lld", &x);
          
            if(jack[x] == 1)
               counter ++;
        }
    
        printf("%lld\n", counter);
        
        memset(jack, 0, sizeof(jack));
    }
    return 0;
}
