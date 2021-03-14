/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:45:22 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/14 10:58:57 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void					*parse_vt(void *arg_f)
{
	t_thread_pars_vt	*vt;
	char				*tmp;
	int					index;

	index = 0;
	vt = (t_thread_pars_vt *)arg_f;
	tmp = vt->buffer;
	vt->vt_size = count_vt_occurence(tmp) * 2;
	vt->vt_tab = (float *)ft_memallocexit(sizeof(float) * vt->vt_size);
	while (strlen(tmp) > 1)
	{
		if (tmp[1] == 'v' && tmp[2] == 't' && tmp[3] == ' ')
			parse_uv_values(vt, tmp, &index);
		tmp = strchr(tmp + 1, '\n');
		if (tmp == NULL)
			break ;
	}
	return (NULL);
}

void					parse_uv_values(t_thread_pars_vt *vt, \
						char *str, int *index)
{
	char				*tmp;
	char				*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (str + 1 && str[0] == '\n')
		str++;
	tmp = str + 3;
	vt->vt_tab[(*index)] = atof(tmp);
	tmp2 = strchr(tmp, ' ');
	vt->vt_tab[(*index) + 1] = atof(tmp2 + 1);
	*index += 2;
}

int						count_vt_occurence(char *buffer)
{
	int					count;
	int					i;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'v' && buffer[i + 1] == 't')
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

void					duplicate_vertice(t_obj_file *obj, int v_id, int i)
{
	obj->vertices[obj->v_size] = obj->vertices[(v_id * VERTICE_SIZE)];
	obj->vertices[obj->v_size + 1] = \
	obj->vertices[(v_id * VERTICE_SIZE) + 1];
	obj->vertices[obj->v_size + 2] = \
	obj->vertices[(v_id * VERTICE_SIZE) + 2];
	obj->vertices[obj->v_size + 3] = \
	obj->vertices[(v_id * VERTICE_SIZE) + 3];
	obj->vertices[obj->v_size + 4] = \
	obj->vertices[(v_id * VERTICE_SIZE) + 4];
	obj->vertices[obj->v_size + 5] = \
	obj->vertices[(v_id * VERTICE_SIZE) + 5];
	obj->vertices[obj->v_size + 6] = \
	obj->vt_tab[obj->text_tab[i] * 2];
	obj->vertices[obj->v_size + 7] = \
	obj->vt_tab[obj->text_tab[i] * 2 + 1];
	obj->v_size += VERTICE_SIZE;
	obj->indices[i] = (obj->v_size / 8) - 1;
}

int						assign_and_split_multiples_uv(t_obj_file *obj)
{
	int					i;
	float				u;
	float				v;
	int					v_id;
	int					ind;

	i = 0;
	while ((unsigned int)i < (obj->i_size))
	{
		v_id = obj->indices[i];
		ind = obj->text_tab[i] * 2;
		u = obj->vt_tab[obj->text_tab[i] * 2 > 0 ? ind : 0];
		v = obj->vt_tab[obj->text_tab[i] * 2 + 1];
		if (obj->vertices[(v_id * VERTICE_SIZE) + 6] == 42.0f)
		{
			obj->vertices[(v_id * VERTICE_SIZE) + 6] = u;
			obj->vertices[(v_id * VERTICE_SIZE) + 7] = v;
		}
		else if (obj->vertices[(v_id * VERTICE_SIZE) + 6] != u || \
				obj->vertices[(v_id * VERTICE_SIZE) + 7] != v)
			duplicate_vertice(obj, v_id, i);
		i++;
	}
	return (0);
}
