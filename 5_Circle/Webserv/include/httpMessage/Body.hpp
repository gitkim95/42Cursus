/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Body.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:02:15 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/26 18:26:59 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BODY_HPP
#define BODY_HPP

#include <vector>
#include <string>
#include <map>
#include "sys/types.hpp"

class Body
{
private:
	CharVec content;
	std::map<std::string, CharVec> fileData;

public:
	Body();
	Body(const CharVec &content);
	Body(const Body &body);

	const CharVec &getContent() const;
	const std::map<std::string, CharVec> &getFileData() const;
	void setContent(const CharVec &content);
	void setFileData(const std::string &fileName, const CharVec &fileBody);

	Body &operator=(const Body &body);
};

#endif