#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

#define MAX 20000

char *ch, buf[MAX], mors[MAX], res[MAX], xx[MAX], morse[1000][20000];
int main()
{
	long i, len, N, fin, kase, con;
	
	gets(xx);
	sscanf(xx, "%ld", &kase);

	con=0;
	while(kase--)
	{
		gets(buf);
		len=strlen(buf);

		for(i=0, N=0; i<len; )
		{
			if(buf[i]==' ' && buf[i+1]==' ')
			{
				mors[N]=buf[i];
				N++;
				i++;
				mors[N]='s';
				N++;
				i++;
				mors[N]=' ';
				N++;
			}
			else
			{
				mors[N]=buf[i];
				N++;
				i++;
			}
		}
		mors[N]='\0';

		N=0;
		ch=strtok(mors, " ");
		while(ch)
		{
			strcpy(morse[N], ch);
			N++;
			ch=strtok(NULL, " ");
		}
		
		fin=0;
		for(i=0; i<N; fin++, i++)
		{
			if(strcmp(morse[i],".-")==0)
				res[fin]='A';
			
			else if(strcmp(morse[i],"-...")==0)
				res[fin]='B';
			
			else if(strcmp(morse[i],"-.-.")==0)
				res[fin]='C';
			
			else if(strcmp(morse[i],"-..")==0)
				res[fin]='D';
			
			else if(strcmp(morse[i],".")==0)
				res[fin]='E';
			
			else if(strcmp(morse[i],"..-.")==0)
				res[fin]='F';
			
			else if(strcmp(morse[i],"--.")==0)
				res[fin]='G';

			else if(strcmp(morse[i],"....")==0)					
				res[fin]='H';		   
			
			else if(strcmp(morse[i],"..")==0)		 
				res[fin]='I';
			
			else if(strcmp(morse[i],".---")==0)
				res[fin]='J';
			
			else if(strcmp(morse[i],"-.-")==0)
				res[fin]='K';
			
			else if(strcmp(morse[i],".-..")==0)
				res[fin]='L';
			
			else if(strcmp(morse[i],"--")==0)
				res[fin]='M';
			
			else if(strcmp(morse[i],"-.")==0)
				res[fin]='N';
			
			else if(strcmp(morse[i],"---")==0)
				res[fin]='O';
			
			else if(strcmp(morse[i],".--.")==0)
				res[fin]='P';
			
			else if(strcmp(morse[i],"--.-")==0)
				res[fin]='Q';
			
			else if(strcmp(morse[i],".-.")==0)
				res[fin]='R';
			
			else if(strcmp(morse[i],"...")==0)
				res[fin]='S';
			
			else if(strcmp(morse[i],"-")==0)
				res[fin]='T';
			
			else if(strcmp(morse[i],"..-")==0)
				res[fin]='U';
			
			else if(strcmp(morse[i],"...-")==0)
				res[fin]='V';
			
			else if(strcmp(morse[i],".--")==0)
				res[fin]='W';
			
			else if(strcmp(morse[i],"-..-")==0)
				res[fin]='X';
			
			else if(strcmp(morse[i],"-.--")==0)
				res[fin]='Y';
			
			else if(strcmp(morse[i],"--..")==0)
				res[fin]='Z';
			
			else if(strcmp(morse[i],"-----")==0)
				res[fin]='0';
			
			else if(strcmp(morse[i],".----")==0)
				res[fin]='1';
			
			else if(strcmp(morse[i],"..---")==0)
				res[fin]='2';
			
			else if(strcmp(morse[i],"...--")==0)
				res[fin]='3';
			
			else if(strcmp(morse[i],"....-")==0)
				res[fin]='4';
			
			else if(strcmp(morse[i],".....")==0)
				res[fin]='5';
			
			else if(strcmp(morse[i],"-....")==0)
				res[fin]='6';
			
			else if(strcmp(morse[i],"--...")==0)
				res[fin]='7';
			
			else if(strcmp(morse[i],"---..")==0)
				res[fin]='8';
			
			else if(strcmp(morse[i],"----.")==0)
				res[fin]='9';
			
			else if(strcmp(morse[i],".-.-.-")==0)
				res[fin]='.';
			
			else if(strcmp(morse[i],"--..--")==0)
				res[fin]=',';
			
			else if(strcmp(morse[i],"..--..")==0)
				res[fin]='?';
			
			else if(strcmp(morse[i],".----.")==0)
				res[fin]=39;
			
			else if(strcmp(morse[i],"-.-.--")==0)
				res[fin]='!';
			
			else if(strcmp(morse[i],"-..-.")==0)
				res[fin]='/';
			
			else if(strcmp(morse[i],"-.--.")==0)					
				res[fin]='(';			 
			
			else if(strcmp(morse[i],"-.--.-")==0)					
				res[fin]=')';
			
			else if(strcmp(morse[i],".-...")==0)
				res[fin]='&';
			
			else if(strcmp(morse[i],"---...")==0)
				res[fin]=':';
			
			else if(strcmp(morse[i],"-.-.-.")==0)
				res[fin]=';';
			
			else if(strcmp(morse[i],"-...-")==0)
				res[fin]='=';
			
			else if(strcmp(morse[i],".-.-.")==0)
				res[fin]='+';
			
			else if(strcmp(morse[i],"-....-")==0)
				res[fin]='-';
			
			else if(strcmp(morse[i],"..--.-")==0)
				res[fin]='_';
			
			else if(strcmp(morse[i],".-..-.")==0)
				res[fin]=34;
			
			else if(strcmp(morse[i],".--.-.")==0)
				res[fin]='@';

			else if(strcmp(morse[i],"s")==0)
				res[fin]=' ';
    }
	   
	   res[fin]='\0';

	   ++con;
	   cout<<"Message #"<<con<<endl;
	   cout<<res<<endl;

	   if(kase) 
		   cout<<endl;

	   for(i=0; i<N; i++)		
		  strcpy(morse[i], "\0");
	   strcpy(mors, "\0");
    }
	return 0;
}
