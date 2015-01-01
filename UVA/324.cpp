#include<stdio.h>
#include<string.h>

char array[10000], f[10000];
char factorial[1010][10000];

void multiply(long k)
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

   for(long j=0; j<i; j++)
      factorial[k][j]=f[j];    //for each value of k save the value of factorial of that value of k;
       
   factorial[k][i]='\0';
}

void fac()
{
    long k;
  
	strcpy(f,"1");

	for(k=1;k<=1000;k++)
      multiply(k);
}

void print(long n)
{
    long i, t, j;
    long len;
	long count0,count1,count2,count3,count4,count5,count6,count7,count8,count9;

	len = strlen(factorial[n]);
	printf("%d! --\n",n);

	for(j=len-1,t=0; j>=0; t++, j--)
	{
      array[t]=factorial[n][j];
	}
	array[t]='\0';

	count0=count1=count2=count3=count4=count5=count6=count7=count8=count9=0;
	for(i=0; i<t; i++)
	{
		if(array[i]=='0')
			count0++;
		else if(array[i]=='1')
			count1++;
		else if(array[i]=='2')
			count2++;
		else if(array[i]=='3')
			count3++;
		else if(array[i]=='4')
			count4++;
		else if(array[i]=='5')
			count5++;
		else if(array[i]=='6')
			count6++;
		else if(array[i]=='7')
			count7++;
		else if(array[i]=='8')
			count8++;
		else if(array[i]=='9')
			count9++;
	}
    printf("   (0)%5ld    (1)%5ld    (2)%5ld    (3)%5ld    (4)%5ld\n", count0, count1, count2, count3, count4); 
    printf("   (5)%5ld    (6)%5ld    (7)%5ld    (8)%5ld    (9)%5ld\n", count5, count6, count7, count8, count9);
}

int main()
{
    long n;

	fac();

	while(scanf("%ld",&n)==1)
		if(n==0)
		{
			break;
		}
		else
		{
            print(n);
		}

	return 0;
}