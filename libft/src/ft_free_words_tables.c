/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_words_tables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:43:51 by jjaouen           #+#    #+#             */
/*   Updated: 2017/11/22 08:00:25 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_words_tables(char ***tab)
{
	char	**target;
	int		i;

	i = -1;
	target = *tab;
	while (target[++i])
		ft_strdel(&(target[i]));
	free(target);
	target = NULL;
}
