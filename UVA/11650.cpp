#include<stdio.h>

int main()
{
	int h,m,t;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d:%d",&h,&m);

		if(m>0 && h==12)
		{
			h=11;
			m=60-m;
		}
		else
		{
			if( m>0 ) 
				h++;

			h=12-h;
			m=60-m;
		}
		if(h==0) 
			h=12;

		if(m==60) 
			m=0;

		if( h<=9 )
		{
			if(m<=9)
				printf("0%d:0%d\n",h,m);
			else
				printf("0%d:%d\n",h,m);
		}
		else
		{
			if(m<=9)
				printf("%d:0%d\n",h,m);
			else
				printf("%d:%d\n",h,m);
		}
	}
	return 0;
}

