/**
  You've a bag that has a fixed CAPACITY (weight it can carry);  and Given an array of items, each item has a WEIGHT and VALUE.  How much max value can we fill in the bag so that we are carrying max value items.  An Item can be taken fully or left fully.  No partial selection possible.  Each item has only one unit available.
 */

#include<bits/stdc++.h>

using namespace std;
vector<long long> weight;
vector<long long> val;

long long dp[2005][5005];
/** Thought process 
    Counting DP : we need to count , which eventually became 2 things
         1. Either a GP series 
         2. Just a sum
    In either case it was easy to deduce the dp solution using i-1, j-1 i-2 j+1 etc
    
    Knapsack and subset dp problems
    These problems are 1 step ahead of counting dp in the sense that 
    dp solution will not be every straight forward , but the concept remains the same 
    Eg: knapsack requires dp of a 2d cell to be calculated using cell above OR any cell in the above row 
    When i say any cell, there is a logic which is defined by the problem and constraints 

    with knapsack and subset dp problem we have a new way of solving problems 
    include in subproblem or not 
*/


/** 
  Table  cap is 7, itemCount = 4
    
                   0 1 2 3 4 5 6 7
 itemCount%2       x x x x x x x x
 itemCount%2       x x x x x x x x

  actual table:  
                   0 1 2 3 4 5 6 7
 itemCount[1]      0 0 0 0 0 0 0 0
 itemCount[2]      0 1 1 1 1 1 1 1
 itemCount[3]      0 1 1 4 5 5 5 5
 itemCount[4]      0 x x x x x x x
 itemCount[5]      0 x x x x x x x
  
  In the actual table we see that result depends on the row just above it,
  so in essence we just need 2 rows to solve this dp 
                
*/

long long knapsackSolBuSpaceSave(long cap, long itemCount)
{
  for (int i=0;i<=itemCount;i++) {
    for(int j=0;j<=cap;j++) {
      if (i==0)
        dp[i][j] = 0;
      else { 
        if (j - weight[i-1] < 0)
          dp[i%2][j] = dp[(i-1)%2][j];
        else
          dp[i%2][j] = max( (val[i-1] + dp[(i-1)%2][j-weight[i-1]]), 
              dp[(i-1)%2][j]);
          
      }  
    }
  }

  return dp[itemCount%2][cap];
}

long long knapsackSolBu(long cap, long itemCount)
{
  for (int i=0;i <=itemCount;i++) { 
    for (int j=0;j<=cap;j++) {

      /** Think : whats the max val when bag cap is 0 or weight of item is 0*/
      if ((i==0)||(j==0))
        dp[i][j] = 0;
      else {
        /** When the 2d matrix is created for all weights of bag less than item weight 
           we can see that the value of cell just above the current cell can be copied */
        if (j - weight[i-1] < 0)
          dp[i][j] = dp[i-1][j];
        else
          dp[i][j] = max( (val[i-1] + dp[i-1][j-weight[i-1]]), 
              dp[i-1][j]);
      }
    }
  }
  return dp[itemCount][cap];
}


long long knapsackSolTd(long cap, long itemCount)
{
  if (cap<=0)
    return 0;

  if (itemCount <=0)
    return 0;

  if (dp[itemCount][cap]!=-1)
    return dp[itemCount][cap];

  if (cap-weight[itemCount-1] < 0)
    return dp[itemCount][cap] = knapsackSolTd(cap, itemCount-1);

  /** include the last item, or not*/
  return dp[itemCount][cap] = max (knapsackSolTd(cap-weight[itemCount-1],itemCount-1)+val[itemCount-1],
              knapsackSolTd(cap, itemCount-1));
}

long long knapsackSolRec(long cap, long itemCount)
{
  if (cap<=0)
    return 0;

  if (itemCount <=0)
    return 0;

  if (cap-weight[itemCount-1] < 0)
    return knapsackSolRec(cap, itemCount-1);

  /** include the last item, or not*/
  return max (knapsackSolRec(cap-weight[itemCount-1],itemCount-1)+val[itemCount-1],
              knapsackSolRec(cap, itemCount-1));
}

long long knapsackSol(long cap, long itemCount)
{
#if 0 
  for (int i=0;i<2005;i++)
    for(int j=0;j<5005;j++)
      dp[i][j]=-1;
  //return knapsackSolRec(cap, itemCount);
  //return knapsackSolTd(cap, itemCount);
  return knapsackSolBu(cap, itemCount);
#else
  for (int i=0;i<2;i++)
    for (int j=0;j<5005;j++)
      dp[i][j] = -1;
  return knapsackSolBuSpaceSave(cap, itemCount);
#endif
}

int main()
{
  long tc, cap, itemCount;
  cin >> tc;  
  while (tc--)
  {
    cin >> cap >> itemCount;
    weight.clear(); 
    val.clear();
    weight.resize(itemCount,0);
    val.resize(itemCount,0);
    
    for (int i=0;i<itemCount;i++)
      cin >> val[i];

    for (int i=0;i<itemCount;i++)
      cin >> weight[i];
  
    
    cout << knapsackSol(cap, itemCount) << endl;; 
  }
}
