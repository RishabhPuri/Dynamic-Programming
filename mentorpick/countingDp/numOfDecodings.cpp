#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define MAX_SIZE    300
using namespace std;

int numberOfDecodingsRec(char s[], int idx, int len)
{
  if (idx>len) return 0;
  if (idx==len)  return 1;
  if (s[idx]-'0' == 0) return 0;

  int ans1 = 0, ans2 = 0;
  if ((s[idx]-'0')>=1 && 
      (s[idx]-'0')<=26 ) {
    ans1 = numberOfDecodingsRec(s,idx+1,len); 
  }

  if ((idx+1<len) && 
      (((s[idx]-'0')*10+s[idx+1]-'0')>=1 && 
       ((s[idx]-'0')*10+s[idx+1]-'0')<=26)) {
    ans2 =  numberOfDecodingsRec(s,idx+2,len);
  }

  return ans1+ans2;
}


int numberOfDecodings(char s[])
{
	return numberOfDecodingsRec(s, 0, strlen(s));
}

int main ()
{
  int tc;
  char string[301];

  cin >> tc;
  while (tc--)
  {
    cin >> string;
    cout << numberOfDecodings(string) << " " ;
  }
}
