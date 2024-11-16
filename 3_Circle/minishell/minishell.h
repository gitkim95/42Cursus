/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:28:35 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/17 01:47:07 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#endif
/*
readline
char	*readline(const char*)
	- #include <readline/readline.h>
	- #include <readline/history.h>
	- 컴파일 할 때는 -lreadline 플래그를 추가해줘야 한다.
	- 입력된 문자열을 저장하고 해당 주소를 반환한다.
	- 메모리 할당이 되므로 해제에 유의한다.

rl_clear_history
void	rl_clear_history(void)
	- #include <readline/readline.h>
	- 현재 history를 지운다.

rl_on_new_line
int		rl_on_new_line(void)
	- #include <readline/readline.h>
	- 
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs

https://velog.io/@sham/minishell%EA%B3%BC-readline
*/