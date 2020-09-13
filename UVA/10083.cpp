#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000

int equal(char *in1, char *in2)
{
	long i, len1, len2, count;

	len1=strlen(in1);
	len2=strlen(in2);

	if(len1!=len2)
		return 0;

	count=0;
	for(i=0; i<len1; i++)
	{
		if(in1[i]==in2[i])
			count++;
		else
			break;
	}
	if(count==len1)
		return 1;
	else
		return 0;
}

/***********************************************************************************************/

void reverse(char *from,char *to)
{
	long len,l;
	len=strlen(from);
	for(l=0;l<len;l++)
		to[l]=from[len-l-1];
	to[len]='\0';
}

/***********************************************************************************************/

void call_mult(char *first,char *sec,char *result)
{
	char F[MAX],S[MAX],temp[MAX];
	long f_len,s_len,f,s,r,t_len,hold,res;
	f_len=strlen(first);
	s_len=strlen(sec);
	reverse(first,F);
	reverse(sec,S);
	t_len=f_len+s_len;
	r=-1;
	for(f=0;f<=t_len;f++)
		temp[f]='0';
	temp[f]='\0';
	for(s=0;s<s_len;s++)
	{
		hold=0;
		for(f=0;f<f_len;f++)
		{
			res=(F[f]-'0')*(S[s]-'0')+hold+(temp[f+s]-'0');
			temp[f+s]=res%10+'0';
			hold=res/10;
			if(f+s>r)
				r=f+s;
		}
		
		while(hold!=0)
		{
			res=hold+(temp[f+s]-'0');
			temp[f+s]=res%10+'0';
			hold=res/10;
			if(f+s>r)
				r=f+s;
			f++;
		}
	}
	for(r=r+1;r>0 && (temp[r]=='0' && temp[r-1]!='0');r--)
		temp[r]='\0';
	reverse(temp,result);
}
/***********************************************************************************************/
void call_minus(char *large, char *small, char *result)
{
   char L[MAX], S[MAX];
   int l,s,now,hold,diff;
  
   l=strlen(large);
   s=strlen(small);
   
   bool sign = 0;
   
   if(l<s)
   {
	 strcpy(result,large);
	 strcpy(large,small);
	 strcpy(small,result);
	 now=l; 
	 l=s; 
	 s=now;
	 sign = 1;
   } //return 0;

   if(l==s)
   {
	 if(strcmp(large, small)<0)
	 {
		strcpy(result,large);
		strcpy(large,small);
		strcpy(small,result);

		now=l; 
		l=s; 
		s=now;
		sign =1;
	 }
   }

   reverse(large,L);
   reverse(small,S);

   for(;s<l;s++)
	 S[s]='0';
	 S[s]='\0';
   for(now=0,hold=0;now<l;now++)
   {
	  diff=L[now]-(S[now]+hold);
	  if(diff<0)
	  {
	     hold=1;
		 result[now]=10+diff+'0';
	  }
	  else
	  {
		 result[now]=diff+'0';
	     hold=0;
	  }
   }

   for(now=l-1;now>0;now--)
   {
	  if(result[now]!='0')
	     break;
   }
   result[now+1]='\0';
	
   reverse(result,L);
   strcpy(result,L);
}

void call_div(char *dividen,char*divisor,char *result)
{
    char sign[]="/";
    char temp[MAX]={0},temp2[MAX]={0},re[MAX]={0};
    long int n,past,i,tl,p,m,hate,l,j,a;

        n=strlen(divisor);
        past=strlen(dividen);

        for(i=0;i<n;i++)
        {
             temp[i]='0';
        }
        temp[n]=dividen[0];
        tl=1;a=0;
        
        do{
            m=0;
            do
            { 
                m++; 
                temp2[0]='0';
                hate=0; l=0;
                for(i=n-1;i>=0;i--)
                {
                    j=(divisor[i]-48)*m+hate;;
                    temp2[i+1]=j%10+48;
                    hate=j/10;
                }
                if(hate>0)
                    temp2[0]=hate+48;

                for(i=0;i<=n;i++)
                {
                    if(temp[i]<temp2[i])
                    {
                        l=2;break; 
                    }
                    if(temp[i]>temp2[i])
                    {
                        l=0;break;
                    }
                }

            }while(l!=2);
            l=m-1;
        
            do{
                re[a]=l%10+48;
                l=l/10; }while(l<0);
                a++;m=m-1;
                temp2[0]='0';hate=0;
                for(i=n-1;i>=0;i--)
                {
                    j=(divisor[i]-48)*m+hate;;
                    temp2[i+1]=j%10+48;
                    hate=j/10;
                }
                if(hate>0)
                    temp2[0]=hate+48;
                hate=0;
                for(i=n;i>=0;i--)
                {
                    p=temp2[i]-48;
                    j=(temp[i]-48)-p-hate;
                    hate=0;
                    if(j<0)
                    {
                        j=j+10;hate=1;      
                    }
                    temp[i]=j%10+48;
                }

               if(tl<past)
               {
                    for(i=0;i<n;i++)
                        temp[i]=temp[i+1];
                   temp[n]=dividen[tl];
                    tl++;
               }
                else
                    break;  
            }while(1);

            if(sign[0]=='/')
            {
                j=a-1;
                for(i=0;i<a-1;i++)
                    if(re[i]!='0')
                    {
                        j=i;
                        break;
                    }
                for(i=j;i<a;i++)
                {
                    result[i-j] = re[i];
                }
                result[i-j] = '\0';
            }
            
}

