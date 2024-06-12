/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:47:24 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/12 01:38:44 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>
# include <float.h>

# define BUFFER_SIZE 1

int		ft_strcmp(char *s1, char *s2);
char	**ohmysplit(char const *s, char c);
int		ft_strlen(char *str);
char	*gnl(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
double	deg2rad(double deg);
double	euclidean_mod(double a, double b);
int		ft_atoi(const char *str);

#endif
