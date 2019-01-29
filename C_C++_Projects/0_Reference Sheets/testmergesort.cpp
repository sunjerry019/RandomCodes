#include <bits/stdc++.h>
#include <iterator>
#include <algorithm> // for std::inplace_merge
#include <functional> // for std::less

using namespace std;

template<typename RandomAccessIterator, typename Order>
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
	{
		RandomAccessIterator middle = first + (last - first) / 2;
		mergesort(first, middle, order);
		mergesort(middle, last, order);
		inplace_merge(first, middle, last, order);
	}
}

template<typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
	mergesort(first, last, less<typename iterator_traits<RandomAccessIterator>::value_type>());
}

int main ()
{
	int x[10] = {5,1,2,4,8,42,5,12};
	printf("%s", "Hi1");
	mergesort(x, x + sizeof(x));
	printf("%s", "Hi3");
	for (int i = 0; i < 8; ++i)
	{
		printf("%s", "Hi2");
		cout << "Hi";
        cout << x[i] << " ";
    }
	return 0;
}
