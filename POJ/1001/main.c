#include<stdio.h>
#include<malloc.h>

int IsaNumber(char c)
{
	return c >= '0' && c <= '9';
}
void Reverse(char * R, int *length, int *p)
{
	int point = -2;
	char Stack[6];
	int i = 0;
	int len = 0;

	while (*(R + i) != '\0')
	{
		if (IsaNumber(*(R + i)))
		{
			if (*(R + i) == '0')
			{
				if (len > 0)
				{
					Stack[len] = *(R + i);
					len++;
				}
			}
			else
			{
				Stack[len] = *(R + i);
				len++;
			}
		}
		else if (*(R + i) == '.')
		{
			point = -1;
		}
		i++;
		if (point >= -1)
			point++;
	}
	for (i = len; i > 0; i--)
	{
		R[len - i] = Stack[i - 1];
	}
	*length = len;
	if (point == -2)
		point = 0;
	*p = point;
}

char* MUL1(char* r, int len, int n, int* newLen)
{
	int inc = 0, i;
	char* result = (char*) malloc(sizeof(char) *(len + 1));
	*newLen = len;

	for (i = 0; i < len; i++)
	{
		int t = (*(r + i) - '0')*n + inc;
		inc = t / 10;
		*(result + i) = t % 10 + '0';
	}
	if (inc > 0)
	{
		*(result + len) = inc + '0';
		*newLen = *newLen + 1;
	}
	else
	{
		*(result + len) = '\0';
	}
	//////free(r);
	return result;
}
char* MUL10(char* r, int len, int n, int* newLen)
{
	int i;
	char* result = (char*) malloc(sizeof(char) *(len + n));
	*newLen = len + n;
	for (i = 0; i < len; i++)
	{
		*(result + i + n) = *(r + i);
	}
	for (i = 0; i < n; i++)
		*(result + i) = '0';
	return result;
}
char* ADD(char* a, int lenA, char* b, int lenB, int* newLen)
{
	char *longer, *shorter;
	int shorterLen;
	char *r;
	int inc = 0;
	int i;
	if (lenA >= lenB)
	{
		longer = a;
		shorter = b;
		*newLen = lenA;
		shorterLen = lenB;
	}
	else
	{
		longer = b;
		shorter = a;
		*newLen = lenB;
		shorterLen = lenA;
	}
	r = (char*) malloc(sizeof(char) *(*newLen + 1));

	for (i = 0; i < *newLen; i++)
	{
		int x = *(longer + i) - '0';
		int y = 0;
		int t;
		if (shorterLen > i)
			y = *(shorter + i) - '0';
		t = x + y + inc;
		*(r + i) = t % 10 + '0';
		inc = t / 10;
	}
	if (inc > 0)
	{
		*(r + *newLen) = inc + '0';
		*newLen = *newLen + 1;
	}
	else
	{
		*(r + *newLen) = '\0';
	}
	return r;
}
char* POINT(char* a, int lenA, int p, int* newLen)
{
	char* r;
	int i;
	int step = 0;
	*newLen = lenA + 1;
	if (p > lenA)
		*newLen = p + 1;
	r = (char*) malloc(sizeof(char) * (*newLen));
	step = 0;
	for (i = 0; i < *newLen; i++)
	{
		if (p == 0)
		{
			*(r + i) = '.';
			step = 1;
		}
		else
		{
			if (i - step <= lenA - 1)
			{
				*(r + i) = *(a + i - step);
			}
			else
			{
				*(r + i) = '0';
			}
		}
		p--;
	}
	return r;
}
char* MUL(char * a, int lena, char *b, int lenb, int* newLen)
{
	int resultLen=0;
	char* result = NULL;
	int i;
	for (i = 0; i < lenb; i++)
	{
		int tLen;
		char* t = MUL1(a, lena, *(b + i) - '0', &tLen);
		t = MUL10(t, tLen, i, &tLen);
		result = ADD(result, resultLen, t, tLen, &resultLen);
	}
	*newLen = resultLen;
	return result;
}
char* FIX0(char *a, int lenA, int* newLen)
{
	int i;
	int f=0;
	int index1 = -1, index2 = lenA;
	char* r;
	for (i = 0; i < lenA; i++)
	{
		char c = *(a + i);
		if (!f && (c == '0' || c == '.'))
		{
			index1 = i;
			if (c == '.')
				break;
		}
		else
		{
			f = 1;
			break;
		}
	}
	f = 0;
	for (i = lenA - 1; i >= index1; i--)
	{
		char c = *(a + i);
		if (!f && (c == '0'))
		{
			index2 = i;
		}
		else
		{
			f = 1;
			break;
		}
	}
	*newLen = lenA - (index1 + 1) - (lenA- index2);
	if (*newLen == lenA)
	{
		return a;
	}
	r = (char*) malloc(sizeof(char) * *newLen);
	for (i = index1 + 1; i <= index2 - 1; i++)
	{
		*(r + i - index1 - 1) = *(a + i);
	}
	return r;
}
int main()
{
	char* R;
	int n;
	R = (char*) malloc(sizeof(char) * 6);
	
	while (scanf("%s%d", R, &n)!=EOF)
	{
		int length, p, i, rLen;
		char *result, *returnResult;
		Reverse(R, &length, &p);
		//printf("%s %d %d\n", R, length, p);
		result = R;
		rLen = length;
		for (i = 1; i < n; i++)
		{
			result = MUL(result, rLen, R, length, &rLen);
		}

		result = POINT(result, rLen, p*n, &rLen);
		result = FIX0(result, rLen, &rLen);
		//printf("%s %d\n", result, rLen);
		returnResult = (char*) malloc(sizeof(char) *(rLen + 1));
		for (i = 0; i < rLen; i++)
		{
			*(returnResult + i) = *(result + rLen - 1 - i);
		}
		*(returnResult + rLen) = '\0';
		printf("%s\n", returnResult);

		R = (char*) malloc(sizeof(char) * 6);
	}

	return 0;
}