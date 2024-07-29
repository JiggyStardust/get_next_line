/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:19:28 by sniemela          #+#    #+#             */
/*   Updated: 2024/07/04 08:57:55 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		printf("[%d]: %s\n", count, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
/*
int main(void)
{
    int     fd1, fd2, fd3;
    char    *line;
    int     count1 = 0, count2 = 0, count3 = 0;
    int     more_to_read = 1;

    // Open three different files
    fd1 = open("example1.txt", O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error opening file example1.txt");
        return (1);
    }

    fd2 = open("example2.txt", O_RDONLY);
    if (fd2 == -1)
    {
        perror("Error opening file example2.txt");
        close(fd1);
        return (1);
    }

    fd3 = open("example3.txt", O_RDONLY);
    if (fd3 == -1)
    {
        perror("Error opening file example3.txt");
        close(fd1);
        close(fd2);
        return (1);
    }

    // Read interleaved lines from each file descriptor until all are fully read
    while (more_to_read)
    {
        more_to_read = 0; // Assume no more data to read; change if any file still has data

        line = get_next_line(fd1);
        if (line)
        {
            printf("File 1, Line %d: %s", ++count1, line);
            free(line);
            more_to_read = 1; // There was more to read from this file
        }

        line = get_next_line(fd2);
        if (line)
        {
            printf("File 2, Line %d: %s", ++count2, line);
            free(line);
            more_to_read = 1; // There was more to read from this file
        }

        line = get_next_line(fd3);
        if (line)
        {
            printf("File 3, Line %d: %s", ++count3, line);
            free(line);
            more_to_read = 1; // There was more to read from this file
        }
    }

    // Close the file descriptors
    close(fd1);
    close(fd2);
    close(fd3);

    return (0);
} */