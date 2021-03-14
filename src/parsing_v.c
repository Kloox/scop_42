/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:45:19 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/12 20:24:18 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int				parse_vertex(t_obj_file *obj, char *buffer)
{
	float		*v;
	int			index;
	char		*tmp;

	tmp = buffer;
	index = 0;
	v = ft_memallocexit(count_v_occurence(buffer) * 8 * \
	sizeof(float) * 16);
	while (strlen(tmp) > 1)
	{
		if ((tmp[1] == 'v' && tmp[2] == ' '))
			parse_vertex_entry(v, tmp + 1, &index, obj);
		else if ((tmp[0] == 'v' && tmp[1] == ' '))
			parse_vertex_entry(v, tmp, &index, obj);
		tmp = strchr(tmp + 1, '\n');
		if (tmp == NULL)
			break ;
	}
	obj->vertices = v;
	obj->v_size = index;
	return (0);
}

void			parse_vertex_entry(float *v, char *str, int *index, \
				t_obj_file *obj)
{
	char		*tmp;
	char		*tmp2;
	char		*tmp3;

	tmp = NULL;
	tmp2 = NULL;
	tmp3 = NULL;
	tmp = str + 2;
	v[*index] = atof(tmp);
	if (fabs(v[*index]) > obj->maxs.x)
		obj->maxs.x = fabs(v[*index]);
	tmp2 = strchr(tmp, ' ');
	v[(*index) + 1] = atof(tmp2 + 1);
	if (fabs(v[(*index) + 1]) > obj->maxs.x)
		obj->maxs.x = fabs(v[(*index) + 1]);
	tmp3 = strchr(tmp2 + 1, ' ');
	v[(*index) + 2] = atof(tmp3 + 1);
	if (fabs(v[(*index) + 2]) > obj->maxs.x)
		obj->maxs.x = fabs(v[(*index) + 2]);
	v[(*index) + 3] = VC_R;
	v[(*index) + 4] = VC_G;
	v[(*index) + 5] = VC_B;
	v[(*index) + 6] = 42.0f;
	v[(*index) + 7] = 42.0f;
	*index += 8;
}

int				count_v_occurence(char *buffer)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'v' && buffer[i + 1] == ' ')
			count++;
		i++;
	}
	return (count);
}
