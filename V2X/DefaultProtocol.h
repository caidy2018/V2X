#pragma once
#ifndef DEFAULTPROTOCOL_H
#define DEFAULTPROTOCOL_H

#include "Message.h"
#include "SliceMessage.h"
#include "SendQueue.h"
#include "CommunicationNode.h"
#include "Protocol.h"
#include <list>

/*
 *默认协议栈
*/
class DefaultProtocol : public Protocol
{
public:
	DefaultProtocol();

	//消息分片
	std::list<SliceMessage>* cutMessage(std::list<Message> &lm) override;//切割消息
	//消息组装
	std::list<Message>* mergeMessage(std::list<SliceMessage> &lsm) override;//整合消息
	//单独一个队列的退避算法
	void backOffAQueue(CommunicationNode &communicationNode) override;
	//对退避算法的相应处理
	void preBackOff(std::list<CommunicationNode> communicationNodes) override;
};

#endif