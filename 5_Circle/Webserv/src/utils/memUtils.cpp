/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memUtils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 07:05:08 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/06 07:51:07 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.hpp"

void freeSplit(char **split)
{
	for (int i = 0; split[i]; ++i)
		delete[] split[i];
	delete[] split;
}
