#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    long a[4];
    while(scanf("%ld %ld %ld",&a[0],&a[1],&a[2])==3)
    {
      if(!a[0]&& !a[1] && !a[2])
		  break;

	  sort(a, a+3);

      if((a[0]*a[0])+(a[1]*a[1])==(a[2]*a[2]))
           printf("right\n");
      else
           printf("wrong\n");
    }
    return 0;
}
