/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:40:19 by smaddux           #+#    #+#             */
/*   Updated: 2018/02/16 21:57:16 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

//set  value with "x = & S_IFMT" and u can use it later"

void lfiletype(struct stat statbuf)
{
	if (statbuf.st_mode & S_IFREG)
		printf("-");
	else if (statbuf.st_mode & S_IFIFO)
		printf("p");
	else if (statbuf.st_mode & S_IFCHR)
		printf("c");
	else if (statbuf.st_mode & S_IFDIR)
		printf("d");
	else if (statbuf.st_mode & S_IFBLK)
		printf("b");
	else if (statbuf.st_mode & S_IFLNK)
		printf("l");
	else if (statbuf.st_mode & S_IFSOCK)
		printf("s");
	else if (statbuf.st_mode & S_IFWHT)
		printf("w");
	else
		;
}

int filedata(const char *pathname) // call the filedata function with the parameter pathname 
{ 
	struct passwd *retval;
	struct group *retval2;
	char *timestr;
	timestr = ft_strnew(26);
    // Use octarray for determining if permission bits set 
	static short octarray[9] = { 0400, 0200, 0100, 0040, \
								 0020, 0010, 0004, 0002, 0001 };
    static char perms[10] = "rwxrwxrwx";
    struct stat statbuf;
    char descrip[10];
	ft_bzero(descrip, 10); //not sure if necessary; probably tho
    int j;
	j = 0;
    if (stat(pathname, &statbuf) == -1) { 
        fprintf(stderr, "Couldn't stat %s\n", pathname); //fprintf? wtf?
        return (-1);
    }
    while (j < 9) 
	{
		if (statbuf.st_mode & octarray[j]) 
            descrip[j] = perms[j];
        else 
            descrip[j] = '-';
		j++;
    }
    descrip[9] = '\0'; // Make sure we have a string
	lfiletype(statbuf);
    printf("%s  ", descrip); 
	printf("%d ", statbuf.st_nlink);
	retval = getpwuid(statbuf.st_uid);
	retval2 = getgrgid(statbuf.st_gid);
	printf("%s ", retval->pw_name);
	printf(" %s ", retval2->gr_name);
	printf("%lld", statbuf.st_size);
	timestr = ctime((&statbuf.st_atimespec.tv_sec));
	timestr[16] = '\0';
	printf(" %s ", timestr + 4);
//    printf("%s\n", pathname);
    return (0); 
}

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
}

void printit(t_list *stuff, char *path)
{
	char *new;
	new = NULL;
	while (stuff->next)
	{
		new = ft_strdup(path);
		new = ft_strjoin(new, "/");
		new = ft_strjoin(new, (char*)stuff->content);
		filedata(new);
		printf("%s\n", stuff->content);
		stuff = stuff->next;
		free (new);
	}
	new = ft_strdup(path);
	new = ft_strjoin(new, "/");
	new = ft_strjoin(new, (char*)stuff->content);
	filedata(new);
	printf("%s\n\n", stuff->content);
	free (new);
}

void ft_dirwalk(char *dir, void(*f)(char *, char *))
{
	struct dirent *sdp;
	void *hmm;
	int bool;
	t_list *nay;
	t_list *temp;

	nay = NULL;
	temp = NULL;
	bool = 0;
	if ((hmm = opendir(dir)) == NULL)
	{
		return;
	}
	printf("%s:\n", dir);
	while ((sdp = readdir(hmm)) != NULL)
	{
		if (ft_strcmp(sdp->d_name, ".") == 0 || ft_strcmp(sdp->d_name, "..") == 0)
			continue;
		else if(sdp->d_name[0] == '.')
			continue;
		else 
		{
			if (bool == 0)
			{
				bool = 1;
				nay = ft_lstnew(sdp->d_name, ft_strlen(sdp->d_name));
			}
			else
			{
				insrt(&nay, temp, (char*)sdp->d_name);
			}
		}
	}
	closedir(hmm);
	if (bool == 1)
		printit(nay, dir);
	if (bool == 1)
	{
		while (nay->next)
		{
			f(dir, nay->content);
			nay = nay->next;
		}
		f(dir, nay->content);
	}
	else
		printf("\n");
}



int main(int argc, char *argv[])
{
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
	if (sopts->recursion == 1)
	{
		ft_dirwalk(".", rhelper);
	}
    return (26);
}

