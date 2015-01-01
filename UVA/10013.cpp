#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char str_1[1000001], str_2[1000001], result[1000001], in_1[1000001], in_2[1000001],flag;
int main()
{
	
	long i, x, len_1=0, len_2=0, diff=0,carry, a, k, l, b, n, m, v, w;
	
	scanf("%ld", &n);
	flag=0;
	for(v=1; v<=n; v++)
	{
		scanf("%ld", &m);
		if(flag!=0)
		{
			printf("\n");
		}
		
		for(i=0; i<m; i++)
		{	 
	           scanf("%s", &str_1[i]);
		       scanf("%s", &str_2[i]);
		}
           
			 x=strlen(str_1);
            
			 for(w=x-1, k=0 ; w>=0; w--)
			 {
				 in_1[k]=str_1[w];
			     k++;
			 }
			 
			 for(b=x-1, l=0 ; b>=0; b--)
			 {
				 in_2[l]=str_2[b];
			     l++;
			 }
			 
			 carry=0;

			 for(i=0;i<x;i++)
			 {
				 carry = carry+in_1[i]-48+in_2[i]-48;
				 result[i] = carry%10+48;
				 carry = carry/10;

			 }
			 
			 while(carry!=0)
			 {
			    result[x] = carry%10+48;
			    carry = carry/10;
			    x++;
			 }
			 
			 result[x]='\0';
			 
			 for(a=x-1; a>=0; a--)
			 {
				printf("%c", result[a]);
				flag=1;
			 }
			 printf("\n");
		
	}
			 
			 
	return 0;
}
