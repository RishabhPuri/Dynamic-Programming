#include <stdio.h>

#define FOR(i,a,b) for(i=a;i<b;i++)

unsigned long a[100001], b[100001];
void main ()
{
  unsigned int i, alen, blen, qCount;
  scanf ("%u %u", &alen, &blen);
  qCount = blen;

  FOR(i,1,alen+1)
    scanf("%lu",&a[i]);

  FOR(i,1,blen+1)
    scanf("%lu",&b[i]);

  unsigned int d = 0, l = 0, r = 0, flag = 0;
  unsigned long long sum = 0;
  while (qCount--)
  {
    scanf ("%u %u %u",&d, &l, &r);
    sum = 0;
    if (d==1)
    {
      if (l==r)
        printf("%lu\n",a[l]);
      else
      {
        flag = 0;
        FOR(i,l,r+1)
        {
          if (flag==0)
          {
            sum+=a[i];
            flag = 1;
          }
          else
          {
            sum+=b[i];
            flag = 0;
          }
        }
          
        printf("%llu\n",sum);
      }
    }
    else
    {
      if (l==r)
        printf("%lu\n",b[r]);
      else
      {
        flag = 0;
        FOR(i,l,r+1)
        {
          if (flag==0)
          {
            sum+=b[i];
            flag = 1;
          }
          else
          {
            sum+=a[i];
            flag = 0;
          }
        }
        printf("%llu\n",sum);
      }

    }
    
  }
  
 
   
}
