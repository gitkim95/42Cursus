/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:09:22 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/29 17:09:00 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_HPP
#define TYPES_HPP

#include <map>
#include <set>
#include <string>
#include <vector>

class Session;
class Socket;
class Client;

typedef std::vector<unsigned char> CharVec;
typedef std::vector<std::string> StringVec;
typedef std::map<int, Socket *> ServerMap;
typedef std::map<int, Client *> ClientMap;
typedef std::map<int, CharVec> CGIInMap;
typedef std::map<std::string, std::string> StringMap;
typedef std::multimap<std::string, std::string> MultiStringMap;
typedef std::set<Client *> ClientSet;
typedef std::set<std::string> StringSet;

#endif