#include<stdio.h>
#define B 110

main(void)
{
  int i,s,briks[B],sum=0,n,m1,m2=0,K=0;

  while(scanf("%d",&s)!=EOF)
  {
  K++;
  sum=0;
  m2=0;

  if(s==0) 
	  break;
  for(i=0;i<s;i++)
  {
     scanf("%d",&briks[i]);
     sum=sum+briks[i];
  }

  n=sum/s;
  for(i=0;i<s;i++)
  {
   if(n<briks[i])
   {
    m1=briks[i]-n;
    m2+=m1;
   }
 }
 
  printf("Set #%d\n",K);
  printf("The minimum number of moves is %d.\n\n",m2);
 }


  return 0;
}


