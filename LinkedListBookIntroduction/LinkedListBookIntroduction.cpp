// LinkedListBookIntroduction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LinkList.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	bool loopMenu = true;
	//Create our Linked List Object
	CLinkList * myList = CLinkList::getSingleton();

	while(loopMenu)
	{
		cout << "Linked List Introduction" << endl;
		cout << "1. Create Nodes" << endl;
		cout << "2. Print Nodes using recursion" << endl;
		cout << "3. Print Nodes in reverse using recursion" << endl;
		cout << "4. Print Nodes using a loop" << endl;
		cout << "5. Print Alt Nodes using recursion" << endl;
		cout << "6. Print Alt Nodes in reverse using recursion" << endl;
		cout << "7. Delete All Nodes using recursion" << endl;
		cout << "8. Delete All Nodes using a loop" << endl;
		cout << "Q. Exit" << endl;
		string choice;
		getline(std::cin, choice);
		if((choice[0] == 'Q')||(choice[0] == 'q'))
		{
			loopMenu = false;
			cout << "Quit Pressed...exited" << endl;
			continue;
		}
		int num_choice = atoi(choice.c_str());
		switch(num_choice)
		{
		case 1:
			{
				myList->createNodes();
			}
			break;
		case 2:
			{
				//Print with Recursion
				myList->mTimer.setStartTime();
				//Print the Nodes in Forward Order
				myList->printNodes(myList->mHead);
				cout << "Elapsed Time: " << (myList->mTimer.getElapsedMillis()) << " ms" << endl;
			}
			break;
		case 3:
			{
				//Print with Recursion
				//Print the Nodes in Reverse Order
				myList->printNodesReverse(myList->mHead);
			}
			break;
		case 4:
			{
				myList->mTimer.setStartTime();
				myList->printNodesLoop(myList->mHead);
				cout << "Elapsed Time: " << (myList->mTimer.getElapsedMillis()) << " ms" << endl;
			}
			break;
		case 5:
			{
				//Print with Recursion
				//Print the Nodes in Reverse Order
				myList->printAltNodes(myList->mHead);
			}
			break;
		case 6:
			{
				myList->printAltNodesReverse(myList->mHead);
			}
			break;
		case 7:
			{
				//Print with Recursion
				//Print the Nodes in Reverse Order
				myList->mTimer.setStartTime();
				myList->deleteNodes(myList->mHead);
				myList->mHead = NULL;
				cout << "Elapsed Time: " << (myList->mTimer.getElapsedMillis()) << " ms" << endl;
			}
			break;
		case 8:
			{
				myList->mTimer.setStartTime();
				myList->deleteNodesLoop(myList->mHead);
				myList->mHead = NULL;
				cout << "Elapsed Time: " << (myList->mTimer.getElapsedMillis()) << " ms" << endl;
			}
			break;
		default:
			{
				cout << "Unrecognized Command: enter number 1, 2, 3 ..." << endl;
			}
			break;
		}
	}//end while
	return 0;
}

