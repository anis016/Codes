#include<stdio.h>

#define MIN(a, b) a <= b ? a : b
#define MAX(a, b) a >= b ? a : b

int main()
{
	long N, Case, cnt = 1;
	long fx1, fx2, fy1, fy2, sx1, sx2, sy1, sy2, tx1, tx2, ty1, ty2;;
	long AX, BX, AY, BY;

	scanf("%ld", &Case);

	while(Case--)
	{
		scanf("%ld", &N);
		AX = BX = AY = BY = 0;

		if(N == 1)
		{
			scanf("%ld %ld %ld %ld", &fx1, &fy1, &fx2, &fy2);

			BX = (fx2 - fx1);
			BY = (fy2 - fy1);

			if(AX >= BX || AY >= BY)
				printf("Case %ld: 0\n", cnt++);
			else
				printf("Case %ld: %ld\n", cnt++, BX * BY);
		}

		else
		{
			for(long i = 0; i < N; )
			{
				scanf("%ld %ld %ld %ld", &fx1, &fy1, &fx2, &fy2);
				scanf("%ld %ld %ld %ld", &sx1, &sy1, &sx2, &sy2);
				
				i = 2;

				AX = MAX(fx1, sx1);
				BX = MIN(fx2, sx2);

				AY = MAX(fy1, sy1);
				BY = MIN(fy2, sy2);

				while(i < N)
				{
					scanf("%ld %ld %ld %ld", &tx1, &ty1, &tx2, &ty2);
					
					AX = MAX(tx1, AX);  // AX AY BX BY
					BX = MIN(tx2, BX);

					AY = MAX(ty1, AY);
					BY = MIN(ty2, BY);

					i++;
				}
			}

			if(AX >= BX || AY >=BY)
				printf("Case %ld: 0\n", cnt++);		
			else
				printf("Case %ld: %ld\n", cnt++, (AX - BX) * (AY-BY) );
		}
	}

	return 0;
}

