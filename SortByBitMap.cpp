#include<iostream>
#include<bitset>
#include<time.h>

using namespace std;

bitset<INT_MAX> bit;

void SortByBitSet( int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		bit.set(a[i], 1);
	}
}

int main()
{
	int a[] = { 5, 1, 6, 9, 1000, 300, 4 };

	int start = clock();

	SortByBitSet(a, sizeof(a) / 4);

	cout << clock() - start << endl;

	start = clock();
	// 输出排序结果
	for (int i = 0; i < INT_MAX; i++)
	{
		if (bit[i] == 1)
			cout << i << " ";
	}

	cout << clock() - start << endl;

	return 0;
}