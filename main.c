/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:49:57 by mmarcott          #+#    #+#             */
/*   Updated: 2023/05/24 14:53:41 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmms.h"

int	main(void)
{
	char	*str;

	str = mms_alloc(20, sizeof(char));
	str[0] = 'd';
	str[1] = 0;
	printf("%s\n", str);
	// mms_kill("free all the peoples\n", true, EXIT_SUCCESS);
	str = mms_free(str);
}
