#include<stdio.h>
int main()
{
	float p = 0;
	float lens[300];
	int max = 1;
	lens[1] = 1.0 / 2.0;
	scanf("%e", &p);
	while (p>1.0e-10)
	{
		int i = 1;
		while (lens[i]<p)
		{
			i++;
			if (i > max)
			{
				lens[max + 1] = lens[max] + 1.0 / (max + 2);
				max++;
			}
		}
		printf("%d card(s)\n", i);
		scanf("%f", &p);
	}
	return 0;
}