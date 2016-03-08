#include <stdio.h>
#include <stdlib.h>
long int board[4][4];

long int flag = 1;

void override(int lineTopLeft, int columTopLeft, int lineSpe, int columSpe, int size);


/************************************************************************************
*fuction-override:
*parameter-lineTopLeft:       *parameter-columTopLeft:
*parameter-lineSpe:          *parameter-columSpe:
*parameter-size:
*return:
************************************************************************************/
void override(int lineTopLeft, int columTopLeft, int lineSpe, int columSpe, int size)
{
  if(size == 1) return;

  int s = size / 2;

  //topleft
  if(lineSpe < lineTopLeft + s && columSpe < columTopLeft + s)
  {
    override(lineTopLeft, columTopLeft, lineSpe, columSpe, s);
  }
  else
  {
    flag = flag + 1;
    board[lineTopLeft + s - 1][columTopLeft + s - 1] = flag;
    override(lineTopLeft, columTopLeft, lineTopLeft + s - 1, columTopLeft + s - 1, s);
  }

  //topright
  if(lineSpe < lineTopLeft + s && columSpe >= columTopLeft + s)
  {
    override(lineTopLeft, columTopLeft + s, lineSpe, columSpe, s);
  }
  else
  {
    flag = flag + 1;
    board[lineTopLeft + s - 1][columTopLeft + s] = flag;
    override(lineTopLeft, columTopLeft + s, lineTopLeft + s - 1, columTopLeft + s, s);
  }

  //bottomleft
  if(lineSpe >= lineTopLeft + s && columSpe < columTopLeft + s)
  {
    override(lineTopLeft + s, columTopLeft, lineSpe, columSpe, s);
  }
  else
  {
    flag = flag + 1;
    board[lineTopLeft + s][columTopLeft + s-1] = flag;
    override(lineTopLeft + s, columTopLeft, lineTopLeft + s, columTopLeft + s-1, s);
  }

  //bottomright
  if(lineSpe >= lineTopLeft + s && columSpe >= columTopLeft + s)
  {
    override(lineTopLeft + s, columTopLeft + s, lineSpe, columSpe, s);
  }
  else
  {
    flag = flag + 1;
    board[lineTopLeft + s][columTopLeft + s] = flag;	
    override(lineTopLeft + s, columTopLeft + s, lineTopLeft + s, columTopLeft + s, s);
  }
}

int main(void)
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      board[i][j] = 0;
    }
  }

  board[1][1] = 1;
  override(0, 0, 1, 1, 4);

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      printf("%ld ",board[i][j]);
    }
    printf("\n");
  }
}
