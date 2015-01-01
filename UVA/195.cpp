#include <stdio.h>
#include <string.h>
#define MAX 200

long hold[200];

void sort(char *v, int n)
{
	int gap,i,j;
	char temp;

	for(gap=n/2; gap ;gap /=2)
		for(i=gap; i<n ;i++)
			for(j=i-gap;hold[v[j]]>hold[v[j+gap]] && j>=0;j-=gap)
			{
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
	return ;
}

int main()
{
	char s[200], t;
	int i,j,len,pos,testCase,dataSet;

	for(i=0, j=0; i<=26; i++)
	{
		hold[i+'A']=j++;
		hold[i+'a']=j++;
	}

	j=0;
	scanf("%d",&dataSet);
	for(testCase=0;testCase<dataSet;testCase++)
	{
		scanf("%s",s);
		len = strlen(s);
		sort(s,len);
		
		while(1)
		{
			puts(s);
			for(i=len-1;i>0;i--)
				if(hold[s[i]] > hold[s[i-1]])
					break;
			if(!i)
				break;
			else
			{
				pos = i-1;
				while(hold[s[i]] > hold[s[pos]])
					i++;

				t = s[pos];
				s[pos] = s[i-1];
				s[i-1] = t;

				for(i=pos+1,j=len-1;i<j;i++,j--)
				{
					t = s[i];
					s[i] = s[j];
					s[j] = t;
				}
			}
		}
	}
	return 0;
}