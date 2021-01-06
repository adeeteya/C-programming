#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//hackerrank problem
struct triangle
{
	int a;
	int b;
	int c;
};
typedef struct triangle triangle;

void swap(triangle* tr,float *arr,int a,int b){
  triangle temp;
  float tmpno;
  temp=tr[a];
  tr[a]=tr[b];
  tr[b]=temp;
  tmpno=arr[a];
  arr[a]=arr[b];
  arr[b]=tmpno;
}
int quick_sort(float *arr,int start,int end,triangle* tr){
  if(start>=end){
    return 0;
  }
  int pivot=(start+end)/2,i;
  for(i=0;i<pivot;i++){
    if(arr[i]>arr[pivot]){
      swap(tr,arr,i,pivot);
    }
  }
  return quick_sort(arr,start,pivot,tr)+quick_sort(arr,pivot+1,end,tr);
}
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    int i,j;
    float p,arr[n];
    for(i=0;i<n;i++){
        p=(tr[i].a+tr[i].b+tr[i].c)/2.0;
        arr[i]=sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
    }
    quick_sort(arr,0,n,tr);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
