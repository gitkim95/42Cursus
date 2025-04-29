/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Context.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:58:52 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/27 17:35:49 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sys/types.hpp"

#include "context/Context.hpp"

/* private */
Context::Context() {}

/* public */
Env &Context::env = Env::getInstance();
