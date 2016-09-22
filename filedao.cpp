// implementation of Data Accessing Obj.
#include <iostream>
using namespace std;
#include "filedao.h"
// creator
FileDao::FileDao (string const& path)
	throw (DBException) {
	cout << "Connecting Database..." << endl;
	m_ofs.open (path.c_str (), ios::app);
	if (! m_ofs)
		throw DBException ("Database cannot be connected");
	cout << "Database connected." << endl;
}
// destructor
FileDao::~FileDao (void) {
	cout << "Closing database..." << endl;
	m_ofs.close ();
	cout << "Databse closed." << endl;
}
// Insertion
void FileDao::insert (MLogRec const& log) throw () {
	cout << "Start inserting data..." << endl;
	m_ofs << log << endl;
	cout << "Data inserted." << endl;
}
