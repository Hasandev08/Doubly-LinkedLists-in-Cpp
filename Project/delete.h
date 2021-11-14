//Header files
#include<iostream>
#include<windows.h>		//Header file for inserting colors and beep sound
#include<stdlib.h>
#include"insert.h"		
using namespace std;

void deleteNodeAtStart(Node*& head)		//function to delete the 1st node
{
	//creating pointers
	Node* temp2 = head;		//temp2 pointer is pointing to the head node	
	head = head->next;
	head->prev = NULL;
	free(temp2);		//removing the 1st node
	temp2 = NULL;
}

void deleteNodeAtPos(Node*& head, int x)		//function to delete any value in the list
{
	//creating pointers
	Node* temp = head->next;	//temp pointer is pointing to the second node
	Node* temp2 = head;		//temp2 pointer is pointing to the head node

	x--;
			
	while (x != 1)		//traversing the list
	{
		temp = temp->next;
		temp2 = temp2->next;
		x--;
	}
	temp2->next = temp->next;	
	temp->next->prev = temp2;
	free(temp);			//removing the node entered
	temp = NULL;
}

void deleteLastNode(Node*& head)	//function to delete the last node
{
	//creating pointers
	Node* temp = head->next;		//temp2 pointer is pointing to the head node
	Node* ptr = head;

	while (temp->next != NULL)		//traversing the list
	{
		temp = temp->next;
	}

	ptr = temp->prev;
	ptr->next = NULL;
	free(temp);			//removing the last node
	temp = NULL;
}
