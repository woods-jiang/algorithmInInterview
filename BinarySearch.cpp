#include<iostream>

using namespace std;

template<class elem_t>
int BinarySearch(elem_t a[], int len, elem_t des)
{
	int start = 0;
	int end = len - 1;

	while (start <= end)
	{
		int mid = (start + end) >> 1;

		if (a[mid] == des)
			return mid;
		else if (a[mid] < des)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
}

int main()
{
	char a[] = {'1','2','3'};

	cout << BinarySearch<char>(a, sizeof(a), '2') << endl;

	int b[] = {1, 2, 3};

	cout << BinarySearch<int>(b, sizeof(b)/4, 2) << endl;

	return 0;
}