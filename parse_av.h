/*
** argument.h for arguments in /home/js/rendu/my_irc/src/client
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Sun Apr 27 18:30:14 2014 thibau_j
** Last update Sun Apr 27 18:31:35 2014 thibau_j
*/

#ifndef ARGUMENT_H
# define ARGUMENT_H

size_t		count_args(char *buffer);
void		dump_arguments(char **av);
char		**get_arguments(int ac, char *buffer);
void		free_arguments(char **av);

#endif /* !ARGUMENT_H */
