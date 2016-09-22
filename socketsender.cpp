// implementation of socketsender
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "socketsender.h"
// creator
SocketSender::SocketSender (string const& failFile,
	short port, string const& ip /* = "127.0.0.1" */) :
	m_failFile (failFile), m_port (port), m_ip (ip) {}
// socket sender
void SocketSender::sendLog (list<MLogRec>& logs)
	throw (ClientException) {
	cout << "Start Sending Files..." << endl;
	try {
		try {
			// read failed files
			readFailFile (logs);
		}
		catch (ReadException& ex) {
			cout << "Cannot Send Failed Files!" << endl;
		}
		connectServer ();

		sendData (logs);
	}
	catch (SocketException& ex) {

		saveFailFile (logs);
		throw;
	}
	catch (SendException& ex) {

		saveFailFile (logs);
		throw;
	}
	cout << "Finish sending logs." << endl;
}
// read failed files
void SocketSender::readFailFile (list<MLogRec>& logs)
	throw (ReadException) {
	cout << "Start reading failed files..." << endl;

	cout << "Finish reading failed files." << endl;
}
// connect to server
void SocketSender::connectServer (void)
	throw (SocketException) {
	cout << "Connecting server..." << endl;

	cout << "Server Connected." << endl;
}
// sending data
void SocketSender::sendData (list<MLogRec>& logs)
	throw (SendException) {
	cout << "Sending data..." << endl;

	cout << "Data sent." << endl;
}
// save failed files
void SocketSender::saveFailFile (list<MLogRec>& logs)
	throw (SaveException) {
	cout << "Saving failed files..." << endl;

	cout << "Failed files saved." << endl;
}
