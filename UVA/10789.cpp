#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 2002

long hold[MAX+10], hold_l[MAX+10], hold_c[MAX+10], long_temp;
long a[MAX+10], is_prime[MAX+10];
char in[MAX], xx[MAX], ch_temp;
long i, j, k, t, M, len, flag, test, zz, kk;

int sorting(const void *a, const void *b)
{
	return ( strcmp( (char *)a, (char *)b) );
}

int main()
{
	M=sqrt(MAX);
	for(i=3; i<=M; i+=2)
		if(a[i]==0)
			for(j=i*i; j<=MAX; j=j+i+i)
				a[j]=1;

	for(k=3, t=1; k<MAX; k=k+2)
		if(a[k]==0)
		{
			is_prime[t]=k;
			t++;
		}
	is_prime[0]=2;

//	for(i=0; i<t; i++)
//		printf("%ld ", is_prime[i]);

	gets(xx);
	sscanf(xx, "%ld", &test);

	for(zz=1; zz<=test; zz++)
	{
		gets(in);
		len=strlen(in);
	
		for(i=0; i<MAX; i++)
		{
			hold[i]=hold_l[i]=0;
			hold_c[i]='0';
		}
		
		for(i=0; i<len; i++)
			hold[in[i]]++;

	    for(i=0, k=0; i<130; i++)
			if(hold[i]!=0)
			{
				hold_l[k]=hold[i];
				hold_c[k]=i;
				k++;
			}
		
//	for(i=0; i<k; i++)
//		printf("%c %ld\n", hold_c[i], hold_l[i]);

	   qsort((void *)hold_c, k , sizeof(hold_c[0]), sorting);

	   printf("Case %ld: ", zz);
	   
	   flag=0;
	   for(j=0; j<k; j++)
	   {
		   for(i=0; i<MAX; i++)
			   if(is_prime[i]==hold_l[j])
			   {
				   flag=1;
				   printf("%c", hold_c[j]);
				   break;
			   }
			   else if(is_prime[i]>hold_l[j])
			   {
				   break;
			   }
	   }
	   if(flag!=1)
		   printf("empty");
	   printf("\n");
	}
	return 0;
}