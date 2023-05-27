/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:03:18 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/27 18:46:13 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmms.h"
#include <stddef.h>
#include <stdlib.h>

void	mms_set_alloc_fn(void *(*f)(size_t, size_t))
{
	if (!f)
		return ;
	get_data_mms()->alloc_func = f;
}
