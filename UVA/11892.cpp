#include<stdio.h>

int main()
{
    int Case, i, heap, ithheaps, one, remain;
    
    scanf("%d", &Case);
    while(Case--)
    {
        scanf("%d", &heap);
        one = remain = 0;
        for(i = 0; i < heap; i++)
        {
            scanf("%d", &ithheaps);
            if(ithheaps == 1)
                   one++;
            else
                   remain++;
        }
        
        if(one % 2 )
           printf("poopi\n");
        else
        {
            if(remain >= 1)
                  printf("poopi\n");
            else
                  printf("piloop\n");
        }
    }
    return 0;
}
