#include <bits/stdc++.h>

#define MAX_SIZE    1001

using namespace std;

string s1,s2;

int lcSubStringLenHelperRec(int len1, int len2, int currMaxLen)
{
  if (len1 == 0) 
    return currMaxLen;
  if (len2 == 0)
    return currMaxLen;

  if (s1[len1-1] == s2[len2-1])
    return lcSubStringLenHelperRec(len1-1, len2-1, currMaxLen+1);

  return max({currMaxLen, lcSubStringLenHelperRec(len1-1,len2,0), lcSubStringLenHelperRec(len1,len2-1,0)});
} 

int lcSubstringLen(string s, string t)
{
  s1 = s; s2 = t;
  return lcSubStringLenHelperRec(s1.size(),s2.size(),0);
}

int main() 
{ 
  string X = "aabcdd";  
  string Y = "abcd"; 

  cout<<lcSubstringLen(X,Y); 

  return 0; 
} 
