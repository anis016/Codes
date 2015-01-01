#include<stdio.h>
#include<string.h>
#define max 1000000

char in1[max];
char in2[max];
char *ptr;

int main()
{
	long len1, len2, i, j, k, m;

	while(scanf("%s %s", in1, in2)==2)
	{
	   len1=len2=i=j=k=m=0;

	   len1=strlen(in1);
	   len2=strlen(in2);

	   ptr = strstr(in2, in1);          /////////in1 holds the first value in2 holds the next value
	   
	   if(ptr!=NULL)
	       printf("Yes\n");
	   
	   else if(len1>len2)
		      printf("No\n");
	   
	   else
	   {
		  k=0;m=0;
		  for(i=0; i<len1; i++)
		  {
			 for(j=m; j<len2; j++)
			 {
				m++;
				if(in1[i]==in2[j])
				{
					k++;
					break;
				}
			}
		}
		if(k==len1)
			printf("Yes\n");
		else 
			printf("No\n");
	   }
	}
	return 0;
}