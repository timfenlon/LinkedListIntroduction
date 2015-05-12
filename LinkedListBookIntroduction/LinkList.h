#pragma once

#include "Node.h"
#include <vector>
#include "ofxMSATimer.h"

class CListBase
{
public:
	CListBase(void);
	virtual ~CListBase(void);

	//virtual classes
	virtual bool createNodes();

	virtual void deleteNodes(const CNode * head);
	virtual void deleteNodesLoop(const CNode * head);

	virtual void printNodesLoop(const CNode * head);
	virtual void printNodes(const CNode * head);
	virtual void printNodesReverse(const CNode * head);
	virtual void printAltNodes(const CNode * head);
	virtual void printAltNodesReverse(const CNode * head);

	CNode* mHead;

	ofxMSATimer mTimer;
};


class CLinkList : public CListBase
{
public:
	CLinkList(void);
	~CLinkList(void);
		
	bool createNodes();
//Make a globally accessible singleton
	//static CLinkList& getSingleton();
	static CLinkList* getSingleton();
	static CLinkList* mCLinkListPtr;
	//implement virtual class
};

