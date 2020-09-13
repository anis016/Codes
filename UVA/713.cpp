#include<stdio.h>
#include<string.h>

int main()
{
	char str_1[100000], str_2[100000], result[100000],n[1000];
	long i, x, len_1, len_2, diff,carry,ll,c,m,z,zz,t,nn,bb, lena, lenb;
	
    gets(n);
	sscanf(n,"%ld",&nn);
	
	for(bb=0;bb<nn;bb++)
	{
	    scanf("%s %s", str_1, str_2);
		 
		 lena=strlen(str_1);
		 lenb=strlen(str_2);
		 
        z=0;
		for(t=lena-1;t>=0;t--)
		{		
			if(str_1[t]=='0'&&z==0)
				continue;
			else
			{ 
				str_1[t+1]='\0';
				break;
			}
		}
		
		zz=0;
		for(t=lenb-1;t>=0;t--)
		{
		
			if(str_2[t]=='0'&&zz==0)
				continue;
			else
			{ 
				str_2[t+1]='\0';
			    break;
			}
		
		}
		
		len_1=strlen(str_1);
		len_2=strlen(str_2);
		
			 if(len_1>len_2)
			 {
				 x = len_1;
				 diff = len_1-len_2;
				 for(i=0;i<diff;i++)
					 str_2[len_2+i]='0';
			 }
		     else
			 {
				 x = len_2;
				 diff = len_2-len_1;
				 for(i=0;i<diff;i++)
					 str_1[len_1+i]='0';
			 }
             
             carry=0;
   		     for(i=0;i<x;i++)
			 {
				 carry = carry+str_1[i]-48+str_2[i]-48;
				 result[i] = carry%10+48;
			     carry = carry/10;
			 }
			 
             while(carry!=0)
			 {
			    result[x] = carry%10+48;
			    carry = carry/10;
			    x++;
			 }
			 result[x]='\0';
			 
             ll=strlen(result);
			 
             c=0;
			 for(m=0;m<ll;m++)        ////omotting leading zero's.
			 {
				 if(result[m]=='0'&&c==0)
					 continue;
				 else
				 {
				    printf("%c",result[m]);
				    c=1; 
				 }
			 }			 
		     printf("\n");
       }
	return 0;
}
