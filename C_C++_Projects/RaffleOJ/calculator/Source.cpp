#include <fstream>
using namespace std;

int main() 
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int a, b;
	char op;
	cin >> a >> op >> b;

	switch (op)
	{
		case '-':
			cout << (a - b);
			break;
		case '*':
			cout << (a * b);
			break;
		case '+':
			cout << (a + b);
			break;
	}

	return 0;
}