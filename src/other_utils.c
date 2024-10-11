/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:52:27 by mmarcott          #+#    #+#             */
/*   Updated: 2024/10/11 10:54:30 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmms.h"

void	mms_unregister_callback(void)
{
	get_data_mms()->callback_status = false;
	get_data_mms()->callback = NULL;
	get_data_mms()->callback_param = NULL;
}
