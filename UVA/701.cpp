#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main()
{
   long double  n, N, E, i, log2, j;

   while(scanf("%Lf", &n) == 1)
   {
      i    = floor(log10(n));
      log2 = log10((long double)2.0);
      
	  for(j = i + 2.0; ; j += 1.0)
      {
         E = n;
         N = n + 1.0;         
         
         if(ceil((log10(E)+j)/log2)==floor((log10(N)+j)/log2))
         {
            printf("%.0Lf\n",ceil((log10(E)+j)/log2));
            break;
         }
      }   
   }   
   return 0;
}
