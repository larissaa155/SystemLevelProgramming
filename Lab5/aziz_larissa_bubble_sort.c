#include <stdio.h>
#define N 10

void swap(int *array, int i, int j);
void bubble_sort(int array[], int n, int *min, int *max); 

int main() {
    int nums[N], smallest, largest; 
     
     for (int i = 0; i < N; i++) {
        printf("%d", &nums[i]);
     }

     bubble_sort(nums, N, &smallest, &largest);

     printf("\n[")
     for (int i = 0; i < N; i++ ) {
       printf("%d, ", nums[i]); 
     }
     printf("%d]\n", nums[N-1]);

     printf("Largest: %d\n", largest);
     printf("Smallest: %d\n", smallest);

     return 0;
}

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void bubble_sort(int array[], int n, int *min, int *max) {
    int i, j;
    for (i = 0; i < n - 1; i++)

    for (j = 0; j < n - 1; j++) 
      if (array[j] > array[j + 1])
        swap(array, j, j + 1);

    *min = array[0];
    *max = array[N - 1];

}