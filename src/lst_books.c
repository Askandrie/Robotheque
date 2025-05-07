/**
 * @ Author: Aska
 * @ Create Time: 2025-05-06 00:55:32
 * @ Modified by: Aska
 * @ Modified time: 2025-05-07 03:31:44
 */

#include "lst_books.h"

t_lst_books *insert_lst_books(t_lst_books **head, t_series series, int idx)
{
	t_lst_books *new_node, *tmp_node;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof *new_node);
	if (new_node == NULL)
		return (NULL);
	memcpy(&new_node->series, &series, sizeof series);
	new_node->idx  = idx;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	tmp_node = *head;
	while (tmp_node->next)
		tmp_node = tmp_node->next;
	tmp_node->next = new_node;
	return (new_node);
}

void delete_node_lst_books(t_lst_books **head, t_lst_books *del_node)
{
	t_lst_books *prev;

	if (!head || !*head || !del_node)
		return;
	if (*head == del_node)
		*head = del_node->next;
	else
	{
		prev = *head;
		while (prev->next && prev->next != del_node)
			prev = prev->next;
		if (prev->next != del_node)
			return;
		prev->next = del_node->next;
	}
	free(del_node->series.name);
	free(del_node);
}

void delete_all_lst_books(t_lst_books **head)
{
	while (*head)
		delete_node_lst_books(head, *head);
}

void print_lst_books(t_lst_books *head)
{
	t_lst_books *tmp_node;

	tmp_node = head;
	while (tmp_node)
	{
		print_series(&tmp_node->series);
		tmp_node = tmp_node->next;
	}
}