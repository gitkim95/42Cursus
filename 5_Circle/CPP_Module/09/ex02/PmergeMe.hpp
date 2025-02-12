/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:29:48 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/12 13:03:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <exception>

class PmergeMe
{
public:
	PmergeMe( void );
	PmergeMe( const PmergeMe &other);
	~PmergeMe( void );

	PmergeMe&	operator=( const PmergeMe &other );
	
	static void	initContainer( std::vector<int>& vec, std::list<int>& list, int ac, char **av );
	void	insertionSort( std::vector<int>& vec, int start, int end );
	void	mergeSort( std::vector<int>& vec, int start, int mid, int end );
	static void	mergeInsertionSort( std::vector<int>& vec, int start, int end );
	void	insertionSort( std::list<int>& list );
	static void	mergeInsertionSort( std::list<int>& list );
	void	splitList( std::list<int>& left, std::list<int>& right, std::list<int>& origin);

	static void	printResult( std::vector<int>& vec );
	static void	printResult( std::list<int>& list );

	class PmergeMeException : public std::exception
	{
	private:
		std::string	errMsg;
	public:
		PmergeMeException( const std::string &errMsg );
		virtual ~PmergeMeException() throw();

		const char* what() const throw();
	};
};

#endif