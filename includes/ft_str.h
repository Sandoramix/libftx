/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:36:51 by odudniak          #+#    #+#             */
/*   Updated: 2024/06/27 00:11:59 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H
# include <libft.h>

/**
 * @brief Returns a pointer to a new string
 * which is a duplicate of the string s.
 * @param s char*
 * @return a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available.
 * @attention Uses: malloc
 */
char		*str_dup(const char *s);
/**
 * @brief Duplicate an array of strings
 * @param mtx array of strings
 * @return pointer to the duplicated data
 * or `NULL` if error occured
 * @attention Uses: malloc + free
 */
char		**str_mtxdup(char **mtx);
/**
 * @brief Get the length of a string
 * @param s (array of chars) | string
 * @return size_t
 */
size_t		str_ulen(const char *s);
/**
 * @brief Get the length of the string
 *
 * @param s string
 * @return Length of the string as integer
 */
int			str_ilen(const char *s);
/**
 * @brief This function copy a string from src to dest.
 * @param dst destination variable
 * @param src source variable
 * @param sz size of the buffer
 * @return The total length of the string it tried to create
 * (that means the length of src).
 */
size_t		str_lcpy(char *dst, const char *src, size_t sz);
/**
 * @brief This function concatenate a string from src to dest.
 * It copies up to `size - 1` characters
 * from the NUL-terminated string src to dst,
 * NUL-terminating the result.
 * @param dst destination variable
 * @param src source variable
 * @param sz size of the buffer
 * @return The total length of the string it tried to create
 * (hat means the initial length of dst plus the length of src).
 */
size_t		str_lcat(char *dst, const char *src, size_t sz);
/**
 * @brief This function returns a pointer to the first occurrence
 *  of the character c in the string s.
 * @param s string
 * @param c char to find
 * @return a pointer to the matched character `c`
 * or `NULL` if the character is not found.
 */
char		*str_chr(const char *s, int c);
/**
 * @brief This function returns a pointer to the last occurrence
 *  of the character c in the string s.
 * @param s string
 * @param c char to find
 * @return a pointer to the matched character `c`
 * or `NULL` if the character is not found.
 */
char		*str_rchr(const char *s, int c);
/**
 * @brief This function compares only the first (at most)
 * `n` bytes of the two strings `s1` and `s2`.
 * @param s1 first string
 * @param s2 second string
 * @param n total bytes to compare
 * @return `0` if s1 and s2 are equal.
 * A `negative number` if s1 is less than s2.
 * A `positive number` if s1 is greater than s2.
 */
