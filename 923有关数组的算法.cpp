#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//一 搜索
int search(int* arr, int sz, int key)
{
	for (int i = 0; i < sz; i++)
	{
		if (key == arr[i])
			return i;

	}
	return -1;
}
int main()
{
	int arr[10];
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		cin >> arr[i];
	}
	int key = 0;
	cin >> key;
	int ret = search(arr, sz, key);
	cout << ret;

	return 0;
}


//二 插入
//法一：转移
#define MAX 6
int main()
{
	int arr[MAX] = { 1,3,4,6,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int num_insert = 0, pos = 0;
	cin >> num_insert>>pos;
	for (int i = sz; i > pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = num_insert;
	sz = sz + 1;

	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << " " << endl;
	}

	return 0;
}
//法二：复制
int main()
{
	int a[4] = { 1,3,4,5 };
	int b[5];
	int index = 0, insert = 0, i = 0;
	cin >> index >> insert;
	for (i = 0; i < 5; i++)
	{
		if (i < index)
			b[i] = a[i];
		else if (i == index)
			b[i] = insert;
		else
			b[i] = a[i - 1];
	}
	
	return 0;
}


//三 删除
//法一：转移
int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int index;
	cin >> index;
	for (int i = index; i < sz-1; i++)
		arr[i] = arr[i + 1];
	sz = sz - 1;

	return 0;
}
//法二：复制
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int b[4];
	int index = 0;
	cin >> index;
	for (int i = 0; i < 4; i++)
	{
		if (i < index)
			b[i] = a[i];
		else
			b[i] = a[i + 1];

	}

	return 0;
}


//四 排序
//冒泡排序
int main()
{
	int arr[10] = { 1,3,4,2,5,6,9,7,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])//从小到大排序
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}

	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}

//插入排序
int main()
{
	int arr[10] = { 1,3,4,2,5,6,9,7,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0, j = 0,temp = 0;
	for (i = 1; i < sz; i++)
	{
		temp = arr[i];
		j = i - 1;//与他前一个数比较
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;//之所以要加1是因为while在退出前又执行了一次j--，注意这条语句要放在循环内部
	}
	
	for (i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}

//选择排序
int main()
{
	int arr[10] = { 1,3,4,2,5,6,9,7,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int index = 0;
	for (int i = 0; i < sz - 1; i++)//与冒泡排序一致，共进行n-1轮
	{
		index = i;
		for (int j = i + 1; j < sz; j++)//前面的数据排好了，向后进行，从i+1到sz-1
		{
			if (arr[j] < arr[index])
				index = j;//index为最小数据的下标
		}
		if (index != i)//下表不太换位置，使数组从左至右排列的数据依次递增
		{
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}


	return 0;
}

//快速排序
void quick_sort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int i = left;
	int j = right;
	int mid = (left + right) / 2;
	int p = arr[mid];
	while (i <= j)
	{
		while (arr[i] < p)
			i++;
		while (arr[j] > p)
			j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort(arr, left, j);
	if (right > i)
		quick_sort(arr, i, right);
}
int main()
{
	int arr[10] = { 1,3,4,2,5,6,9,7,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	quick_sort(arr, left, right);

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}