/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:16:12 by motero            #+#    #+#             */
/*   Updated: 2022/05/13 14:22:21 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbr_words(char const *s, char c)
{
	size_t	nbr_words;

	nbr_words = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			nbr_words++;
		}
	}
	return (nbr_words);
}

static size_t	ft_wlen(char const *s, char c)
{
	size_t	w_len;

	w_len = 0;
	while (*s && *s++ != c)
		w_len++;
	return (w_len);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	nbr_words;
	size_t	w_len;
	size_t	i;

	if (!s)
		return (NULL);
	nbr_words = ft_nbr_words(s, c);
	split = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s && i < nbr_words)
	{
		w_len = 0;
		while (*s == c)
			s++;
		w_len = ft_wlen(s, c);
		split[i] = ft_substr(s, 0, w_len);
		i++;
		s += w_len;
	}
	split[i] = 0;
	return (split);
}

/*int	main()
{
	char	**tabstr;
	int		i;
	tabstr = ft_split("    lorem    ipsum dolor      sit  amet,    ", ' ' );
	i = 0;
	printf("Start : \n");
	if (!tabstr)
		printf("NULL");
	else
	{
		while (tabstr[i])
		{
			printf("|%s| len : %ld \n ", tabstr[i], ft_strlen(tabstr[i]));
			i++;
		}
	}
	return 0;
}*/
