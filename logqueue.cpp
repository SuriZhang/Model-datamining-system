// implementation of log queue
#include <iostream>
using namespace std;
#include "logqueue.h"
#define MAX_LOGS 1024*1024
LogQueue g_logQueue;
// constructor
LogQueue::LogQueue (void) {
	// Synchronous mutex
	pthread_mutex_init (&m_mutex, 0);
	// Non full condition 
	pthread_cond_init (&m_full, 0);
	// non-empty conditions
	pthread_cond_init (&m_empty, 0);
}
// deconstructor
LogQueue::~LogQueue (void) {
	// destory non-empty conditions
	pthread_cond_destroy (&m_empty);
	// destory full condiction
	pthread_cond_destroy (&m_full);
	// destory mutex
	pthread_mutex_destroy (&m_mutex);
}
// push log 
LogQueue& LogQueue::operator<< (MLogRec const& log) {
	cout << "Pushing logs..." << endl;
	pthread_mutex_lock (&m_mutex);
	while (m_logs.size () >= MAX_LOGS) {
		cout << "Wait Log queues non-full..." << endl;
		pthread_cond_wait (&m_full, &m_mutex);
	}
	m_logs.push_back (log);
	pthread_cond_signal (&m_empty);
	pthread_mutex_unlock (&m_mutex);
	cout << "Logs pushed." << endl;
	return *this;
}
// pop log
LogQueue& LogQueue::operator>> (MLogRec& log) {
	cout << "Pop logs..." << endl;
	pthread_mutex_lock (&m_mutex);
	while (m_logs.empty ()) {
		cout << "Wait log queues non-full..." << endl;
		pthread_cond_wait (&m_empty, &m_mutex);
	}
	log = m_logs.front ();
	m_logs.pop_front ();
	pthread_cond_signal (&m_full);
	pthread_mutex_unlock (&m_mutex);
	cout << "Logs popped." << endl;
	return *this;
}
