/*
** struct.h for struct.h in /home/js/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Mon Apr 28 08:55:55 2014 thibau_j
** Last update Mon Apr 28 16:37:38 2014 thibau_j
*/

/*
** Liste chainé générique by thibau_j.
*/

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef	struct		s_ctrl
{
  void			(*add_data)(t_list **, void *);
  void			(*dump_list_char)(t_list *);
  void			(*free_list)(t_list **, int);
  void			(*remove_one)(t_list **, int, int);
  void			(*insert_one)(t_list **, void *, int place, int da);
  void			(*remove_last)(t_list **, int place);
  size_t		(*get_list_size)(t_list *ptr);
}			t_ctrl;

/*
** The only function you need to call.
*/

void			init_fct_ctrl(t_ctrl *fct);


/*
** Other function you DON'T need to call.
*/

/*
** function_list_move.c
*/

void			remove_one(t_list **, int, int);
void			insert_one(t_list **ptr, void *data, int place,
				   int da);
void			remove_last(t_list **, int data);

/*
** function_list_state.c
*/

size_t			get_list_size(t_list *);

#endif			/* !STRUCT_H_ */
