/*
** function_list_state.c for function_list_state.c in /home/js/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Mon Apr 28 16:31:50 2014 thibau_j
** Last update Mon Apr 28 16:35:33 2014 thibau_j
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include "list.h"

size_t			get_list_size(t_list *ptr)
{
  t_list		*tmp;
  size_t		i;

  i = 0;
  tmp = ptr;
  while (tmp != NULL)
    {
      ++i;
      tmp = tmp->next;
    }
  return (i);
}
