#include<stdio.h>
#include<math.h>
int main()
{
	int N, i;
	float Rs[1000];
	int max = 0;
	Rs[0] = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		float X, Y, D;
		int n = 0;
		scanf("%f %f", &X, &Y);
		D = sqrtf(X*X + Y*Y);
		while (D>Rs[n])
		{
			n++;
			if (n > max)
			{
				max++;
				Rs[max] = sqrtf(50 * max * 2 / 3.141592653);
				
			}
		}
		printf("Property %d: This property will begin eroding in year %d.\n", i, n);
	}
	printf("END OF OUTPUT.");
	return 0;
}