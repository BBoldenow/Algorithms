#include <vector>
#include <iostream>

template <typename T> 
void insertionSort(std::vector<T> &arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		T current = arr[i];
		int pos = i;

		while (pos > 0 && current < arr[pos - 1])
		{
			arr[pos] = arr[pos - 1];
			arr[pos - 1] = current;
			--pos;
		}
	}
}
