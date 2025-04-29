/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:26:32 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/29 18:04:47 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <csignal>
#include <iostream>
#include <sys/wait.h>
#include "config/MetaConfig.hpp"
#include "server/Server.hpp"
#include "response/ResponseGenerator.hpp"

/**
 * temp server shutdown handler
 * must remove
 */
Server *tmp;

static void sigIntHandler(int signum)
{
	(void)signum;
	tmp->stop();
	std::cout << std::endl;
	std::cout << "server stop" << std::endl;
}

static void sigChldHandler(int signum)
{
	(void)signum;
	int status;
	pid_t pid;

	while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
	{
		std::cout << "cgi " << pid << " exited ";
		if (WIFEXITED(status))
			std::cout << "at " << WEXITSTATUS(status) << std::endl;
		else if (WIFSIGNALED(status))
			std::cout << "with signal " << WTERMSIG(status) << std::endl;
	}
}

int main(int argc, char **argv)
{
	try
	{
		MetaConfig config;
		if (argc > 2)
		{
			std::cerr << "Invalid number of arguments." << std::endl;
			return (1);
		}
		else if (argc == 2)
		{
			if (ResponseGenerator::getFileExtension(argv[1]) == "conf")
				config.applyConfigFile(argv[1]);
			else
			{
				std::cerr << "Invalid file format." << std::endl;
				return (1);
			}
		}

		Server server;
		config.setDefaultConfig();
		server.setMetaConfig(config);
		server.openServerPort();

		tmp = &server;
		signal(SIGINT, sigIntHandler);
		signal(SIGCHLD, sigChldHandler);

		std::cout << "server run" << std::endl;
		server.run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
