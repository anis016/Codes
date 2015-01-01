#include<stdio.h>
#include<string.h>

char f[10000];
char factorial[1010][10000];

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
    int i;
    int len = strlen(factorial[n]);

	printf("%d!\n",n);

	for(i=len-1;i>=0;i--)
	{
      printf("%c",factorial[n][i]);
	}

	printf("\n");
}

int main()
{
    int n;

//	factorial[0][0]='1';
 //   factorial[1][0]='1';

	fac();

	while(scanf("%d",&n)==1)
		if(n==0)
			printf("0!\n1\n");
		else
		{
            print(n);
		}

	return 0;
}