#include<stdio.h>
int main()
{long a;
while(1)
{scanf("%ld",&a);
 if(a==0)
 break;
 switch(a)
{
 case 561:
 case 1105:
 case 1729:
 case 2465:
 case 2821:
 case 6601:
 case 8911:
 case 10585:
 case 15841:
 case 29341:
 case 41041:
 case 46657:
 case 52633:
 case 62745:
 case 63973: printf("The number %ld is a Carmichael number.\n",a);//The number 1729 is a Carmichael number.
	     break;
 default:printf("%ld is normal.\n",a);
	 break;}
	 }
return 0;
	 }
