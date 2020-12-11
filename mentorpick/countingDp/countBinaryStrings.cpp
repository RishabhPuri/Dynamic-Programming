/** 
Count Binary Strings with Max 2 adjacent 1sPROBLEM STATEMENT	For a given number N, find the total number of N-bit numbers which do not have more than 2 adjacent set bits in their binary representation.
INPUT FORMAT	First line of input contains T - number of test cases. Its followed by T lines, each containing a single number N.
OUTPUT FORMAT	For each test case, print the total numbers with no more than 2 adjacent set bits, separated by newline. Since the number can be very large, print result % 1000000007.
CONSTRAINTS	1 <= T, N <= 106
SAMPLE INPUT	SAMPLE OUTPUT	EXPLANATION
5
1
2
3
5
20	2
4
7
24
223317	Test Case 1
1-bit numbers with no more than 2 adjacent set bits: 0, 1
Test Case 2
2-bit numbers with no more than 2 adjacent set bits: 0, 1, 2, 3
Test Case 3
3-bit numbers with no more than 2 adjacent set bits: 0, 1, 2, 3, 4, 5, 6
Test Case 5
5-bit numbers with no more than 2 adjacent set bits: 0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 27
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    /** thought process
      n        Countbinarystrings
      0         1
      1         2 {0,1}
      2         4 {00,01,10,11}
      3         7 {4+2+1}
      4         13 {7+4+2}
      5         24 (13+7+4} 
      */
    /** 
      Another one 
      n = 0 
      n = 1 { 0, 1} = 2
      n = 2 
        we can add 0 to both the strings above a = 2
        we can add 1 to both the strings above b = 2 
        Here 
          Let strings ending with 0 a1 = 2
          Let strings ending with 1 a2 = 1
          Let strings ending with 11 b1 = 1
      {00,01,10,11}  = 4

      n = 3 
        we can add 0 to all strings above so a1' = 4
        we can add 1 to all strings that end with 0 a11' = a1 (2)
        we can add 1 to all strings that have single 1, a2' = a2(1)
        {000,001,010,011,100,101,110}  (4+2+1) = 7
      n = 4
        we can add 0 to all stings above so a1 = 7
        we can add 1 to all strings that end with 0 a11' = 4
        we can add 1 to all strings that end with single 1 a2' = 2 ( 7+4+2) = 13
         
    */  
    
    vector<long long >dp(1000001,0);  
    long tc, x;
    dp[0] = 0, dp[1] = 2, dp[2] = 4, dp[3] = 7;
    for (int i = 4; i<1000001;i++)
      dp[i] = dp[i-1]+dp[i-2]+dp[i-3];

    cin >> tc ;
    
    while (tc--)
    {
      cin >> x;
      cout << dp[x] << endl;  
    } 
    return 0;
}