void call_mod(char *dividen,char*divisor,char *result)
{
    char temp[MAX]={0},temp2[MAX]={0},re[MAX]={0};
    long int n,past,i,tl,p,m,hate,l,j,a;

    n=strlen(divisor);
    past=strlen(dividen);

    for(i=0;i<n;i++)
    {
         temp[i]='0';
    
    }
    temp[n]=dividen[0];
    tl=1;a=0;

    do{
        m=0;
        do
        { 
            m++; 
            temp2[0]='0';
            hate=0; l=0;
            for(i=n-1;i>=0;i--)
            {
                j=(divisor[i]-48)*m+hate;;
                temp2[i+1]=j%10+48;
                hate=j/10;
            }
            if(hate>0)
                temp2[0]=hate+48;

            for(i=0;i<=n;i++)
            {
                if(temp[i]<temp2[i])
                {
                    l=2;
                    break; 
                }
                if(temp[i]>temp2[i])
                {
                    l=0;
                    break;
                }
            }

        }while(l!=2);
        l=m-1;
        
        do{
            re[a]=l%10+48;
            l=l/10; 
        }while(l<0);
        
            a++;m=m-1;
            temp2[0]='0';hate=0;
            for(i=n-1;i>=0;i--)
            {
                j=(divisor[i]-48)*m+hate;;
                temp2[i+1]=j%10+48;
                hate=j/10;
            }
            if(hate>0)
                temp2[0]=hate+48;
            hate=0;
            for(i=n;i>=0;i--)
            {
                p=temp2[i]-48;
                j=(temp[i]-48)-p-hate;
                hate=0;
                if(j<0)
                {
                    j=j+10;hate=1;      
                }
                temp[i]=j%10+48;
            }

           if(tl<past)
           {
                for(i=0;i<n;i++)
                    temp[i]=temp[i+1];
                temp[n]=dividen[tl];
                tl++;
           }
            else
                break;  
    }while(1);

    j=n;
    for(i=0;i<=n-1;i++)
        if(temp[i]!='0')
        {
            j=i;
            break;
        }
    for(i=j;i<=n;i++)
    {
        result[i-j] = temp[i];
    }
    result[i-j] = '\0';
            
}

int main()
{
	long lena,lenb,kk,l,m,exp,exp1,len_res;
	long tt, a, b, nDigit;
	double temp;
	char t[MAX],fir[MAX],sec[MAX],res1[MAX],res2[MAX], store1[MAX], store2[MAX], div_out[MAX], mod_out[MAX];
	
	while(scanf("%s%s%s",t,fir,sec)==3)
	{
		exp=0;
		exp1=0;
					
		sscanf(t, "%ld", &tt);
		sscanf(fir, "%ld", &a);
		sscanf(sec, "%ld", &b);

		if(tt > 1 && a && b)
		{
			if(a%b)
			{
				printf("(%ld^%ld-1)/(%ld^%ld-1) ",tt,a,tt,b);
				puts("is not an integer with less than 100 digits.");
				continue;
			}
			else if(a==b)
			       printf("(%ld^%ld-1)/(%ld^%ld-1) 1\n",tt,a,tt,b);
			else
			{
				temp    = (double)(a-b)*log10(tt);
				nDigit  = (long)temp;
				nDigit ++;
				if(nDigit >= 100)
				{
					printf("(%ld^%ld-1)/(%ld^%ld-1) ",tt,a,tt,b);
					puts("is not an integer with less than 100 digits.");
					continue;
				}
				else
				{
					m=strlen(fir);							
					l=strlen(sec);
					
					for(kk=0;kk<m;kk++)
						exp=exp*10+(fir[kk]-48);
					
					for(kk=0;kk<l;kk++)
						exp1=exp1*10+(sec[kk]-48);
					strcpy(res1,t);
					strcpy(res2,t);

					for(kk=0;kk<exp-1;kk++)
					{
						call_mult(t,res1,res1);
					}
					lena=strlen(res1);
					res1[lena]='\0';

					for(kk=0;kk<exp1-1;kk++)
					{
						call_mult(t,res2,res2);
					}
					lenb=strlen(res2);
					res2[lena]='\0';
									
					call_minus(res1,"1",store1);
					call_minus(res2,"1",store2);

					call_div(store1,store2,div_out);    //////////////// how to divide?????
					call_mod(store1,store2,mod_out);
					
					len_res=strlen(div_out);

					if(len_res<100 && (equal(mod_out, "0")==1) )		
					{
						printf("(%s^%s-1)/(%s^%s-1) ", t, fir, t, sec);
						printf("%s", div_out);
					}
					else
					{
						printf("(%s^%s-1)/(%s^%s-1) ", t, fir, t, sec);
						printf("is not an integer with less than 100 digits.");
					}
					printf("\n");
				}
			}
		}
		else if(tt == 1 || b==0)
		{
			printf("(%ld^%ld-1)/(%ld^%ld-1) ",tt,a,tt,b);
			puts("is not an integer with less than 100 digits.");
		}
		else
			printf("(%ld^%ld-1)/(%ld^%ld-1) 0\n",tt,a,tt,b);
	}
	return 0;
}