#include <iostream>

using namespace std;

int partition(int a[], int start, int end)
{
	int small = start;

	for (int i = start; i < end; i++)
	{
		if (a[i] < a[end])
		{
			if (small != i)
			{
				swap(a[small], a[i]);
			}
			small++;
		}
	}
	
	swap(a[small], a[end]);

	return small;
}

void quickSort(int a[], int start, int end)
{
	if (start < end)
	{
		int mid = partition(a, start, end);
		quickSort(a, start, mid - 1);
		quickSort(a, mid + 1, end);
	}
}

void quickSort2(int *a, int size)
{
	int mystack[100000];
	int top = -1;
	mystack[++top] = 0;
	mystack[++top] = size - 1;

	while (top>0)
	{
		int end = mystack[top--];
		int start = mystack[top--];

		int x = a[end];
		int i = start - 1;
		for (int j = start; j < end; j++)
		{
			if (a[j] < x)
			{
				i++;
				swap(a[i], a[j]);
			}
		}
		swap(a[i + 1], a[end]);
		if (start < i)
		{
			mystack[++top] = start;
			mystack[++top] = i;
		}
		if (i + 2 < end)
		{
			mystack[++top] = i + 2;
			mystack[++top] = end;
		}
	}
}


int main()
{
	int a[] = {19, 6, 1, 4, 8,2,3,5,9,7,10,11,15,12,13,14,20,1000};

//	quickSort2(a, sizeof(a) / 4);

	quickSort(a, 0, sizeof(a) / 4-1);

	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}