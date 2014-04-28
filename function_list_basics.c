/*
** list.c for list.c in /home/js/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Mon Apr 28 09:02:44 2014 thibau_j
** Last update Mon Apr 28 16:56:39 2014 thibau_j
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include "list.h"

static void		add_data(t_list **ptr, void *data)
{
  t_list		*new;
  t_list		*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    perror("Malloc : ");
  bzero(new, sizeof(*new));
  new->data = data;
  new->next = NULL;
  if (*ptr == NULL)
    {
      *ptr = new;
    }
  else
    {
      tmp = *ptr;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      new->prev = tmp;
    }
}

/*
** Modify this function as you want for your own output.
*/

static void		dump_list_char(t_list *ptr)
{
  t_list		*tmp;
  int			i;

  tmp = ptr;
  i = 1;
  while (tmp != NULL)
    {
      printf("Maillon n°%d : [%s]\n", i, (char *)tmp->data);
      tmp = tmp->next;
      ++i;
    }
  tmp = ptr;
  while (tmp->next != NULL)
    tmp = tmp->next;
  while (tmp != NULL)
    {
      --i;
      printf("De l'arrière Maillon n°%d : [%s]\n", i, (char *)tmp->data);
      tmp = tmp->prev;
    }
}

static void		free_list(t_list **ptr, int data)
{
  t_list		*tmp;
  t_list		*free_ptr;

  tmp = *ptr;
  while (tmp != NULL)
    {
      free_ptr = tmp;
      tmp = tmp->next;
      if (data == 1)
	free(free_ptr->data);
      free (free_ptr);
    }
}

void			init_fct_ctrl(t_ctrl *fct)
{
  fct->dump_list_char = dump_list_char;
  fct->add_data = add_data;
  fct->free_list = free_list;
  fct->remove_one = remove_one;
  fct->insert_one = insert_one;
  fct->remove_last = remove_last;
  fct->get_list_size = get_list_size;
}

/*
** Exemple de main.
*/

/*int			main(int ac, char **av)
{
  t_list		*list;
  t_ctrl		fct;
  int			i;

  init_fct_ctrl(&fct);
  i = 0;
  list = NULL;
  if (ac < 2)
    {
      printf("./a.out data1 data2 data3 [...]\n");
      return (1);
    }
  while (av[i] != NULL)
    {
      (*(fct.add_data))(&list, av[i]);
      i++;
   }
  (*(fct.dump_list_char))(list);
  (*(insert_one))(&list, "PIPIPIPI", 2, 0);
  (*(remove_last))(&list, 0);
  (*(fct.dump_list_char))(list);
  (*(fct.free_list))(&list, 0);
  printf("%d\n", (int)(*(fct.get_list_size))(list));
  return (1);
  }*/
