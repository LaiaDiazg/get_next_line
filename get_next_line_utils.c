#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l;

	if (size > 0)
	{
		l = 0;
		while (l < (size - 1) && src[l] != '\0')
		{
			dst[l] = src[l];
			l++;
		}
		dst[l] = '\0';
	}
	return (ft_strlen_gnl(src));
}

char *ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		l;

	l = ft_strlen_gnl(s1) + 1;
	str = (char *)malloc((l + ft_strlen_gnl(s2)) * sizeof(char));
	if (str == NULL)
		return (0);
	i = ft_strlcpy(str, s1, l);
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_strchr_gnl(const char *s, int c)
{
    while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}

void ft_bzero_gnl(void *s, size_t n)
{
    size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void *ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*sz;

	sz = malloc(nmemb * size);
	if (!sz)
		return (NULL);
	ft_bzero_gnl(sz, (nmemb * size));
	return (sz);
}

size_t ft_strlen_gnl(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}