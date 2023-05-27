/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmms.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:48:36 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/27 18:40:07 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMMS_H
# define LIBMMS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_pointer
{
	void				*ptr;
	struct s_pointer	*next;
	void			*alloc_func;
}				t_pointer;

// Delete all the used memory from the manager.
void		mms_kill(char *message, bool quit, int code);

void		*mms_alloc(size_t size, size_t typesize);

void		print_list(void);

void		*mms_free(void *ptr);

t_pointer	*get_data_mms(void);

#endif
