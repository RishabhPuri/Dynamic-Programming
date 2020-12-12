/**
  You've a bag that has a fixed CAPACITY (weight it can carry);  and Given an array of items, each item has a WEIGHT and VALUE.  How much max value can we fill in the bag so that we are carrying max value items.  An Item can be taken fully or left fully.  No partial selection possible.  Each item has only one unit available.
 */

#include<bits/stdc++.h>

using namespace std;
vector<long long> weight;
vector<long long> val;

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
  return knapsackSolRec(cap, itemCount);
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
