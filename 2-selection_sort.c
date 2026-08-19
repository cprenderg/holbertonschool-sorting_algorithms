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
 * selection_sort - selection sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int i;
	int tracker;
	int min;

	tracker = 0;
	while (tracker < (int)size)
	{
		i = tracker;
		min = tracker;
		while (i < (int)size)
		{
			if (array[i] < array[min])
			{
				min = i;
			}
			i++;
		}
		if (min != tracker)
		{
			arr_swap(tracker, min, array);
			print_array(array, size);
		}
		tracker++;
	}
}
