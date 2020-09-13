#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int h[] = { 1,1,-1,-1,2,2,-2,-2 };
int v[] = { 2,-2,2,-2,1,-1,1,-1 };

typedef pair<int, int>ii;
typedef pair<ii, int>st;
queue<st>Q;

int VALUE[150], fr, fc, mat[9][9];
void generate()
{
	int i, j = 1;

	for(i='a'; i<='h'; i++)
		VALUE[i] = j++;
	return ;
}

int BFS(int r, int c)
{
	int i, cnt;

	Q = std::queue<st>();
	Q.push(st(ii(r, c), 0));
	while(!Q.empty())
	{
		st T = Q.front();
		
		r = T.first.first;
		c = T.first.second;
		cnt = T.second;
		
		Q.pop();

		if(r == fr && c == fc)
			break;

		for(i=0; i<8; i++)
		{
			int nr = r + h[i];
			int nc = c + v[i];

			if(nr > 0 && nr <= 8 && nc > 0 && nc <= 8 )
			{
				if(mat[nr][nc] <= cnt)
					continue;

				Q.push(st(ii(nr, nc), cnt + 1));
				mat[nr][nc] = cnt + 1;
			}			
		}
	}

	return mat[fr][fc];
}

void init()
{
	int i, j;

	for(i=0;i<=8;i++)
		for(j=0;j<=8;j++)
			mat[i][j] = 65;

	return ;
}

int main()
{
	char PP[10], QQ[10];
	int len;

	generate();
	int ir, ic;

    while(cin>>PP>>QQ)
	{
		init();

		ir = PP[1] - '0';
		ic = VALUE[PP[0]];

		fr = QQ[1] - '0';
		fc = VALUE[QQ[0]];
		
		
		len = BFS(ir, ic);

		if(len == 65)
			len = 0;

		printf("To get from %s to %s takes %ld knight moves.\n", PP, QQ, len);
	}
	return 0;
}

