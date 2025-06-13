#ifndef DEBUG_H
# define DEBUG_H

# define __DEBUG__
# define _u __attribute__((unused))
# define TODO 0

void	*ft_print_memory(void *addr, unsigned int size);
void	*ft_print_memory_fd(int fd, void *addr, unsigned int size);


char	*rot13_decode(char *encoded);

#endif /* DEBUG_H */
