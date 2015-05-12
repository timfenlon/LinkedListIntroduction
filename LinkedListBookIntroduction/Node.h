#pragma once

//Just for reference a c style struct can be used
typedef struct node {
	int data;
	node * next;
} NODE;

//We choose a class CNode for our examples
class CNode
{
public:
	CNode(void);
	~CNode(void);

	int mData;
	CNode* mNext;
};

