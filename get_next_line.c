/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:17:01 by sel-jama          #+#    #+#             */
/*   Updated: 2022/11/15 17:40:57 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_rest(char **save)
{
    int     i;
    char    *rest;
    
    i = 0;
    while (*(*save + i) && *(*save + i) != '\n')
        i++;
    rest = malloc(ft_strlen(*save) - i + 1);
    if (!rest)
        return (NULL);
    if (*(*save + i) == '\n')
        i += 1;
    int j = 0;
    while (*(*save + i))
    {
        rest[j] = *(*save + i);
        i++;
        j++;
    }
    rest[j] = '\0';
    free(*save);
    *save = NULL;
    return (rest); 
}

char    *ft_read_save(int fd, char  **saver)
{
    char    *R_buff;
    int     nbytes;

    if (!(*saver))
        *saver = ft_calloc(1, sizeof(char));
    R_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!R_buff)
    {
        free(*saver);
        // *saver = NULL;
        return (NULL);
    }
    nbytes = 1;
    while (!ft_strchr(*saver, '\n') && nbytes != 0)
    {
        nbytes = read(fd, R_buff, BUFFER_SIZE);
        if (nbytes == -1)
        {
            free(R_buff);
            free(*saver);
            // *saver = NULL;
            return (NULL);
        }
        R_buff[nbytes] = '\0'; 
        *saver = ft_strjoin(*saver, R_buff);
        if (nbytes == 0 && *(*saver) == '\0')
        {
            free(R_buff);
            free(*saver);
            // *saver = NULL;
            return (NULL);
        }
    }
free (R_buff);
return (*saver);
    
}

char    *get_myline(char *saver)
{
    int		i;
	char	*line;
 
	i = 0;
	// if (!saver[i])
	// 	return (NULL);
	while (saver[i] && saver[i] != '\n')
		i++;
    if (saver[i] == '\n')
        i += 1;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (saver[i] && saver[i] != '\n')
    {
		line[i] = saver[i];
        i++;
    }
	if (saver[i] == '\n')
    {
		line[i] = saver[i];
        i++;
    }
	line[i] = '\0';
	return (line);
}


char    *get_next_line(int fd)
{
    char        *fd_line;
    static char *saver;
     
    if (fd < 0 && BUFFER_SIZE <= 0)
        return (NULL);
    saver = ft_read_save(fd, &saver);
    if (!saver)
        return (NULL);
    fd_line = get_myline(saver);
    saver = ft_rest(&saver);
    return (fd_line);
}
// #include <fcntl.h>
// int main()
// {
//     char *line;
//     int fd;
//     fd = open("test.txt", O_RDONLY);
//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);
//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);
//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);
//     while (line)
//     {
//         line = get_next_line(fd);
//         printf("%s", line);
//         free(line);
//     }
// system("leaks a.out");
// }