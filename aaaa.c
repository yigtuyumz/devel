#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// counts consecutive set bits
int longest_consecutive_ones(unsigned int x)
{
	int	ret = 0;
	// for system-independency
	int bit_count = sizeof(unsigned int) * 8;
	// for system-independency
	unsigned int last = 1 << (bit_count - 1);

	for (int i = 0; i < bit_count; i++)
	{
		if ((x & last) == 0)
			ret = 0;
		else
			ret++;
		x <<= 1;
	}

	return (ret);
}

// Counts unique character (printable ASCII) count in a string
int count_unique_chars(const char *str)
{
	size_t a[2] = {0, 0};
	int ret = 0;
	while (*str)
	{
		if (!(a[(((unsigned char) *str) / 64)] >> (((unsigned char) *str) % 64)))
		{
			a[(((unsigned char) *str) / 64)] |= ((size_t) 1) << (((unsigned char) *str) % 64);
			ret++;
		}
		str++;
	}

	return (ret);
}


// char *row1[] = { "hello", "world", NULL };
// char *row2[] = { "42", "istanbul", NULL };
// char **matrix[] = { row1, row2, NULL };

// Calculates character count of a matrix
int count_total_chars(char ***matrix)
{
	// NULL matrix shall fail to prevent UB...
	if (!matrix)
		return (0);
	int tot_len = 0;
	// Each list of matrix, MUST be ended with a NULL pointer...
	// And of course, matrix too..
	while (*matrix)
	{
		while (*(*(matrix)))
		{
			while (*(*(*(matrix))))
			{
				tot_len++;
				*(*(*(matrix)))++;
			}
			(*(*(matrix))++);
		}
		*(matrix++);
	}

	return (tot_len);
}

// ?
int * const volatile restrict * const volatile restrict * volatile restrict p;

int main()
{
	char *row1[] = { "knowledge", "is", "the", "most", "dangerous", "weapon", NULL };	// 33
	char *row2[] = { "less", "is", "more", NULL };										// 10
	char *row3[] = { "I", "shall", "remain", "and", "I", "am", "forever!", NULL };		// 26
	char **matrix[] = { row1, row2, row3, NULL };

	int character_count = count_total_chars(matrix);
	printf("The matrix contains %d printable ASCII character(s).\n", character_count);

	return (0);
}
