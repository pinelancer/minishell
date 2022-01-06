/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:53:53 by gpaeng            #+#    #+#             */
/*   Updated: 2022/01/06 12:49:29 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct Jop {
    char **envp;
}jop;

/*
**utils
*/
size_t ft_strlen(const char *str);
void *ft_memcpy(void *dest, const void *src, size_t n);
char **ft_split(char const *s, char c);
char *ft_strdup(const char *str);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_set_malloc(size_t nmemb, int size);
void    ft_free_arr(char **arr);
int     ft_cnt_arg(char *args[]);
int		ft_isdigit(int c);
int     ft_isalpha(int c);
char	*ft_get_env(char *path_n);

/*
**ft_cd.c
*/
void ft_cd(char *args[]);

/*
**ft_echo.c
*/
void ft_echo(char *args[]);

/*
**ft_env.c
*/
void ft_env(char *args[]);

/*
**ft_exit.c
*/
void    ft_exit(char *args[]);

/*
**ft_export.c
*/
void ft_export(char *args[]);

/*
**ft_pwd.c
*/
void ft_pwd(char *args[]);

/*
**ft_unset.c
*/
void    ft_unset(char *args[]);

#endif