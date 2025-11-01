#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int strMatch(const char* str, char* pattern)
{
	int size_str = strlen(str);
	int size_pat = strlen(pattern);
	int i = 0;
	for (i = 0; i <= (size_str - size_pat); i++)//注意循环条件，最多到这个位置，否则越界
	{
		int j = 0;//用作pattern数组下标
		while (j < size_pat)
		{
			if (str[i] == pattern[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j;
				break;
			}
		}
		if (j == size_pat)//如果j等于pattern数组的元素个数，说明找到了
			return i - j;
		//i下标为3开始，j从下标为0开始，由于循环遍历了pattern数组，所以i,j都增加4
	}
	return -1;
}
int main()
{
	const char* str = "abcabaabcabc";
	char pattern[] = "abaa";
	//"..."字符串常量是const char* 类型
	int pos = strMatch(str, pattern);
	printf("%d\n", pos);

	return 0;
}
