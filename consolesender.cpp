// implimentation of consolesender
#include <iostream>
using namespace std;
#include "consolesender.h"
// send log
void ConsoleSender::sendLog (list<MLogRec>& logs)
	throw () {
	cout << "Sending log..." << endl;
	// iterate and match data
	for (list<MLogRec>::iterator it = logs.begin ();
		it != logs.end (); ++it)
		cout << *it << endl;
	cout << "Log sent." << endl;
}
