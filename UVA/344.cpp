#include<stdio.h>
#include<string.h>
#include<math.h>

typedef long tall;

#define max 100000

const char roman_unit[10][20]={ " ", "i","ii","iii","iv","v","vi","vii","viii","ix" };
const char roman_ten[10][20]={ " ", "x","xx","xxx","xl","l","xl","lxx","lxxx","xc" };
const char roman_hund[2][10]={" ", "c"};

int main()
{
	char out_u[max]="", out_h[max]="", out_t[max]="";
	char ho1[max]="";
	tall in, i=0;
	double hold; 
	tall  ho_d, ho_m, length;
	tall counti, countv, countx, countl, countc, len, j;

	while(scanf("%ld", &in), in)
	{
		counti=countv=countx=countl=countc=len=0;
		for(tall ss=0; ss<max; ss++)
			out_u[ss]=out_t[ss]=out_h[ss]=ho1[ss]=0;

		for(i=1; i<=in; i++)
		{
		  hold = log10(i);
          length = tall(floor(hold)+1);
		  
		  if(i==10 || i==20 || i==30 || i==40 || i==50 || i==60 || i==70 || i==80 || i==90)
			  length=2;

		  if(length==1)
		  {
			ho_d=i;
			strcpy(out_u, roman_unit[ho_d]);

		    strcat(ho1, out_u);
///			printf("%s", out_u);
		  }

		  else if(length==2)
		  {
			ho_d=i/10;
			ho_m=i%10;

			strcpy(out_t, roman_ten[ho_d]);
			strcpy(out_u, roman_unit[ho_m]);

			if(ho_m!=0)
			  strcat(ho1, out_u);
			strcat(ho1, out_t);
//			printf("%s%s", out_t, out_u);
		  }

		  else if(i==100)
		  {
			strcpy(out_h, roman_hund[1]);
			strcat(ho1, out_h);
//			printf("%s", out_h);
		  }
		}

		len=strlen(ho1);
		for(j=0; j<len; j++)
		{
			if(ho1[j]=='i')
				counti++;
			if(ho1[j]=='x')
				countx++;
			if(ho1[j]=='l')
				countl++;
			if(ho1[j]=='v')
				countv++;
			if(ho1[j]=='c')
				countc++;
			if(ho1[j]==' ')
				continue;
		}

		printf("%ld: %ld i, %ld v, %ld x, %ld l, %ld c\n", in, counti, countv, countx, countl, countc);
	}
	
	return 0;
}