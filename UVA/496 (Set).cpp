#pragma warning (disable : 4786)
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

#define MAX 200
char str[MAX];

int main () 
{
   while(gets(str))
   {
	   if(strcmp(str, "")==0)
		   break;

	   set<int>A, B;
	   
	   char *p = strtok(str, " ");
	   while(p != NULL)
	   {
		   int a = atoi(p);
		   A.insert(a);
		   p=strtok(NULL, " ");
	   }

	   int cnt = 0;

	   gets(str);
	   p = strtok(str, " ");
	   while(p != NULL)
	   {
		   int a = atoi(p);
		   B.insert(a);
		   int t = 0;
		   
		   t = A.count(a);
		   if(t != 0)
			   cnt++;

		   p=strtok(NULL, " ");
	   }
	   if(cnt == A.size() && cnt == B.size())
		   printf("A equals B\n");
	   else if(cnt == 0)
		   printf("A and B are disjoint\n");
	   else if(cnt == A.size())
		   printf("A is a proper subset of B\n");
	   else if(cnt == B.size())
		   printf("B is a proper subset of A\n");
	   else	   
		   printf("I'm confused!\n");
   }
 
   return 0;
}