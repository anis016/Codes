#include<stdio.h>
#include<string.h>

int main()
{
	char in[1000], x[100];
	long i, sum=0, count=1, test=0, j, n=0;
	
	gets(x);                   /////////////// new thing 
	sscanf(x,"%ld", &test);
	
	for(j=1; j<=test; j++)
	{
	    sum=0;
	  gets(in);
	  for(i=0; i<=strlen(in); i++)
	  {
		 
		if(in[i]=='a' || in[i]=='d' || in[i]=='g' || in[i]=='j' || in[i]=='m' || in[i]=='p' || in[i]=='t' || in[i]=='w' || in[i]==' ')
		{
			n=1;
			sum+=n;
		}
		if(in[i]=='b' || in[i]=='e' || in[i]=='h' || in[i]=='k' || in[i]=='n' || in[i]=='q' || in[i]=='u' || in[i]=='x')
		{
			n=2;
			sum+=n;
		}
		if(in[i]=='c' || in[i]=='f' || in[i]=='i' || in[i]=='l' || in[i]=='o' || in[i]=='r' || in[i]=='v' || in[i]=='y')
		{
			n=3;
			sum+=n;
		}
		if(in[i]=='s' || in[i]=='z')
		{
			n=4;
			sum+=n;
		}
	  }
	   
	  printf("Case #%ld: %ld\n", j, sum);
	}
	return 0;
}

