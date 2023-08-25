#include <stdio.h>
#include <stdlib.h>
void find_mth_max_and_nth_min(int arr[], int size, int M, int N, int *mth_max, int *nth_min) 
{
    // Sorting the array using selection sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if (M > size || N > size || M < 1 || N < 1) {
        // Invalid M or N values
        *mth_max = 0;
        *nth_min = -1;
        return;
    }

    *mth_max = arr[size - M];
    *nth_min = arr[N - 1];
}
void calculate_sum_and_difference(int a, int b, int *sum_result, int *diff_result) 
{
    *sum_result = a + b;
    *diff_result = abs(a - b);
}
int main() 
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
	{
        scanf("%d", &array[i]);
    }
    int M, N;
    printf("Enter the value of M: ");
    scanf("%d", &M);
    printf("Enter the value of N: ");
    scanf("%d", &N);

    int mth_max, nth_min, sum_result, diff_result;

    find_mth_max_and_nth_min(array, size, M, N, &mth_max, &nth_min);
    calculate_sum_and_difference(mth_max, nth_min, &sum_result, &diff_result);

    printf("M-th maximum: %d\n", mth_max);
    printf("N-th minimum: %d\n", nth_min);
    printf("Sum: %d\n", sum_result);
    printf("Difference: %d\n", diff_result);
    return 0;
}
