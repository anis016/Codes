#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define max 100000

typedef long tall;

const char hexc[16][100]={"0000", "0001", "0010", "0011",
						      "0100", "0101", "0110", "0111",
						      "1000", "1001", "1010", "1011",
						      "1100", "1101", "1110", "1111"};
int main()
{
	char in1[max], in2[max];
	char out1[max]="" , out2[max]="";
	char hold1[max], hold2[max];
	char mig1[max], mig2[max];

	char test1[max];
        char d;

	tall test, pe, va;
	tall len1, len2;
	tall gam1, gam2; 
	tall ans;
	
	gets(test1);
	sscanf(test1, "%ld", &test);
	
	for(pe=0; pe<test; pe++)
	{
	
		for(va=0; va<max; va++)
			in1[va]=in2[va]=out1[va]=out2[va]=hold1[va]=hold2[va]=mig1[va]=mig2[va]=0;

	   scanf("%s %c %s", &in1, &d, &in2);
 	
	   sscanf(in1, "%X", &gam1);
	   sscanf(in2, "%X", &gam2);
	
	  len1 = strlen(in1); ////////holds 1st

	  len2 = strlen(in2); ////////holds 2nd

	  tall ii;

	  for(ii=0; ii<len1; ii++)
	  {
		 char ho1;
		 if(in1[ii]>='0' && in1[ii]<='9')
			ho1=in1[ii]-'0';
		 else if(in1[ii]>='A' && in1[ii]<='F')
			ho1=in1[ii]-'A'+10;

		strcat(out1, hexc[ho1]);
	  }

	  tall jj, llen, kk, tt;
	
	  llen= strlen(out1);

	  if(llen<13)
	  {
		 for(kk=llen-1, tt=0; kk>=0; kk--, tt++)
			mig1[tt]=out1[kk];
			
		 for(jj=llen; jj<13; jj++)
			mig1[jj]='0';
	  }

	  kk=0;
	  for(kk=12, tt=0; kk>=0; kk--, tt++)
			hold1[tt]=mig1[kk];
	
	  hold1[tt]='\0';

	  printf("%s", hold1);

/**************************************************************/
	  if(d=='+')
		 printf(" + ");
	  else
		 printf(" - ");
/**************************************************************/
	
	  tall i;
	  for(i=0; i<len2; i++)
	  {
		 char ho2;
		 if(in2[i]>='0' && in2[i]<='9')
			ho2=in2[i]-'0';
		 else if(in2[i]>='A' && in2[i]<='F')
			ho2=in2[i]-'A'+10;

		 strcat(out2, hexc[ho2]);
	  }

	  tall j, len, k, t;
	
	  len= strlen(out2);

	  if(len<13)
	  {
		 for(k=len-1, t=0; k>=0; k--, t++)
			mig2[t]=out2[k];
			
		 for(j=len; j<13; j++)
			mig2[j]='0';
	  }
	  k=0;
	  for(k=12, t=0; k>=0; k--, t++)
			hold2[t]=mig2[k];
	
	  hold2[t]='\0';

	  printf("%s", hold2);

/**************************************************************************/
	  printf(" = ");
/**************************************************************************/

	  if(d=='+')
	  {
		 ans = gam1+gam2;
	    printf("%ld\n", ans);
	  }
	  else
	  {
		 ans=gam1-gam2;
		printf("%ld\n", ans);
	  }
	}
	 
	return 0;
}

