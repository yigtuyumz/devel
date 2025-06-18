#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>

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
// We use __uint128_t in there because ASCII set contains values between from 0 to 128
// Each bit in the datatype, represents whether a encountered or not
int count_unique_chars(const char *str)
{
	__uint128_t a = 0;
	unsigned char ret = 0;
	while (*str)
	{
		if (!((a >> (*str % 128)) & 0x01))
		{
			a |= (((__uint128_t) 1) << (*str % 128));
			ret++;
		}
		str++;
	}
	return ((int) ret);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *) dest + i) = *((unsigned char *) src + i);
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*ret;

	str_len = ft_strlen(s);
	ret = (char *) malloc(sizeof(char) * (str_len + 1));
	if (!ret)
		return (NULL);
	return (ft_memcpy(ret, s, str_len + 1));
}


char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*d;

	d = (const unsigned char *) s;
	while (*d)
	{
		if (*d == (unsigned char) c)
			return ((char *) d);
		d++;
	}
	if (c == 0)
		return ((char *) d);
	return ((char *) 0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (*(src + i) && (i < size - 1))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (ft_strlen(src));
}


char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = (char *) malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}


int main()
{
	char *row1[] = { "knowledge", "is", "the", "most", "dangerous", "weapon", NULL };	// 33
	char *row2[] = { "less", "is", "more", NULL };										// 10
	char *row3[] = { "I", "shall", "remain", "and", "I", "am", "forever!", NULL };		// 26
	char **matrix[] = { row1, row2, row3, NULL };

	int character_count = count_total_chars(matrix);
	printf("The matrix contains %d printable ASCII character(s).\n", character_count);

	char *s = ft_strtrim("jjaaaaaaaaaajsjsjsjsjsjsjsjjjjjsssssssssssss", "js");

	printf("%s\n", s);

	free(s);
	printf("%d\t%d\n", count_unique_chars("asdhgdfhjhw5on#%@#&*&%$#^^rjk;io[iojhmcnbdy394647624dfhdfh8khgygxxx"), _count_unique_chars("asdhgdfhjhw5on#%@#&*&%$#^^rjk;io[iojhmcnbdy394647624dfhdfh8khgygxxx"));
	return (0);
}
