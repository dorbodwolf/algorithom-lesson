#include <stdio.h>
#include <stdlib.h>

void nightTravel(int N);

int board[8][8] = {
{1, 2 , 3, 4, 5, 6, 7, 8},
{9, 10,11,12,13,14,15,16},
{17,18,19,20,21,22,23,24},
{25,26,27,28,29,30,31,32},
{33,34,35,36,37,38,39,40},
{41,42,43,44,45,46,47,48},
{49,50,51,52,53,54,55,56},
{57,58,59,60,61,62,63,64}
};

int main(void)
{
  int start = 0;
  printf("please type the initial point: ");
  scanf("%d", &start);
  nightTravel(start);
}

void nightTravel(int i)
{
  int route[64];
  for(int i = 0; i < 64; i++)
  {
    route[i] = 0;
  }
  
  //printf("the travel route is %d \n", N);
}
