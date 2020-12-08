#include <iostream>
//#include <bits/stdc++.h>

using namespace std;
#define X 1000

long long dp[X][X];

bool hasPathInGridRec(int m[X][X], int r, int c, int i, int j)
{
	if ((i<0)||(j<0)||(i>r-1)||(j>c-1))
      return false;
  
  	if (m[i][j]==1)
    	return false;
  
	if ((i==r-1)&&(j==c-1))
  		return true;
  
  	
  	return hasPathInGridRec(m,r,c,i+1,j) || hasPathInGridRec(m,r,c,i,j+1);
}

bool hasPathInGridTd(int m[X][X], int r, int c, int i, int j)
{
	if ((i<0)||(j<0)||(i>r-1)||(j>c-1))
		return false;
  
  	if (m[i][j]==1)
    	return dp[i][j] = false;
  
	if ((i==r-1)&&(j==c-1))
  		return true;
  
  	if (dp[i][j] != -1)
      return dp[i][j];
  	
  	return dp[i][j] =  hasPathInGridTd(m,r,c,i+1,j) || hasPathInGridTd(m,r,c,i,j+1);
}

bool hasPathInGridBu(int m[X][X], int r, int c)
{
  if ((m[0][0] == 1) || (m[r-1][c-1] == 1))
    return false;
    
  for (int i=0; i<r; i++)  {
    for (int j=0; j<c; j++)  {
      if ((i==0)&&(j==0)) 
        dp[i][j] = true;
      else {

        if (i==0)
          dp[i][j] = ((m[i][j]==0) && (dp[i][j-1]==true)) ? true : false;

        if (j==0)
          dp[i][j] = ((m[i][j]==0) && (dp[i-1][j]==true)) ? true : false;

        dp[i][j] = ((m[i][j]==0) && ((dp[i-1][j]==true) || (dp[i][j-1]==true))) ? true : false;
      }
    }
  }
  	return dp[r-1][c-1];
        
}

bool hasPathInGrid(int m[X][X], int r, int c) {
  
	//return hasPathInGridRec(m,r,c,0,0);
  	for (int i=0;i<X;i++)
      for(int j=0;j<X;j++)
        dp[i][j] = -1;
  
  	//return hasPathInGridTd(m,r,c,0,0);
  	return hasPathInGridBu(m,r,c);
}

int main()
{
  int tc,r,c;
  int m[X][X];

  cin >> tc;
  while (tc--)
  {
    cin >> r >> c;
    for (int i=0;i<r;i++)
      for (int j=0;j<c;j++)
        cin >> m[i][j];

    cout << hasPathInGrid(m,r,c) << endl;
  }
}
