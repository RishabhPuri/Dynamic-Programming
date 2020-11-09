#include <stdio.h> 

void foo (int *A, int n, int *start, int *end)
{
  int sum, max = A[0];
  int i,j,k;
  for (i=0;i<n;i++)
  {
    for (j=i; j<n; j++)
    {
      sum = 0;
      for (k=i; k<=j; k++)
      {
        sum += A[k];
        printf ("k is %d \n",k);
      }
      if (sum >= max )
      {
        *start = i;
        *end = j;
        max = sum;
      }
    }
  }
}

void main ()
{
  int a [10] = {1,2,3,4,5,6,7,8,9,0};
  int s,e;
  foo (a,10,&s,&e);

}
