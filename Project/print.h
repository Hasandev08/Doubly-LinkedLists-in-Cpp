//Header files
#include<iostream>
#include<windows.h>		//Header file for inserting colors and beep sound
#include<stdlib.h>		
#include"update.h"
using namespace std;

void printForward(Node* head)		//to print the list in the ascending order
{
	Node* ptr = head;		//ptr pointer pointing to the head node
	
	if (head->next == NULL)
	{
		cout << "There is no page left " << endl;		//if there is no node is left to be deleted this message will be displayed
		cout << endl;
	}
						
	else
	{
		if (ptr)
		{
			while (ptr != NULL)		//traversing the node till the last node
			{
				cout << "Name of page : " << ptr->data << endl;
				cout << "Number of images : " << ptr->num << endl;
				cout << endl;
				ptr = ptr->next;
			}
		}
	}
}

void printBackward(Node* head)		//to print the list in the descending order
{
	Node* ptr = head;		//declaring a pointer pointing at the head node
	head->prev = NULL;
						
	if (ptr)
	{
		while (ptr->next != NULL)	//traversing the node till the last node
		{
			ptr = ptr->next;
		}
		head = ptr;		//making the last node as the head node

		while (ptr != NULL)		//printing the list in the opposite direction
		{
			if (ptr)
			{
				cout << "Name of page : " << ptr->data << endl;
				cout << "Number of images : " << ptr->num << endl;
				cout << endl;
				ptr = ptr->prev;
			}
		}
	}
}

