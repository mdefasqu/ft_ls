/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 13:02:15 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 16:53:04 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <uuid/uuid.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/xattr.h>
# include <string.h>
# include <sys/acl.h>
# include <errno.h>

typedef struct			s_infos
{
	char				*name;
	char				*right;
	int					nb_link;
	char				*link;
	char				*user_name;
	char				*group_name;
	unsigned int		nb_bytes;
	time_t				epoch_time;
	char				*date;
	char				*lien_symb;
	char				type;
	char				xattr;
	int					nb_block;
	int					minor;
	int					major;
}						t_infos;

typedef	struct			s_list
{
	t_infos				*infos;
	struct s_list		*next;
	struct s_list		*prev;
	char				*path;
	int					error;
}						t_list;

typedef struct			s_options
{
	unsigned int		a;
	unsigned int		l;
	unsigned int		r;
	unsigned int		t;
	unsigned int		o;
	unsigned int		p;
	unsigned int		r_maj;
	unsigned int		s_maj;
	unsigned int		g;
	unsigned int		nb_arg_real;
	unsigned int		nb_flag;
	unsigned int		del_argv;
	char				*username;
	char				**finish_argv;
}						t_options;

typedef struct			s_check
{
	int					t_nb_link;
	size_t				t_user_name;
	size_t				t_group_name;
	int					t_nb_byte;
	int					if_xattr;
	int					nb_block;
	int					max_major;
	int					max_minor;
	int					if_device;
}						t_check;

t_options				*init_option(void);
t_infos					*init_infos(void);
t_infos					*ft_long_format(char *path, char *name,
							t_options *options);
t_list					*init_list(void);
char					**parsing(t_options *options, char **argv, int argc);
void					ft_parse_error(char c);
t_list					*read_directory(char *path, t_options *options, int i);
void					ft_no_dir_error(char *str);
void					sort_by_order_name(t_list **list);
void					sort_rev(t_list **list);
t_list					*hard_display(t_options *options, char **argv);
void					sort_by_date(t_list **list);
void					sort_by_taille(t_list **list);
void					ft_print_l(t_options *options, t_list *list,
							char *name, int i);
void					ft_print_no_l_r(t_options *options, t_list *list,
							char *name, int i);
t_check					*init_check(void);
t_check					*creat_check(t_list *list);
void					print_blank_int(int i, int y, int z);
void					print_blank_char(size_t i, size_t y);
int						nbr_len(int i);
char					**sort_argv(int i, char **argv, t_options *options);
void					print_blank_int_2(int i, int y, char c, int v);
char					*get_right(mode_t buff);
char					get_type(mode_t buff);
char					*get_user_id(uid_t buff);
char					*get_grp_id(gid_t buff);
int						get_bytes(off_t buff);
int						get_nb_link(nlink_t buff);
time_t					get_epoch_time(time_t buff);
char					*ft_ls_trim(char *str, int start, int end);
char					*get_date(time_t buff);
char					*get_link(char *path);
int						get_nb_blocks(blkcnt_t buff);
char					get_attr(char *path);
static inline __int32_t ft_major(__uint32_t x);
static inline __int32_t ft_minor(__uint32_t x);
int						get_minor(dev_t buff);
int						get_major(dev_t buff);
void					ft_print_l2(t_list *list, t_options *options);
void					ft_print_wr_maj(t_options *options,
							t_list *list, t_list *list_parent, int i);
void					free_list(t_list *list);
char					*get_final_path(char *str);
char					*getusername(char **env);
void					free_options(t_options *options);
int						nbr_len_long(unsigned int i);
void					ft_putnbr_long(unsigned int n);
char					**add_argv(t_options *options, int i);
t_list					*sort_list(t_list *list, t_options *options);
char					**del_one_argv(char **argv, int i);
void					change_color(t_list *list);
void					ft_print_on_wr_maj(t_list *list, t_options *options);
void					ft_print_permission(t_list *list_parent);
void					ft_print_l4(t_list *list, t_check *check,
							t_options *options);
char					getgright(mode_t buff);
char					geturight(mode_t buff);
char					getoright(mode_t buff);
void					ft_print_l_3(t_list *list, t_check *check,
							t_options *options);
void					add_to_list(t_list *list, t_list **prev, t_list **head);
int						type_cmp(char c);
void					sort_by_int_rev(int i, char **finish_argv,
							t_options *options);
void					swap_str(char **s1, char **s2, char **s3);
void					sort_by_int_error(int i, char **finish_argv,
							t_options *options);
void					check_argv_3(t_list *list, char **argv,
							t_options *options, int i);
char					**del_argv_check(t_options *options,
							char **argv, int i);
void					print_argv(char *str);
t_list					*get_info_list(t_list *list, char *str,
							t_options *options);
void					only_print_l_3(t_list *list,
							t_options *options);
char					**perror_check_argv(char **argv,
							int i, t_options *options);
char					**fu_25_lign(char **argv, t_options *options,
							int i, t_list *list);
int						close_dir_lol(int i, DIR *current_dir);

#endif
