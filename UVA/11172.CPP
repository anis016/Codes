#include<stdio.h>


int main()
{
 int n, m;
 long int i, j;

 scanf("%d", &m);
  for(n=0;n<m;n++)
 
  {
		scanf("%ld %ld", &i, &j);
	if(i==j)
		printf("=\n");
	else if(i>j)
		printf(">\n");
	else
		printf("<\n");
  }
 
  return 0;
}