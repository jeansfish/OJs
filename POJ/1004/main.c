#include <stdio.h>
int main()
{
	float total=0.0;
	float balance;
	float avg;
	int i;
	for (i = 0; i < 12; i++)
	{
		scanf("%f", &balance);
		total += balance;
	}
	avg = total / 12 * 100 + 0.5;
	printf("$%.2f", total/12);
	return 0;
}