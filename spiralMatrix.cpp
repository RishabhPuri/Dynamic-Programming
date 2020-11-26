#include <iostream>
#include <vector>
using namespace std;

#if 0
void printDiagonalSpirally(int arr[7][6], int r, int c)
#else
//void printDiagonalSpirally(int arr[3][3], int r, int c)
//void printDiagonalSpirally(int arr[3][4], int r, int c)
void printDiagonalSpirally(int arr[4][1], int r, int c)
#endif
{
  int i,j,k,l,minRow,minCol, maxRow, maxCol;
  maxRow = r, maxCol = c;
  j=0,i=0;
  
  bool up = true;

  // first half
  for (i=0;j<maxCol&&i<maxRow;i++,j++)
  {
    // up means we always start 
    // from first col (0)
    if (up)
    {
      for (k=0,l=i;k<=j&&l>=0;k++,l--)
        cout << arr[l][k] << " ";
      up = false;
    }
    else
    {
      for (k=j,l=0;k>=0&&l<=i;k--,l++)
        cout << arr[l][k] << " ";
      up = true;
    }
  }

  // calculate minRow, minCol for different cases
 
  if (r>=c)
  {
    minRow = 1;
  } 
  else
  {
    minRow = 0;
  }


  if (r>c)
  {
    minCol = 0;
  }
  else
  {
    minCol = 1;
  }  
  
  for (i=minRow,j=minCol;j<maxCol&&i<maxRow;i++,j++)
  {
    if (up)
    {
      for(l=maxRow-1,k=j;l>=i&&k<maxCol;l--,k++)
        cout << arr[l][k] << " ";
      up = false;
    }
    else
    {
      for(k=maxCol-1,l=i;k>=j&&l<maxRow;k--,l++)
        cout << arr[l][k] << " ";
      up = true;
    }
  }
  
}


int main()
{
#if 0
  int arr[7][6] = {{1,2,3,4,5,6},
                   {7,8,9,10,11,12},
                   {13,14,15,16,17,18},
                   {19,20,21,22,23,24},
                   {25,26,27,28,29,30},
                   {31,32,33,34,35,36},
                   {37,38,39,40,41,42},
                  };

  printDiagonalSpirally(arr, 7, 6);
#else
#if 0
  int arr[3][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}
                    };

  printDiagonalSpirally(arr, 3, 3);

  int arr[3][4] = {{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12}
                    };

  printDiagonalSpirally(arr, 3, 4);

  int arr[1][4] = {{1,2,3,4},
                    };

  printDiagonalSpirally(arr, 3, 4);
#endif

  int arr[4][1] = {{1},{2},{3},{4}};


  printDiagonalSpirally(arr, 4, 1);
#endif
}
