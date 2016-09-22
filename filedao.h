//  declaration of File Data Accessing  Obj.
#ifndef _FILEDAO_H
#define _FILEDAO_H
#include <fstream>
using namespace std;
#include "logdao.h"

class FileDao : public LogDao {
public:
	
	FileDao (string const& path) throw (DBException);

	~FileDao (void);

	void insert (MLogRec const& log) throw ();
private:
	ofstream m_ofs; // outstream of files
};
#endif // _FILEDAO_H
