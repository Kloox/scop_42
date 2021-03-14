/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:45:11 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/12 20:15:40 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char					*alloc_parser(t_thread_pars_f *f, int *count_slash, \
						int *index)
{
	*index = 0;
	*count_slash = 0;
	f->count_f = count_f_occurence(f->buffer, 'f');
	if (f->count_f == 0)
	{
		f->error = 1;
		return (NULL);
	}
	f->f_tab = (unsigned int *)
		ft_memallocexit(sizeof(unsigned int) * f->count_f * 3 * 2);
	f->text_tab = (unsigned int *)
		ft_memallocexit(sizeof(unsigned int) * f->count_f * 3 * 2);
	f->f_tab = (unsigned int *)
		memset(f->f_tab, 0, sizeof(unsigned int) * f->count_f * 3 * 2);
	f->text_tab = (unsigned int *)
		memset(f->text_tab, 0, sizeof(unsigned int) * f->count_f * 3 * 2);
	return (f->buffer);
}

void					*parse_f(t_thread_pars_f *f)
{
	int					count_slash;
	char				*tmp;
	int					index;
	char				*tmp2;

	if ((tmp = alloc_parser(f, &count_slash, &index)) == NULL)
		return (NULL);
	while (strlen(tmp) > 1)
	{
		if (tmp[1] == 'f' && tmp[2] == ' ')
		{
			tmp2 = strchr(tmp + 1, '\n');
			if (index == 0)
				count_slash = find_occurence(tmp2, '/', 10);
			count_slash == 0 ? parse_no_slash(f, tmp + 1, &index, tmp2) :
			parse_three_slash(f, tmp + 1, &index, tmp2);
		}
		tmp = strchr(tmp + 1, '\n');
		if (tmp == NULL)
			break ;
	}
	f->nb_indices = (unsigned int)(index / 3);
	f->i_size = index;
	return (NULL);
}

void					parse_no_slash(t_thread_pars_f *f, char *str,
						int *index, char *endline)
{
	char				*tmp2;
	char				*tmp3;
	char				*tmp4;

	f->f_tab[*index] = (unsigned int)atoi(str + 2) - 1;
	tmp2 = strchr(str + 2, ' ');
	f->f_tab[(*index) + 1] = (unsigned int)atoi(tmp2 + 1) - 1;
	tmp3 = strchr(tmp2 + 1, ' ');
	f->f_tab[(*index) + 2] = (unsigned int)atoi(tmp3 + 1) - 1;
	tmp4 = strchr(tmp3 + 1, ' ');
	if (tmp4 == NULL || tmp4 > endline || (tmp4[0] == ' ' && tmp4[1] == '\n'))
	{
		*index = *index + 3;
		return ;
	}
	f->f_tab[(*index) + 3] = f->f_tab[*index];
	f->f_tab[(*index) + 4] = f->f_tab[(*index) + 2];
	f->f_tab[(*index) + 5] = (unsigned int)atoi(tmp4 + 1) - 1;
	*index = *index + 6;
}

void					parse_three_slash(t_thread_pars_f *f, char *str,
						int *index, char *endline)
{
	char				*tmp2;
	char				*tmp3;
	char				*tmp4;

	f->f_tab[*index] = (unsigned int)atoi(str + 2) - 1;
	tmp2 = strchr(str + 2, ' ');
	f->f_tab[(*index) + 1] = (unsigned int)atoi(tmp2 + 1) - 1;
	tmp3 = strchr(tmp2 + 1, ' ');
	f->f_tab[(*index) + 2] = (unsigned int)atoi(tmp3 + 1) - 1;
	tmp4 = strchr(tmp3 + 1, ' ');
	str = strchr(str, '/');
	f->text_tab[*index] = (unsigned int)atoi(str + 1) - 1;
	tmp2 = strchr(tmp2, '/');
	f->text_tab[(*index) + 1] = (unsigned int)atoi(tmp2 + 1) - 1;
	tmp3 = strchr(tmp3, '/');
	f->text_tab[(*index) + 2] = (unsigned int)atoi(tmp3 + 1) - 1;
	if (tmp4 == NULL || tmp4 > endline || (tmp4[0] == ' ' && tmp4[1] == '\n'))
	{
		*index = *index + 3;
		return ;
	}
	parse_second_three_slash(f, index, tmp4);
}

int						count_f_occurence(char *buffer, char c)
{
	int					i;
	int					count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			count++;
		i++;
	}
	return (count);
}
