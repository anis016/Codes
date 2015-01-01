#include<stdio.h>
#include<string.h>
#define MAX 100000

char in[MAX], iin[MAX], alp[MAX];

int main()
{
	alp['A']='A',alp['E']='3',alp['H']='H',alp['I']='I',alp['J']='L',alp['L']='J',alp['M']='M',alp['O']='O';
	alp['S']='2',alp['T']='T',alp['U']='U',alp['V']='V',alp['W']='W',alp['X']='X',alp['Y']='Y',alp['Z']='5';
	alp['1']='1',alp['2']='S',alp['3']='E',alp['5']='Z',alp['8']='8';

	
	long len, i, j, mid, mid1, mid2, count,flagm, flagp,flagn, t, p;

	while(gets(in))
	{
		len=strlen(in);

		mid=mid2=mid1=count=flagm=flagp=flagn=t=p=0;
		
		i=j=0;
		if(len%2==0)
		{
			mid1=(len/2)-1;
			mid2=mid1+1;

			for(i=mid1, j=mid2; i>=0 ; i--, j++)
			{
				t=p=0;
				if(in[i]==in[j])
				{
					flagp++;
					t=1;
				}
				if(alp[in[i]]==in[j])
				{
					flagm++;
					p=1;
				}
				if(t==0 && p==0)
					flagn=1;

				count++;

			}
		}

		i=j=0;
		if(len%2==1)
		{
			mid=(len/2);

			for(i=mid, j=mid; i>=0 ; i--, j++)
			{
				t=p=0;
				if(in[i]==in[j])
				{
					flagp++;
					t=1;
				}
				if(alp[in[i]]==in[j])
				{
					flagm++;
					p=1;
				}
				if(t==0 && p==0)
					flagn=1;

				count++;
			}
		}

		if(flagp==count && flagm==count)
			printf("%s -- is a mirrored palindrome.\n\n",in);
		
		else if(flagp!=count && flagm==count)
			printf("%s -- is a mirrored string.\n\n", in);
		
		else if(flagp==count && flagm!=count)
			printf("%s -- is a regular palindrome.\n\n", in);
		
		else if(flagn==1)
			printf("%s -- is not a palindrome.\n\n", in);
		
	}
	return 0;
}