#include "sort.h"
/**
 * move_dnode_forward - moves a node forward at a given position
 * @head: head of list
 * @node: node to move
 *
 * Return: void
 */
void move_dnode_forward(listint_t **head, listint_t *node)
{
	listint_t *temp;

	temp = node->next->next;
	node->next->next = node;
	if (node->prev != NULL)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	else
	{
		*head = node->next;
	}
	node->prev = node->next;
	node->next = temp;
	if (temp != NULL)
	{
		temp->prev = node;
	}
}
/**
 * move_dnode_backward - moves a node forward at a given position
 * @head: head of list
 * @node: node to move
 *
 * Return: void
 */
void move_dnode_backward(listint_t **head, listint_t *node)
{
	listint_t *temp;

	temp = node->prev->prev;
	node->prev->prev = node;
	node->prev->next = node->next;
	if (node->next != NULL)
	{
		node->next->prev = node->prev;
	}
	node->next = node->prev;
	node->prev = temp;
	if (temp != NULL)
	{
		temp->next = node;
	}
	if (node->prev == NULL)
	{
		*head = node;
	}
}
/**
 * insertion_sort_list - insertion sorts doubly linked list in ascending order
 * @list: pointer to head of list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *backwards;

	current = *list;
	while (current != NULL)
	{
		while (current->next != NULL && current->n > current->next->n)
		{
			move_dnode_forward(list, current);
			print_list(*list);
			backwards = current->prev;
			while (backwards != NULL && backwards->prev != NULL &&
				backwards->n < backwards->prev->n)
			{
				move_dnode_backward(list, backwards);
				print_list(*list);
			}
		}
		current = current->next;
	}
}
