// Declaration of logreader
#ifndef _LOGREADER_H
#define _LOGREADER_H
#include <string>
#include <list>
using namespace std;
#include "data.h"
#include "except.h"
// Logreader
class LogReader {
public:
	// Creator
	LogReader (string const& logFile,
		string const& loginsFile);
	// Read Logs
	list<MLogRec>& readLog (void)
		throw (ClientException);
private:
	// Backup 
	void backup (void) throw (BackupException);
	// Readlogin
	void readLoginsFile (void) throw (ReadException);
	// Readbackup
	void readBackupFile (void) throw (ReadException);
	// Match
	void match (void);
	// Save Login files
	void saveLoginsFile (void) throw (SaveException);
	string m_logFile;    
	string m_loginsFile; 
	string m_backupFile; 
	list<LogRec>  m_logins;  
	list<LogRec>  m_logouts; 
	list<MLogRec> m_logs;    
};
#endif // _LOGREADER_H