int			str_ncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief Check if the given string `s` is blank
 * (after removing all whitespaces it's length is `0`)
 * @attention Uses: `malloc`
 * @param s string to check
 * @return `true` if the string `s` is blank, `false` otherwise.
 */
bool		str_isblank(char *s);
/**
 * @brief Compare two strings (`strcmp`).
 * @param s1 first string
 * @param s2 second string
 * @return `0` if both strings are equal.
 * If they're not equal, the difference of the first different character of the
 * first string (s1[i]) and the second string (s2[i]) is returned
 * (`s1[i] - s2[i]`)
 */
int			str_cmp(const char *s1, const char *s2);
/**
 * @brief Check whether the two strings are equal
 * @param a first string
 * @param b second string
 * @return `true` if the strings are equal, `false` otherwise.
 */
bool		str_equals(void *a, void *b);
/**
 * @brief Deallocate a matrix of chars (array of strings)
 * @param mtx matrix to free
 * @return `NULL`
 */
void		*str_freemtx(char **mtx);
/**
 * @brief Deallocate a cube of chars (array of array of strings)
 * @param mtx cube to free
 * @return `NULL`
 */
void		*str_freemtx_cube(char ***mtx);
/**
 * @brief Deallocate a cube of chars (array of array of strings)
 * until the given `length` (starting from 1)
 * @param mtx cube to free
 * @param length how many elements to free
 * @return `NULL`
 */
void		*ft_freemtx_cubes(char ***mtx, int length);
/**
 * @brief Deallocate a matrix of chars (array of strings)
 * from a starting position
 * @param mtx matrix to free
 * @param start index from where start deallocating
 * @return `NULL`
 */
void		*str_freemtx_from(char **mtx, int start);
/**
 * @brief This function locates the first occurrence of the
 * null-terminated string s2 in the string s1,
 * where not more than len characters are searched.
 * Characters that appear after a '\0' character are not searched.
 * @param s1 original string
 * @param s2 substring to find
 * @param n number of the first characters inside `s1` to check
 * @return If `s2` is an empty string, `s1` is returned; if `s2` occurs nowhere
 * in big, NULL is returned; otherwise a pointer to the first character of
 * the first occurrence of `s2` is returned.
 */
char		*str_nstr(const char *s1, const char *s2, size_t n);
/**
 * @brief Find the index of first char `c` inside the string `s`
 *
 * @param s string
 * @param c char to find
 * @return Index of the first occurence of `c`, or `-1` if it's not present
 */
int			str_idxofchar(const char *s, char c);
/**
 * TODO docs
 */
int			str_idxofchar_from(const char *s, int start, char c);
/**
 * @brief FInd the index of first occurence of substring `find` inside `str`
 *
 * @param str string
 * @param find substring to find
 * @return Index of the first occurence of `find` inside `str`,
 * or `-1` if it's not present.
 */
int			str_idxofstr(const char *str, char *find);
/**
 * TODO docs
 */
int			str_idxofstr_from(const char *str, int start, char *find);
/**
 * @brief Add right padding to the string with specified char if necessary.
 * @attention Original string is mutated.
 * @param s string to modify
 * @param c pad character
 * @param n total len with the string should have.
 * @param start Choose if the padding should be at start or end of the string
 * E.g. if `n` is 2, `c` is '0' and the s is `"4"` the result will be `"40"`
 * @return Copy of the string plus the added padding if necessary.
 * @attention Uses: malloc
 */
char		*str_pad(char *s, char c, int n, bool start);
/**
 * @brief Update the string to uppercase.
 * @attention Original string is mutated.
 *
 * @param s string to return
 * @return The converted string.
 */
char		*str_toupper(char *s);
/**
 * @brief Update the string to lowercase.
 * @attention Original string is mutated.
 *
 * @param s string to return
 * @return The converted string.
 */
char		*str_tolower(char *s);
/**
 * @brief Find and replace the `first` substring of `str` with another string.
 * @attention Uses: malloc, free.
 * Unexpected behaviour may happen if the index is wrong.
 * `str` is freed.
 * @param str start string
 * @param start index where you want to start from.
 * @param find string to find
 * @param replace string to replace `find` with
 * @return the pointer to the new `str`. Or the same str if something went wrong.
 */
char		*str_replace_first(char *str, char *find, char *replace);
/**
 * TODO docs
 */
char		*str_replace_from_to(char *str, int start, int end, char *replace);
/**
 * @brief Find and replace the `all` substrings of `str` with another string.
 * @attention Uses: malloc, free.
 * `str` is freed.
 * @param str start string
 * @param find string to find
 * @param replace string to replace `find` with
 * @return the pointer to the new `str`
 */
char		*str_replace(char *str, char *find, char *replace);
/**
 * @brief Count how many times does `c` appear in `s`
 *
 * @param s string
 * @param c char
 * @return size_t
 */
size_t		str_count_c(const char *s, char c);
/**
 * @brief Add a character to the end of a string
 * @attention Uses: malloc, free. Original string is mutated.
 * @param s string
 * @param c char to add
 * @return pointer to the start of modified string.
 * If there's been an issue with allocation, null is returned
 */
char		*str_pushchar(char *s, char c);
/**
 * @brief Allocates and returns a substring
 * from the string 's'.
 * The substring begins at index 'start' and is of
 * maximum size 'len'.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char		*str_lensubstr(char *s, size_t start, size_t len);
/**
 * @brief Create a substring of string `s` from `start` to `end` (included)
 * @param s Main string
 * @param start Start index
 * @param end End index (included)
 * @return Result of the string or `NULL` if length of `s` is zero.
 */
char		*str_substr(char *s, size_t start, size_t end);
/**
 * @brief Allocates (with malloc(3)) and returns a new
 * string, which is the result of the concatenation
 * of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char		*str_join(char const *s1, char const *s2);
/**
 * @brief Allocates (with malloc(3)) and returns a new
 * string, which is the result of the concatenation
 * of 's1' and 's2'. At the end `s1` is deallocated.
 * @param s1 The prefix string. (will be freeed).
 * @param s2 The suffix string.
 * @return The new string.
 * NULL if the allocation fails.
 * @attention Uses: malloc, free
 */
char		*str_freejoin(char *s1, char const *s2);
/**
 * @brief Allocates and returns a copy of
 * 's1' with the characters specified in 'set' removed
 * from the beginning and the end of the string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char		*str_trim(char *s1, char const *set);
/**
 * @brief Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting 's' using the
 * character 'c' as a delimiter. The array must end
 * with a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 * @attention Uses: malloc
 */
char		**str_split(char *s, char c);
/**
 * TODO docs
 */
char		**str_split_first(char *s, char c);
/**
 * TODO docs
 */
char		**str_split_firststr(char *str, char *s);
/**
 * @brief Check if the given `s` string ends with `end` string
 * @param s string to check
 * @param end expected ending of the string
 * @return `true` if `s` ends with `end`, `false` otherwise
 */
bool		str_endswith(const char *s, char *end);

/**
 * @brief Check if the given `s` string starts with `start` string
 * @param s string to check
 * @param start expected start of the string
 * @return `true` if `s` starts with `start`, `false` otherwise
 */
bool		str_startswith(const char *s, const char *start);
/**
 * @brief Applies the function 'f' to each character of the
 * string 's', and passing its index as first argument
 * to create a new string resulting
 * from successive applications of 'f'.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of 'f'.
 * Returns NULL if the allocation fails.
 * @attention Uses: malloc
 */
char		*str_mapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief Applies the function 'f' on each character of the string
 * passed as argument, passing its index as first argument.
 * Each character is passed by address to 'f' to be modified if necessary
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void		str_iteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief Tests whether all characters in the string
 * pass the test implemented by the provided function.
 *
 * @param str string to check
 * @param check_fn function that takes a char as a parameter and returns a bool
 * @note Example: `check_fn:` bool test(char);
 * @return `true` if every characters pass the function test, `false` otherwise
 */
bool		str_every(char *str, bool(*check_fn)(char));
/**
 * @brief Check if the given `array` of strings contains a given `value` string.
 * @param array `NULL` terminated array of strings
 * (or matrix of chars) to loop over.
 * @param value string to search inside `array`
 * @return `true` if `value` is contained inside `array`, `false` otherwise.
 */
bool		str_array_includes(char **array, char *value);
/**
 * @brief Check if the string `s` contains any character is `set` string.
 *
 * @param s string to check
 * @param set set of chars to find.
 * @return `true` if there's at least one char of `set` in `s`,
 * `false` otherwise
 */
bool		str_includesset(char *s, char *set);
/**
 * @brief Get the length of the given matrix of chars/ array of strings
 *
 * @param mtx matrix
 * @return Length of the matrix as `int`. If `NULL` is passed, the return is `0`
 */
int			str_mtxlen(char **mtx);
int			str_mtxcublen(char ***mtxcub);
/**
 * @brief This function copies `n` elements from `src` to `dest`.
 * @param dest mtx
 * @param src mtx
 * @param n number of elements to copy
 * @return a pointer to `dest`
 */
char		**str_mtxcpy(char **dest, char **src, size_t n);
char		***str_mtxcubcpy(char ***dest, char ***src, size_t n);
/**
 * @brief add a new string to the matrix of chars/array of strings.
 * Original matrix may be mutated.
 * @attention If everyting goes fine, the original `*mtxp` is replaced
 * by the newly allocated matrix, and the old one is freed with `free`.
 * @param mtxp pointer to the matrix.
 * @param s string to push
 * @return pointer to the newly allocated matrix,
 * or `NULL` if any error happened.
 */
char		**str_mtxpush(char ***mtxp, char *s);
char		***str_mtxcubpush(char ****mtxcubp, char **s);
/**
 * @brief Check if the given char at `idx` position of `str` is surrounded
 * by quotes.
 * @param str string to compare
 * @param idx index of the char to check
 * @return `0` if the given idx is not surrounded by a quote, otherwise a
 * char of the surrounding quote is returned (`'` or `"`)
 */
char		str_ischar_inquotes(char *str, int idx);
/**
 * @brief Concatenate two strings and `free` the first one.
 * @attention Uses: `malloc` & `free`
 * @param s1 First string which will be freed after the copy.
 * @param s2 Second string
 * @param s2_n Number of characters to copy from `s2`
 * @return Concatenation of both strings, or `NULL` on allocation
 * failure.
 */
char		*str_nfreejoin(char *s1, char *s2, size_t s2_n);
/**
 * TODO docs
 */
bool		str_isvariable(char *s);
/**
 * TODO docs
 */
int			str_var_ending_idx(char *s, int start);
/**
## Cleanup della stringa, rimuovendo le quotes di apertura + chiusura.
- Si alloca la stringa finale con 1 byte (per semplificare controlli interni)
e si scorre `*str`
- Se si trova un carattere spazio con il successivo `non spazio` si aggiorna
`edge` che indica lo start/fine di un blocco di stringa (parola/quotes)
- Si gestiscono i casi delle quotes e non in due if separati.
- Si aggiorna la stringa finale e la si restituisce.
*/
char		*str_clearquotes(char **str);

int			str_find_next_idx(char *str, char c,
				int start_idx, bool skip_escaped);

#endif