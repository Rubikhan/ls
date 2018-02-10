/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:40:19 by smaddux           #+#    #+#             */
/*   Updated: 2018/02/09 19:40:26 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void insrt( t_list **zoast, t_list *temp, char *dname)
{
    t_list *current;
    temp = ft_lstnew(dname, ft_strlen(dname) + 1); //not sure if I need the +1
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
//      if (ft_strcmp(b->d_name, ".") == 0 || ft_strcmp(b->d_name, "..") == 0)
//          ;
//      else if (b->d_name[0] == '.')
//          ;
//      else
//        printf("%s\n", b->d_name);
        stat((const char*)b->d_name, &s);
//      printf("%x\n", s.st_mode);
        if ((s.st_mode & S_IFDIR) == S_IFDIR)
			;
			//          printf("directory?\n");
        if (bool == 0)
        {
            bool = 1;
            zoast = ft_lstnew(b->d_name, ft_strlen(b->d_name));
        }
        else
        {
            insrt(&zoast, temp, (char*)b->d_name);
//          ft_lstadd(&zoast, temp);
        }
    }
	return (zoast);
}

/* void beginparse(int argc, char *argv[]) */
/* { */
/* 	int argcount; */
/* 	argcount = argc - 1; */

	

/* } */

int main(int argc, char *argv[])
{
    
    t_list *zoast;

	
	
	zoast = oprd();

    while (zoast->next)
    {
        printf("%s\n", zoast->content);
        zoast = zoast->next;
    }
    printf("%s\n", zoast->content);

	

    return (26);
}
