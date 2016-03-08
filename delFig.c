#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void getMinNumber(char n[240], int k);

void getMinNumber(char n[240], int k)
{
  //long int minNumber = -1;
  int len = strlen(n);
  //printf("len = %d\n", len);
  do
  {
    for(int i = 0; i < len - 1; i++)
    {
      if(n[i] > n[i+1])
      {
        for(int j = i; j < len -1; j++)
        {
          n[j] = n[j+1];
        }
        len--;
        break;
      }
      if((i == len - 2) && (!(n[i] > n[i+1])))
      {
        len--;
      }
    }
    k--;
  }
  while(k > 0); 

  for(int i = 0; i < len; i++)
  {
    printf("%c",n[i]);
  }
}

int main(void)
{
  char n[240];
  //long int minNumber = -1;
  int k = -1;
  printf("Please enter a integer：");
  scanf("%s",n);
  printf("the number of digits to delete : ");
  scanf("%d",&k);
  printf("the result:");
  getMinNumber(n, k);
  printf("\n-the end-\n");  
}
