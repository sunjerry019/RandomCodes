#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream in("marathon.in");
    ofstream out("marathon.out");
    int n;
    in >> n;
    int coord[n][2];
    int length[n];
    length[0] = 0;
    int mini = 1000000000;
    for(int i=0;i<n;i++)
    {
        in >> coord[i][0] >> coord[i][1];
        if(i)
        {
            length[i] = length[i-1] + abs(coord[i-1][0]-coord[i][0]) + abs(coord[i-1][1]-coord[i][1]);
        }
    }
    for(int i=1;i<(n-1);i++)
    {
        int l = length[n-1] - length[i+1] + length[i-1];
        l += abs(coord[i-1][0]-coord[i+1][0]) + abs(coord[i-1][1]-coord[i+1][1]);
        mini = min(mini,l);
    }
    mini = min(mini,length[n-1]);
    out << mini << endl;
    return 0;
}
