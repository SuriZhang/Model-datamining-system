// implimentation of logreader
#include <sys/stat.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
#include "logreader.h"
// Creator
LogReader::LogReader (string const& logFile,
	string const& loginsFile) :
	m_logFile (logFile), m_loginsFile (loginsFile) {}
// Read log
list<MLogRec>& LogReader::readLog (void)
	throw (ClientException) {
	cout << "Reading Log..." << endl;

	backup ();

	readLoginsFile ();

	readBackupFile ();

	match ();

	saveLoginsFile ();
	cout << "Reading Log finished." << endl;
	return m_logs;
}
// back up log
void LogReader::backup (void) throw (BackupException) {
	cout << "Start backup..." << endl;

	cout << "Backup finished." << endl;
}
// Read log in files
void LogReader::readLoginsFile (void)
	throw (ReadException) {
	cout << "Start reading login files..." << endl;

	cout << "Finish reading login files." << endl;
}
// Read backup files
void LogReader::readBackupFile (void)
	throw (ReadException) {
	cout << "Start reading backup files..." << endl;

	cout << "Finish reading backup files." << endl;
}
// Match login & logout
void LogReader::match (void) {
	cout << "Start matching logs..." << endl;

	cout << "Finished mapping." << endl;
}
// Save login files
void LogReader::saveLoginsFile (void)
	throw (SaveException) {
	cout << "Start saving files..." << endl;

	cout << "Login files saved." << endl;
}
