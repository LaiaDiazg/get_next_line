#include "get_next_line.h"

char *ft_free(char *buffer, char *b)
{
    char *temp;

    temp = ft_strjoin_gnl(buffer, b);
    free(buffer);
    return (temp);
}

char *ft_next(char *buffer)
{
    int i;
    int j;
    char *l;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    l = ft_calloc_gnl((ft_strlen_gnl(buffer) - i + 1), sizeof(char));
    i++;
    j = 0;
    while (buffer[i])
        l[j++] = buffer[i++];
    free(buffer);
    return (l);
}

char *ft_line(char *buffer)
{
    int i;
    char *l;

    i = 0;
    if (!buffer[i])
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;

    l = ft_calloc_gnl(i + 2, sizeof(char));
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        l[i] = buffer[i];
        i++;
    }
    if (buffer[i] && buffer[i] == '\n')
        l[i++] = '\n';
    return (l);
}

char *read_file(int fd, char *res)
{
    int byte;
    char *tmpbuffer;

    if (!res)
        res = ft_calloc_gnl(1, 1);
    tmpbuffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
    byte = 1;
    while (byte > 0)
    {
        byte = read(fd, tmpbuffer, BUFFER_SIZE);
        if (byte == -1)
        {
            free(tmpbuffer);
            return (NULL);
        }
        tmpbuffer[byte] = 0;
        res = ft_free(res, tmpbuffer);
        if (ft_strchr_gnl(tmpbuffer, '\n'))
            break;
    }
    free(tmpbuffer);
    return (res);
}

char *get_next_line(int fd)
{
    char *line;
    static char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer = read_file(fd, buffer);
    if (!buffer)
        return (NULL);
    else
    {
        line = ft_line(buffer);
        buffer = ft_next(buffer);
        return (line);
    }
}