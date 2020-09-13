#include<stdio.h>
int main()
{
	long int a,i,x[50000],j,t,count;
   
while(scanf("%ld",&a)!=EOF)
	{
		    for(i=0;i<a;i++)
		    scanf("%ld",&x[i]);
            count=0;
		    for(i=1;i<a;i++)
		       for(j=1;j<=a-i;j++)
	           if(x[j-1]>x[j])
	           {
		          t=x[j-1];
	              x[j-1]=x[j];
	              x[j]=t;
	              count++;
				}
            
		printf("Minimum exchange operations : %ld\n",count);
      }
    return 0;
}
