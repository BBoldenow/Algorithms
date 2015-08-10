#include <vector>
#include <tuple>
#include <iostream>

template <typename T> std::tuple<bool, T> 
findPeak(std::vector<T> &arr)
{
	auto it_begin = std::begin(arr);
	auto it_end = std::end(arr);
	auto mid_point = (it_end - it_begin) / 2;

	if (mid_point != it_begin && *mid_point < *(mid_point - 1))
	{
		return findPeak(std::vector<T>(it_begin, mid_point));
	}
	else if (it_end != mid_point + 1 && *mid_point < *(mid_point + 1))
	{
		return findPeak(std::vector<T>(mid_point, it_end));
	}
	else
	{
		return std::tuple<bool, T>(true, *mid_point);
	}
}

template <typename T> std::tuple<bool, T>
findPeak_2D(std::vector<std::vector<T>> &arr2D, unsigned start_row, unsigned end_row, unsigned start_col, unsigned end_col)
{
	int col = start_col + (end_col - start_col) / 2;
	int row = findGlobalMax(arr2D, col);

	if (int(start_col) <= (col - 1) && arr2D[row][col] < arr2D[row][col - 1])
	{
		return findPeak_2D(arr2D, start_row, end_row, start_col, col);
	}
	else if (int(end_col) > (col + 1) && arr2D[row][col] < arr2D[row][col + 1])
	{
		return findPeak_2D(arr2D, start_row, end_row, col, end_col);
	}
	else
	{
		return std::tuple<bool, T>(true, arr2D[row][col]);
	}
}

template <typename T> 
unsigned findGlobalMax(std::vector<std::vector<T>> &arr2D, unsigned j)
{
	unsigned retIndex = 0;
	for (int i = 0; i < arr2D.size(); ++i)
	{
		if(arr2D[i][j] > arr2D[retIndex][j])
		{
			retIndex = i;
		}
	}

	return retIndex;
}
