/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 05:44:29 by jjaouen           #+#    #+#             */
/*   Updated: 2020/10/12 20:27:19 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "glmft.h"
# include "libft.h"
# include <stdio.h>
# include <time.h>
# include <math.h>
# include "glad/glad.h"
# include <stdbool.h>
# include <GLFW/glfw3.h>
# include <pthread.h>
# include <assert.h>

/*
** ****************************** Defines *************************************
*/

# define REFRESH_RATE_MIN 24
# define REFRESH_RATE_MAX 240
# define WIDTH_DEFAULT 1920
# define HEIGHT_DEFAULT 1080
# define WIDTH_MIN 320
# define HEIGHT_MIN 240
# define WIDTH_MAX 15360
# define HEIGHT_MAX 8460
# define VERTICE_SIZE 8
# define FOV 45.0f
# define WIN_TITLE "jjaouen - scop"
# define SHADER_PATH "./Contents/Resources/shaders/\0"
# define TEXTURE_PATH "./Contents/Resources/textures/\0"
# define OPENGL_MAJOR_VERSION 4
# define OPENGL_MINOR_VERSION 1
# define HOOK_BIG_DELAY 0.25f
# define ROT_SPEED 0.1f
# define ZOOM_SPEED 0.2f
# define CAM_SPEED 0.075f
# define MOUSE_SENSIVITY 0.000000005f
# define BG_R 0.080f
# define BG_G 0.155f
# define BG_B 0.155f
# define VC_R 0.050f
# define VC_G 0.050f
# define VC_B 0.050f

/*
** ****************************** Globals *************************************
*/

extern float g_zoom;

/*
** ****************************** Structs *************************************
*/

typedef struct		s_matrices
{
	float			**model;
	float			**view;
	float			**projection;
}					t_matrices;

typedef struct		s_cam
{
	t_vec3			cam_pos;
	t_vec3			cam_front;
	t_vec3			cam_right;
	t_vec3			cam_up;
	t_vec3			direction;
	float			lastxpos;
	float			lastypos;
	float			pitch;
	float			yaw;
	bool			first;
	float			angle;
}					t_cam;

typedef struct		s_obj_file
{
	float			*vertices;
	unsigned int	v_size;
	unsigned int	*indices;
	unsigned int	i_size;
	unsigned int	nb_indices;
	float			*vt_tab;
	unsigned int	vt_size;
	unsigned int	*text_tab;
	t_vec3			maxs;
	bool			color;
	bool			texture;
}					t_obj_file;

typedef struct		s_texture_file
{
	unsigned char	*header;
	unsigned char	*data;
	unsigned int	data_pos;
	unsigned int	width;
	unsigned int	height;
	unsigned int	image_size;
}					t_texture_file;

typedef struct		s_state_gl_uint
{
	GLuint			vao;
	GLuint			vbo;
	GLuint			ebo;
	GLuint			shader_program;
	GLuint			vertex_shader;
	GLuint			fragment_shader;
	GLuint			texture;
}					t_state_gl_uint;

typedef struct		s_window_mgt
{
	GLFWwindow		*win;
	t_state_gl_uint	gl_state;
	t_obj_file		*obj;
	t_matrices		*ms;
	t_cam			cam;
	int				major;
	int				minor;
	bool			custom_version;
	int				width;
	int				height;
	int				refresh_rate;
	bool			fullscreen;
	int				ret_code;
	double			delay;
	bool			sleep;
	int				texture_mapping;
	int				color_type;
	char			*text_bind;
	int				flip;
}					t_window_mgt;

typedef struct		s_thread_pars_vt
{
	char			*buffer;
	float			*vt_tab;
	unsigned int	vt_size;
	int				error;
}					t_thread_pars_vt;

typedef struct		s_thread_pars_f
{
	char			*buffer;
	unsigned int	*f_tab;
	int				count_f;
	unsigned int	*text_tab;
	unsigned int	nb_indices;
	unsigned int	i_size;
	int				error;
}					t_thread_pars_f;

typedef struct		s_entry
{
	int		custom_w;
	int		seen_w;
	int		custom_h;
	int		seen_h;
	int		seen_tt;
	int		custom_rr;
	int		seen_rr;
	int		seen_v;
	char	**custom_v;
}					t_entry;

/*
** ****************************** Funcs *************************************
*/

/*
** scop.c
*/
void				print_keys(void);
void				framecode(t_window_mgt **winmgt);
void				init_mats(t_window_mgt **winmgt, int mvp);

/*
** shaders.c
*/
void				build_shaders_vertex(t_window_mgt **winmgt);
void				build_shaders_frag(t_window_mgt **winmgt);
void				build_shaders(t_window_mgt **winmgt);

/*
** build.c
*/
void				build_vaos(void);
void				build_gl_data(t_window_mgt **winmgt);
void				build_texture_parameters(t_window_mgt **winmgt);

/*
** hooks.c
*/
void				custom_key_hooks(t_window_mgt **winmgt);
void				mouse_hook(t_window_mgt **winmgt);
void				mouse_move_cam(t_window_mgt **winmgt, double xpos, \
					double ypos, int state);

