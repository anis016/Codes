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
//typedef long long long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)

#define MAX 1000

typedef pair<long long, long long>ii;
map<char, ii>mat;

char str[MAX];
int N;

void input()
{
	int i;
	char s[MAX];

	gets(s);
	sscanf(s, "%lld", &N);

	for(i = 0; i < N; i++)
	{
		char a;
		long long row, col;

		gets(str);
		sscanf(str, "%c %lld %lld", &a, &row, &col);
		mat[a] = ii(row, col);
	}
	return ;
}



long long matrix_chain_multi(string ss)
{
	int i, j;

	int counter = 0;
	long long error = 0;
	deque<char>Q, F;

	for(i = 0; i < (long)ss.length(); i++)
	{
		if(ss.at(i) == ')')
		{
			ss.erase(i, 1);
			for(j = i-1; ss[j] != '('; j--)
			{
				Q.push_front(ss.at(j));
				ss.erase(j, 1);
			}
			ss.at(j) = 'a' + counter;
            
			for(int k = 0; k < (int)Q.size() ; )
			{
				ii f1, f2;
            
				char front1 = Q.front();
				Q.pop_front();
				f1 = mat[front1];
				k++;
            
				if(!Q.empty())
				{
					char front2 = Q.front();
					Q.pop_front();
					f2 = mat[front2];
					
					if(f1.second != f2.first)
						return -1;
			        else
				    {
					    error += f1.first * f1.second * f2.second;
					    mat['a' + counter] = ii(f1.first, f2.second);
					    F.push_front('a' + counter);
						counter++;
					    i = 0;
				    }
					k++;
				}
			}
		}
	}
	return error;
}

int main()
{
	//Fin;
	
	input();
	string ss;
	
	while(cin>>ss)
	{
		if(ss.length() == 1)
		{
			printf("0\n");
			continue;
		}
		long long res = matrix_chain_multi(ss);
		if(res == -1)
			printf("error\n");
		else
			printf("%lld\n", res);
	}
	return 0;
}
