#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int strMatch(const char* str, char* pattern)
{
	int size_str = strlen(str);
	int size_pat = strlen(pattern);
	int i = 0;
	for (i = 0; i <= (size_str - size_pat); i++)//ע��ѭ����������ൽ���λ�ã�����Խ��
	{
		int j = 0;//����pattern�����±�
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
		if (j == size_pat)//���j����pattern�����Ԫ�ظ�����˵���ҵ���
			return i - j;
		//i�±�Ϊ3��ʼ��j���±�Ϊ0��ʼ������ѭ��������pattern���飬����i,j������4
	}
	return -1;
}
int main()
{
	const char* str = "abcabaabcabc";
	char pattern[] = "abaa";
	//"..."�ַ���������const char* ����
	int pos = strMatch(str, pattern);
	printf("%d\n", pos);

	return 0;
}
