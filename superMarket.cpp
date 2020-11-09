#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> weight;
vector<int> price;
vector<int> persons;
vector<int> dp;
    
long maxValueGoodsHelper(int len, int totalweight, long currentMax)
{
    if (len < 0)  return 0;
    
    if (totalweight <= 0)
        return 0;

    cout << "1. len :"<<len<<" "<<"weight :"<<totalweight<< " "<< "current max :"<<currentMax << endl;
    
    currentMax = max({(maxValueGoodsHelper(len-1, totalweight-weight[len-1], currentMax+price[len-1])), 
                maxValueGoodsHelper(len-1, totalweight, currentMax),
                currentMax});

    //cout << "2. len :"<<len<<" "<<"weight :"<<totalweight<< " "<< "current max :"<<currentMax << endl;

    return currentMax;
}

long maxValueGoodsHelperTd(int len, int totalweight, long currentMax)
{
    if (len < 0)  return 0;
    
    if (totalweight <= 0)
        return 0;

    //cout << "1. len :"<<len<<" "<<"weight :"<<totalweight<< " "<< "current max :"<<currentMax << endl;

    if (dp[len] != -1)
      return dp[len];
    
    dp[len] = max({(maxValueGoodsHelperTd(len-1, totalweight-weight[len-1], currentMax+price[len-1])), 
                maxValueGoodsHelperTd(len-1, totalweight, currentMax),
                currentMax});

    //cout << "2. len :"<<len<<" "<<"weight :"<<totalweight<< " "<< "current max :"<<currentMax << endl;

    return dp[len];
}

long maxValueGoods()
{
    long maxAns = 0;
    for (int i=0; i<=price.size();i++)
      dp[i] = -1;

    for (int i=0;i<persons.size();i++)
        maxAns += maxValueGoodsHelperTd(weight.size(), persons[i], 0);
    
    return maxAns;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t; cin>>t;
    int size;
    while(t--)
    {
        cin>>size;
        weight.clear();
        price.clear();
        persons.clear();
        dp.clear();
        
        weight.resize(size);
        price.resize(size);
        dp.resize(size+1);
        for (int i=0;i<size;i++)
            cin>>price[i]>>weight[i];
        
        cin>>size;
        persons.resize(size);
        for(int i=0; i<size;i++)
            cin>>persons[i];
        
        cout << maxValueGoods() << endl;
    }
    return 0;
}
