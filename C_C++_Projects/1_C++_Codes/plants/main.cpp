#include <bits/stdc++.h>

using namespace std;

int dist(int row, int col)
{
    return 2*(row+col);
}

int main()
{
    int r, c, t;
    scanf("%d%d%d", &r, &c, &t);
    int arr[r][c] = {0}; visited[r][c] = {0};
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    return 0;
}
