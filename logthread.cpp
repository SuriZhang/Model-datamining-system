// implementation of threads
#include <pthread.h>
#include <errno.h>
#include <cstring>
#include <iostream>
using namespace std;
#include "logthread.h"
// start thread
void LogThread::start (void) throw (ThreadException) {
	cout << "Starting threads..." << endl;
	pthread_t tid;
	int error = pthread_create (&tid, NULL, run, this);
	if (error)
		throw ThreadException (strerror (error));
	cout << "Threads ready." << endl;
}
// processing threads
void* LogThread::run (void* arg) {
	pthread_detach (pthread_self ());
	static_cast<LogThread*> (arg)->run ();
	return NULL;
}
