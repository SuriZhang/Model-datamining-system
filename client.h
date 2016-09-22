// client declaration
#ifndef _CLIENT_H
#define _CLIENT_H
#include "logreader.h"
#include "logsender.h"
// Client
class Client {
public:
	// creator
	Client (LogReader& reader, LogSender& sender);
	// data mining
	void dataMine (void) throw (ClientException);
private:
	LogReader& m_reader; 
	LogSender& m_sender; 
};
#endif // _CLIENT_H
