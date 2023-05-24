/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:49:57 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/24 02:54:06 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmms.h"

int	main(void)
{
	char	*cock;

	cock = mms_alloc(2, sizeof(char));
	cock[1] = 0;
	cock[0] = 'g';
	printf("%s\n", cock);
	mms_kill("Mange moi le dart\n", true, EXIT_SUCCESS);
	print_list();
}
