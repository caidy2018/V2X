#pragma once
#include <vector>
#include <list>
#include "CommunicationNode.h"
#include "SendQueue.h"

/*工具类*/

//获取0到n-1之间count个随机数，存到数组a中
void getRandNum(vector<int> &a, int n, int count);

//根据str的内容，获取所有通信节点的信息
std::list<CommunicationNode>* getAllCommunicationNode(string str);

//获取节点ID为id的通信节点
CommunicationNode getNode(std::list<CommunicationNode> comNodes, long id);

//计算两个节点间的距离
double getDistance(CommunicationNode a, CommunicationNode b);

//将CommunicationNode类转换成json串
string communicationToJson(CommunicationNode comNode);