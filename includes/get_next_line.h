/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:57:04 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/24 14:11:26 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*
** Macro for the buffer size, the max number of file descriptors available
** Find the max number of files:
** Mac: launchctl limit maxfiles
** Linux: ulimit -n / -Hn / -Sn / -aH
** The hard limit is the maximum value that is allowed for the soft limit
** Any changes to the hard limit require root access.
** The soft limit is the value that Linux uses to limit
** the system resources for running processes.
** The soft limit cannot be greater than the hard limit.
*/
# define BUFF_SIZE 8
# define MAX_FD 4096
# include "libft.h"

int	get_next_line(const int fd, char **line);

#endif
