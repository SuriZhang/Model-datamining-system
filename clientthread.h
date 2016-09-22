// declaration fo client thread
#ifndef _CLIENTTHREAD_H
#define _CLIENTTHREAD_H
#include "logthread.h"
// client thread
class ClientThread : public LogThread {
public:
	// creator
	ClientThread (int connfd);
private:
	// processing threads
	void run (void);
	int m_connfd; // connect to socket
};
#endif // _CLIENTTHREAD_H
