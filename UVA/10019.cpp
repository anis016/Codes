#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define max 100000

typedef long tall;

const char hexc[16][100]={"0000", "0001", "0010", "0011",
						  "0100", "0101", "0110", "0111",
						  "1000", "1001", "1010", "1011",
						  "1100", "1101", "1110", "1111"};

tall convert_to_bin(tall in1)
{
	tall num=0,help=0,convert[max];
	tall i=0,j=0;
	tall count=0;
	tall ss=0;
	tall ret=0;
	
	for(ss=0; ss<max; ss++)
		convert[ss]=0;

	num=in1;
	
	i=0;
	while(num!=0)
	{
			help=num%2;
			convert[i++]=help;
			num/=2;
	}
	
	count=0;
	for(j=i-1;j>=0;j--)
	{
		if(convert[j]==1)
			count++;
	}

	ret= count;

	return ret;
}

char in[max], out[max]="", xx[max];
int main()
{
	
	tall in2;
	tall test, g, len, i, count, len2, j, ho1, s;
	
	char hold;

	gets(xx);
	sscanf(xx, "%lld", &test);
	for(g=0; g<test; g++)
	{
	   len=i=count=len2=j=ho1=0;
	   for(s=0; s<max; s++)
		   out[s]=in[s]=0;

	   gets(in);

	   in2=atoi(in);
  
	   ho1 = convert_to_bin(in2);

	   len = strlen(in);

	   for(i=0; i<len; i++)
	   {		  
		if(in[i]>='0' && in[i]<='9')
			hold=in[i]-'0';
		else if(in[i]>='A' && in[i]<='F')
			hold=in[i]-'A'+10;
	 	
		strcat(out, hexc[hold]);
	   }

	   len2=strlen(out);
	   count=0;
	   for(j=0; j<len2; j++)
	   if(out[j]=='1')
		  count++;

      printf("%lld %lld\n", ho1, count);
	}

	return 0;
}
