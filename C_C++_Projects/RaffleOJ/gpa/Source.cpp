#include <iostream>

using namespace std;

int main()
{
	int x;
	cin >> x;

	if (x >= 80) cout << "4.0";
	else if (x >= 70) cout << "3.6";
	else if (x >= 65) cout << "3.2";
	else if (x >= 60) cout << "2.8";
	else if (x >= 55) cout << "2.4";
	else if (x >= 50) cout << "2.0";
	else if (x >= 45) cout << "1.6";
	else if (x >= 40) cout << "1.2";
	else cout << "0.8";

	system("pause");

	return 0;
}