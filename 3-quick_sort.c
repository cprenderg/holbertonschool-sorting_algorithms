#include "sort.h"
/**
 * arr_swap - swaps two positions in an array
 * @a: first index
 * @b: second index
 * @arr: pointer to array
 *
 * Return: void
 */
void arr_swap(int a, int b, int *arr)
{
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
/**
 * rquick_sort - recursive helper function for quick sort
 * @array: array to quick sort
 * @size: size of array
 *
 * Return: void
 */
void rquick_sort(size_t size, int *array, int start_index, int pivot_index)
{
	int pivot;
	int i;
	int j;

	if (size < 2)
	{
		return;
	}
	i = start_index;
	j = start_index;
	pivot = pivot_index;
	while (i < pivot)
	{
		if (array[i] < array[pivot])
		{
			if (i != j)
			{
				arr_swap(i, j, array);
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
	if (j != pivot)
	{
		arr_swap(j, pivot, array);
		print_array(array, size);
	}
	if (pivot - j > 1)
	{
		rquick_sort(size, array, j + 1, pivot);
	}
	if (j - 1 > 1)
	{
		rquick_sort(size, array, 0, j - 1);
	}
}
/**
 * quick_sort - quick sorts an array in ascending order
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
	{
		return;
	}
	rquick_sort(size, array, 0, (int)(size - 1));
}

