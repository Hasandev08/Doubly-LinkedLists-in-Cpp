//Header files
#include<iostream>
#include<windows.h>		//Header file for inserting colors and beep sound
#include<stdlib.h>
#include"menu.h"		
using namespace std;

int main()
{
	//creating nodes of the linked list
	Node* head = new Node();
	Node* temp = new Node();
	Node* temp1 = new Node();
	Node* temp2 = new Node();
	Node* temp3 = new Node();
	Node* temp4 = new Node();

	//passing values to the nodes
	head->num = 22;
	head->data = "Rose";
	head->prev = NULL;			//head node
	head->key = 1;
	head->next = temp;

	temp->num = 37; 
	temp->key = 2;
	temp->data = "Sunflower";	//2nd node
	temp->prev = head;			
	temp->next = temp1;			
	head->next = temp;

	temp1->num = 54;
	temp1->key = 3;
	temp1->data = "Jasmine";	//3rd node
	temp1->prev = temp;
	temp1->next = temp2;		
	temp->next = temp1;

	temp2->num = 69;
	temp2->key = 4;
	temp2->data = "Iris";		//4th node
	temp2->prev = temp1;
	temp2->next = temp3;		
	temp1->next = temp2;

	temp3->num = 73;
	temp3->key = 5;
	temp3->data = "Tulips";		//5th node
	temp3->prev = temp2;
	temp3->next = NULL;			
	temp2->next = temp3;

	Node* ptr = head;		//ptr pointer pointing to the head node

	for (int i = 0; i < 10; i++)
	{
		system("cls");
		system("color 8B");		//setting color of code and the background color

		{
			for (int j = 1; j < i; j++)
			{
				cout << "\n";
			}
		}
		menu();
		Sleep(25);
	}
	Beep(3000, 500);		//for making beep sound
	Sleep(10);
	Beep(2000, 1000);

	system("cls");
	menu();

	char operation;

	do
	{
		string data;
		string y;
		int num;

		//*********************************************    MENU    **************************************************
		start:
		cout << "Select the option that you want to perform " << endl;
		cout << "   1. Insert any page " << endl;
		cout << "   2. Delete any page" << endl;
		cout << "   3. Update any page " << endl;
		cout << "   4. Display " << endl;
		cout << "   5. To display the PAGE NAME " << endl;
		cout << "   0. To End the program " << endl;
		cin >> operation;
	
		switch (operation)		//switch case
		{
			case '1':
				system("cls");
				menu();
				
				char z;
				cout << "Enter the page NAME that you want to insert in the list " << endl;
				cin >> data;

				cout << "Enter the number of IMAGES that you want to insert on the page " << endl;
				cin >> num;

				system("cls");
				menu();
				cout << "Select any option from the following " << endl;
				cout << "   1. Insert data at the beginning " << endl;
				cout << "   2. Insert data at any desired position " << endl;
				cout << "   3. Insert data at the end " << endl;
				cout << "   4. Exit to main menu " << endl;
				cin >> z;

				switch (z)		//nested switch case for insertion
				{
					case '1':	//for inserting at the start
						insertNodeAtStart(head, data, num);		//calling the function to insert the data at start
						temp4 = head;
						system("cls");
						menu();
						break;

					case '2':		//for insertion at any position
						int pos;
						cout << "Enter the position at which you want to insert the new page " << endl;
						cin >> pos;
						insertNodeAtPos(head, data, num, pos);		//calling the function to insert data at any position
						system("cls");
						menu();
						break;

					case '3':		//for insertion at the end position
						insertNodeAtEnd(head, data, num);		//calling the function to insert data at the end
						system("cls");
						menu();
						break;

					case '4':		//for moving to main menu
						system("cls");
						menu();
						goto start;
						break;
				}
				break;

			case '2':			//for deletion
				system("cls");
				menu();
				
				char op;
				
				//*********************************************    MENU    **************************************************

				cout << "Select the options from the following " << endl;
				cout << "   1. Delete 1st page " << endl;
				cout << "   2. Delete desired page " << endl;
				cout << "   3. Delete the last page " << endl;
				cout << "   4. Exit to main menu " << endl;
				cin >> op;

				switch (op)		//nested switch case for deletion
				{
					case '1':		//for deletion of head node
						if (head->next == NULL)
						{
							cout << "There is no page left " << endl;		//if there is no node is left to be deleted this message will be displayed
							cout << endl;
						}
						
						else
						{
							deleteNodeAtStart(head);		//calling the function for deletion of head node
							system("cls");
							menu();	
						}
						break;
						
					case '2':		//for deletion of data at any position
						int s;

						cout << "Enter the position of the page which you want to be deleted " << endl;
						cin >> s;

						deleteNodeAtPos(head, s);		//calling the function for deletion of data at any position
						system("cls");
						menu();
						break;

					case '3':		//for deletion of the last node
						if (head->next == NULL)
						{
							cout << "There is no page left " << endl;		//if there is no node is left to be deleted this message will be displayed
							cout << endl;
						}
						
						else
						{
							deleteLastNode(head);		//calling the function to delete the last node
							system("cls");
							menu();
						}					
						
						break;

					case '4':		//for moving to main menu
						system("cls");
						menu();
						goto start;
						break;
				}
				break;

			case '3':		//for updating
				system("cls");
				menu();
				
				int i;
				int p;

				cout << "Enter the NAME that you want to be updated in the page " << endl;
				cin >> y;

				cout << "Enter the NUMBER of IMAGES you want to be updated on the page " << endl;
				cin >> i;

				cout << "Enter the position at which you want to update the data you entered " << endl;
				cin >> p;

				updateNode(head, y, i, p);		//calling the function to update any node in the list
				system("cls");
				menu();
				break;

			case '4':		//for printing the nodes
				system("cls");
				menu();

				char d;

				//*********************************************    MENU    **************************************************

				cout << "Select the option from the following " << endl;
				cout << "   1. Print the pages in ascending order " << endl;
				cout << "   2. Print the pages in descending order " << endl;
				cout << "   3. Exit to main menu " << endl;
				cin >> d;

				switch(d)
				{
					case '1':		//for printing in ascending order
						printForward(head);		//calling the function
						break;

					case '2':		//for printing in descending order
						printBackward(head);	//calling the funtion
						break;

					case '3':		//for moving to main menu
						system("cls");
						menu();
						goto start;
						break;
				}
				break;

			case '5':		//for printing the names of the pages
				char u;

				//*********************************************    MENU    **************************************************
				b:
				system("cls");
				menu();
				cout << "Select any option " << endl;
				cout << "   1. Get NAME of page by no.of images " << endl;
				cout << "   2. Get NAME of page by page number " << endl;
				cout << "   3. Exit to main menu " << endl;
				cin >> u;
				
				ptr = head;
				bool flag = false;
				char s;
				
				switch (u)
				{
					case '1':		//for printing name through no.of images
						system("cls");
						menu();
						int h;
								
						cout << "Enter the number of images of the page whose name you want " << endl;
						cin >> h;
						cout << endl;
	
						if(ptr)
						{
							while(ptr != NULL)
							{
								if(ptr->num == h) 
									flag = true;
				
								ptr = ptr->next;
							}
						}
						// end of search function
	
						if (flag) //checking if search function found that data in list
						{
							cout << "The name of the Page is : ";
							if (h == head->num)
								cout << getFirstPageNameFromNumber(head, h);	  //calling the function for printing the name of 1st page
								
							else
								cout << getPageNameFromNumber(head, h);			//calling the function for printing name of any page
						}
						
						else
						{
							//if user enters any page number that is not present 
							cout << "The number of images entered is not present in the list. Do you want to try again? (Y/N)" << endl;
							d:
							cin >> s;
							
							//different conditions for user to end or continue the program
							if (s == 'Y' || s == 'y')
								goto b;
								
							else if (s == 'N' || s == 'n')
							{
								system("cls");
								menu();
								
								cout << "Select the option " << endl;
								h:
								cout << "   0. To End the program " << endl;
								cout << "   1. Perform another operation " << endl;			
								cin >> s;
								
								if (s == '0')
									return 0;
									
								else if (s == '1')
								{
									system("cls");
									menu();
									goto start;
								}
									
								else
								{
									cout << endl;
									cout << "Invalid input " << endl;
									cout << endl;
									cout << "Enter correct option " << endl;
									goto h;
								}		
							}
							
							else
							{
								cout << endl;
								cout << "Invalid input " << endl;
								cout << endl;
								cout << "Enter correct option (Y/N) " << endl;
								goto d;		
							}		
						}
						
						cout << endl;
						cout << endl;
						break;

					case '2':		//for printing the name of the page through position
						system("cls");
						menu();
						int k;

						cout << "Enter the page number whose name you want to be displayed " << endl;
						cin >> k;

						cout << "The name of the Page is : ";
						if (k == head->key)
							cout << getFirstPageName(head, k);		//calling the function to print the name of the 1st page

						else
							cout << getPageName(head, k);		//calling the function to print the name of any page

						cout << endl;
						cout << endl;
						break;

					case '3':			//for moving to main menu
						system("cls");
						menu();
						goto start;
						break;
				}

				break;
		}
	} while (operation != '0');		//if user enters '0' the program will be ended

	return 0;
}
