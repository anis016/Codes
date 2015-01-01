#include<stdio.h>
#include<string.h>

#define max 10000
int main()
{
	char c,a[max],b[max];
	long lengtha,lengthb,i,t,hate,carry;

  while(scanf("%s %s",a,b)==2)
  {
	if(a[0]=='0'&& b[0]=='0')
		break;

     lengtha=strlen(a);
     lengthb=strlen(b);

     t=lengtha;
     if(t>lengthb)
       t = lengthb;

     hate=carry=0;

     for(i=0;i<lengtha/2;i++)
	 {
        c=a[i];
        a[i]=a[lengtha-1-i];
        a[lengtha-1-i]=c;
	 }

	for(i=0;i<lengthb/2;i++)
	{
		c=b[i];
		b[i]=b[lengthb-1-i];
		b[lengthb-1-i]=c;
	}
	
	for(i=0;i<t;i++)
	{
		hate=hate+a[i]-48+b[i]-48;
		a[i]=hate%10+48;
		hate=hate/10;
			if(hate!=0)
				carry++;
	}

	for(i=t;i<lengtha;i++)
	{
       hate=hate+a[i]-48;
	   a[t]=hate%10+48;
       hate=hate/10;
            if(hate!=0)
                carry++;
            t++;
	}

    for(i=t;i<lengthb;i++)
	{
       hate=hate+b[i]-48;
       a[t]=hate%10+48;
       hate=hate/10;
           if(hate!=0)
                carry++;
           t++;
	}
    while(hate!=0)
	{
       a[t]=hate%10+48;
       hate=hate/10;
          if(hate!=0)
               carry++;
          t++;
	}

    if(carry==0)
        printf("No carry operation.\n");
    else if(carry==1)
        printf("1 carry operation.\n");
    else
        printf("%ld carry operations.\n",carry);
  }
  return 0;
}