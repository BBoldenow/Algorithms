template <typename T>
void merge(std::vector<T> &vec, std::vector<T> &left, std::vector<T> &right)
{
	// define local variables, including the return vector
	std::vector<T> ret;
	unsigned int l = 0;
	unsigned int r = 0;

	// As long as left and right are smaller than their vectors
	// figure out which value to sort into the return vector
	while (l < left.size() && r < right.size())
	{
		if (left[l] < right[r])
		{
			ret.push_back(left[l]);
			++l;
		}
		else
		{
			ret.push_back(right[r]);
			++r;
		}
	}

	// Make sure that the remaining vector values get added to the return
	while (l < left.size())
	{
		ret.push_back(left[l++]);
	}

	while (r < right.size())
	{
		ret.push_back(right[r++]);
	}

	// Set the original vector to the return vector
	vec = ret;
}

// Merge sort
template <typename T>
void mergeSort(std::vector<T> &vec)
{
	// if there's only a single element, there's nothing to sort
	if (vec.size() == 1)
		return;

	// get the middle of the vector, and construct the left/right vectors
	auto it_beg = std::begin(vec);
	auto it_end = std::end(vec);
	auto it_mid = it_beg + (it_end - it_beg) / 2;
	std::vector<T> left(it_beg, it_mid);
	std::vector<T> right(it_mid + 1, it_end);

	// Recursively call the merge insertion function on the two smaller vectors
	// This will break them down smaller and smaller until they are size one
	mergeSort(left);
	mergeSort(right);

	// Merge the two smaller vectors together
	merge(vec, left, right);
}
