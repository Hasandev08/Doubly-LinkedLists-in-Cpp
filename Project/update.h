//Header files
#include<iostream>
#include<windows.h>		//Header file for inserting colors and beep sound
#include<stdlib.h>	
#include"delete.h"	
using namespace std;

void updateNode(Node* head, string data, int num, int x)		//update function
{
	Node* temp = new Node();	//creating a node that is to be replaced by the already present node
	temp->data = data;		//passing the value (string) entered by the user to the newly created node 
	temp->num = num;		//passing the value (integer) entered by the user to the newly created node
	Node* ptr = head->next;		//creating a pointer that is pointing to next node of head

	if (head == NULL)		//condition if there is no linked list present
	{
		cout << "The list is empty " << endl;
	}

	else if (x == 1)	//condition if user wants to update the head node
	{
		head->data = temp->data;
		head->num = temp->num;
	}

	else		//condition if user wants to update any value in the node
	{
		x--;
		while (x != 1)
		{
			ptr = ptr->next;
			x--;
		}
		ptr->data = temp->data;
		ptr->num = temp->num;
	}
}

