/*
** funcion_list_move.c for function_lsit_move in /home/js/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Mon Apr 28 13:50:00 2014 thibau_j
** Last update Mon Apr 28 16:38:13 2014 thibau_j
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include "list.h"

static void		case_manage_remove(t_list **ptr, t_list *tmp, int data)
{
  if (tmp->next != NULL && tmp->prev != NULL)
    {
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;

    }
  else if (tmp->next == NULL && tmp->prev != NULL)
    {
      tmp->prev->next = tmp->next;
    }
  else if (tmp->next != NULL && tmp->prev == NULL)
    {
      tmp->next->prev = tmp->prev;
      *ptr = tmp->next;
    }
  if (data == 1)
    free(tmp->data);
  free(tmp);
}

void			remove_one(t_list **ptr, int place, int data)
{
  int			i;
  t_list		*tmp;

  i = 1;
  tmp = *ptr;
  while (tmp != NULL && i != place)
    {
      tmp = tmp->next;
      ++i;
    }
  if (tmp != NULL)
    {
      case_manage_remove(ptr, tmp, data);
    }
}

void			insert_one(t_list **ptr, void *data, int place, int da)
{
  t_list		*tmp;
  int			i;

  i = 1;
  tmp = *ptr;
  while (tmp != NULL && i != place)
    {
      ++i;
      tmp = tmp->next;
    }
  if (tmp != NULL)
    {
      if (da == 1)
	free(tmp->data);
      tmp->data = data;
    }
}

void			remove_last(t_list **ptr, int data)
{
  t_list		*tmp;

  tmp = *ptr;
  if (tmp != NULL)
    {
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	}
      tmp->prev->next = NULL;
      if (data == 1)
	free(tmp->data);
      free(tmp);
    }
}
