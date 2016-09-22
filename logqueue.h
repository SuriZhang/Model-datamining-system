// declaration of log queue
#ifndef _LOGQUEUE_H
#define _LOGQUEUE_H
#include <pthread.h>
#include <list>
using namespace std;
#include "data.h"
// log queue
class LogQueue {
public:
	// constructor
	LogQueue (void);
	// deconstructor
	~LogQueue (void);
	// push logs
	LogQueue& operator<< (MLogRec const& log);
	// pop logs
	LogQueue& operator>> (MLogRec& log);
private:
	pthread_mutex_t m_mutex; 
	pthread_cond_t  m_full;  
	pthread_cond_t  m_empty; 
	list<MLogRec>   m_logs;  
};
extern LogQueue g_logQueue;
#endif // _LOGQUEUE_H
