#include <stdio.h>
#include <stdlib.h>

int inverseNum = 0;
 int b[100];
int main(void)
{
    int testArr1[5] = {5,4,3,2,1};
    int testArr2[8] = {5,7,9,22,1,15,56,4};
    int testArr3[10] = {5,17,9,2,12,59,56,4,23,89};
    //int resultNum[3] = {0,0,0};
    /*resultNum[0] = */merge_sort(testArr1, 0, 4); 
       printf("the inverseNum of test array 1 is %d.\n", inverseNum);
      inverseNum = 0;
    /*resultNum[1] = */merge_sort(testArr2, 0, 7);  
     printf("the inverseNum of test array 2 is %d.\n", inverseNum);
      inverseNum = 0;
    /*resultNum[2] = */merge_sort(testArr3, 0, 9);
     printf("the inverseNum of test array 3 is %d.\n", inverseNum);

   // for(int i = 0; i < 3; i++ )
    //{
       // printf("the inverseNum of test array %d is %d.\n", i + 1, resultNum[i]);
    //}    	
}

void merge(int a[], int start, int mid, int end)
{
     //int n1 = mid - start + 1;
     //int n2 = end - mid;
     //int left[n1], right[n2];
     int i, j, k,m;
    
//     int inverseNum = 0;
     //for (i = 0; i < n1; i++) /* left holds a[start..mid] */
       //  left[i] = a[start+i];
     //for (j = 0; j < n2; j++) /* right holds a[mid+1..end] */
       //  right[j] = a[mid+1+j];
 
     i = start;
     j = mid + 1;
     k = start;
     while (i <= mid && j <= end)
     {
         if (a[i] <= a[j])
             {b[k] = a[i]; i = i + 1;}
         else
             {
                  inverseNum += mid - i +1 ;
                 b[k] = a[j]; j = j + 1;
                
             }
          k = k + 1;
      }
     //while (i < n1) /* left[] is not exhausted */
       //  a[k++] = left[i++];
     //while (j < n2) /* right[] is not exhausted */
      //  a[k++] = right[j++];
     if(i > mid)
     {     
         for(m = j; m <= end; m++)
         {
             b[k] = a[m]; k = k + 1;
         }
     }
     else
     {
         for(m = i; m <= mid; m++)
         {
             b[k] = a[m]; k = k + 1;
         } 
     }
     for(m = start; m <= end; m++)
     {
         a[m] = b[m];
     }     
}

void merge_sort(int a[], int start, int end)
{
     int mid;
     //int inverseNum = 0;
     if (start < end)
     {
         mid = (start + end) / 2;
 
         // 分解 + 解决：Divide + Conquer
         merge_sort(a, start, mid); // 递归划分原数组左半边array[start...mid]
         merge_sort(a, mid+1, end); // 递归划分array[mid+1...end]
         // 合并：Combine
         merge(a, start, mid, end); // 合并

     }
    // return inverseNum; 
}
