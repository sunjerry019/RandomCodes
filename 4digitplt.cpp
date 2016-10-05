#include <iostream>

using namespace std;

int main()
{
	int count = 0;
	for(int x=1000;x<=9999;x++)
	{
		int num = x, prevDigit = -1;
		for(int i=0;i<4;i++)
		{
			if(num % 10 == prevDigit)
			{
				count++;
				break;
			}
			prevDigit = num % 10;
			num /= 10;
		}
	}
	cout << count << endl;
	return 0;
}
