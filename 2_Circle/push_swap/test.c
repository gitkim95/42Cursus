#include "push_swap.h"
#include <stdio.h>
#include <limits.h>


int	find_max_val(int *list, int size)
{
	int	idx;
	int	ret;
	int	max_val;

	max_val = INT_MIN;
	idx = 0;
	while (idx < size)
	{
		if (list[idx] > max_val)
		{
			max_val = list[idx];
			ret = idx;
		}	
		idx++;
	}
	list[ret] = INT_MAX;
	return (ret);
}

int	find_min_val(int *list, int size)
{
	int	idx;
	int	ret;
	int	min_val;

	min_val = INT_MAX;
	idx = 0;
	while (idx < size)
	{
		if (list[idx] < min_val)
		{
			min_val = list[idx];
			ret = idx;
		}	
		idx++;
	}
	list[ret] = INT_MAX;
	return (ret);
}

int	*indexing_list(int *list, int size)
{
	int	*new_list;
	int	idx;
	int	freq;

	new_list = (int *)malloc(sizeof(int) * size);
	if (!new_list)
		return (NULL);
	freq = 0;
	idx = find_max_val(list, size);
	new_list[idx] = size - 1;
	while (freq < size - 1)
	{
		idx = find_min_val(list, size);
		new_list[idx] = freq;
		freq++;
	}
	return (new_list);
}

int main(){

	int *a;
	int b[5] = {9, 10, 99, 2, 1};

	a = indexing_list(b, 5);
	int i = 0;
	while (i < 5)
	{
		printf("%d\n", b[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		printf("%d\n", a[i]);
		i++;
	}
	return (0);
}