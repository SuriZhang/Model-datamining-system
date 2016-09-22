// Data Access Object interface
#ifndef _LOGDAO_H
#define _LOGDAO_H
#include "data.h"
#include "except.h"
// LogDao interfae
class LogDao {
public:
	virtual ~LogDao (void) {}
	// insert
	virtual void insert (MLogRec const& log)
		throw (DBException) = 0;
};
#endif // _LOGDAO_H
