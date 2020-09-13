#include<stdio.h>

int main()
{
    int a, b, c, d, e, n, i;
    
    while(scanf("%d", &n) == 1)
    {
        if(!n)
          break;
        
        for(i = 0; i < n; i++)
        {
            int flagB, flag;
            flagB = flag = 0;
            
            scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
            if(a <= 127)
            {
                 flag = 65; 
                 flagB++;
            }
            if(b <= 127)
            {
                 flag = 66; 
                 flagB++;
            }
            if(c <= 127)
            {
                 flag = 67; 
                 flagB++;
            }
            if(d <= 127)
            {
                 flag = 68; 
                 flagB++;
            }
            if(e <= 127)
            {
                 flag = 69; 
                 flagB++;
            }
            
            if(flagB == 1)
            {
                printf("%c\n", flag);
            }
            else
                printf("*\n");
        }
    }
    return 0;
}
