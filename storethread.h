// declaration of storethread
#ifndef _STORETHREAD_H
#define _STORETHREAD_H
#include "logthread.h"
#include "logdao.h"
// store thread
class StoreThread : public LogThread {
public:
	// constructor
	StoreThread (LogDao& dao);
private:
	// processing threads
	void run (void);
	LogDao& m_dao; // dao
};
#endif // _STORETHREAD_H
