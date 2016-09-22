// implementation of client threads
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;
#include "clientthread.h"
#include "logqueue.h"
// creator
ClientThread::ClientThread (int connfd) :
	m_connfd (connfd) {}
// client thread
void ClientThread::run (void) {
	MLogRec log;
	// every time the sever receives a thread
	for (;;) {
		ssize_t rlen = recv (m_connfd, (char*)&log,
			sizeof (log), 0);
		if (rlen <= 0)
			break;
		log.pid = ntohl (log.pid);
		log.logintime = ntohl (log.logintime);
		log.logouttime = ntohl (log.logouttime);
		log.durations = ntohl (log.durations);
		g_logQueue << log;
	}
	close (m_connfd);
	delete this;
}
