#include "sort.h"


void print_array(const int *array, size_t size)
{
    if (!array || size == 0)
        return;

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    selection_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
