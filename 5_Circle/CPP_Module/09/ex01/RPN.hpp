/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:55:03 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 21:30:17 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <exception>

class RPN
{
private:
	std::stack<int>	digit;
public:
	RPN( void );
	RPN( const RPN &other );
	~RPN( void );

	RPN&	operator=( const RPN &other );

	int	calculate( const std::string &input );

	class RPNException : public std::exception
	{
	private:
		std::string	errMsg;
	public:
		RPNException( const std::string &errMsg );
		virtual ~RPNException() throw();

		const char* what() const throw();
	};
};

#endif