#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 1010

long a[MAX+9];
long is_prime[MAX+10], save[MAX],out[MAX];
									//a[2]=0 FIXED
int fun_name(  const void *a, const void *b )
{
	long *p = (long *)a;  //Convert It your working type..(here int)
	long *q = (long *)b;  //Convert It your working type..(here int)

	
	return *p - *q ;   // 1st - 2nd if Increasing
}

int main()
{
	long i,j,k,M,in,m,t,l,kk,count1, count2, count,tt,inc,mm,f;
	
	M=sqrt(MAX);
	
	for(i=3;i<=M;i+=2)
		if(a[i]==0)
			for(j=i*i;j<=MAX;j=j+i+i)
				a[j]=1;

	for(k=3, t=2;k<=MAX;k=k+2)
		if(a[k]==0)
		{
			is_prime[t]=k;
			t++;
		}
	is_prime[0]=1, is_prime[1]=2;

   while(scanf("%ld %ld", &in, &m)==2)
   {
	   printf("%ld %ld: ",in,m);
	  
	   count=0;
	   for(i=0, kk=0; is_prime[i]<=in; i++)
		   if(is_prime[i])
			   save[kk]=is_prime[i], kk++;
  
   l=i=inc=count=count1=count2=mm=0;
   
   if(kk%2==0)            ////////// even ////////////
   {
	   tt=m*2;

	   if(tt>in)
	   {
		   mm=kk;
		   for(i=0; i<kk; i++)
		   {
			   printf("%ld", save[i]);
			   if((mm-1)!=0)           
			   {               
				   printf(" ");    
				   mm--;
			   }
           }
	   }

	   else
	   {
		   if(kk%2==1)
		   {
			   count=(kk/2)+1;
			   l=count;
			   
			   j=0;
			   while(1)
			   {
				   if(inc==tt)
					   break;
				   else
				   {
					   out[j]=save[count-1];
					   inc++;
					   count++;

				       j++;

				       if(inc==tt)
						   break;

				       l--;
					   out[j]=save[l-1];
					   j++;
					   inc++;
				   }
			   }
		   }


		   else if(kk%2==0)
		   {
			   l=(kk/2);
			   count2=(kk/2)+1;
		   
   			   j=0;
			   while(1)
			   {
				   if(inc==tt || inc==kk)
					   break;

				   else
				   {
					   out[j]=save[count2-1];
					   inc++;
					   count2++;
					   j++;

				       if(inc==tt || inc==kk)
						   break;

				       l--;
					   out[j]=save[l];
					   j++;
					   inc++;
				   }
			   }
		   }

         qsort(out, j, sizeof(long), fun_name );
   
         mm=j;
         for(i=0; i<j; i++)
		 {
			 printf("%ld", out[i]);
		     if((mm-1)!=0)
			 {
               printf(" ");
               mm--;
			 }
		 }
	   }
   }

   if(kk%2==1)            ////////// odd ////////////
   {
	   tt=m*2-1;

	   if(tt>in)
	   {
		   mm=kk;
		   for(i=0; i<kk; i++)
		   {
			   printf("%ld", save[i]);
			   if((mm-1)!=0)           
			   {               
				   printf(" ");    
				   mm--;
			   }
           }
	   }

	   else
	   {
		   if(kk%2==1)
		   {
			   count=(kk/2)+1;
			   l=count;
			   
			   j=0;
			   while(1)
			   {
				   if(inc==tt || inc==kk)
					   break;

				   else
				   {
					   out[j]=save[count-1];
					   inc++;
					   count++;

				       j++;

				       if(inc==tt || inc==kk)
						   break;


				       l--;
					   out[j]=save[l-1];
					   j++;
					   inc++;
				   }
			   }
		   }


		   else if(kk%2==0)
		   {
			   l=(kk/2);
			   count2=(kk/2)+1;
		   
   			   j=0;
			   while(1)
			   {
				    if(inc==tt || inc==kk)
					   break;

				   else
				   {
					   out[j]=save[count2-1];
					   inc++;
					   count2++;
					   j++;

				      if(inc==tt || inc==kk)
						  break;

				       l--;
					   out[j]=save[l];
					   j++;
					   inc++;
				   }
			   }
		   }

		   mm=0;
         qsort(out, j, sizeof(long), fun_name );
   
		 mm=j;
         for(i=0; i<j; i++)
		 {
			 printf("%ld", out[i]);
		     if((mm-1)!=0)
			 {
               printf(" ");
               mm--;
			 }
		 }
	   }
   }
   printf("\n");
   printf("\n");

   }
   return 0;
}
