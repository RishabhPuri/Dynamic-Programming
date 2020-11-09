#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


#if 0
Kadane's algorithm is used for maxsubset sum problem 
(subset is always contiguos so max contiguous subarray problem)

sample test case 
1
5
-3 2 -1 4 -1

expected output 
5
#endif


long kadaneAlgo(vector<long>arr)
{   
    vector<long>dp;
    dp.resize(arr.size()+1);
    
    dp[0] = arr[0];
    
    long maxResult = dp[0];
    
    for (int i=1;i<arr.size();i++)
    {
        dp[i] = max(arr[i],arr[i]+dp[i-1]);
        maxResult = (dp[i] >= maxResult )? dp[i] : maxResult;
    }
    
    return maxResult;
}


#if 0
// space saving trick algo
int kadaneAlgo(vector<int>arr)
{
    int maxResult = INT_MIN; 
    int currMax = 0;
    for (int i=0; i<arr.size();i++)
    {
        currMax = currMax + arr[i];
        if (maxResult < currMax)
            maxResult = currMax;
        
        if (currMax < 0)
            currMax = 0;
    }
    return maxResult;
}
#endif

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t;
    vector<long>arr;
    
    long item;
    while (t--)
    {
        int size; cin >>size;
        arr.clear();
        
        while(size--)
        {
            cin>>item;
            arr.push_back(item);
        }
        cout << kadaneAlgo(arr) << endl;
    }
    
    return 0;
}

