#include <stdio.h>
void show(short int x);

int main(void)
{
	short int number;
	scanf("%hi", &number);
	show(number);
	return 0;
}

void show(short int x)
{
	short int i, begin = 0;
	if (!x)
	{
		putchar('0');
	}
	else if (x == 2)
	{
		putchar('2');
	}
	else
	{
		for (i = 14; i >= 0; i--)
		{
			if (x >> i & 1)
			{
				if (begin)
				{
					putchar('+');
				}
				else
				{
					begin++;
				}
				if (i == 1)
				{
					putchar('2');
					continue;
				}
				putchar('2');
				putchar('(');
				show(i);
				putchar(')');
			}
		}
	}
}
