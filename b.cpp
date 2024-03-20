/*
Q. Linked List - How to find the middle element of a singly linked list in one pass?

Submitted by:
Khushal Gautam
CS20B1080
7891616255
*/

#include <bits/stdc++.h>
using namespace std;

// The structure of linked list node
class Node{
	public:
		int data;
		Node *next;
};


// Function to add a new node at the head
void pushNodeAtHead(class Node** head,int data_val){
	
	// Allocate memory to new node 
    class Node *newNode = new Node();
		
	// Put in the data value 
	newNode->data = data_val;
		
	// Link the newNode to the head of old list 
	newNode->next = *head;
		
	// update the head pointer to the newNode
	*head = newNode;
}
	
// Function to print the linked list
void printlist(class Node *head){
	while(head != NULL){
		cout <<head->data << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}
	
// Function to print the middle element with two pointer approach
void printMiddle(class Node *head)
{
	struct Node *slow = head;
	struct Node *fast = head;

	if (head!=NULL)
	{
		while (fast != NULL && fast->next != NULL)
        {
			fast = fast->next->next;
			slow = slow->next;
		}
        /*
        Let n = size of linked list
        If n is odd, then (n+1)/2 position node is printed
        If n is even, then (n/2)+1 position node is printed
        Considering the numbering of linked list starts from 1.
        */
		cout << "The middle element is [" << slow->data << "]" << endl;
	}
}

int main(){
	class Node *head = NULL;
	for(int i=5; i>0; i--){
		pushNodeAtHead(&head, i);
	}
    printlist(head);
	printMiddle(head);
	return 0;
}

