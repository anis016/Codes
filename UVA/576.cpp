#include<stdio.h>
#include<string.h>

char in[1000000];

int main()
{
	long long i, len, j=0, k=0, count_5_b=0, count_7_m=0, count_5_e=0, sla_1=0, sla_2=0, diff=0;

	long long hold1=0, hold2=0, hold3=0;

	while(gets(in))
	{
		hold1=hold2=hold3=0;
		count_5_b=count_7_m=count_5_e=0;
		sla_1=sla_2=0;
		i=len=j=k=0;
		diff=0;

		if( (in[0]==101) && (in[1]==47) && (in[2]==111) && (in[3]==47) && (in[4]==105) )
			break;
		
		else
		{
			len= strlen(in);
			count_5_b=0;
			for(i=0; i<len; i++)
			{
				if(in[i]==47)
				{
					sla_1=i;
					break;
				}
				else if( (in[i]=='a' || in[i]=='e' || in[i]=='i' || in[i]=='o' || in[i]=='u' || in[i]=='y') && diff==0)
				{
			        count_5_b++;
			        diff=1;
				}
		        else if(in[i]==' ')
			        diff=0;
		        else if( (in[i]>='b' && in[i]<='d') || (in[i]>='f' && in[i]<='h') || (in[i]>='j' && in[i]<='n') || (in[i]>='p' && in[i]<='t') || (in[i]>='v' && in[i]<='x') || in[i]=='z')
			        diff=0;				
			}
			hold1=count_5_b;
			 
			diff=0;
			count_7_m=0;
			for(j=sla_1+1; j<len; j++)
			{
				  if(in[j]==47)
				  {
					 sla_2=j;
					 break;
				  }
				  else if( (in[j]=='a' || in[j]=='e' || in[j]=='i' || in[j]=='o' || in[j]=='u' || in[j]=='y') && diff==0)
				  {
			         count_7_m++;
			         diff=1;
				  }
		          else if(in[j]==' ')
			         diff=0;
		          else if( (in[j]>='b' && in[j]<='d') || (in[j]>='f' && in[j]<='h') || (in[j]>='j' && in[j]<='n') || (in[j]>='p' && in[j]<='t') || (in[j]>='v' && in[j]<='x') || in[j]=='z')
			         diff=0;
			}
			hold2=count_7_m;

			diff=0;
			count_5_e=0;
			for(k=sla_2+1; k<=len; k++)
			{
				 if( (in[k]=='a' || in[k]=='e' || in[k]=='i' || in[k]=='o' || in[k]=='u' || in[k]=='y') && diff==0)
				 {
			        count_5_e++;
			        diff=1;
				 }
		         else if(in[k]==' ')
			        diff=0;
		         else if( (in[k]>='b' && in[k]<='d') || (in[k]>='f' && in[k]<='h') || (in[k]>='j' && in[k]<='n') || (in[k]>='p' && in[k]<='t') || (in[k]>='v' && in[k]<='x') || in[k]=='z')
			        diff=0;
				
			}
			hold3=count_5_e; 
		}

		if(hold1==5 && hold2==7 && hold3==5)
		{
			printf("Y\n");
		}
		else if(hold1!=5)
		{
			printf("1\n");
		}
		else if(hold2!=7)
		{
			printf("2\n");
		}
		else if(hold3!=5)
		{
			printf("3\n");
		}
	}

	return 0;
}

/*

aaa aa a a a/ abe a e y u o / i i i i

3

*/