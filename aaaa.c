#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void	ft_puthexa(unsigned long int nb, unsigned char addrlen)
{
	unsigned char	temp;
	unsigned char	iterator;

	iterator = 0x00;
	while (iterator++ < addrlen)
	{
		temp = ((nb >> ((addrlen * 0x08) - (iterator * 0x08))) & 0xF0) >> 0x04;
		if (temp >= 0x0A)
			temp = 0x61 + (temp % 0x0A);
		else
			temp += 0x30;
		write(STDOUT_FILENO, &temp, 0x01);
		temp = (nb >> ((addrlen * 0x08) - (iterator * 0x08))) & 0x0F;
		if (temp >= 0x0A)
			temp = 0x61 + (temp % 0x0A);
		else
			temp += 0x30;
		write(STDOUT_FILENO, &temp, 0x01);
	}
	if (addrlen == 0x08)
		write(STDOUT_FILENO, ":", 0x01);
}

static void	ft_putascii(char c)
{
	if (c >= 0x20 && c <= 0x7E)
		write(STDOUT_FILENO, &c, 0x01);
	else
		write(STDOUT_FILENO, ".", 0x01);
}

static void	ft_hexaloop(void *addr, unsigned int *iter, unsigned int size)
{
	unsigned int	iternext;

	iternext = *iter + 0x10;
	while (*iter < iternext)
	{
		if (*iter % 0x02 == 0x00)
			write(0x01, " ", 0x01);
		if (*iter < size)
			ft_puthexa(((char *) addr)[*iter], 0x01);
		else
			write(STDOUT_FILENO, "  ", 0x02);
		*iter += 0x01;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	iter;
	unsigned int	iternext;

	if (!addr)
		return ((void *) 0x00);
	iter = 0x00;
	while (iter < size)
	{
		iternext = iter + 0x10;
		if (iter % 0x10 == 0x00)
		{
			ft_puthexa((unsigned long int) &((char *) addr)[iter], 0x08);
			ft_hexaloop(addr, &iter, size);
			write(STDOUT_FILENO, " ", 0x01);
			iter -= 0x10;
			while ((iter < iternext) && (iter < size))
				ft_putascii(((char *) addr)[iter++]);
			write(STDOUT_FILENO, "\n", 0x01);
		}
	}
	return (addr);
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



static int	ft_isoverlap(void *a, void *b, size_t n)
{
	printf("a:    %p\tb:   %p\n", a, b);
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				diff;

	p1 = (const unsigned char *) a;
	p2 = (const unsigned char *) b;
	if (p1 > p2)
		diff = p1 - p2;
	else
		diff = p2 - p1;
	return (diff < n);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	printf("d:    %p\ts:   %p\n", d, s);
	if (d == s || n == 0)
		return (dest);
	if (!ft_isoverlap(dest, (void *) src, n)) {
		printf("no overlap.\n");
		return (ft_memcpy(dest, src, n));
	}
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
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

// There are 95 printable characters but a char type can hold 256 different value
// We need 256 bits for memoization, but thanks to your restrictions, there is no valid
// built-in C data type can hold 256 bits of information.
// For that fact, I define 4 separate 64 bit variables
// And divide incoming byte by its decimal value to assign properly
// And ofc, this code assumes the sizeof size_t is 8 bytes.

// GPT confuses, haha, it's meaningless to have to work with a retarted AI...
// Now we shaped our challenge into this: the range of *str is limited to 0-127 (inclusive)
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

int fixed_strlen(const char *str)
{
	// Are you serious??
	if (!str)
		return (0);
	int len = 0;
	while (*str++)
		len++;
	return len;
}

char *row1[] = { "hello", "world", NULL };
char *row2[] = { "42", "istanbul", NULL };
char **m[] = { row1, row2, NULL };


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

int * const volatile restrict * const volatile restrict * volatile restrict p;

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
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

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*(s + i))
	{
		f(i, (s + i));
		i++;
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *) s + i) = (unsigned char) c;
		i++;
	}
	return ((void *) s);
}


void funcsss(unsigned int i, char *a)
{
	if (islower(*a))
		*a -= 32;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
		*(ret + i++) = *(s1++);
	while (*s2)
		*(ret + i++) = *(s2++);
	*(ret + i) = 0;
	return (ret);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		n = n % 10;
	}
	if (n < 10)
		write(fd, "0123456789" + n, 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	while (n--)
	{
		if (*a != *b || *a == '\0' || *b == '\0')
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}

int	_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (*(s1 + i) || *(s2 + i)))
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len && *(s + start + i))
	{
		*(ret + i) = *(s + start + i);
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}

char *_ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i;
    char *str;
    
    /* we first check that the string we received is not null
     * if it's the case we return NULL as we won't be able to take
     * a substring out of something empty
     */
    if (!s)
        return (NULL);
    /* if the start index is greater than the length of the original 
     * string we return an allocated empty string that can be freed
     * later on
     */
    if (start > ft_strlen(s))
        return (ft_strdup(""));
    /* if the len we have to copy is greater than the length of the string
     * starting at index start, that means we have to stop after we read
     * the whole string and that the allocated size has not to be 
     * equal to the len received as parameter but only the size we will
     * copy plus one for the NUL-terminating character
     * this let's us only allocate memory that is really necessary
     */
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    /* we then allocate the memory
    */
    str = calloc(len + 1, sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    /* we then loop over the string received as parameter from index
     * start + i and copy each character into our new string index i
     */
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    /* we finally return the substring
     */
    return (str);
}
int main()
{
	char *s = _ft_substr("selam", 0, 0);

	printf("%s\n", s);

	free(s);
	return (0);
}
