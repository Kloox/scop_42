/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_f_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:45:11 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/12 20:16:08 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void					parse_second_three_slash(t_thread_pars_f *f, \
						int *index, char *tmp4)
{
	f->f_tab[(*index) + 3] = f->f_tab[*index];
	f->f_tab[(*index) + 4] = f->f_tab[(*index) + 2];
	f->f_tab[(*index) + 5] = (unsigned int)atoi(tmp4 + 1) - 1;
	f->text_tab[(*index) + 3] = f->text_tab[*index];
	f->text_tab[(*index) + 4] = f->text_tab[(*index) + 2];
	tmp4 = strchr(tmp4, '/');
	f->text_tab[(*index) + 5] = (unsigned int)atoi(tmp4 + 1) - 1;
	*index = *index + 6;
}
