#define _CRT_SECURE_NO_WARNINGS
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

typedef pair<int, int>p;

#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

#define MAX 200

char UD[2][MAX];
char Code[MAX];

int Decimal(char Temp[]) 
{
     int i, k, p = 1;
	 double Sum = Temp[4] - '0';
	 for(i = 3; i>= 0; i--)
	 { 
		 k = Temp[i] - '0';
	     Sum += k * pow(2.0,(double)p);
		 p ++;
	 }
	 return (int)Sum;
}

void SolvedCase() 
{
     int F = 0;
	 int i, j, k,D;
	 char Temp[10];
	 for(i = 0; Code[i];i+= 5 ) 
	 {
		 k = 0;
		 for(j = i; j <i+5;j++)
            Temp[k++] = Code[j];
         Temp[k] = '\0';      
		 D = Decimal(Temp);
			if(D == 27)
				F = 0;
			else if(D == 31)
				F = 1;
			else printf("%c",UD[F][D]);
	 }
	 return ;
}

int main() 
{
	gets(UD[0]);
	gets(UD[1]);
	while(gets(Code)) 
	{
		SolvedCase();
		printf("\n");
	}
	return 0;
}