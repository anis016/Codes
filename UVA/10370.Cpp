#include<stdio.h>
#define N 1010

main(void)
{
  int c,s[N],i,j,sum,k,l,m;
  double A_avg,avg;

  scanf("%d",&k);
  {
  
  for(i=0;i<k;i++)
  {
  sum=0;
  scanf("%d",&c);
  for(l=0;l<c;l++)
  {

   scanf("%d",&s[l]);
   sum=sum+s[l];
  }
  avg=sum/(float)c;
  j=0;
  for(m=0;m<c;m++)
  {
   if(avg<s[m])
   j++;
  }

  A_avg=(j/(double)c)*100;

  printf("%.3lf%\n",A_avg);
  }
  }
  return 0;
}