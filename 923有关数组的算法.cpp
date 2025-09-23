#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//һ ����
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


//�� ����
//��һ��ת��
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
//����������
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


//�� ɾ��
//��һ��ת��
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
//����������
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


//�� ����
//ð������
int main()
{
	int arr[10] = { 1,3,4,2,5,6,9,7,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])//��С��������
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

//��������
int main()
{
	int arr[10] = { 1,3,4,2,5,6,9,7,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0, j = 0,temp = 0;
	for (i = 1; i < sz; i++)
	{
		temp = arr[i];
		j = i - 1;//����ǰһ�����Ƚ�
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;//֮����Ҫ��1����Ϊwhile���˳�ǰ��ִ����һ��j--��ע���������Ҫ����ѭ���ڲ�
	}
	
	for (i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}

//ѡ������
int main()
{
	int arr[10] = { 1,3,4,2,5,6,9,7,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int index = 0;
	for (int i = 0; i < sz - 1; i++)//��ð������һ�£�������n-1��
	{
		index = i;
		for (int j = i + 1; j < sz; j++)//ǰ��������ź��ˣ������У���i+1��sz-1
		{
			if (arr[j] < arr[index])
				index = j;//indexΪ��С���ݵ��±�
		}
		if (index != i)//�±�̫��λ�ã�ʹ��������������е��������ε���
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

//��������
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