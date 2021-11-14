//Header files
#include<iostream>
#include<windows.h>		//Header file for inserting colors and beep sound
#include<stdlib.h>	
#include"struct.h"	
using namespace std;

Node* insertNodeAtStart(Node* &head, string data, int num)	//to insert data at the start of linked list
{
	Node* temp = new Node();	//creating a new node
	//passing values to the part of each node
	temp->data = data;
	temp->num = num;
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;

	return head;
}

void insertNodeAtPos(Node* head, string data, int num, int x)	//to inert data at any position in the list
{
	Node* temp = new Node();		//declaring a new node
	Node* ptr = head;		//pointing the pointer to head
	//passing the values to the new node created
	temp->data = data;
	temp->num = num;

	x--;
	while (x != 1)		//traversing the list
	{
		if (ptr)
		{
			ptr = ptr->next;
			x--;
		}
	}
	Node* ptr1 = ptr->next;		//creating another pointing to the node next to ptr
	//inserting the node entered by the user
	ptr->next = temp;
	ptr1->prev = temp;
	temp->prev = ptr;
	temp->next = ptr1;
}

void insertNodeAtEnd(Node* head, string data, int num)		//to insert data at the end of the list
{
	Node* temp = new Node();	//creating a new node
	//*******passing the data to the newly created node*******
	temp->data = data;
	temp->num = num;
	temp->next = NULL;
	//********************************************************
	Node* ptr = head;	//creating a pointer pointing at the head

	while (ptr->next != NULL)	//traversing the list till the last node
	{
		ptr = ptr->next;
	}

	ptr->next = temp;	//inserting the node at the end of the list
	temp->prev = ptr;
}
