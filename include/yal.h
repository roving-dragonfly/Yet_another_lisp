/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yal.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 02:23:39 by aalves            #+#    #+#             */
/*   Updated: 2019/11/27 07:29:22 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YAL_H
 #define YAL_H

#include <stdint.h>

/*
**	Dynamic objects
*/

/* Types */
enum {
	e_nil = 0,
	e_unit,
	e_env,
	e_true,
	e_false,
	e_symbol,
	e_cons,
	e_list,
	e_function,
	e_int,
	e_real
};

struct	s_cell
{
    int		type;
	union {
		int64_t			i;
		float			f;
		char			*sym;		//better as a void* ?
		struct s_cell	*car;
	};
	struct s_cell		*cdr;
};
typedef	struct s_cell t_cell;

/*
**	Utils C<=>Lisp
*/
t_cell	*make_cell(t_cell *cell);
t_cell	*cell_cons(t_cell *cell);
t_cell	*cell_list(t_cell *cell);

static t_cell	*nil_c = &(t_cell){e_nil, .i = 0};
static t_cell	*true_c = &(t_cell){e_true, .i = 1};
static t_cell	*false_c = &(t_cell){e_false, .i = 0};
static t_cell	*cons_c(t_cell *cell) &(t_cell){e_cons, .car = cell};


#endif
