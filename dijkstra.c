#include <stdio.h>
#include <stdlib.h>

#define N 10000

void dijkstraPaths(int v, int end);
int selecAsSrchd(int *s, int *d, int n);
void PrintPrev(int prev[],int v0,int vn);

int cost[7][7] = {{0,20,50,30,N,N,N},{N,0,25,N,N,70,N},{N,N,0,40,25,50,N},
                    {N,N,N,0,55,N,N},{N,N,N,N,0,10,70},{N,N,N,N,N,0,50},{N,N,N,N,N,N,0}};

int main(void)
{
  dijkstraPaths(0,1);
  dijkstraPaths(0,3);
  dijkstraPaths(0,5);
}

void dijkstraPaths(int v, int end)
{
  //do define
  int isSearched[7];
  //int parent[7];
  int *parent = (int *) malloc(sizeof(int)*7);
  int dist[7];
  //do init
  for(int i = 0; i < 7; i++)
  {
    isSearched[i] = 0;
    parent[i] = v;
    dist[i] = cost[v][i];
  }
  isSearched[v] = 1;
  parent[v] = -1;
  //start search paths
  for(int i = 1; i < 6; i++)
  {
    int u = selecAsSrchd(isSearched, dist, 7);
    isSearched[u] = 1;
    for(int j = 0; j < 7; j++)
    { 
      if(isSearched[j] == 0)
      {
        if(dist[j] > dist[u] + cost[u][j])
        { 
          dist[j] = dist[u] + cost[u][j];
          parent[j] = u;
        }
      }
    }
  }
/*******for test*******************/ 
//  for(int i = 0; i < 7; i++)   /**/
//  {                            /**/
//    printf("%d ", *(parent+i));/**/
//  }                            /**/
//  printf("\n");                /**/
  printf("length of verter-%d to vercter-%d is %d. \n",v+1, end+1, dist[end]);
  PrintPrev(parent, v, end);
  printf("\n");
/********************************/
  free(parent);
}

int selecAsSrchd(int *s, int *d, int n)
{
  int u = N;
  int min = N;
  for(int i = 0; i < n; i++)
  {
    if(s[i] == 0)
    {
      if(d[i] < min)
      {
        min = d[i];
        u = i;
      }
    }
  }
  return u;
}

// 输出最短路径
// 参数：路径前一点记录、出发点的下标、到达点下标
void PrintPrev(int prev[],int v0,int vn)
{
  int tmp = vn;
  int i, j;
  //临时存路径
  int tmpprv[N];
  //初始化数组
  for(i=0; i < N; i++)
    tmpprv[i] = 0;

  //记录到达点下标
  tmpprv[0] = vn+1;
  //中间点用循环记录
  for(i =0, j=1; j < N ;j++)
  {
    if(prev[tmp]!=-1 && tmp!=0)
    {
      tmpprv[i] = prev[tmp]+1;
      tmp = prev[tmp];
      i++;
    }
    else break;
  }

  //输出路径，数组逆向输出
  for(i=N-1; i >= 0; i--)
  {
    if(tmpprv[i] != 0)
    { //排除0元素
      printf("V%d", tmpprv[i]);
      if(i)  //不是最后一个输出符号 
        printf("-->");
    }
  }
  printf("-->V%d", vn+1);
}
/*int getMin(int a, int b)
{ 
  if(a >= b)
  {return b;}
  else {return a;}
}*/
