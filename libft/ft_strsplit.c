/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:13:42 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:16:20 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
//vasia version


size_t	ft_count_w(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == '\0') ||
			(s[i] != c && s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}


static size_t	word_len(const char *s, size_t i, char c) 
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static	void	ft_free(char ***ret, int nb)
{
	while (nb >= 0)
	{
		ft_memdel((void*)&(*ret[nb]));
		nb--;
	}
	free(*ret);
	*ret = NULL;
}

static char		*ft_word(const char *s, size_t i, char c)
{
	char	*word;
	size_t	wl;
	size_t	j;

	wl = word_len(s, i, c);
	j = 0;
	word = (char *)malloc(sizeof(char) * (wl + 1));
	if (!word)
		return (NULL);
	while (j < wl)
	{
		word[j++] = s[i++];
	}
	word[j] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i[2];
	char	**ret;

	if (!s)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	if (!(ret = (char**)malloc(sizeof(char *) * (ft_count_w(s, c) + 1))))
		return (NULL);
	while (s[i[0]] != '\0')
	{
		(s[i[0]] == c) ? i[0]++ : i[0];
		if (s[i[0]] && s[i[0]] != c)
		{
			ret[i[1]] = ft_word(s, i[0], c);
			if (!(ret[i[1]++]))
			{
				ft_free(&ret, i[1] - 1);
				return (NULL);
			}
			i[0] += (word_len(s, i[0], c));
		}
	}
	ret[i[1]] = NULL;
	return (ret);
}



// static size_t			word_nb(char const *s, char c)
// {
// 	size_t				i;
// 	size_t				count;

// 	i = 0;
// 	count = 0;
// 	while (s[i] != '\0')
// 	{
// 		if ((s[i] != c && s[i + 1] == '\0') ||
// 			(s[i] != c && s[i + 1] == c))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// static size_t			word_len(const char *s, size_t i, char c)
// {
// 	size_t				len;

// 	len = 0;
// 	if ((s[i] != c && s[i]) && (s[i - 1] == c || !s[i - 1]))
// 	{
// 		while (s[i] != c && s[i])
// 		{
// 			i++;
// 			len++;
// 		}
// 	}
// 	return (len);
// }

// static char				*ft_word(const char *s, size_t i, char c)
// {
// 	char				*word;
// 	size_t				wl;
// 	size_t				j;

// 	wl = word_len(s, i, c);
// 	j = 0;
// 	word = (char *)malloc(sizeof(char) * (wl + 1));
// 	if (!word)
// 		return (NULL);
// 	while (j < wl)
// 	{
// 		word[j] = s[i];
// 		j++;
// 		i++;
// 	}
// 	word[j] = '\0';
// 	return (word);
// }

// char					**ft_strsplit(char const *s, char c)
// {
// 	size_t				i;
// 	size_t				nb;
// 	char				**ret;
// 	size_t				wn;

// 	if (!s)
// 		return (NULL);
// 	wn = word_nb(s, c);
// 	i = 0;
// 	nb = 0;
// 	ret = (char**)malloc(sizeof(char *) * (wn + 1));
// 	if (!ret)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		if ((s[i] != c && s[i]) && (s[i - 1] == c || !s[i - 1]))
// 		{
// 			ret[nb] = ft_word(s, i, c);
// 			nb++;
// 		}
// 		i++;
// 	}
// 	ret[nb] = 0;
// 	return (ret);
// }
