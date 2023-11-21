/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:22:19 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/17 14:22:06 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* -------------------------------------------------------------------------- */
/*  Compte le nombre de mots dans une chaîne en utilisant le separateur.      */
/* -------------------------------------------------------------------------- */
static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

/* -------------------------------------------------------------------------- */
/*  Récupère le prochain mot dans une chaîne en utilisant le separateur.      */
/*  Retourne le mot alloué dynamiquement.                                     */
/* -------------------------------------------------------------------------- */
static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

/* -------------------------------------------------------------------------- */
/*  Découpe la chaine de caracteres en tableau de mots alloués malloc         */
/*  en fonction du séparateur (dans notre cas, un espace).                    */
/* -------------------------------------------------------------------------- */
char	**ft_split(char *str, char c)
{
	int		words_count;
	char	**dest;
	int		i;

	i = 0;
	words_count = count_words(str, c);
	if (!words_count)
		exit(1);
	dest = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!dest)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			dest[i] = malloc(sizeof(char));
			if (!dest[i])
				return (NULL);
			dest[i++][0] = '\0';
			continue ;
		}
		dest[i++] = get_next_word(str, c);
	}
	dest[i] = NULL;
	return (dest);
}

/* -------------------------------------------------------------------------- */
/*  Libère la mémoire allouée lors du Parse des arguments quand argc == 2     */
/* -------------------------------------------------------------------------- */
void	free_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}
