#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long long N, t=1;
   long  double out;
      
    while(scanf("%lld", &N),N)
    {
      out = ceil((3.0+sqrt(9.0+8.0*N))/2.0);
      printf ("Case %lld: %.0Lf\n", t++, out);
    }
    return 0;
}
