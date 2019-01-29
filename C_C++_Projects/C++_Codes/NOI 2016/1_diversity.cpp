#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int n;
	int q;
	long long int cnt = 0;
	scanf("%lld%d", &n, &q);
	
	if(!q) cnt = (n*(n+1))/2;
	else 
	{
		vector<int> arr;
		vector< vector< pair<int, int> > > brr;
		vector< vector <bool> > crr;
		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d", &tmp);
			arr.push_back(tmp);
			
			vector< pair<int, int> > tempa;
			vector< bool > tempb;
			for(int j = 0; j < n; j ++)
			{
				tempa.push_back(make_pair(0,0));
				tempb.push_back(false);
			}
			brr.push_back(tempa);
			crr.push_back(tempb);
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=(i+1); j<n;j++)
			{
				//i is start, j is end idx
				if(j == (i+1))
				{
					//first of its kind
					auto mini = min(arr[i], arr[j]);
					auto maxi = max(arr[i], arr[j]);
					brr[i][j] = make_pair(mini, maxi);
					
					if(abs(maxi-mini) >= q)
					{
						crr[i][j] = true;
					}
					else
					{
						crr[i][j] = false;
					}
				}
				else
				{
					auto currMinMax = brr[i][j-1];
					auto currMin = currMinMax.first;
					auto currMax = currMinMax.second;
					
					if(arr[j] <= currMax  && arr[j] >= currMin)
					{
						//in between the current min/max
						crr[i][j] = crr[i][j-1];
						brr[i][j] = currMinMax;
					}
					else if(arr[j] > currMax)
					{
						brr[i][j] = make_pair(currMin, arr[j]);
						if(abs(arr[j]-currMin) >= q)
						{
							crr[i][j] = true;
						}
						else
						{
							crr[i][j] = false;
						}
					}
					else if(arr[j] < currMin)
					{
						brr[i][j] = make_pair(arr[j], currMax);
						if(abs(arr[j]-currMax) >= q)
						{
							crr[i][j] = true;
						}
						else
						{
							crr[i][j] = false;
						}
					}
				}
				
				if(crr[i][j]) cnt++;
				//cout << i << " " << j << " " << mini << " " << maxi << endl;
				
			}
		}
		//if(!cnt) cnt = 1;
	}
	
	printf("%lld\n", cnt);
	
	return 0;
}
