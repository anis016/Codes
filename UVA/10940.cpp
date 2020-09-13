#include<stdio.h>
#include<iostream.h>
//using namespace std;

int main()
{
	long n, x, s, result=0;

	while(scanf("%ld", &n), n)
	{
		s=0, result=0;
		
		for(x=1; ;)
		{
			if(x>=n)
				break;
			x=x*2;
		  s=x%n;
		}

	    result=n-s;
  	    printf("%ld\n", result);
	}
	return 0;
}

/************************************************************/
/*
(how can i do using queue?? it gets tle, refer to formula)

Steven Halim 

Take the input n.
Let x is an integer initialized by 1.
Loop until x>=n
  x = x*2
s = x%n
Result = n - s
Output = Result.
*/
/************************************************************/