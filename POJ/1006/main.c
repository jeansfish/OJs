#include<stdio.h>
int GetStart(int delta, int p)
{
	int i = delta / p;
	delta =delta- i*p;
	//if (delta > 0)
	//	delta -= p;
	return delta;
}
int main()
{
	int p, e, i, d;
	int pp = 23, ep = 28, ip = 33;
	int n = 1;
	scanf("%d %d %d %d", &p, &e, &i, &d);
	while (p!=-1&&e!=-1&&i!=-1&&d!=-1)
	{
		int total;
		p = GetStart(p, pp);
		e = GetStart(e, ep);
		i = GetStart(i, ip);
		total = pp;
		while (!((total - e +p)%ep == 0 && (total - i + p)%ip == 0))
		{
			total += pp;
		}
		total = total + p - d;
		if (total > 21252)
			total %= 21252;
		if (total <= 0)
			total += 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",n, total);
		scanf("%d %d %d %d", &p, &e, &i, &d);
		n++;
	}
	return 0;
}