/*
** graphic_hooks.c
*/
void				graphics_hook(t_window_mgt **winmgt);
void				graphics_hooks_opt(t_window_mgt **winmgt, double ts);
void				graphics_hooks_text_mapping(t_window_mgt **winmgt, \
					double ts);
void				graphics_hooks_color_mapping(t_window_mgt **winmgt, \
					double ts);
void				graphics_hooks_text_opt(t_window_mgt **winmgt, \
					double ts);

/*
** cam_hooks.c
*/
void				cam_hook(t_window_mgt **winmgt);
void				cam_hooks_ws(t_window_mgt **winmgt, double ts, \
					const float camera_speed);
void				cam_hooks_da(t_window_mgt **winmgt, double ts, \
					const float camera_speed);
void				cam_hooks_up_down(t_window_mgt **winmgt, double ts, \
					const float camera_speed);
void				cam_hooks_right_left(t_window_mgt **winmgt, double ts, \
					const float camera_speed);

/*
** vertices.c
*/
void				center_vertices(t_obj_file *obj);
t_obj_file			*normalize_vertices(t_obj_file *obj);
void				assign_center(t_obj_file *obj, float *vert, t_vec3 center);

/*
** uniforms.c
*/
void				set_uniform_mvp(t_window_mgt **winmgt);
t_texture_file		*get_file_texture(char *name);

/*
** utils_uniforms.c
*/
void				set_uniform_int(GLuint id, char *name, int v);
void				set_uniform_mat4(GLuint id, char *name, float m[][4]);
void				set_uniform_float(GLuint id, char *name, float v);

/*
** parsing.c
*/
int					parse_obj_file(t_window_mgt **winmgt, char *path);
int					find_occurence(char *buffer, char c, int len);
void				assign_and_normalize_obj(t_obj_file *obj, \
					t_thread_pars_f *f, \
					t_thread_pars_vt *vt, t_window_mgt **winmgt);
int					manage_multithread_parsing(t_window_mgt **winmgt, \
					t_obj_file *obj, char *buffer);

/*
** parsing_v.c
*/
int					parse_vertex(t_obj_file *obj, char *buffer);
void				parse_vertex_entry(float *v, char *str, \
					int *index, t_obj_file *obj);
int					count_v_occurence(char *buffer);

/*
** parsing_f_second.c
*/
void				parse_second_three_slash(t_thread_pars_f *f, \
					int *index, char *tmp4);

/*
** parsing_f.c
*/
void				*parse_f(t_thread_pars_f *f);
void				parse_three_slash(t_thread_pars_f *f, char *str,\
					int *index, char *endline);
void				parse_no_slash(t_thread_pars_f *f, char *str, \
					int *index, char *endline);
int					count_f_occurence(char *buffer, char c);
void				alloc_and_parse(t_thread_pars_f *f, char *tmp, \
					int *index);

/*
** parsing_vt.c
*/
void				*parse_vt(void *arg_f);
void				parse_uv_values(t_thread_pars_vt *vt, char *str, \
					int *index);
int					count_vt_occurence(char *buffer);
int					assign_and_split_multiples_uv(t_obj_file *obj);
void				duplicate_vertice(t_obj_file *obj, int v_id, int i);

/*
** utils_entry.c
*/
int					do_res_width(t_entry *state, char **av, int *i);
int					do_res_height(t_entry *state, char **av, int *i);
int					do_refresh_rate(t_entry *state, char **av, int *i);
int					do_texture(t_window_mgt **winmgt, t_entry *state, \
					char **av, int *i);
int					version_is_valid(t_window_mgt **winmgt);

/*
** entry.c
*/
int					manage_entry(t_window_mgt **winmgt, int ac,\
					char **av);
int					parse_file(t_window_mgt **winmgt, char **av, int *i);
int					parse_entry(t_window_mgt **winmgt, \
					t_entry *state, char **av, int *i);
int					do_version(t_window_mgt **winmgt, t_entry *state, \
					char **av, int *i);
int					free_state(t_entry *state);

/*
** render.c
*/
void				render(t_window_mgt **winmgt);
void				pass_uniforms(t_window_mgt **winmgt, float time);
void				compute_mvp_mats(t_window_mgt **winmgt, t_vec3 vadd);

/*
** file.c
*/
bool				is_valid_file(char *path);
char				*get_path(char *name);
char				*get_shader(t_window_mgt **winmgt, char *name);
char				*get_string_file(char *path);
void				edit_shaders_version(t_window_mgt **winmgt, \
					char *shader_text);

/*
** utils.c
*/
void				write_usage(void);
void				free_scop(t_window_mgt *winmgt);
int					random_int(int min, int max);
t_vec3				get_front(t_window_mgt **winmgt);

/*
** utils_glfw.c
*/
int					clean_glfw(t_window_mgt *winmgt, char *reason);
void				init_window_hints(t_window_mgt **winmgt);
void				init_glfw(t_window_mgt **winmgt);
int					set_texture(char *name);

/*
** callbacks.c
*/
void				error_callback(int code, const char *description);
void				scroll_callback(GLFWwindow *window, double xoffset, \
					double yoffset);

#endif
