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

#define eps 1e-8
#define pinf (1<<30)
#define ninf -1*pinf
#define pi (2*acos(0.0))
//typedef long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true; return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

long vertex, edge;
long source, sink;    // mention it or initialize it.

struct node
{
	long next, weight;
	node() {};
	node(long n, long w) : next(n), weight(w) {};
};

bool operator < (node a, node b)
{
	return a.weight > b.weight;
}

long dijkstra(vector< vector < pair<long, long> > > &G)
{	
	long next, len;

	vector<long>dist(vertex + 2, pinf);
	dist[source] = 0;

	priority_queue< node >pq;   // node no. , weight
	pq.push(node(source, 0));
	while(!pq.empty())
	{
		long V = pq.top().next;
		long current_distance = pq.top().weight;
		pq.pop();

		if(current_distance > dist[V])
			continue;

		for(size_t i = 0; i < G[V].size(); i++)
		{
			next = G[V][i].first;
			len = G[V][i].second;

			long dv = dist[V]; long dn = dist[next];
			if( (dv + len) < dn)
			{
				dist[next] = dist[V] + len;
				pq.push(node(next, dist[next]));
			}
		}
	}

	return dist.at(sink);
}

int main () 
{
	long x, y, weight, ii, test;

	ii = 1;
	scanf("%ld", &test);
	while(ii <= test)
	{
		scanf("%ld %ld %ld %ld", &vertex, &edge, &source, &sink);
		if(source > sink)
			swap(source, sink);
		
		vector< vector < pair<long, long> > > g(vertex + 2);
		if(edge == 0 || (source == sink) )
		{
			printf("Case #%ld: unreachable\n", ii++);
			continue;
		}

		while(edge--)
		{
			scanf("%ld %ld %ld", &x, &y, &weight);

			g[x].push_back(make_pair(y, weight));
			g[y].push_back(make_pair(x, weight));
		}
		long distance = dijkstra(g);
		if(distance == pinf )
			printf("Case #%ld: unreachable\n", ii++);
		else
			printf("Case #%ld: %ld\n", ii++, distance);
	}
	return 0;
}
