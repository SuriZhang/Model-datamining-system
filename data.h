// data object
#ifndef _DATA_H
#define _DATA_H
#include <unistd.h>
#include <iostream>
using namespace std;
// Login and log out records
struct LogRec {
	char  logname[32]; 
	char  logip[32];   
	pid_t pid;         
	long  logtime;     
};
// Match log
struct MLogRec {
	char  logname[32]; 
	char  logip[32];   
	pid_t pid;         
	long  logintime;   
	long  logouttime;  
	long  durations;   
	friend ostream& operator<< (ostream& os,
		MLogRec const& log) {
		return os << log.logname << ','
			<< log.logip << ','
			<< log.pid << ','
			<< log.logintime << ','
			<< log.logouttime << ','
			<< log.durations;
	}
};
#endif // _DATA_H
