#include<stdio.h>
#include<string.h>

char f[10000];
char factorial[1010][10000];
char hold[10000];

void multiply(int k)
{
   int cin,sum,i;
   
   int len = strlen(f);
   
   cin=0; 
   i=0;

   for(i=0; i<len; i++)
   {
    sum = cin+(f[i] - '0') * k;
    f[i] = (sum % 10) + '0';
    cin = sum/10;
   }

   while(cin>0)
   {
    f[i++] = (cin%10) + '0';
    cin/=10;
   }

   f[i]='\0';

   for(int j=0; j<i; j++)
      factorial[k][j]=f[j];    //for each value of k save the value of factorial of that value of k;
       
   factorial[k][i]='\0';
}

void fac()
{
    int k;
  
	strcpy(f,"1");

	for(k=1;k<=1000;k++)
      multiply(k);
}

void print(int n)
{
    long i, j, sum;
    long len = strlen(factorial[n]);
	long t;

	for(i=len-1, t=0;i>=0;t++, i--)
	{
       hold[t]=factorial[n][i];
	}
	hold[t]='\0';
	
	sum=0;
	for(j=0; j<t; j++)
		sum+=hold[j]-48;

	printf("%ld\n", sum);

}

int main()
{
    long n;

	fac();

	while(scanf("%ld",&n)==1)
		if(n==0)
			printf("1\n");
		else
		{
            print(n);
		}

	return 0;
}