/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 22:51:21 by smaddux           #+#    #+#             */
/*   Updated: 2018/02/27 15:22:25 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct		s_sopts
{
	int	recursion;
	int reverse;
	int all;
	int longoutput;
	int time;
}					t_sopts;

/* typedef struct		s_curr */
/* { */
/* 	char *mpath; */
/* 	char *mname; */
/* 	struct stat mstatbuf; */
/* 	char mfiletype; */
/* 	char *mperms; */
/* 	struct s_curr	*mdirs; */
/* 	struct s_curr	*mfiles; */
/* 	int	mid; */
/* 	struct s_curr	*next; */
/* }					t_curr; */



int	ft_getopt1(int argc, char *argv[], char *soptstring);
int ft_getopt2(int argc, char *argv[], char *soptstring);
t_sopts *assignsopts(int c, t_sopts *sopts);
t_sopts *soptszero(t_sopts *sopts);
void rhelper(char *name, char *another);
void ft_dirwalk(char *dir, void(*f)(char *, char *));

int soptind;

# endif