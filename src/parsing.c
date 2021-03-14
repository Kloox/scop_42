/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:53:24 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/12 20:12:31 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int						find_occurence(char *buffer, char c, int len)
{
	int					i;

	i = 0;
	while (buffer[i] && i < len)
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void					assign_and_normalize_obj(t_obj_file *obj, \
						t_thread_pars_f *f, t_thread_pars_vt *vt, \
						t_window_mgt **winmgt)
{
	obj->indices = f->f_tab;
	obj->nb_indices = f->nb_indices;
	obj->i_size = f->i_size;
	obj->text_tab = f->text_tab;
	obj->vt_tab = vt->vt_tab;
	obj->vt_size = vt->vt_size;
	(*winmgt)->obj = obj;
	assign_and_split_multiples_uv((*winmgt)->obj);
	(*winmgt)->obj = normalize_vertices((*winmgt)->obj);
	center_vertices((*winmgt)->obj);
	free(vt);
	free(f);
}

int						manage_multithread_parsing(t_window_mgt **winmgt, \
						t_obj_file *obj, char *buffer)
{
	pthread_t			thread_1;
	pthread_t			thread_2;
	t_thread_pars_vt	*vt;
	t_thread_pars_f		*f;

	vt = (t_thread_pars_vt *)ft_memallocexit(sizeof(t_thread_pars_vt));
	vt = (t_thread_pars_vt *)memset(vt, 0, sizeof(t_thread_pars_vt));
	f = (t_thread_pars_f *)ft_memallocexit(sizeof(t_thread_pars_f));
	f = (t_thread_pars_f *)memset(f, 0, sizeof(t_thread_pars_f));
	vt->buffer = buffer;
	f->buffer = buffer;
	if (pthread_create(&thread_1, NULL, (void*)parse_f, f))
		return (1);
	if (pthread_create(&thread_2, NULL, parse_vt, vt))
		return (1);
	if (parse_vertex(obj, buffer))
		return (1);
	pthread_join(thread_1, NULL);
	if (f->error)
		return (1);
	pthread_join(thread_2, NULL);
	if (vt->error)
		return (1);
	assign_and_normalize_obj(obj, f, vt, winmgt);
	return (0);
}

int						parse_obj_file(t_window_mgt **winmgt, char *path)
{
	char				*buffer;
	t_obj_file			*obj;
	time_t				myt;
	time_t				ft;

	myt = time(NULL);
	obj = (t_obj_file *)ft_memallocexit(sizeof(t_obj_file));
	obj = (t_obj_file *)memset(obj, 0, sizeof(t_obj_file));
	buffer = get_string_file(path);
	if (buffer == NULL)
		return (1);
	if (manage_multithread_parsing(winmgt, obj, buffer))
		return (1);
	ft = time(NULL);
	printf("Parsing time (multithreading): %ld secs\n", ft - myt);
	free(buffer);
	return (0);
}
