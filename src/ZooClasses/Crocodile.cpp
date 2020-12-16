#include "../ZooClasses/Crocodile.h"

Crocodile::Crocodile(string trackNum, string name, int numEggs) {
	this->name = name;
	this->trackNum = trackNum;
	this->numberOfEggs = numEggs;
}

// Formats a stream and then saves into string. Return string to caller
string Crocodile::OutputData() {
	stringstream tempString;
	tempString << trackNum << "      "
			<< setw(15) << setfill(' ') << left << name
			<< setw(15) << "  Oviparous"
			<< setw(15) << "    Crocodile         "
			<< numberOfEggs << "        0";


	return tempString.str();
}
