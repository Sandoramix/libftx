/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:33:51 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/24 19:01:58 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <ft_def.h>
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

bool		file_exists(char *path);

int			file_open_or_create(char *path, mode_t mode);

bool		file_hasperm(char *path, mode_t perms);

t_list		*env_load(char **envp);

//!-------------------------CONVERTERS-------------------------

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 *
 * @param n the integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails.
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