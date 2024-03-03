/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:33:51 by odudniak          #+#    #+#             */
/*   Updated: 2024/03/04 00:30:00 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <limits.h>
# include <sys/wait.h>

# include <ft_structs.h>
# include <ft_colors.h>
# include <ft_errors.h>

# include <ft_char.h>
# include <ft_ctype.h>
# include <ft_gnl.h>
# include <ft_int.h>
# include <ft_lists.h>
# include <ft_math.h>
# include <ft_mem.h>
# include <ft_printf.h>
# include <ft_str.h>
# include <ft_structs.h>
# include <ft_unistd.h>

# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16UPPER "0123456789ABCDEF"

# ifndef FILE_HEREDOC
#  define FILE_HEREDOC ".heredoc"
# endif

typedef enum e_status
{
	OK,
	KO
}	t_status;

bool		file_exists(char *path);
/**
 * @brief Open a file with in requested mode. An error would be returned if
 * it is a directory or the user doesn't have enough permissions.
 * @param path path of file to open.
 * @param mode how should the file be opened.
 * @return `fd` of the opened file, of `-1` and a possible print to console if
 * there's been an error.
 */
int			file_open(char *path, mode_t mode);
/**
 * @brief Close all files inside the given array of `fds`
 * @param fds array of `fd`s to close
 * @param n size of `fds`
 * @return number of files closed
 */
int			file_close(int fds[], int n);

char		*file_gen_name(char *prefix, mode_t mode);

int			file_open_or_create(char *path, mode_t mode);

bool		file_hasperm(char *path, mode_t perms);

bool		file_isdir(char *path);

t_list		*sys_loadcmds(char **cmds, char **paths);
char		**env_load_paths(t_list *env);
t_list		*env_load(char **envp);
t_list		*lst_findbykey_str(t_list *envlist, char *key);

char		*sys_findcmdpath(char **paths, char *cmd);

void		*str_freemtx(char **mtx);
void		*str_freemtx_cube(char ***mtx);
void		*ft_freemtx_cubes(char ***mtx, int length);
void		*str_freemtx_from(char **mtx, int start);
//!-------------------------CONVERTERS-------------------------

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 *
 * @param n the integer to convert.
 * @return The string representing the integer.
 * `NULL` if the allocation fails.
 * @attention Uses: malloc
 */
char		*ft_itoa(int n);
/**
 * @brief Get the boolean value as a string
 * @param value boolean
 * @return "true" if the value is `true` otherwise "false"
 */
char		*ft_boolstr(bool value);
/**
 * @brief Converts the given string into a number.
 * It skips all the `isspace` characters on start, ignores all the non digits
 * at the end, and handles only `one` sign
 * @param nptr string to convert
 * @return the final number
 * @attention If the input is invalid it returns `0` (zero)
 * so it might give some issues in future.
 */
int			ft_atoi(const char *nptr);
/**
 * @brief print the number in given base
 *
 * @param n number to print
 * @param base the base in which to convert the number.
 * @return The converted number in specified base
 * @attention Uses: malloc
 */
char		*ft_itoa_base(int n, const char *base);
/**
 * @brief Convert a number to hex
 * @param n number `int`
 * @return String of the hex number. (`0x`) excluded
 * @attention Uses: malloc
 */
char		*ft_itohex(unsigned long n);
/**
 * @brief Convert an `unsigned int` into a string
 * @param n unsigned int
 * @return The number as a string
 * @attention Uses: malloc.
 */
char		*ft_uitoa(unsigned int n);
/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 *
 * @param n the unsigned integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char		*ft_ultoa_base(unsigned long n, const char *base);

//!-------------------------STRICT GANG--------------------------
/**
 * @brief Atoi but very strict. doesn't tollerate any non digit characters
 * except for spaces
 *
 * @param s
 * @return int*
 */
int			*strict_atoi(const char *s);
#endif