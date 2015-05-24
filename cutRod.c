#include <stdio.h>

unsigned int price[11] = {1,5,8,9,10,17,17,20,24,30};
#define max(x,y) (x)>(y)?(x):(y)
static int count=0;

/** i=0 , we cut the rod in unit of 1 , hence for length 3 anser is 3 */

unsigned int cutRod (unsigned int bprice, unsigned int len1)
{
  if (len1==0) return 0;
  int i = 0, maxVal = 0, temp1 = 0;
  count++;
  for (i=0; i<len1; i++)
  {
    temp1  = cutRod(price[i], len1-i-1);
    maxVal = max(maxVal, (price[i] + temp1));
    printf ("maxVal %d, i %d , len %d\n", maxVal, i, len1 );
  }
  return maxVal;
}

/** top-down approach , start memoization for subproblems*/
unsigned int cutRodDp1 (unsigned int memo[], unsigned int len1)
{
  unsigned int maxVal=0, i;
  count++;
  if (memo[len1] > 0) return memo[len1];
  if (len1==0) maxVal = 0;
  else
  {
    for (i=0; i< len1; ++i)
    {
      maxVal = max(maxVal, (price[i] + cutRodDp1(memo, len1-i-1)));
    }
  }
  memo[len1] = maxVal;
  printf ("memo %d, len1 %d \n", memo[len1], len1);
  return memo[len1];
}

/** bottom - up approach , solve smaler subproblems for a given problem */
unsigned int cutRodDp2(unsigned int optSize[], unsigned int memo[], unsigned int len1)
{
  unsigned int maxVal=0, i , j;
  /** think: the subproblem approach required me to think , that to solve a problem i should have solved
   * all subproblems
   * So we start j from 1 as memo[0] shall be done in the nested for loop , so for prb 1 i solved subprob 0
   * Secondly since j starts from 1 it needs to lopp to len1 , contrary to len1-1 in prev approaches*/
  for (j=1;j<=len1;++j)
  {
    maxVal = 0;
    for (i=0;i<j;++i)
    {
      maxVal = max(maxVal, (price[i]+memo[j-i-1]));
      count++;
      optSize[j] = i;
    }
    memo[j] = maxVal;
    //printf ("memo %d, len1 %d \n", memo[j], j);
  }
  return memo[len1];
}

void main (int argc , char **argv)
{

   unsigned int len1=atoi(argv[1]), len2=0, maxRev1 = 0,maxRev = 0, i ;
   unsigned int memo[11] =  {0};
   unsigned int optSize[11] =  {0};
   //maxRev= cutRod(price[len1-1], len1);
   //maxRev = cutRodDp1(memo, len1);
   maxRev = cutRodDp2(optSize, memo, len1);
   printf ("Max revenue is %d count %d\n", maxRev, count);
   for (i=0; i<len1;++i)
   {
     printf ("length %d, max-revenue %d, firstCut %d\n", i, memo[i], optSize[i]);
   }

}


