#include "DefaultCrowd.h"
#include "constUtil.h"
#include "Util.h"

using namespace std;

DefaultCrowd::DefaultCrowd()
{
}

//简单分簇方法，在地图上，一堆为一簇
std::list<std::list<CommunicationNode>>* DefaultCrowd::getCrowds(list<CommunicationNode> communicationNode)
{
	cout << "CrowdManagement开始分簇" << endl;
	cout << "CrowdManagement通信节点链表大小：" << communicationNode.size() << endl;
	list<list<CommunicationNode>> *resNode = new list<list<CommunicationNode>>;
	list<CommunicationNode>::iterator iter1;
	list<CommunicationNode>::iterator iter2;
	for (iter1 = communicationNode.begin(); iter1 != communicationNode.end(); iter1++) {
		list<CommunicationNode> *comNodelist = new list<CommunicationNode>;
		for (iter2 = iter1; iter2 != communicationNode.end(); iter2++)
		{
			if ((*iter2).getCrowd() == 1) {
				continue;
			}
			else if ((*comNodelist).size() == 0) {
				(*comNodelist).push_back(*iter2);
				(*iter2).setCrowd(1);
			}
			else {
				list<CommunicationNode>::iterator iter3;
				for (iter3 = (*comNodelist).begin(); iter3 != (*comNodelist).end(); iter3++) {
					if (getDistance((*iter3), (*iter2)) <= REACHDISTANCE) {
						(*comNodelist).push_back(*iter2);
						(*iter2).setCrowd(1);
						break;
					}
				}
			}
		}
		if ((*comNodelist).size() != 0) {
			(*resNode).push_back(*comNodelist);
		}
		
	}
	
	return resNode;
}
