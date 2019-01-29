#include <bits/stdc++.h>
using namespace std;

vector<int> co (unsigned int val)
{
    vector<int> tst;
    
	for(int I(0); I< sizeof(val)*8;++I) tst.push_back((val & (1 << I)) ? 1 : 0);
	
    return tst;
}

string a[17] =
{
	"(0)",
	"",
	"(2)",
	"(2+2(0))",
	"(2(2))",
	"(2(2)+2(0))",
	"(2(2)+2)",
	"(2(2)+2+2(0))",
	"(2(2+2(0)))",
	"(2(2+2(0))+2(0))",
	"(2(2+2(0))+2)",
	"(2(2+2(0))+2+2(0))",
	"(2(2+2(0))+2(2))",
	"(2(2+2(0))+2(2)+2(0))",
	"(2(2+2(0))+2(2)+2)",
	"(2(2+2(0))+2(2)+2+2(0))",
	"(2(2(2)))",
};

int main() {
    int n;
    scanf("%d", &n);
    vector<int> ao = co(n);
    int sz = ao.size();
	int fst = 0;
    for(int i=(sz-1);i>=0;i--)
    {
		//cout << ao[i] << " ";
		if(ao[i])
		{
			string power = a[i];
			if(!fst) 
			{
				cout << "2" << power;
				fst = 1;
			}
			else cout << "+2" << power;
		}
    }
	//cout << endl << "2(2(2)+2+2(0))+2(2+2(0))+2(0)";
	return 0;
}
