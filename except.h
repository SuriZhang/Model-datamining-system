// exceptions 
#ifndef _EXCEPT_H
#define _EXCEPT_H
#include <string>
using namespace std;
// client expection
class ClientException : public exception {
public:
	ClientException (void) :
		m_msg ("Client exception!") {}
	ClientException (string const& msg) :
		m_msg ("Client expe :") {
		m_msg += msg;
		m_msg += "！";
	}
	~ClientException (void) throw () {}
	char const* what (void) const throw () {
		return m_msg.c_str ();
	}
private:
	string m_msg;
};
// Backup Exception
class BackupException : public ClientException {
public:
	BackupException (void) :
		ClientException ("Backup Error.") {}
	BackupException (string const& msg) :
		ClientException (msg) {}
};
// Read Exception
class ReadException : public ClientException {
public:
	ReadException (void) :
		ClientException ("Read Error.") {}
	ReadException (string const& msg) :
		ClientException (msg) {}
};
// Save Exception
class SaveException : public ClientException {
public:
	SaveException (void) :
		ClientException ("Save Error.") {}
	SaveException (string const& msg) :
		ClientException (msg) {}
};
// Socket Exception
class SocketException : public ClientException {
public:
	SocketException (void) :
		ClientException ("Socket Error.") {}
	SocketException (string const& msg) :
		ClientException (msg) {}
};
// Send Exception
class SendException : public ClientException {
public:
	SendException (void) :
		ClientException ("Send Error.") {}
	SendException (string const& msg) :
		ClientException (msg) {}
};
#endif // _EXCEPT_H
