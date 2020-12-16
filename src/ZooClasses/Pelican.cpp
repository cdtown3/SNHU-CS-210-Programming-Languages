#include "../ZooClasses/Pelican.h"

Pelican::Pelican(string trackNum, string name, int numEggs) {
	this->name = name;
	this->trackNum = trackNum;
	this->numberOfEggs = numEggs;
}

// Formats a stream and then saves into string. Return string to caller
string Pelican::OutputData() {
	stringstream tempString;
	tempString << trackNum << "      "
			<< setw(15) << setfill(' ') << left << name
			<< setw(15) << "  Oviparous"
			<< setw(15) << "    Pelican           "
			<< numberOfEggs << "        0";


	return tempString.str();
}
