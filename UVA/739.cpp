#pragma warning (disable : 4789)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<ctime>
#include<stack>
using namespace std;

#define eps 1e-8
#define pinf (1<<30)
#define ninf -1*pinf
#define pi (2*acos(0.0))
//typedef long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)

#define MAX 50
char str[MAX];
char Temp[2*MAX];

void init()
{
	Temp['B'] = Temp['P'] = Temp['F'] = Temp['V'] = '1';
	Temp['C'] = Temp['S'] = Temp['K'] = Temp['G'] = Temp['J'] = Temp['Q'] = Temp['X'] = Temp['Z'] = '2';
	Temp['D'] = Temp['T'] = '3';
	Temp['L'] = '4';
	Temp['M'] = Temp['N'] = '5';
	Temp['R'] = '6';

	Temp['A'] = Temp['E'] = Temp['I'] = Temp['O'] = Temp['U'] = Temp['Y'] = Temp['W'] = Temp['H'] = '0';

	return ;
}

char out[10];

int main () 
{
	int len, i;

//	Fin;

	init();

    printf ("         NAME                     SOUNDEX CODE\n");
    while(gets(str))
	{
		len = strlen(str);
		memset(out, '\0', sizeof(out));

		out[0] = str[0];
		int j = 1;
		for(i = 1; j <= 3 && i < len; i++)
		{
			if(Temp[str[i]] == Temp[str[i-1]])
				continue;
			else
			{
				if(Temp[str[i]] != '0')
				{
					out[j] = Temp[str[i]];
					j++;
				}
			}
		}
		out[j] = '\0';
		len = strlen(out);
	
		if(len <= 3)
		{
			for(i = j; i <= 3; i++)
				out[i] = '0';
			out[i] = '\0';
		}

		printf ("%9s%s", "", str);
	    for(i = 0; i < 25 - strlen(str); i++ )
			printf (" ");
		printf("%s\n", out);
	}

	printf ("                   END OF OUTPUT\n");

	return 0;
}
