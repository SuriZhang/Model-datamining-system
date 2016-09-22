// Client
#include <iostream>
using namespace std;
#include "client.h"
// create client
Client::Client (LogReader& reader, LogSender& sender) :
	m_reader (reader), m_sender (sender) {}
// collect data
void Client::dataMine (void) throw (ClientException) {
	cout << "Collecting data..." << endl;
	// read and send data to log
	m_sender.sendLog (m_reader.readLog ());
	cout << "Data collection finished." << endl;
}
