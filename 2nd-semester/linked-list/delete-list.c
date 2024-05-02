#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  struct Node *next;
};

int count(struct Node *head, int searchFor);
struct Node *BuildOneTwoThree();
int Length(struct Node *head);
void Push(struct Node **headRef, int newData);
void DeleteList(struct Node **headRef);

int main()
{
  struct Node *myList = BuildOneTwoThree();

  DeleteList(&myList);

  printf("Successfully deleted myList");
}

/*

Write a function DeleteList() that takes a list, deallocates all of its memory and sets its
head pointer to NULL (the empty list).

*/

void DeleteList(struct Node **headRef)
{
  struct Node *current = *headRef; // we created a current node that references the head
  struct Node *next;               // then we initialized a next node

  // the intialization of the next node is similar to swapping of values

  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }

  *headRef = NULL;
}

/*

functions below are basic utility. start writing code above.

*/

// Given a reference (pointer to pointer) to the head
// of a list and an int, push a new node on the front of the list.
// Creates a new node with the int, links the list off the .next of the
// new node, and finally changes the head to point to the new node.
void Push(struct Node **headRef, int newData)
{
  struct Node *newNode =
      (struct Node *)malloc(sizeof(struct Node)); // allocate node
  newNode->value = newData;                       // put in the data
  newNode->next = (*headRef);                     // link the old list off the new node
  (*headRef) = newNode;                           // move the head to point to the new node
}

struct Node *BuildOneTwoThree()
{
  struct Node *head = NULL; // Start with the empty list
  Push(&head, 3);           // Use Push() to add all the data
  Push(&head, 2);
  Push(&head, 1);
  return (head);
}

int Length(struct Node *head)
{
  int count = 0;
  struct Node *current = head;
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return (count);
}