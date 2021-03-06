#pragma once

/*
 *分片消息类
*/
class SliceMessage
{
public://公用接口
	/*******构造函数*********/
	SliceMessage();
	SliceMessage(long mID, long sID, long rID, int s, bool flag, int Sequence);
	//析构函数
	~SliceMessage();

	/**********信息函数：获取消息的相关信息*********/
	//获取消息ID
	long getMessageID();
	//获取源地址
	long getSourceAddress();
	//获取目的地址
	long getDestinationAddress();
	//获取消息大小
	int getSize();
	//获取消息类型
	int getMessageType();
	//获取分片标志位
	bool getFlag();
	//获取片偏移
	int getSequence();
	//获取误码消息位
	bool getError();
	//获取时延
	float getDelay();
	//获取所述消息总长度
	int getTotalSize();

	//设置源地址
	void setSourceAddress(long sourceAddress);
	//设置目的地址
	void setDestinationAddress(long destinationAddress);
	//设置消息大小
	void setSize(int size);
	//设置消息类型
	void setMessageType(int messageType);
	//设置分片标志位
	void setFlag(bool flag);
	//设置片偏移
	void setSequence(int sequence);
	//设置误码位
	void setError(bool error);
	//设置消息的时延
	void setDelay(float delay);
	//设置消息ID
	void setMessageID(long id);
	//设置分片消息所属消息总长度
	void setTotalSize(int size);

private://消息内部变量
	long MessageID;			   //消息ID
	long SourceAddress;        //消息的源地址
	long DestinationAddress;   //消息的目的地址，目的地址为-1时表示广播
	int Size;                  //消息大小
	int MessageType;           //消息类型
	bool Flag;                  //是否有下一个分片的标志位
	int Sequence;              //片偏移
	bool Error = false;      //是否是误码消息
	float Delay = 0;           //时延
	int TotalSize = 0;			//该分片消息所属消息总长度	
};
