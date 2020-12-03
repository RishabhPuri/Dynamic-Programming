#include <iostream>
#include<vector>
using namespace std;

int totalDistTravelled(vector<int> &gasarr, int totalFuel, int totalDist, int carno)
{
        
    if (carno == 0)
    {
        totalFuel += gasarr[carno];
        gasarr[carno] = 0;
    }
    
    if (carno == gasarr.size())
        carno = 0;
    
    if ((totalFuel <= 0 ) && (gasarr[carno] == 0))
           return totalDist;
    
    totalFuel += gasarr[carno];
    gasarr[carno] = 0;
    
    return totalDistTravelled(gasarr, totalFuel-1, totalDist+1, carno+1);
    
}

int main() {
	int tc;
	int n;
	vector<int> gasarr(100,0);
	cin >> tc;
	while (tc--)
	{
	    cin >> n;
	    gasarr.resize(n);
	    for (int i=0;i<n;i++)
	        cin >> gasarr[i];
	        
	   cout << totalDistTravelled(gasarr,0,0,0);
	}
	return 0;
}

