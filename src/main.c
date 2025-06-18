#include "debug.h"
#include "libft.h"
#include "json.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/auxv.h>
#include <elf.h>
#include <iso646.h>
#include <string.h>

void print(void *c)
{
	printf("%s\n", (char *) c);
}

void *low(void *c)
{
	char *s = ft_strdup((char *) c);
	char *curr = s;

	while (*curr)
	{
		if (islower(*curr))
			*curr -= 32;
		curr++;
	}

	return (s);
}

// void (*f)(void *))

void mystrlen(void *s)
{

}


int main(int argc _u, char *argv[] _u)
{
	// {node: "one"}->{node: "two"}->{node: "three"}->{node: "four"}->{node: "five"}->(null)>


	t_list *lst = ft_lstnew(ft_strdup("one"));
	t_list *new = ft_lstnew(ft_strdup("two"));
	t_list *new1 = ft_lstnew(ft_strdup("three"));
	t_list *new2 = ft_lstnew(ft_strdup("four"));
	t_list *new3 = ft_lstnew(ft_strdup("five"));
	
	ft_lstadd_back(&lst, new);
	ft_lstadd_back(&lst, new1);
	ft_lstadd_back(&lst, new2);
	ft_lstadd_back(&lst, new3);


	t_list *copy = ft_lstmap(lst, mystrlen, free);


	ft_lstclear(&copy, NULL);
	ft_lstclear(&lst, free);
	return (0);
}
