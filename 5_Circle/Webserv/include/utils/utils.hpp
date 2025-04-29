/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:59:44 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/29 03:26:18 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <stdint.h>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include "sys/types.hpp"

/* fdUtils.cpp */
int epCtl(int epfd, int opt, int fd, uint32_t events);
void setFdNonBlock(int fd);
void setFdNonBlock(int *pipeDes);
void closePipes(int *pipeDes);

/* memUtils.cpp */
void freeSplit(char **split);

/* strUtils.cpp */
StringVec strSplit(const std::string &str, char delim);
std::string sizeToStr(size_t value);
std::string trimBlank(const std::string &str);
std::string extractValue(const std::string &line);
size_t strToSize(const std::string &str);
bool isAllDigits(const std::string &str);
std::string stripPrefix(const std::string &uri, const std::string &aliasPath);
std::string stripQuotes(const std::string &str);
void stripCarriage(std::string &str);
CharVec readFileData(const std::string &filePath);
std::string normalizedPath(const std::string &path);
std::string getVecLine(const CharVec &buffer, size_t &pos);
void extractHeader(CharVec &httpMessage);

/* timeUtils.cpp*/
time_t getCurrentTimeMillis(void);
std::string formatMillisToDateTime(const std::string &millisStr);

#endif