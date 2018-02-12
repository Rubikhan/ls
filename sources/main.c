/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:40:19 by smaddux           #+#    #+#             */
/*   Updated: 2018/02/12 13:56:45 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void insrt( t_list **zoast, t_list *temp, char *dname)
{
    t_list *current;
    temp = ft_lstnew(dname, ft_strlen(dname) + 1); //not sure if I need the +1 //FREE THIS
    if (ft_strcmp((*zoast)->content, temp->content) > 0)
    {
        temp->next = *zoast;
        *zoast = temp;
    }
    else
    {
        current = *zoast;
        while(current->next != NULL && ft_strcmp(current->next->content, temp->content) < 0)
            current = current->next;
        temp->next = current->next;
        current->next = temp;
    }
}

t_list *oprd (void)
{
    struct dirent *b;
    struct stat s;
    void *a;
	t_list *zoast;
    a = opendir(".");


    if (a == NULL)
    {
        printf("error\n");
        return (NULL);
    }
    int bool = 0;

    t_list *temp;

    temp = NULL;

    while ((b = readdir(a)) != NULL)
    {
        stat((const char*)b->d_name, &s);
        if ((s.st_mode & S_IFMT) == S_IFDIR) //worked too with & S_IFDIR
			;
        if (bool == 0)
        {
            bool = 1;
            zoast = ft_lstnew(b->d_name, ft_strlen(b->d_name));
        }
        else
        {
            insrt(&zoast, temp, (char*)b->d_name);
        }
    }
	closedir(a);
	return (zoast);
}

void printsopts(t_sopts *sopts)
{
	printf("R:%d\n", sopts->recursion);
	printf("r:%d\n", sopts->reverse);
	printf("a:%d\n", sopts->all);
	printf("l:%d\n", sopts->longoutput);
	printf("t:%d\n", sopts->time);
}

void rhelper(char *name, char *another)
{
	struct stat buffer;

	stat((const char*)name, &buffer);
	if ((buffer.st_mode & S_IFMT) == S_IFDIR)
	{
		name = ft_strjoin(name, "/");
		name = ft_strjoin(name, another);
		ft_dirwalk(name, rhelper);
	}
	printf("%s\n", name);
}

void ft_dirwalk(char *dir, void(*f)(char *, char *))
{
	struct dirent *sdp;
	void *hmm;

	if ((hmm = opendir(dir)) == NULL)
	{
		return;
	}
	while ((sdp = readdir(hmm)) != NULL)
	{
		if (ft_strcmp(sdp->d_name, ".") == 0 || ft_strcmp(sdp->d_name, "..") == 0)
			continue;
		else 
		{
			f(dir, sdp->d_name);
		}
	}
	closedir(hmm);
}

int main(int argc, char *argv[])
{
    t_list *zoast;
	t_sopts *sopts;
	int c;

	soptind = 1;
	sopts = malloc(sizeof(t_sopts*) * (2)); //FREE THIS
	sopts = soptszero(sopts);

	while ((c = ft_getopt1(argc, argv, "rltaR")) != -1)
	{
		if (c == '?')
		{
			ft_putstr("ls: illegal option\n");
			ft_putstr("usage: ls [-Ralrt]\n");
			exit(-1);
		}
		else
			sopts = assignsopts(c, sopts);
	}
	printsopts(sopts);
	zoast = oprd();
    while (zoast->next)
    {
        printf("%s\n", zoast->content);
        zoast = zoast->next;
    }
	if (sopts->recursion == 1)
	{
		ft_dirwalk(".", rhelper);
	}
    printf("%s\n", zoast->content);
    return (26);
}
