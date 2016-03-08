#include <stdio.h>

typedef struct{
int start;
int end;
//int maxSum; 
}str;

int max(int x,int y);
int refStartIndx(int arr_i, int s, int i, int last_start);
str getMaxSubStr(int* arr, int arrLength);

int main(void)
{
  str s;
  //int array[5] = {-1, 2, 3, -4, 2}; 
  int array[7] = {5, -3, 4, -7, 8, -9, 2}; 
  //int array[6] = {-2, 11, -4, 13, -5, 2}; 
  s = getMaxSubStr(array, sizeof(array)/sizeof(array[0]));
  
  for(int i = s.start; i <= s.end; i++)
  {
    printf("%d ",array[i]);
  }
  printf("\n");
}

/* FUCTION...
   get the max one of two input int number.
*/
int max(int x,int y)
{
  int z;
  if(x>y) z=x;
  else z=y;
  return z;
}


/* FUCTION...
   get the subarray which has the max sum of the input integer array
*/
str getMaxSubStr(int* arr, int arrLength)
{
  //define some tmp vars and init the struct var "str"
  int tmpSum = arr[0];
  int maxSum = arr[0];
  str s;
  s.start = 0;
  s.end = 0;
  
  //THE FOR LOOP: get the max substring
  for(int i = 1; i < arrLength; i++)
  {
    if(arr[i] > tmpSum + arr[i])
    {
      tmpSum = arr[i];
      //s.start = i;
      //s.end = i;
      if(tmpSum > maxSum)
      {
        s.start = i;
        //s.end = i;
      }
    }
    else
    {
      tmpSum = arr[i] + tmpSum;
      //s.end = i;
    }

    //tmpSum = max(arr[i], tmpSum + arr[i]);
    //s.start = refStartIndx(arr[i], tmpSum, i, s.start);
    //s.end = refEndIndx(tmpSum, maxSum, i, s.end);
    
    if(tmpSum > maxSum)
    {
      maxSum = tmpSum;
      s.end = i;
    }


    /*if(tmpSum > maxSum && arr[i] < tmpSum + arr[i])
    {
      //maxSum = tmpSum;
      s.end = i;
    }*/
    //maxSum = max(tmpSum, maxSum);
  }
  //s.maxSum = maxSum;
  return s;
}
