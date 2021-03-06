#include "DelieveQueue.h"
#include "constUtil.h"

DelieveQueue::DelieveQueue()
{
}

DelieveQueue::DelieveQueue(queue<SliceMessage> & qsm)
{//³õÊ¼»¯²Ù×÷
	DelieveQ = &qsm;
}

DelieveQueue::~DelieveQueue()
{
	//delete DelieveQ;
}

bool DelieveQueue::isFull()
{
	if ((*DelieveQ).size() >= CHANNEL_COUNT)
	{
		return true;
	}
	else {
		return false;
	}
}

bool DelieveQueue::isEmpty()
{
	return (*DelieveQ).empty();
}

bool DelieveQueue::insertToDelieveQ(SliceMessage sMsg)
{
	if (isFull()) 
	{
		return false;
	}
	else {
		(*DelieveQ).push(sMsg);
		return true;
	}
}

SliceMessage DelieveQueue::getMessage()
{
	SliceMessage smsg = (*DelieveQ).front();
	(*DelieveQ).pop();
	return smsg;
}

int DelieveQueue::getQueueSize()
{
	return (*DelieveQ).size();
}
