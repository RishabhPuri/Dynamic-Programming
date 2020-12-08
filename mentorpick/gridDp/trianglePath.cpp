
/* 
Consider a triangle of numbers in which
ONE number appears in the first line
TWO numbers appear in the second line
THREE numbers appear in the third line and so on

Develop a program which will compute the LARGEST of the sums of numbers that appear on the paths starting from the top towards the bottom, so that:

on each path the next number is located on the row either directly below or below and one place to the right;
the number of rows is strictly positive, but less than 100;
all numbers are positive integers between 0 and 99.

*/


#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

//long dp[101][101];
int spaceSavDp[2][101];
const int inf = 0x80000000;

int maxSumInTriRec(vector< vector<int> > mat, int i, int j)
{
	if (i > mat.size()-1)
    	return 0;

  	if (j>i)
    	return 0;
  
  	return mat[i][j] + max(maxSumInTriRec(mat,i+1,j), maxSumInTriRec(mat,i+1,j+1));
}

#if 0
int maxSumInTriTd(vector< vector<int> > mat, int i, int j)
{
	if (i > mat.size()-1)
    	return 0;

  	if (j>i)
    	return 0;
  
  	if (dp[i][j] !=-1)
      return dp[i][j];

  	return dp[i][j] = mat[i][j] + max(maxSumInTriTd(mat,i+1,j), maxSumInTriTd(mat,i+1,j+1));
}
#endif

/* The space complexity in this question was O(C)
*  dp[i%2][j] = mat[i][j] + Math.max( dp[(i+1)%2][j], dp[(i+1)%2][j+1]) 
  i=0 
    dp[0][j] = mat[0][j] + Math.max(dp[1][j], dp[1][j+1]) 
  i=1 
    dp[1][j] = mat[1][j] + Math.max(dp[0][j], dp[0][j+1]) 
  i=2 
    dp[0][j] = mat[0][j] + Math.max(dp[1][j], dp[1][j+1]) 
 
SPACE:  2 * C 
*/

int maxSumInTriBu(vector< vector<int> > mat, int i, int j)
{
	for (int i=0;i<mat.size();i++) { 
    	for (int j=0; j<=i;j++) {
    		if (i%2==0) {
            	if (i==0)
                  spaceSavDp[0][j]=mat[0][j];
              	else {
                  if (j == 0)
                  	spaceSavDp[0][j] = mat[i][j] + spaceSavDp[1][j];
                  else
                    spaceSavDp[0][j] = mat[i][j] + 
                    				max(spaceSavDp[1][j],spaceSavDp[1][j-1]);
                }
            }
          	else {
				if (j == 0)
                	spaceSavDp[1][j] = mat[i][j] + spaceSavDp[0][j];
                else
                    spaceSavDp[1][j] = mat[i][j] + 
                  					max(spaceSavDp[0][j],spaceSavDp[0][j-1]);
            
            } 
        }
    }
  
  	int  ans = 0;
  	for (int j=0;j<mat.size();j++) {
    	if ((mat.size()-1) % 2 == 0)
      		ans = max (ans, spaceSavDp[0][j]);
    	else
      		ans = max (ans, spaceSavDp[1][j]);
  }

  return ans;
      
}


int maxSumInTri(vector< vector<int> > mat)
{	
  	//for (int i=0;i<101;i++)
      //for (int j=0; j<101;j++)
      	//dp[i][j]=-1;
  
  	//return maxSumInTriTd(mat,0,0);
	//return maxSumInTriRec(mat, 0,0);
  	for (int i=0;i<2;i++)
      for (int j=0; j<101;j++)
      	spaceSavDp[i][j]=inf;
  
  	return maxSumInTriBu(mat,0,0);
}

int main() {
    int t; cin>>t;
    while(t--){
        int r;
        cin>>r;
        vector< vector<int> > v(r);  // Create a Vector of size r where each element is a vector<int> 
        for(int i=0;i<r;i++){
            for(int j=0;j<=i;j++){
                int x; cin>>x;
                v[i].push_back(x);
            }
        }
        cout<<maxSumInTri(v)<<"\n";
    }
    return 0;
}


