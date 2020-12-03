/** 
  Given a 2D Matrix containing integers,  Find the maximum cost that one will incur to start from TOP LEFT (0, 0) to reach to bottom right of matrix.
  You can only move in RIGHT or DOWN directions.
  Expected Time Complexity: O(N^2) Allowed Space Complexity:O(N^2)

 */

#include<bits/stdc++.h>
using namespace std;

#define ROWS 200
#define COLS 200

const int inf=0x80000000;
long dp[ROWS+1][COLS+1];
int maxPathCostRec(int a[ROWS][COLS], int m, int n, int i, int j)
{
	if (i==m) return inf;
  	if (j==n) return inf;
  
  	if ((i==m-1)&&(j==n-1))
      return a[i][j];
  
  	return a[i][j] + max(maxPathCostRec(a,m,n,i,j+1),maxPathCostRec(a,m,n,i+1,j));
}

int maxPathCostTd(int a[ROWS][COLS], int m, int n, int i, int j)
{
	if ( (i==m) || (j==n) ) return inf;
  
  	if ((i==m-1) && (j == n-1))
      return dp[i][j] = a[i][j];
  
  	if (dp[i][j] != -1) return dp[i][j];
  
  	return dp[i][j] = a[i][j]+ max(maxPathCostTd(a,m,n,i,j+1),maxPathCostTd(a,m,n,i+1,j));
}

int maxPathCostBu(int a[ROWS][COLS], int m, int n)
{
	// dp formula is 
  	// dp[i][j] = a[i][j] + max (dp[i][j-1],dp[i-1][j])
  	// for first row, since dp[i-1][j] is out of boundary
  	// for first row formula is 
  	// dp[i][j] = a[i][j] + dp[i][j-1]
  	// similarly for first col formula is 
  	// dp[i][j] = a[i][j] + dp[i][j-1]
  	// fill first row
    // also answer will be in dp[m-1][n-1]
  	// The above approach causes a slight discomfort in the sense
  	// dp[0][0] isnt derivable
  	// So we change our approach , answer will be now stored in dp[m][n]
  	// and our dp matrix wil dp[m+1][n+1]
  	// Initialize the first row and col with 0
    // The approach discussed above didnt work for negative values in array
  	// as base case if taken as 0 will become a problem for negative values 
  	// if base case is taken as -inf , again it becomes a problem
    dp[0][0] = a[0][0];
    for (int j=1;j<n;j++)
      dp[0][j] = a[0][j]+dp[0][j-1];
    for(int i=1;i<m;i++)
      dp[i][0] = a[i][0]+dp[i-1][0];

    for (int i=1;i<m;i++)
      for(int j=1;j<n;j++)
        dp[i][j] = a[i][j]+max(dp[i-1][j],dp[i][j-1]);

  	
  return dp[m-1][n-1];
}

int maxPathCost(int a[ROWS][COLS], int m, int n)
{
   for (int i=0;i<201;i++)
     for (int j=0;j<201;j++)
       dp[i][j] = -1;
   //return maxPathCostRec(a, m, n, 0, 0);
   //return maxPathCostTd(a, m, n, 0, 0);
   return maxPathCostBu(a,m,n);
}

int main()
{
  	int t, m, n;
  
  	scanf("%d", &t);
  	while(t--){
      
      for (int i=0;i<=ROWS;i++)
      for(int j=0;j<=COLS;j++)
        dp[i][j]=-1;
      
      scanf("%d %d", &m, &n);
      int a[ROWS][COLS];
      int i, j;
      for(i=0;i<m;i++)
        for(j=0;j<n;j++)
          scanf("%d", &a[i][j]);
	  
      printf("%d\n", maxPathCost(a, m, n));
    }
	return 0;
}
