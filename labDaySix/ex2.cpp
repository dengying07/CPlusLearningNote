void selection_sort(int a[], int length)
	{
		for (int count = 0 ; count < length - 1 ; count++)
			swap(a[count],a[minimum_from(a,count,length)]);
	}
	
	int minimum_from(int a[], int position, int length)
	{
		int min_index = position;
	
		for (int count = position + 1 ; count < length ; count ++)
			if (a[count] < a[min_index])
				min_index = count;
	
		return min_index;
	}
	
	void swap(int& first, int& second)
	{
		int temp = first;
		first = second;
		second = temp;
	}
