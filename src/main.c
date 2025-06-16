#include "debug.h"
#include "libft.h"
#include "json.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/auxv.h>
#include <elf.h>
#include <iso646.h>

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

int main(int argc _u, char *argv[] _u)
{
	t_list	*head;
	t_list	*new_head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;

	head = ft_lstnew("head node, id: 0");
	node1 = ft_lstnew("first node, id: 1");
	node2 = ft_lstnew("second node, id: 2");
	node3 = ft_lstnew("third node, id: 3");
	node4 = ft_lstnew("tail node, id: 4");
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	ft_lstadd_back(&head, node4);

	new_head = ft_lstmap(head, low, NULL);

	ft_lstiter(head, print);
	ft_lstiter(new_head, print);


	ft_lstclear(&head, NULL);
	ft_lstclear(&new_head, free);
	return (0);
}
