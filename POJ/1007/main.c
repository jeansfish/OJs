#include <stdio.h>
#include <stdlib.h>
typedef struct Unsortedness
{
	char* DNA;
	int l;
} Pair;
Pair CalcUnsortedness(char * dna, int n)
{
	int i, j;
	int unsortedness = 0;
	Pair p;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (*(dna + i) > *(dna + j))
				unsortedness++;
		}
	}
	p.DNA = dna;
	p.l = unsortedness;
	return p;
}
int GetKey(Pair a)
{
	return a.l;
}
int cmp(const void* a, const void* b)
{
	return GetKey(*(Pair*) a) - GetKey(*(Pair*) b);
}
void sort(Pair* array, int m)
{
	int i, j;
	for (i = m - 1 - 1; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			int a, b;
			a = GetKey(*(array + j));
			b = GetKey(*(array + j + 1));
			if (a > b)
			{
				Pair t = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = t;
			}
		}
	}
}
int main()
{
	int m, n;
	Pair* a;
	int i;
	scanf("%d %d", &n, &m);
	a = (Pair*) malloc(sizeof(Pair) *m);
	for (i = 0; i < m; i++)
	{
		char *t = (char*) malloc(sizeof(char) *(n + 1));
		scanf("%s", t);
		*(a + i) = CalcUnsortedness(t, n);
		//printf("%s %d\n", a + nn*i, *(a + nn*(i + 1) - 1));
	}
	//qsort(a, m, sizeof(Pair), cmp);
	sort(a, m);
	for (i = 0; i < m; i++)
	{
		printf("%s\n", (*(a + i)).DNA);
	}
	return 0;
}