// implementation of Oracle data accessing obj.
#include <iostream>
using namespace std;
#include "oracledao.h"
// constructor
OracleDao::OracleDao (string const& username,
	string const& password) throw (DBException) {
	cout << "Connecting to Oracle..." << endl;

	cout << "Oracle connected." << endl;
}
// deconstructor
OracleDao::~OracleDao (void) {
	cout << "Closing database..." << endl;

	cout << "Database closed." << endl;
}
// insert
void OracleDao::insert (MLogRec const& log)
	throw (DBException) {
	cout << "Start inserting data to database..." << endl;
	cout << log << endl;
	cout << "Data inserted." << endl;
}
