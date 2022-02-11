/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:18:39 by hyeonsok          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/02/10 16:14:56 by gpaeng           ###   ########.fr       */
=======
/*   Updated: 2022/02/11 14:10:37 by hyeonsok         ###   ########.fr       */
>>>>>>> d0c4100a9a1f68d99e757a09b883160ad82f1c32
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

#include <stddef.h>

<<<<<<< HEAD
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int 			ft_strlchr(char *str, int c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(char *str1, char *str2);
char			*ft_strdup(const char *s1);
char			*ft_strndup(char *str, size_t idx);
=======
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strchrspn(char *str, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *s1);
>>>>>>> d0c4100a9a1f68d99e757a09b883160ad82f1c32

#endif /* string.h */
