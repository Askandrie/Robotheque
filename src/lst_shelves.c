/**
 * @ Author: Aska
 * @ Create Time: 2025-05-06 00:55:32
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 18:45:52
 */

#include "lst_shelves.h"
#include "volume.h"

t_lst_shelves *insert_lst_shelves(t_lst_shelves **head, char *shelf_name, t_vol3us volumes)
{
	t_lst_shelves *new_node, *tmp_node;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof *new_node);
	if (new_node == NULL)
		return (NULL);
	memcpy(&new_node->volumes, &volumes, sizeof(t_vol3us));
	new_node->shelf_name = shelf_name;
	new_node->next       = NULL;
	if (*head == NULL)
		*head = new_node;
	tmp_node = *head;
	while (tmp_node->next)
		tmp_node = tmp_node->next;
	tmp_node->next = new_node;
	return (new_node);
}

void delete_node_lst_shelves(t_lst_shelves **head, t_lst_shelves *del_node)
{
	t_lst_shelves *prev;

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
	free(del_node);
}

void delete_all_lst_shelves(t_lst_shelves **head)
{
	while (*head)
		delete_node_lst_shelves(head, *head);
}

void print_lst_shelves(t_lst_shelves *head)
{
	t_lst_shelves *tmp_node;

	tmp_node = head;
	while (tmp_node)
	{
		printf("Shelf Name: %s\n", tmp_node->shelf_name);
		print_vol3us(tmp_node->volumes);
		tmp_node = tmp_node->next;
	}
}