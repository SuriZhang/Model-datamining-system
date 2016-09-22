// declaration of oracle dao
#ifndef _ORACLEDAO_H
#define _ORACLEDAO_H
#include "logdao.h"
// oracle dao
class OracleDao : public LogDao {
public:
	// constructor
	OracleDao (string const& username,
		string const& password) throw (DBException);
	// deconstructor
	~OracleDao (void);
	// insert
	void insert (MLogRec const& log)
		throw (DBException);
};
#endif // _ORACLEDAO_H
