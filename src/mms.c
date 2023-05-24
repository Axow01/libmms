/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mms.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:51:32 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/24 15:16:58 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmms.h"

// Note: add protection later.
t_pointer	*get_data_mms(void)
{
	static t_pointer	*data = NULL;

	if (!data)
	{
		data = calloc(1, sizeof(t_pointer));
		if (!data)
			mms_kill("Failled to allocate ! \n", true, EXIT_FAILURE);
	}
	return (data);
}

void	mms_kill(char *message, bool quit, int code)
{
	t_pointer	*current;
	t_pointer	*buffer;

	current = get_data_mms();
	while (current)
	{
		if (current->ptr)
			free(current->ptr);
		current->ptr = NULL;
		buffer = current->next;
		free(current);
		current = buffer;
	}
	printf("%s", message);
	if (quit)
		exit(code);
}

void	*mms_alloc(size_t size, size_t typesize)
{
	t_pointer	*current;

	if (!get_data_mms()->ptr)
	{
		get_data_mms()->ptr = malloc(size * typesize);
		if (!get_data_mms()->ptr)
			mms_kill("Failled to allocate ! \n", true, EXIT_FAILURE);
		get_data_mms()->next = NULL;
		return (get_data_mms()->ptr);
	}
	current = get_data_mms();
	while (current->next)
		current = current->next;
	current->next = malloc(1 * sizeof(t_pointer));
	if (!current->next)
		mms_kill("Failled to allocate ! \n", true, EXIT_FAILURE);
	current->next->ptr = malloc(size * typesize);
	if (!current->next->ptr)
		mms_kill("Failled to allocate ! \n", true, EXIT_FAILURE);
	current->next->next = NULL;
	return (current->next->ptr);
}

void	*mms_free(void *ptr)
{
	t_pointer	*current;

	current = get_data_mms();
	while (current)
	{
		if (current->ptr == ptr)
		{
			free(current->ptr);
			current->ptr = NULL;
			return (NULL);
		}
		current = current->next;
	}
	return (NULL);
}

void	print_list()
{
	t_pointer	*current;

	current = get_data_mms();
	if (!current)
		return ;
	while (current)
	{
		printf("%p\n", current->ptr);
		current = current->next;
	}
}
