#include <stdio.h>
#include <stdlib.h>

void printTable (unsigned char pTable[] , unsigned int count)
{
  int i ;
  for (i=0;i<=count;i++)
    printf ("%d ", pTable[i]);
  printf ("\n");
}


unsigned int RecChange (unsigned int money, unsigned int coin[], unsigned int coinCount)
{
  if (money == 0)
    return 0;

  unsigned int rMinCount = 0xffffffff, tMinCount = 0;
  unsigned int i;
  for (i=0;i<coinCount;i++)
  {
    if (money >= coin[i])
    {
      tMinCount = RecChange (money-coin[i], coin, coinCount);
      if (tMinCount + 1  < rMinCount)
        rMinCount = tMinCount + 1;
    }
    printf ("money %d, rMinCount is %d i %d\n", money,rMinCount, i);
  } 
  return rMinCount;
}

unsigned int DpChange (unsigned int money, unsigned int coin[], unsigned coinCount)
{
  unsigned char *MinCountTable = calloc (money+1, sizeof(char));
  unsigned int i,j;
  /** start from money <--- 0  */
  for (i=0;i<=money;i++)
  {
    for (j=0;j<coinCount;j++)
    {
      if (i == 0 )
        MinCountTable[i] = 0;

      if (i == coin[j])
        MinCountTable[i] = 1;

      if (i>coin[j])
        MinCountTable[i] = MinCountTable[i-1]+1;
    
    }
    printTable (MinCountTable, money);
  }
  return MinCountTable[money];
}

void main ()
{
  unsigned int money = 9;
  unsigned int coinDen[3]   = {1,5,6};

  //unsigned int ans = RecChange (9, coinDen, 3);
  unsigned int ans = DpChange (9, coinDen, 3);
  printf ("minCount is %d\n",ans);
}
