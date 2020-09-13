#include<iostream>
using namespace std;
#include<string.h>

int main()
{
	char in[100];

	while(gets(in))
	{
		long count=0, t, flag_2=0, flag_1=0, flag_3=0, flag_4=0, flag_5=0, flag_6=0;

		for(t=0; t<strlen(in); t++)
		{ 
		  if((in[t]=='B' || in[t]=='F' || in[t]=='P' || in[t]=='V') && flag_1==0)
		  {
		          cout<<"1";
		          flag_1=1;
		          flag_2=flag_3=flag_4=flag_5=flag_6=0;
		  }
		  else if((in[t]=='C' || in[t]=='G' || in[t]=='J' || in[t]=='K' || in[t]=='Q' || in[t]=='S' || in[t]=='X' || in[t]=='Z') &&flag_2==0)
		  {
			  cout<<"2";
			  flag_2=2;
			  flag_1=flag_3=flag_4=flag_5=flag_6=0;
		  }
		  else if((in[t]=='D' || in[t]=='T') && flag_3==0)
		  {
			  cout<<"3";
			  flag_3=3;
			  flag_1=flag_2=flag_4=flag_5=flag_6=0;
		  }
		  else if(in[t]=='L' && flag_4==0)
		  {
			  cout<<"4";
			  flag_4=4;
			  flag_1=flag_2=flag_3=flag_5=flag_6=0;
		  }
		  else if((in[t]=='M' || in[t]=='N') && flag_5==0)
		  {
			  cout<<"5";
			  flag_5=5;
			  flag_1=flag_2=flag_3=flag_4=flag_6=0;
		  }
		  else if(in[t]=='R' && flag_6==0)
		  {
			  cout<<"6";
			  flag_6=6;
			  flag_1=flag_2=flag_3=flag_4=flag_5=0;
		  }
		  else if(in[t]=='A' || in[t]=='E' || in[t]=='I' || in[t]=='O' || in[t]=='U' || in[t]=='H' || in[t]=='W' || in[t]=='Y')
          	  
			  flag_1=flag_2=flag_3=flag_4=flag_5=flag_6=0;
		}
		cout<<endl;
	}

	return 0;
}

