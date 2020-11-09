#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#define MAX_SIZE    200
using namespace std;

string str1;
string str2;


int lcsLenHelperRecursive (int len1, int len2)
{
  // Boundary and base cases can be converged. 
  // because they return same values.
  // this may not be the case always.
  if (len1 < 0) 
    return 0;
  if (len2 < 0)
    return 0;
  
  if ((len1 == 0) || (len2 == 0))
    return 0;
  
  // if character at idx i and j is same 
  // thats 1+ rest of string cmp result
  
  if (str1[len1-1] == str2[len2-1])
      return 1+ lcsLenHelperRecursive(len1-1,len2-1);
  
  // if char at idx 1 and j dont match, 
  // match char[i] of str1 to chara[j-1] of str2
  // AND match char[i-1] of str1 to char[j] of str2;
  return max(lcsLenHelperRecursive(len1-1,len2), 
             lcsLenHelperRecursive(len1, len2-1));
}


int lcsLenHelperTopDown(int len1, int len2 , vector<vector<int>> &arr)
{
  // Boundary and base cases can be converged. 
  // because they return same values.
  // this may not be the case always.
  if (len1 <= 0) 
    return 0;
  if (len2 <= 0)
    return 0;
  
  
  if (arr[len1][len2] != -1)
    return arr[len1][len2];
  
  if (str1[len1-1] == str2[len2-1])
  return arr[len1][len2] = 1 + lcsLenHelperTopDown(len1-1, len2-1, arr);
  
  return arr[len1][len2] = max (lcsLenHelperTopDown(len1-1,len2,arr),
                                lcsLenHelperTopDown(len1,len2-1,arr));
  
}

int lcsLenHelperBotUp(int len1, int len2, vector<vector<int>> &arr)
{
  // Fill the base case and boundary case 
    // First base case lcs(0,len2)
    for (int j=0;j<=len2;j++)
      arr[0][j]=0;
    
    // Second base case lcs(len1,0)
    for(int i=0;i<=len1;i++)
      arr[i][0] = 0;

    for (int i=1;i<=len1;i++)
    {
      for (int j=1;j<=len2;j++)
        {
          if (str1[i-1]==str2[j-1])
                arr[i][j] = 1 + arr[i-1][j-1];
            else
                arr[i][j] = max (arr[i-1][j],arr[i][j-1]);
        }
    }
   
  return arr[len1][len2];
   
}

int lcsLen(char s1[], char s2[])
{
    //str1(s1);  str2(s2);
    str1 = s1; str2 = s2;
  //return lcsLenHelperRecursive(str1.size(), str2.size());
    vector<vector<int>> arr(101,vector<int>(101,-1));
    //return lcsLenHelperTopDown(str1.size(), str2.size(), arr);
  return lcsLenHelperBotUp(str1.size(), str2.size(), arr);
}
