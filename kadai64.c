#include <stdio.h>
#define MAX 1000
#define INF 2000000000

void swap(int* a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubbleSort(int a[], int n){
  int i,j;
  for(i = n-1; i > 0; i--){
    for(j = 0; j < i; j++){
      if(a[j] > a[j+1]){
	swap(&a[j], &a[j+1]);
      }
    }
  }
}

int partition(int a[], int left, int right){
  int res = a[left];
  int idx = left+1;
  int i;
  for(i = left+1; i < right; i++){
    if(a[i] <= res){
      swap(&a[idx], &a[i]);
      idx++;
    }
  }
  swap(&a[left], &a[idx-1]);
  return idx - 1;
}

void quickSort(int a[], int left, int right){
  if(left == right) return;
  int q = partition(a, left, right);
  quickSort(a, left, q);
  quickSort(a, q+1, right);
}

void merge(int a[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i,p,q;
  int b1[n1+1], b2[n2+1];
  for(i = 0; i < n1; i++){
    b1[i] = a[left + i];
  }
  for(i = 0; i < n2; i++){
    b2[i] = a[mid + i];
  }
  b1[n1] = INF;
  b2[n2] = INF;
  p = 0;
  q = 0;
  for(i = 0; i < n1 + n2; i++){
    if(b1[p] < b2[q]){
      a[left + i] = b1[p];
      p++;
    }else{
      a[left + i] = b2[q];
      q++;
    }
  }
}

void mergeSort(int a[], int left, int right){
  if(left + 1 >= right) return;
  int mid = (right + left) / 2;
  mergeSort(a, left, mid);
  mergeSort(a, mid, right);
  merge(a, left, mid, right);
}

int main(){
  FILE* fp;
  int num[MAX];
  int tmp, i;
  int len = 0;
  
  fp = fopen("input.txt", "r");
  if(fp != NULL){
    while(fscanf(fp, "%d", &num[len]) != EOF){
      len++;
    }
  }

  printf("which sort? {0: bubble sort, 1: quick sort, 2: merge sort} \n");
  scanf("%d", &tmp);
  
  if(tmp == 0){
    bubbleSort(num, len);
  }else if(tmp == 1){
    quickSort(num, 0, len);
  }else{
    mergeSort(num, 0,len);    
  }
  
  for(i = 0; i < len; i++){
    printf("%d\n", num[i]);
  }
  
  fclose(fp);
}
