#include <stdio.h>
#include <string.h>

char findNthchar(char src[], long long index, long long size)
{
	int len = strlen(src);
	while (1)
	{
		if (index < len)
			return src[index];
		else
		{
			if (index < size)
				size = size / 2;
			else if (index == size)
				index = size - 1, size /= 2;
			else
				index -= (size + 1), size /= 2;
		}
	}
}
int main()
{
	long long index;
	char src[30];
	scanf("%s %lld", src, &index);
	long long len = strlen(src);
	index--;
	while (index > len)
		len *= 2;
	printf("%c\n", findNthchar(src, index, len / 2));
	return 0;
}