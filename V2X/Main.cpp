#include "SendQueue.h"
#include "ReceiveQueue.h"
#include "DelieveQueue.h"
#include "CommunicationNode.h"
#include "MessageTransferManagement.h"
#include "constUtil.h"
#include "Util.h"
#include <stdio.h>
#include <stdlib.h>
#include "ProcessManagement.h"
#include "ProtocolFactory.h"
#include "DefaultProtocolFactory.h"
#include "ChannelFactory.h"
#include "DefaultChannelFactory.h"
#include "Crowd.h"
#include "DefaultCrowd.h"
#include "CrowdFactory.h"
#include "DefaultCrowdFactory.h"

using namespace std;

int main(int argc, char* argv[])
{
	//初始化通信节点
	list<CommunicationNode> *comNode = new list<CommunicationNode>;

	//初始化协议栈
	ProtocolFactory *f = new DefaultProtocolFactory();
	Protocol *protocol = (*f).CreateProtocol();

	//初始化物理信道
	ChannelFactory *c = new DefaultChannelFactory();
	Channel *channel = (*c).CreateChannel();

	//初始化分簇过程
	CrowdFactory *cf = new DefaultCrowdFactory();
	Crowd *crowd = (*cf).CreateCrowd();

	//模拟测试
	
	Message ma = Message(1, 1, 2, 360);
	Message ma_1 = Message(3, 1, 3, 40);
	list<Message> *lma_s = new list<Message>;
	(*lma_s).push_back(ma);
	(*lma_s).push_back(ma_1);
	queue<SliceMessage> *qsa_s = new queue<SliceMessage>;
	SendQueue sqa = SendQueue(1, (*qsa_s));
	queue<SliceMessage> *qsa_r = new queue<SliceMessage>;
	ReceiveQueue rqa = ReceiveQueue(1, (*qsa_r));
	list<Message> *lma_r = new list<Message>;
	CommunicationNode A = CommunicationNode(1, 111, 123, 60, 90, 80, 30, (*lma_s), (*lma_r), sqa, rqa);
	A.setHaveMessage(true);
	
	Message mb = Message(2, 2, 1,360);
	Message mb_1 = Message(4, 2, 3, 40);
	list<Message> *lmb_s = new list<Message>;
	(*lmb_s).push_back(mb);
	(*lmb_s).push_back(mb_1);
	queue<SliceMessage> *qsb_s = new queue<SliceMessage>;
	SendQueue sqb = SendQueue(1, (*qsb_s));
	queue<SliceMessage> *qsb_r = new queue<SliceMessage>;
	ReceiveQueue rqb = ReceiveQueue(1, (*qsb_r));
	list<Message> *lmb_r = new list<Message>;
	CommunicationNode B = CommunicationNode(2, 111, 123, 60, 90, 80, 30, (*lmb_s), (*lmb_r), sqb, rqb);
	B.setHaveMessage(true);
	
	Message mc = Message(3, 3, 1, 360);
	list<Message> *lmc_s = new list<Message>;
	(*lmc_s).push_back(mc);
	queue<SliceMessage> *qsc_s = new queue<SliceMessage>;
	SendQueue sqc = SendQueue(1, (*qsc_s));
	queue<SliceMessage> *qsc_r = new queue<SliceMessage>;
	ReceiveQueue rqc = ReceiveQueue(1, (*qsc_r));
	list<Message> *lmc_r = new list<Message>;
	CommunicationNode C = CommunicationNode(3, 111, 123, 60, 90, 80, 30, (*lmc_s), (*lmc_r), sqc, rqc);
	C.setHaveMessage(true);
	/*
	Message md = Message(4, 4, 1, 360);
	list<Message> *lmd_s = new list<Message>;
	(*lmd_s).push_back(md);
	queue<SliceMessage> *qsd_s = new queue<SliceMessage>;
	SendQueue sqd = SendQueue(1, (*qsd_s));
	queue<SliceMessage> *qsd_r = new queue<SliceMessage>;
	ReceiveQueue rqd = ReceiveQueue(1, (*qsd_r));
	list<Message> *lmd_r = new list<Message>;
	CommunicationNode D = CommunicationNode(4, 111, 123, 60, 90, 80, 30, (*lmd_s), (*lmd_r), sqd, rqd);
	D.setHaveMessage(true);

	Message me = Message(5, 5, 1, 360);
	list<Message> *lme_s = new list<Message>;
	(*lme_s).push_back(me);
	queue<SliceMessage> *qse_s = new queue<SliceMessage>;
	SendQueue sqe = SendQueue(1, (*qse_s));
	queue<SliceMessage> *qse_r = new queue<SliceMessage>;
	ReceiveQueue rqe = ReceiveQueue(1, (*qse_r));
	list<Message> *lme_r = new list<Message>;
	CommunicationNode E = CommunicationNode(5, 111, 123, 60, 90, 80, 30, (*lme_s), (*lme_r), sqe, rqe);
	E.setHaveMessage(true);

	Message mf = Message(6, 6, 1, 360);
	list<Message> *lmf_s = new list<Message>;
	(*lmf_s).push_back(mf);
	queue<SliceMessage> *qsf_s = new queue<SliceMessage>;
	SendQueue sqf = SendQueue(1, (*qsf_s));
	queue<SliceMessage> *qsf_r = new queue<SliceMessage>;
	ReceiveQueue rqf = ReceiveQueue(1, (*qsf_r));
	list<Message> *lmf_r = new list<Message>;
	CommunicationNode F = CommunicationNode(6, 111, 123, 60, 90, 80, 30, (*lmf_s), (*lmf_r), sqf, rqf);
	F.setHaveMessage(true);

	Message mg = Message(7, 7, 1, 360);
	list<Message> *lmg_s = new list<Message>;
	(*lmg_s).push_back(mg);
	queue<SliceMessage> *qsg_s = new queue<SliceMessage>;
	SendQueue sqg = SendQueue(1, (*qsg_s));
	queue<SliceMessage> *qsg_r = new queue<SliceMessage>;
	ReceiveQueue rqg = ReceiveQueue(1, (*qsg_r));
	list<Message> *lmg_r = new list<Message>;
	CommunicationNode G = CommunicationNode(7, 111, 123, 60, 90, 80, 30, (*lmg_s), (*lmg_r), sqg, rqg);
	G.setHaveMessage(true);

	Message mh = Message(8, 7, 1, 360);
	list<Message> *lmh_s = new list<Message>;
	(*lmh_s).push_back(mh);
	queue<SliceMessage> *qsh_s = new queue<SliceMessage>;
	SendQueue sqh = SendQueue(1, (*qsh_s));
	queue<SliceMessage> *qsh_r = new queue<SliceMessage>;
	ReceiveQueue rqh = ReceiveQueue(1, (*qsh_r));
	list<Message> *lmh_r = new list<Message>;
	CommunicationNode H = CommunicationNode(8, 111, 123, 60, 90, 80, 30, (*lmh_s), (*lmh_r), sqh, rqh);
	H.setHaveMessage(true);
	*/
	(*comNode).push_back(A);
	(*comNode).push_back(B);
	(*comNode).push_back(C);
	//(*comNode).push_back(D);
	//(*comNode).push_back(E);
	//(*comNode).push_back(F);
	//(*comNode).push_back(G);
	//(*comNode).push_back(H);

	//开始模拟
	ProcessManagement process;
	process.startSimulation(*comNode, *protocol, *channel, *crowd);
		
	//cout << "A sendMessage size: " << A.getMessageToRecv()->size() << endl;
	//cout << "B sendMessage size: " << B.getMessageToRecv()->size() << endl;
	//cout << "C sendMessage size: " << C.getMessageToRecv()->size() << endl;

	cout << "A get message example:" << endl;
	Message am = A.getMessageToRecv()->back();
	cout << "mID: " << (am).getMessageID() << " sID: " << (am).getSourceAddress() << " rID: " << (am).getDestinationAddress()
		<< " size: " << (am).getSize() << endl;
		
	cout << "B get message example:" << endl;
	Message bm = B.getMessageToRecv()->back();
	cout << "mID: " << (bm).getMessageID() << " sID: " << (bm).getSourceAddress() << " rID: " << (bm).getDestinationAddress()
		<< " size: " << (bm).getSize() << endl;
		
	delete lma_s, qsa_s, qsa_r, lma_r;
	delete lmb_s, qsb_s, qsb_r, lmb_r;
	delete lmc_s, qsc_s, qsc_r, lmc_r;
	//delete lmd_s, qsd_s, qsd_r, lmd_r;
	//delete lme_s, qse_s, qse_r, lme_r;
	//delete lmf_s, qsf_s, qsf_r, lmf_r;
	//delete lmg_s, qsg_s, qsg_r, lmg_r;
	//delete lmh_s, qsh_s, qsh_r, lmh_r;

	system("pause");
	return 0;
}