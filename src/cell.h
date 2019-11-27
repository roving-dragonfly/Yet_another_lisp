/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:41:58 by aalves            #+#    #+#             */
/*   Updated: 2019/11/27 06:25:23 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yal.h"

t_cell	*make_cell(t_cell *cell)
{
	t_cell	*ret;
	assert((ret = malloc(sizeof(t_cell))));
	*ret = *cell;
    return (ret);
}

t_cell	*cell_cons(t_cell *cell)
{
	return (make_cell(&(t_cell){e_cons, .car = cell}));
}

t_cell	*cell_list(t_cell *cell)
{
	return (make_cell(&(t_cell){e_list, .car = cell}));
}
