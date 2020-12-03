#include <bits/stdc++.h>

using namespace std;
#define MAX_R 100
#define MAX_C 100

long long countPathsRec(int m[MAX_R][MAX_C], int r, int c, int i, int j)
{
	if ((i<0)||(j<0)||(i>r-1)||(j>c-1))
      return 0;

  	if (m[i][j]==-1)
      return 0;
  
  	if ((i==r-1)&&(j==c-1))
      return 1;
  
  	return countPathsRec(m,r,c,i+1,j)+countPathsRec(m,r,c,i,j+1);
  
}

long long countPathsBu(int m[MAX_R][MAX_C], int r, int c)
{

  /** In this appproach , a mistake could be that for
    * first row , first column , we might be tempted to 
    * set dp[i][j] =1 if m[i][j] != -1 , no hurdle, BUT BUT
    * if assume 2 row first column is a hurdle , then all column
    * from 3rd row to nth row will become inaccessible */
	int dp[r][c];
  	for (int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        dp[i][j] = 0;
  
  	for (int i=0;i<r;i++) {
      for(int j=0;j<c;j++) {
        if (((i==0)&&(j==0))&&(m[i][j]!=-1))
			dp[i][j] = 1;          
        else if (i==0) {
          if (m[i][j] != -1)
        	dp[i][j] = dp[i][j-1];
        }
        else if (j==0) {
          if (m[i][j] != -1)
        	dp[i][j] = dp[i-1][j];
        }
        else
        {
          if (m[i][j] != -1)
        	dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
      }
    }
  	return dp[r-1][c-1];
}

long long countPaths(int m[MAX_R][MAX_C], int r, int c){
	//return countPathsRec(m,r,c,0,0);
  	return countPathsBu(m,r,c);
}

void resetMatrix(int m[MAX_R][MAX_C], int r, int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            m[i][j] = 1;
}
int main()
{
    int t, n, r, c, b, x, y;
    scanf("%d", &t);
    int m[MAX_R][MAX_C];
    while(t--){
        scanf("%d %d %d", &r, &c, &b);
        resetMatrix(m, r, c);
        for(int i=1;i<=b;i++)
        {
            scanf("%d %d", &x, &y);
            m[x][y] = -1; // BLOCK
        }
      	printf("%lld\n", countPaths(m, r, c));
    }

    return 0;
}
