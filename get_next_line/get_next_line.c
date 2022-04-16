# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char    *get_next_line(int fd)
{
    char    *dest = malloc(9999), *buffer = malloc(999);
    int        j = 0, i = read(fd, buffer, 1);
    if (fd < 0 || i < 0)
        return (NULL);
    while (i > 0)
    {
        dest[j++] = buffer[0];
        if (buffer[0] == '\n')
            break ;
        i = read(fd, buffer, 1);
    }
    free(buffer);
    return (dest);
}
