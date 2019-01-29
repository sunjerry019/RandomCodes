#include <fstream>

using namespace std;

int grid[50][50];
int ans[2500][2];
int total = 0;
int m, n;

int isValid(int y, int x)
{
    int val = 0;
    //check horizontal
    if((x-1) == (-1))
    {
        if((x+1) < n && (x+2) < n)
        {
            if((grid[x+1][y] == 0) && (grid[x+2][y] == 0))
            {
                val = 1;
                ans[total][0] = x+1;
                ans[total][1] = y+1;
            }
        }
    }
    else if(grid[x-1][y] == 1)
    {
        if((x+1) < n && (x+2) < n)
        {
            if((grid[x+1][y] == 0) && (grid[x+2][y] == 0))
            {
                val = 1;
                ans[total][0] = x+1;
                ans[total][1] = y+1;
            }
        }
    }

    //check vertical
    if((y-1) == (-1))
    {
        if((y+1) < m && (y+2) < m)
        {
            if((grid[x][y+1] == 0) && (grid[x][y+2] == 0))
            {
                val = 1;
                ans[total][0] = x+1;
                ans[total][1] = y+1;
            }
        }
    }
    else if(grid[x][y-1] == 1)
    {
        if((y+1) < m && (y+2) < m)
        {
            if((grid[x][y+1] == 0) && (grid[x][y+2] == 0))
            {
                val = 1;
                ans[total][0] = x+1;
                ans[total][1] = y+1;
            }
        }
    }

    return val;
}

int main()
{
    ifstream in("crosswords.in");
    ofstream out("crosswords.out");
    in >> m >> n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            char temp;
            in >> temp;
            if(temp == '#') grid[j][i] = 1;
            else grid[j][i] = 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!grid[j][i]) total += isValid(i, j);
        }
    }
    out << total << endl;
    for(int i = 0; i < total; i++)
    {
        out << ans[i][1] << " " << ans[i][0] << endl;
    }
    return 0;
}
