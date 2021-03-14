/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:53:24 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/09 19:03:22 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float				g_zoom = FOV;

int					main(int ac, char **av)
{
	t_window_mgt	*winmgt;
	const int		len = sizeof(t_window_mgt);

	winmgt = (t_window_mgt *)ft_memallocexit(len);
	winmgt = (t_window_mgt *)memset(winmgt, 0, len);
	if (manage_entry(&winmgt, ac, av))
	{
		write_usage();
		free_scop(winmgt);
		return (1);
	}
	init_glfw(&winmgt);
	build_gl_data(&winmgt);
	if (winmgt->ret_code != 0 && clean_glfw(winmgt, "Initialization failed."))
		return (winmgt->ret_code);
	else
	{
		print_keys();
		init_mats(&winmgt, 1);
		glEnable(GL_DEPTH_TEST);
		while (!glfwWindowShouldClose(winmgt->win))
			framecode(&winmgt);
	}
	clean_glfw(winmgt, "Should Close");
	return (0);
}

void				print_keys(void)
{
	printf("\nBasic keys:\n\tEscape: Quit the program.\n");
	printf("\tMouse: Use left click to change cam position.\n");
	printf("\tZQSD & Arrow keys: Move object.\n");
	printf("\tScroll: zoom/unzoom\n");
	printf("Texture & color keys:\n");
	printf("\tt: Activate texture\n");
	printf("\tKP 1 to 3: Set texture map algo: Cubic, spheric, cylindrical\n");
	printf("\tKP 4 to 6: Set color type\n");
	printf("\tKP 7: Use obj vt mapping.\n");
	printf("\tKP 8: flip custom texture.\n");
	printf("\tKP 9: Use custom texture.\n");
	printf("\tk: Use default kitty texture\n");
	printf("Special keys:\n");
	printf("\tKP *: sleep rotation\n");
	printf("\tr: reset cam & object positions.\n");
}

void				framecode(t_window_mgt **winmgt)
{
	glfwGetFramebufferSize((*winmgt)->win,
		&((*winmgt)->width), &((*winmgt)->height));
	glViewport(0, 0, (*winmgt)->width, (*winmgt)->height);
	glClearColor(BG_R, BG_G, BG_B, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	render(winmgt);
	glfwSwapBuffers((*winmgt)->win);
	glfwPollEvents();
	custom_key_hooks(winmgt);
}

void				init_mats(t_window_mgt **winmgt, int mvp)
{
	(*winmgt)->cam.cam_pos = (t_vec3){0.0f, 0.0f, 3.0f};
	(*winmgt)->cam.cam_front = (t_vec3){0.0f, 0.0f, -1.0f};
	(*winmgt)->cam.cam_up = (t_vec3){0.0f, 1.0f, 0.0f};
	(*winmgt)->cam.cam_right = (t_vec3){1.0f, 0.0f, 0.0f};
	(*winmgt)->cam.yaw = -90.0f;
	if (mvp)
	{
		(*winmgt)->ms = (t_matrices *)ft_memallocexit(sizeof(t_matrices));
		(*winmgt)->ms->model = mat4_init(0.0f);
		(*winmgt)->ms->view = mat4_init(0.0f);
		(*winmgt)->ms->projection = mat4_init(0.0f);
	}
}
