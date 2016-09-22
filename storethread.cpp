// implementation of store thread
#include <iostream>
using namespace std;
#include "storethread.h"
#include "logqueue.h"
// constructor
StoreThread::StoreThread (LogDao& dao) : m_dao (dao) {}
// processing threads
void StoreThread::run (void) {
	MLogRec log;
	for (;;) {
		//  everytime a log pops out
		g_logQueue >> log;
		// insert to db
		try {
			m_dao.insert (log);
		}
		catch (DBException& ex) {
			cout << ex.what () << endl;
		}
	}
}
