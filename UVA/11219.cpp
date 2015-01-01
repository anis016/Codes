#include<stdio.h>

int main()
{
	long day, month, year, i, day1, month1, year1, age, age1, hold;
	long test,bo;
	char ch;

	scanf("%ld", &test);
	for(i=1; i<=test; i++)
	{ 
 	   scanf("%ld %c %ld %c %ld", &day, &ch,  &month, &ch, &year);
	   scanf("%ld %c %ld %c %ld", &day1, &ch, &month1, &ch, &year1);

	   age =  day + (month-1)*30  + year*365 ;
	   age1 = day1 + (month1-1)*30 + year1*365 ;
		   
	   hold = age-age1;
	   if(hold<0)
	   {
			printf("Case #%ld: Invalid birth date\n",i);
	   }
	   else
	   {
	   
	         bo = hold/365;
		   
	       if(bo>130)
			   printf("Case #%ld: Check birth date\n",i);
		   else
			   printf("Case #%ld: %ld\n",i,bo);
	  }   
	}

	return 0;

}