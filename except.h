// exception class
#ifndef _EXCEPT_H
#define _EXCEPT_H
#include <string>
using namespace std;
// server exception
class ServerException : public exception {
public:
	ServerException (void) :
		m_msg ("Server Exception!") {}
	ServerException (string const& msg) :
		m_msg ("Server Exception:") {
		m_msg += msg;
		m_msg += "！";
	}
	~ServerException (void) throw () {}
	char const* what (void) const throw () {
		return m_msg.c_str ();
	}
private:
	string m_msg;
};
// Database exception
class DBException : public ServerException {
public:
	DBException (void) :
		ServerException ("Database exception!") {}
	DBException (string const& msg) :
		ServerException (msg) {}
};
// socekt excepion
class SocketException : public ServerException {
public:
	SocketException (void) :
		ServerException ("Socket Exception!") {}
	SocketException (string const& msg) :
		ServerException (msg) {}
};
// Thread exceptions
class ThreadException : public ServerException {
public:
	ThreadException (void) :
		ServerException ("Thread Exception!") {}
	ThreadException (string const& msg) :
		ServerException (msg) {}
};
#endif // _EXCEPT_H
