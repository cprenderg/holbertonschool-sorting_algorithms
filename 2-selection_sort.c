#include "sort.h"
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
	int lowest;
	int temp;

	tracker = 0;
	while (tracker < (int)size)
	{
		i = tracker;
		lowest = tracker;
		while (i < (int)size)
		{
			if (array[i] < array[lowest])
			{
				lowest = i;
			}
			i++;
		}
		temp = array[lowest];
		array[lowest] = array[tracker];
		array[tracker] = temp;
		print_array(array, size);
		tracker++;
	}
}
