/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:47:35 by odudniak          #+#    #+#             */
/*   Updated: 2024/02/09 16:04:57 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H
# include <libft.h>

//!-----------------------DOUBLE LINKED LISTS (INTEGERS)---------

/**
 * @brief get list's last node
 * @param head head of the list
 * @return pointer to tail
 */
t_dllist	*dll_gettail(t_dllist *head);
/**
 * @brief Print the list from head to tail
 * @param head list's head
 */
void		dll_printlist(t_dllist *head);
/**
 * @brief Print the list from tail to head
 * @param head list's head
 */
void		dll_printrevlist(t_dllist *head);
/**
 * @brief Get list's node by it's index
 * @param head list's head
 * @param idx index to get
 * @return list's node or `NULL` if `idx` is not valid
 */
t_dllist	*dll_byidx(t_dllist *head, int idx);
/**
 * @brief Retrieve the list's current size
 * @param head list's head
 * @return `int`
 */
int			dll_size(t_dllist *head);

// TODO ADD DOCS
t_dllist	*dll_delhead(t_dllist **head);
t_dllist	*dll_deltail(t_dllist **head);
t_dllist	*dll_addtail(t_dllist **head, int *val);
t_dllist	*dll_addnode_tail(t_dllist **head, t_dllist *node);
t_dllist	*dll_addhead(t_dllist **head, int *val);
t_dllist	*dll_addnode_head(t_dllist **head, t_dllist *node);
t_dllist	*dll_new(int *val);
void		*dll_clearlist(t_dllist **head);

int			dll_idxof(t_dllist *head, int val);
t_dllist	*dll_minmax(t_dllist *head, bool min);
int			dll_minmax_idx(t_dllist *head, bool min);
int			dll_next_occur_idx(t_dllist *head, int prevmax, bool min);

//!-------------------------LISTS------------------------------

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
 * The member variable 'content' is initialized with
 * the value of the parameter 'content'. The variable
 * 'next' is initialized to NULL.
 * @param content The content to create the node with.
 * @return The new node
 * @attention Uses: malloc
 */
t_list		*ft_lstnew(void *content);
/**
 * @brief Adds the node 'new' at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 */
void		*ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list
 */
int			ft_lstsize(t_list *lst);
/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list
 */
t_list		*ft_lstlast(t_list *lst);
/**
 * @brief Adds the node 'new' at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param The address of a pointer to the node to be added to the list.
 */
void		*ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Takes as a parameter a node and frees the memory of
 * the node's content using the function 'del' given
 * as a parameter and free the node. The memory of 'next' must not be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 * @attention Uses: free
 */
void		*ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function 'del' and free(3).
 * Finally, the pointer to the list must be set to NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
 * the content of the node.
 * @attention Uses: malloc
 */
void		*ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief Iterates the list 'lst' and applies the function
 * 'f' on the content of each node.
 * @param lst The address of a pointer to a node.
 * @param f  The address of the function used to iterate on the list.
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Iterates the list 'lst' and applies the function
 * 'f' on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function 'f'. The 'del' function is used to
 * delete the content of a node if needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete
 * the content of a node if needed.
 * @return The new list. NULL if the allocation fails.
 * @attention Uses: malloc
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif