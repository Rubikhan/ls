/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sopts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 19:10:38 by smaddux           #+#    #+#             */
/*   Updated: 2018/02/10 19:14:43 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static char *soptcursor = NULL; //idk

//#############
char* soptarg;
//############

int ft_getopt2(int argc, char *argv[], char *soptstring)
{
    int soptchar;
    const char*  soptdecl = NULL;

    argc++;
    soptchar = -1; //don't think this is necessary
    if (soptcursor == NULL || *soptcursor == '\0')
        soptcursor = argv[soptind] + 1;
    soptchar = *soptcursor;
    soptdecl = ft_strchr(soptstring, soptchar);
    if (soptdecl)
    {
        ;
    }
    else
        soptchar = '?';
    if (soptcursor == NULL || *++soptcursor == '\0') //?
        ++soptind;
    return (soptchar);
}

int ft_getopt1(int argc, char *argv[], char *soptstring)
{
    int bool;

    bool = 0;
    if (soptind >= argc)
        bool = 1;
    else if (argv[soptind] == NULL)
        bool = 1;
    else if (*argv[soptind] != '-')
        bool = 1;
    else if (ft_strcmp(argv[soptind], "-") == 0)
        bool = 1;
    else if (ft_strcmp(argv[soptind], "--") == 0 && bool == 0)
    {
        ++soptind;
        bool = 1;
    }
    if (bool == 1)
    {
        soptcursor = NULL;
        return (-1);
    }
    return (ft_getopt2(argc, argv, soptstring));
}

t_sopts *assignsopts(int c, t_sopts *sopts)
{
    if (c == 'R')
        sopts->recursion = 1;
    else if (c == 'r')
        sopts->reverse = 1;
    else if (c == 'a')
        sopts->all = 1;
    else if (c == 'l')
        sopts->longoutput = 1;
    else if (c == 't')
        sopts->time = 1;
    return (sopts);
}

t_sopts *soptszero(t_sopts *sopts)
{
    sopts->recursion = 0;
    sopts->reverse = 0;
    sopts->all = 0;
    sopts->longoutput = 0;
    sopts->time = 0;
    return (sopts);
}