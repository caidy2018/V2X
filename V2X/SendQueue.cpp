#include "SendQueue.h"

SendQueue::SendQueue()
{
}

SendQueue::SendQueue(long ID, queue<SliceMessage> & qsm)
{//初始化操作
	nodeID = ID;
	sendQueue = &qsm;
}

SendQueue::~SendQueue()
{
	//delete sendQueue;
}

queue<SliceMessage>* SendQueue::getSendQueue()
{//获取发送队列的指针
	if (!isEmpty()) {
		return sendQueue;
	}
	else return NULL;
}

bool SendQueue::isEmpty()
{//判断发送队列是否为空
	return (*sendQueue).empty();
}

void SendQueue::addMessage(SliceMessage &sMsg)
{//向发送队列添加消息
	(*sendQueue).push(sMsg);
}

SliceMessage* SendQueue::getMessage()
{//获取发送队列头消息并删除
	if ((*sendQueue).empty() != true) {
		SliceMessage *sMsg = NULL;
		sMsg = &((*sendQueue).front());
		(*sendQueue).pop();
		return sMsg;
	}
}

int SendQueue::getSize()
{//获取发送队列大小
	return (*sendQueue).size();
}

long SendQueue::getNodeID()
{
	return nodeID;
}

void SendQueue::setNodeID(long id)
{
	nodeID = id;
}

int SendQueue::getBackOffCount()
{
	return backOffCount;
}

void SendQueue::setBackOffCount(int count)
{
	backOffCount = count;
}

bool SendQueue::getBackOff()
{
	return backOff;
}

void SendQueue::setBackOff(bool back)
{
	backOff = back;
}

