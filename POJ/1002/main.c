#include <stdio.h>
#include <stdlib.h>
int maps [] = { 2, 2, 2,  //A,B,C
				3,3,3,    //D,E,F
				4,4,4,    //G,H,I
				5,5,5,    //J,K,L
				6,6,6,    //M,N,O
				7,7,7,7,  //P,Q,R,S
				8,8,8,	  //T,U,V
				9,9,9,9   //W,X,Y,Z
				};
int IsNum(char c)
{
	return c >= '0' && c <= '9';
}
int IsCharacter(char c)
{
	return c >= 'A' && c <= 'Z';
}
int Format(char* num)
{
	int i = 0;
	int f=1000000;
	char c;
	int result = 0;
	while ((c=*(num+i))!='\0')
	{
		if (IsNum(c))
		{
			result += f*(c - '0');
			f /= 10;
		}
		if (IsCharacter(c))
		{
			result += f*(maps[c - 'A']);
			f /= 10;
		}
		i++;
	}
	return result;
}
void QSort(int* array,int n,int l,int r)
{

	int i = l, j = r;
	int key = *(array + i);
	int iKey = i;
	if (l >= r)
		return;
	while (i<j)
	{
		while (j > i && *(array + j) >= key)
			j--;
		*(array + iKey) = *(array + j);
		*(array + j) = key;
		iKey = j;
		while (j > i && *(array + i) <= key)
			i++;
		*(array + iKey) = *(array + i);
		*(array + i) = key;
		iKey = i;
	}
	QSort(array, n, l, iKey - 1);
	QSort(array, n, iKey + 1, r);
}
char *Print(int num)
{
	int i = 3;
	char str[9];
	sprintf(str, "%07d", num);
	
	for (i = 6; i >=3; i--)
	{
		str[i + 1] = str[i];
	}
	str[8] = '\0';
	str[3] = '-';
	printf("%s", str);
	return str;
}
int cmp(const void *a, const void *b)
{
	return *(int *) a - *(int*) b;
}
int main()
{
	int n;
	int i;
	int* nums;
	int t = -1, count=0, emtpy = 1;
	scanf("%d", &n);
	nums = (int*) malloc(sizeof(int) *n);
	for (i = 0; i < n; i++)
	{
		char num[100];
		scanf("%s", num);
		*(nums + i) = Format(num);
	}
	//QSort(nums, n,0,n-1);
	qsort(nums, n, sizeof(int) , cmp);
	for (i = 0; i < n; i++)
	{
		if (t != *(nums + i))
		{
			if (count > 1)
			{
				emtpy = 0;
				Print(t);
				printf(" %d\n", count);
			}
			t = *(nums + i);
			count = 1;
		}
		else
		{
			count++;
		}
	}
	if (count > 1)
	{
		emtpy = 0;
		Print(t);
		printf(" %d\n", count);
	}
	if (emtpy)
		printf("No duplicates.");
	return 0;
}