/*
** arguments.c for arguments in /home/js/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Tue Apr 29 08:41:14 2014 thibau_j
** Last update Tue Apr 29 08:43:39 2014 thibau_j
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

size_t		count_args(char *buffer)
{
  size_t	nb = 0;
  size_t	i = 0;

  while (buffer[i] != '\0')
  {
    if ((i == 0 || buffer[i - 1] == ' ' || buffer[i - 1] == '\t') &&
        buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != '\n')
      nb++;
    i++;
  }
  return (nb);
}

void		dump_arguments(char **av)
{
  size_t	i;

  i = 0;
  printf("dumping...\n");
  while (av[i])
  {
    printf("%ld: %s\n", i, av[i]);
    ++i;
  }
  printf("end dumping...\n");
}

char		**get_arguments(int ac, char *buffer)
{
  char		**av;
  char		*str;
  char		*tmp;
  size_t	i;

  i = 0;
  str = NULL;
  if (!(tmp = strdup(buffer)))

  if (NULL == (av = malloc(sizeof(*av) * ac)))
    perror("Malloc : ");
  str = strtok(tmp, " \n\t");
  if (!(av[i] = strdup(str)))
    perror("strdup : ");
  while (str)
  {
    ++i;
    str = strtok(NULL, " \n\t");
    if (!str)
      break;
    if (!(av[i] = strdup(str)))
      perror("strdup : ");
  }
  free(tmp);
  return (av);
}

void		free_arguments(char **av)
{
  if (av)
    free(av);
}
