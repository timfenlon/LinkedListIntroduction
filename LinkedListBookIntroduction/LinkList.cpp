#include "stdafx.h"
#include "LinkList.h"
#include <string>
#include <iostream>

using namespace std;

CListBase::CListBase(void)
: mHead(nullptr)
{
	cout << "CListBase() ctor" << endl;
}

CListBase::~CListBase(void)
{
	cout << "~CListBase() dtor" << endl;

	//Delete our dynamically allocated data on heap
	if(mHead != NULL)
		deleteNodes(const_cast<const CNode*>(mHead));
	mHead = NULL;

}

//derived class should implement
bool CListBase::createNodes()
{
	cout << "CListBase()::createNodes()" << endl;
	return true;
}

//Recursive Delete Nodes Function
void CListBase::deleteNodes(const CNode * head)
{
	if(head == NULL)
		return;
	//Recursive call
	deleteNodes(const_cast<const CNode*>(head->mNext));
	cout << "CListBase()::deleteNodes(node: "<< head->mData << " )" << endl;
	//now delete the Node
	delete head;
}

//Looping Delete Nodes Function
void CListBase::deleteNodesLoop(const CNode * head)
{
	if(head == NULL)
		return;
	CNode * currNode = const_cast<CNode*>(head);
	CNode * nextNode = NULL;
	while(currNode != NULL)
	{
		cout << "CListBase()::deleteNodesLoop(node: "<< currNode->mData << " )" << endl;
		nextNode = currNode->mNext;
		delete currNode;
		currNode = nextNode;
	};
}

//Looping Print Nodes Function
void CListBase::printNodesLoop(const CNode * head)
{
	if(head == NULL)
		return;
	CNode * currNode = const_cast<CNode*>(head);
	while(currNode != NULL)
	{
		cout << "CListBase()::printNodesLoop(node: "<< currNode->mData << " )" << endl;
		currNode = currNode->mNext;

	}
}

//Recursive Print Nodes Function
void CListBase::printNodes(const CNode * head)
{
	if(head == NULL)
		return;
	cout << "CListBase()::printNodes(node: "<< head->mData << " )" << endl;
	//Recursive call
	printNodes(head->mNext);
}

//Recursive Print Nodes in Reverse Function
void CListBase::printNodesReverse(const CNode * head)
{
	if(head == NULL)
		return;
	//Recursive call
	printNodesReverse(head->mNext);
	cout << "CListBase()::printNodesReverse(node: "<< head->mData << " )" << endl;
}

//Recursive Print Nodes Function
void CListBase::printAltNodes(const CNode * head)
{
	if(head == NULL)
		return;
	//Recursive call
	cout << "CListBase()::printAltNodes(node: "<< head->mData << " )" << endl;
	printAltNodes((head->mNext->mNext));
}

//Recursive Print Nodes in Reverse Function
void CListBase::printAltNodesReverse(const CNode * head)
{
	if(head == NULL)
		return;
	//Recursive call
	printAltNodesReverse((head->mNext->mNext));
	cout << "CListBase()::printAltNodesReverse(node: "<< head->mData << " )" << endl;
}

//Init Global Static which is local static
CLinkList* CLinkList::mCLinkListPtr = NULL;

CLinkList::CLinkList(void)
{
	cout << "CLinkList() ctor" << endl;
}


CLinkList::~CLinkList(void)
{
	cout << "~CLinkList() ctor" << endl;
	CLinkList::mCLinkListPtr = NULL;
}

#if 0
CLinkList& CLinkList::getSingleton()
{
	//create local static in function
	static CLinkList linkList;
	return linkList;
}
#else
CLinkList* CLinkList::getSingleton()
{
	if(CLinkList::mCLinkListPtr == NULL)
		CLinkList::mCLinkListPtr = new CLinkList();
	return CLinkList::mCLinkListPtr;
}
#endif

bool CLinkList::createNodes()
{
	//CListBase::createNodes();
	cout << "CLinkList()::createNodes()" << endl;

	//Create Head Node and Save a pointer to its location
	this->mHead = new CNode();
	this->mHead->mData = 1;
	//Create 2nd Node as Temp
	CNode* tmpNode = new CNode();
	tmpNode->mData = 2;
	//Point Head to next Node tmpNode
	this->mHead->mNext = tmpNode;
	//Create 3rd Node as Temp2
	CNode* tmpNode2 = new CNode();
	tmpNode2->mData = 3;
	//Point 2nd Node to 3rd node
	tmpNode->mNext = tmpNode2;
	//Reuse tmpNode, create 4th node
	tmpNode = new CNode();
	tmpNode->mData = 4;
	//Point 3rd Node to 4th Node
	tmpNode2->mNext = tmpNode;
	//Point 4th Node - Last Node to NULL
	tmpNode->mNext = NULL;

	return true;
}