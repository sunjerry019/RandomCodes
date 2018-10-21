/*
#include <fstream>
#include <vector>

using namespace std;

ifstream cin("in.txt");
ofstream cout("out.txt");
int n;
int currentLength = 0;
vector<int> arr;
vector<int> sorted;

void shift(int idx)
{
	for (int j = currentLength; j >= (idx + 1); j--)
	{
		sorted[j] = sorted[j - 1];
	}
}

int main()
{
	cin >> n;
	arr.resize(n, 0);
	sorted.resize(n, 0);

	for (int l = 0; l < n; l++)
	{
		cin >> arr[l];
	}

	for (int i = 0; i < n; i++)
	{
		if (!i)
		{
			sorted[0] = arr[i];
			currentLength = 1;
		}
		else
		{
			for (int k = 0; k < currentLength; k++)
			{
				if (sorted[k] >= arr[i])
				{
					shift(k);
					sorted[k] = arr[i];
					currentLength++;
					break;
				}
				else if (k == (currentLength - 1))
				{
					sorted[currentLength] = arr[i];
					currentLength++;
					break;
				}
			}
		}
	}

	for (int h = 0; h < n; h++)
	{
		if (h != (n - 1)) cout << sorted[h] << " ";
		else cout << sorted[h] << endl;
	}
	return 0;
}

/*#include <cstdio>
int num[3000001];

int partition(int beg, int length)
{
	int pivot = num[beg];
	int pivot_point = beg;
	for(int i = (beg+1); i < (beg+length); ++i)
	{
		if(num[i] < pivot)
		{
			pivot_point ++;
			if(i != pivot_point)
			{
				int temp = num[pivot_point];
				num[pivot_point] = num[i];
				num[i] = temp;
			}
		}
	}
	num[beg] = num[pivot_point];
	num[pivot_point] = pivot;
	return pivot_point;
}

void sort(int left, int len)
{
	if(len > 1)
	{
		int p = partition(left, len);
		int n = len;
		sort(left, p-left);
		sort(p+1, n-p);
	}
	else return;
}

int main()
{
	int n = 0;
	scanf_s("%d",&n);
	for(int q = 0; q < n; q++)
	{
		scanf_s("%d", &num[q]);
	}
	sort(0,n);
	for(int w = 0; w < n; w++)
	{
		if(w != 0) printf("%c", ' ');
		printf("%d", num[w]);
	}
	printf("%c", '\n');
	system("pause");
}*/