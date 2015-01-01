#include<stdio.h>

typedef long long tall;

tall gcd(tall a,tall b) 
{
  if (a%b==0) 
	  return b; 
  else 
	  return gcd(b,a%b);
}

void Divbygcd(tall& a,tall& b) 
{
  tall g=gcd(a,b);
  a/=g;
  b/=g;
}

tall COMBINATIONS(tall n,tall k)
{
  tall numerator=1,denominator=1,toMul,toDiv,i;

  if (k>n/2) 
	  k=n-k; /* use smaller k */

  for (i=k;i;i--) 
  {
    toMul=n-k+i;
    toDiv=i;
    Divbygcd(toMul,toDiv);       /* always divide before multiply */
    Divbygcd(numerator,toDiv);
    Divbygcd(toMul,denominator);
    numerator*=toMul;
    denominator*=toDiv;
  }

  return numerator/denominator;
}

int main()
{
	tall n, k, c;

	while(scanf("%lld %lld", &n, &k)!=EOF)
	{
		if(n==0 && k==0)
			break;
		else
		{
		      c=COMBINATIONS(n, k);
 	          printf("%lld\n", c);
		}
	}
	return 0;
}
