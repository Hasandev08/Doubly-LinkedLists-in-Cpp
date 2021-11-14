//Header files
#include<iostream>
#include<windows.h>		//Header file for inserting colors and beep sound
#include<stdlib.h>		
#include"print.h"
using namespace std;

string getFirstPageNameFromNumber(Node* head, int num)		//function to get the page name of 1st page from number of images
{
	Node* temp = new Node();		//creating a new node
	Node* ptr = head;			//creating a pointer pointing at the head
	temp->num = num;

	return ptr->data;		//the string present in the head is returned
}

string getPageNameFromNumber(Node* head, int num)		//function to get the page name of any page from number of images
{
	Node* temp = new Node();		//creating a new node
	Node* ptr = head;			//creating a pointer pointing to the head
	temp->num = num;

	if (ptr)
	{
		while (ptr->next != NULL)		//traversing the list
		{
			ptr = ptr->next;
			if (ptr->num == temp->num)
			{
				return ptr->data;		//returning the string of the specific number
				break;
			}
			
		}
	}
}

string getFirstPageName(Node* head, int k)		//function to get the page name of 1st page from the position
{
	Node* temp = new Node();		//creating a new node
	Node* ptr = head;			//creating a pointer pointing at the head
	temp->key = k;

	return ptr->data;		//the string present in the head is returned
}

string getPageName(Node* head, int k)		//function to get the page name of any page from the position
{
	Node* temp = new Node();		//creating a new node
	Node* ptr = head;			//creating a pointer pointing to the head
	temp->key = k;

	if (ptr)
	{
		while (ptr->next != NULL)		//traversing the list
		{
			ptr = ptr->next;
			if (ptr->key == temp->key)
			{
				return ptr->data;		//returning the string of the specific number
				break;
			}

		}
	}
}

