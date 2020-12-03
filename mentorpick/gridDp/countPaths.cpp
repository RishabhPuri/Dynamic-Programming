#include <bits/stdc++.h>

using namespace std;

long long countPathsHelperBu(int srow, int scol, int r, int c, int maxrow, int maxcol)
{
  long long dp[maxrow+1][maxcol+1];

  for (int j=scol+1;j<maxcol;j++)
    dp[srow][j]=1;

  for(int i=srow-1;i>=0;i--)
    dp[i][scol]=1;

  for(int i=srow-1;i>=0;i--)
    for(int j=scol+1;j<maxcol;j++)
      dp[i][j] = dp[i][j-1]+dp[i+1][j];

  return dp[r][c];
}

long long countPathsHelper(int i, int j, int r, int c)
{
    if ((i<0) || (j>c))
      return 0;
  
	if ((i==r) && (j==c) )
      return 1;
  
  	return countPathsHelper(i-1,j,r,c)+countPathsHelper(i,j+1,r,c);
}

long long countPaths(int r, int c){
    // TODO: Your Code Here
  //return countPathsHelper(r-1,0,0,c-1);
  return countPathsHelperBu(r-1,0,0,c-1,r,c);
}

int main()
{
    int t, n;
  	int r,c;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &r, &c);
      	printf("%lld\n", countPaths(r, c));
    }

    return 0;
}
