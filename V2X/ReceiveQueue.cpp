#include "ReceiveQueue.h"

using namespace std;
ReceiveQueue::ReceiveQueue()
{
}

ReceiveQueue::ReceiveQueue(long id, queue<SliceMessage> &qsm)
{//初始化流程
	nodeID = id;
	receiveQueue = &qsm;
}

ReceiveQueue::~ReceiveQueue()
{
	//delete receiveQueue;
}

long ReceiveQueue::getNodeID()
{//获取发送队列对应节点id
	return nodeID;
}

void ReceiveQueue::setNodeID(long id)
{
	nodeID = id;
}

queue<SliceMessage>* ReceiveQueue::getSliceMessage()
{//获取接收队列的分片消息
	if (!isEmpty())
	{
		return receiveQueue;
	}
	else return NULL;
}

bool ReceiveQueue::isEmpty()
{//判断当前接收队列是否为空
	if ((*receiveQueue).empty()) {
		return true;
	}
	return false;
}

//获取接收队列队头消息并删除
SliceMessage* ReceiveQueue::getMessage()
{
	SliceMessage *sMsg = NULL;
	if ((*receiveQueue).empty() != true) {
		
		sMsg = &((*receiveQueue).front());
		(*receiveQueue).pop();
		
	}
	return sMsg;
}

void ReceiveQueue::addMessage(SliceMessage &sMsg)
{//向接受队列添加消息
	(*receiveQueue).push(sMsg);
}

int ReceiveQueue::getSize()
{//获取接收队列大小
	return (*receiveQueue).size();
}

queue<SliceMessage>* ReceiveQueue::getReceiveQueue()
{//获取接收队列指针
	if (!isEmpty()) {
		return receiveQueue;
	}
	else return NULL;
}
