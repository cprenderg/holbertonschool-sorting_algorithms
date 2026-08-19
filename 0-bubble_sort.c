#include "sort.h"
/**
 * bubble_sort - sorts an array in ascending order using bubble sort algorithm
 * @array: pointer to array
 * @size: size of array
 *
 * Return - void
 */
void bubble_sort(int *array, size_t size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < (int)size)
	{
		if (array[i] > array[i + 1] && i + 1 < (int)size)
		{
			j = i;
			while (array[j] > array[j + 1] && j + 1 < (int)size)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				j++;
			}
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
