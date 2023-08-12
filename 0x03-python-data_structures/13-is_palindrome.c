#include <stdio.h>
#include <stdlib.h>

/* Definition of singly linked list node */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Pointer to a pointer to the head of the linked list.
 * Return: 0 if not a palindrome, 1 if a palindrome.
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
	return 1;

	listint_t *slow = *head, *fast = *head, *prev_slow = *head, *mid = NULL;
	listint_t *second_half, *prev_of_slow = *head;
	int is_palindrome = 1;

	/* Find the middle of the list */
	while (fast != NULL && fast->next != NULL)
	{
	fast = fast->next->next;
	prev_slow = slow;
	slow = slow->next;
	}

	/* If list has odd number of elements, skip the middle node */
	if (fast != NULL)
	{
	mid = slow;
	slow = slow->next;
	}

	/* Reverse the second half of the list */
	second_half = slow;
	prev_slow->next = NULL;
	while (second_half != NULL)
	{
	listint_t *temp = second_half->next;
	second_half->next = prev_of_slow;
	prev_of_slow = second_half;
	second_half = temp;
	}

	/* Compare the first and second halves */
	listint_t *ptr1 = *head, *ptr2 = prev_of_slow;
	while (ptr1 != NULL && ptr2 != NULL)
	{
	if (ptr1->n != ptr2->n)
	{
		is_palindrome = 0;
		break;
	}
	ptr1 = ptr1->next;
	ptr2 = ptr2->next;
	}

	/* Restore the list */
	second_half = prev_of_slow;
	prev_of_slow = NULL;
	while (second_half != NULL)
	{
	listint_t *temp = second_half->next;
	second_half->next = prev_of_slow;
	prev_of_slow = second_half;
	second_half = temp;
}

	if (mid != NULL)
	{
	prev_slow->next = mid;
	mid->next = prev_of_slow;
	}
	else
{
        prev_slow->next = prev_of_slow;
	{

	return is_palindrome;
}

/* Helper function to create a new node */
listint_t *newNode(int data)
{
	listint_t *node = malloc(sizeof(listint_t));
	if (node == NULL)
	{
	fprintf(stderr, "Memory allocation failed\n");
	exit(EXIT_FAILURE);
	}
	node->n = data;
	node->next = NULL;
	return node;
}

/* Helper function to print the linked list */
void printList(listint_t *head)
{
	listint_t *temp = head;
	while (temp != NULL)
	{
	printf("%d ", temp->n);
	temp = temp->next;
	}
	printf("\n");
}

int main(void)
{
	listint_t *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(2);
	head->next->next->next->next = newNode(1);

	printf("Original Linked List: ");
	printList(head);

	if (is_palindrome(&head))
	printf("The linked list is a palindrome.\n");
	else
	printf("The linked list is not a palindrome.\n");

	return 0;
}
