#include<stdio.h>
#include<string.h>
#include<math.h>
#define pi 2*acos(0.0)

int main()
{
	int N, i, Case;
	char str[10];
	int value;
	double x, y, theta;

	scanf("%d", &Case);
	while(Case--)
	{
		theta = x = y = 0.0000;
		scanf("%d", &N);
		for(i = 0; i < N; i++)
		{
			scanf("%s %d", str, &value);
			
			if(strcmp(str, "fd")==0)
			{
				x += value * cos( (theta * pi) / 180);
				y += value * sin( (theta * pi) / 180);
			}
			else if(strcmp(str, "lt")==0)
			{
				theta += value;
				theta = fmod(theta, 360);
			}
			else if(strcmp(str, "rt")==0)
			{
				theta -= value;
				theta = fmod(theta, 360);
			}
			else
			{
				x -= value * cos( (theta * pi) / 180);
				y -= value * sin( (theta * pi) / 180);
			}		
		}
		printf("%0.0lf\n", sqrt(x * x + y * y) );
	}
	return 0;
}