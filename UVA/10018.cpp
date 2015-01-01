#include<stdio.h>
#include<string.h>
#include<math.h>

typedef long tall;

#define max 100000

tall reverse(tall b)
{
	tall a=0, c=0;
	while(b>0)
	{
		c=c*10;
		c=b%10+c;
		b=b/10;
	}
	return c;
}

tall palindrome(tall jj)
{
	char iin[100];
	tall i, j, b, t, k, length, hold;

	hold = log10(jj);                     /////finding the length of the long number
	length = tall(floor(hold)+1);

	j=0;
	while(j!=length)         
	{
 	    iin[j]=(jj%10)+'0'; 
		b=jj/10;
		jj=b;
		j++;
	 }
     iin[j]='\0';

	 for(i=0, t=j-1, k=0; i<j; t--, i++)
	 {
		if(iin[i]==iin[t])
		{
			k++;
		}
	 }

	if(k==j)
		return 1;
	else
		return 0;
}

int main()
{
	tall test, in, rev, add, palin, count=0, i;

	scanf("%lld", &test);
	for(i=0 ;i<test; i++)
	{
		palin=add=rev=count=in=0;
		scanf("%lld", &in);
		while(palin==0)
		{
			  rev = reverse(in);
			  add=in+rev;
			  count++;
			  palin = palindrome(add);
			  in=add;		
		}
		printf("%lld %lld\n", count, add);
	}
	

	return 0;
}