//Header files
#include<iostream>
#include<windows.h>		//Header file for inserting colors and beep sound
#include<stdlib.h>		
using namespace std;

struct Node		//using struct to create a node
{
	int num;		//part of node storing the no of images
	int key;		//part of node storing the page number 
	string data;	//part of node storing the names
	Node* prev;		//pointer pointing at the previous node
	Node* next;		//pointer pointing at the next node
};
