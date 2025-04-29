/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Session.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:37:04 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/29 03:26:47 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include "utils/utils.hpp"

#include "server/Session.hpp"

const std::map<std::string, StringVec> &Session::getConnectionTimes() const
{
	return (this->connectionTimes);
}

const StringVec Session::getConnectionTimes(const std::string &uuid)
{
	if (this->connectionTimes.count(uuid) > 0)
		return (this->connectionTimes[uuid]);
	return (StringVec());
}

bool Session::isSessionRequest(const std::string &filePath) const
{
	StringVec splitPath = strSplit(filePath, '/');
	size_t splitSize = splitPath.size();

	if (splitSize >= 2 && splitPath[splitSize - 1] == "session.html")
		return (true);
	return (false);
}

void Session::setConnectionTimes(const std::string &uuid, const std::string &currentConnectionTime)
{
	this->connectionTimes[uuid].push_back(currentConnectionTime);
}

CharVec Session::getSessionPage(const std::string &session_id, const std::string &filePath)
{
	CharVec vecHtml;

	std::ifstream stream(filePath.c_str());
	std::stringstream buffer;

	buffer << stream.rdbuf();
	std::string htmlStart = buffer.str();

	std::string htmlEnd =
		"        </ul>\n"
		"    </div>\n"
		"</body>\n"
		"</html>\n";

	std::string html;
	for (size_t i = 0; i < this->connectionTimes[session_id].size(); ++i)
		html += "            <li>" + formatMillisToDateTime(this->connectionTimes[session_id][i]) + "</li>\n";

	vecHtml.insert(vecHtml.end(), htmlStart.begin(), htmlStart.end());
	vecHtml.insert(vecHtml.end(), html.begin(), html.end());
	vecHtml.insert(vecHtml.end(), htmlEnd.begin(), htmlEnd.end());

	return (vecHtml);
}
