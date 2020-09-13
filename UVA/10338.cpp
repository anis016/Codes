#include<stdio.h>
#include<string.h>

#define max 10000

typedef long long tall;
/////////////////////////////  TILL 12!  //////////////////////////////////////////
//////  factorial of whole length / factorial of all the word individually   //////
///////////////////////////////////////////////////////////////////////////////////

tall factorial(tall n) 
{
  
  tall i;
  tall result = 1;
  for (i=2; i<=n; i++) 
	  result *= i; 
  return 
	  result;
}

int main()
{
	char in[max], xx[max]; 
	tall count[max], test;
	tall len, i, k, l, out, ans, s;

	gets(xx);
	test=0;
	sscanf(xx, "%lld", &test);
	for(s=1; s<=test; s++)
	{
	   for(l=0; l<max; l++)
		  count[l]=0;
	   ans=out=0;
		
	   gets(in);
	   len=strlen(in);

	   for(i=0; i<len; i++)
		  if(in[i]>='A' && in[i]<='Z')
		  {
			 count[in[i]-'A']++;
		  }

	   ans=factorial(len);
	   
	   for(k=0; k<26; k++)
	   {
		   out=ans/factorial(count[k]);
		   ans=out;
	   }

	  printf("Data set %lld: %lld\n", s, out);
	}
	return 0;
}