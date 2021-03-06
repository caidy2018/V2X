#pragma once
#include "CommunicationNode.h"
#include "Crowd.h"
#include <list>
/*
 *默认的分簇类
*/
class DefaultCrowd : public Crowd {
	//分簇过程
public:
	DefaultCrowd();
	std::list<std::list<CommunicationNode>>* getCrowds(list<CommunicationNode> communicationNode);
};