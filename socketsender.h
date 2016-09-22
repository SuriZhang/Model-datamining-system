// Declaration of socketsender
#ifndef _SOCKETSENDER_H
#define _SOCKETSENDER_H
#include "logsender.h"
// Socket Sender
class SocketSender : public LogSender {
public:
	// Creator
	SocketSender (string const& failFile,
		short port, string const& ip = "127.0.0.1");
	// Send log
	void sendLog (list<MLogRec>& logs)
		throw (ClientException);
private:
	// Read failed file
	void readFailFile (list<MLogRec>& logs)
		throw (ReadException);
	// connect to sever
	void connectServer (void) throw (SocketException);
	// send data
	void sendData (list<MLogRec>& logs)
		throw (SendException);
	// save failed files
	void saveFailFile (list<MLogRec>& logs)
		throw (SaveException);
	string m_failFile; 
	short  m_port;     
	string m_ip;       
	int    m_sockfd;   
};
#endif // _SOCKETSENDER_H
