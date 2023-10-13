/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:03:18 by mmarcott          #+#    #+#             */
/*   Updated: 2023/10/13 09:50:23 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmms.h"

void	mms_set_alloc_fn(void *(*f)(size_t, size_t))
{
	if (!f)
		return ;
	get_data_mms()->f = f;
}

/// @brief This function check the presence of a pointer in the lib structure.
/// @param ptr Any pointer to check.
/// @return True if the ptr is present in the lib, false if not.
static bool	check_presence(void *ptr)
{
	t_pointer	*buf;

	buf = get_data_mms();
	while (buf)
	{
		if (buf->ptr == ptr)
			return (true);
		buf = buf->next;
	}
	return (false);
}

bool	mms_add_ptr(void *ptr)
{
	t_pointer	*ptr_list;

	if (check_presence(ptr))
		return (false);
	ptr_list = get_data_mms();
	if (!ptr_list->initiated && !ptr_list->ptr)
	{
		ptr_list->initiated = true;
		ptr_list->ptr = ptr;
		ptr_list->last_allocated = ptr_list;
		return (true);
	}
	ptr_list = ptr_list->last_allocated;
	ptr_list->next = (get_data_mms()->f(1, sizeof(t_pointer)));
	ptr_list = ptr_list->next;
	ptr_list->next = NULL;
	ptr_list->f = get_data_mms()->f;
	ptr_list->ptr = ptr;
	get_data_mms()->last_allocated = ptr_list;
	return (true);
}
