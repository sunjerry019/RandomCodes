#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
		if (i < (arr.size() - 1)) cout << " ";
		else cout << endl;
	}
	return 0;
}