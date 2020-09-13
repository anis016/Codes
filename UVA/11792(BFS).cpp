#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define MAX 10001
#define MAXIMUM  1<<21
 
int counter[MAX],  move[MAX];
vector<int>V[MAX];
int line, station;

void init()
{
	int i;
	for(i = 0; i <= station; i++)
	{
		counter[i] = 0;
		V[i].clear();
	}

	return ;
}

void init_move()
{
	int i;

	for(i = 0; i <= station; i++)
		move[i] = MAXIMUM;
	return ;
}

typedef pair<int, int>ii;

int BFS(int pos)
{
	init_move();

	int i;
	queue<ii>Q;

	Q.push( ii(pos, 0) );
	while(!Q.empty())
	{
		ii t = Q.front();
		int state = t.first;
		int cost = t.second;

		Q.pop();

		if(move[state] != MAXIMUM)
			continue;
		
		move[state] = cost;
		for(i = 0; i < V[state].size(); i++)
		{
			int k = V[state][i];
			Q.push(ii(k, cost + 2) );
		}
	}

	int sum = 0;
	for(i = 0; i < station; i++)
		if(counter[i] >= 2)
			sum += move[i];

	return sum;
}

void read_input()
{
	int i;
	for(i = 0; i < line; i++)
	{
		int x, y;
		scanf("%d", &y);
		y = y - 1;
		counter[y]++;

		while(scanf("%d", &x), x)
		{
			x = x - 1;
			V[x].push_back(y);
			V[y].push_back(x);

			counter[x]++;

			y = x;
		}		
	}
	return ;
}

int main()
{
	int i, Case;

	scanf("%d",  &Case);
	while(Case--)
	{
		scanf("%d %d", &station, &line);
			
		init();	
		read_input();
		
		int mas = MAXIMUM;
		int pos = MAXIMUM;
		for( i = 0; i < station; i++)
		{
			if(counter[i] >= 2)	
			{
				int dist = BFS(i);

				if(dist < mas)
				{
					mas = dist;				
					pos = i;			
				}
				
				else if(dist == mas)
				{
					if(i < pos)
						pos = i;
				}
			}
		}
		
		printf("Krochanska is in: %d\n", pos + 1);
	}
	return 0;
}
