/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:13:36 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/26 17:52:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <list>
# include <stdexcept>

template <typename T>
typename T::const_iterator	easyfind(const T& container, int value)
{
	typedef typename T::const_iterator ConstIterator;
	ConstIterator	result = std::find(container.begin(), container.end(), value);
	if (result == container.end())
	{
		throw (std::runtime_error("Value not found."));
	}
	return (result);
}

#endif