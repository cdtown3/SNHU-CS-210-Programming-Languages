#include "../ZooClasses/Goose.h"

Goose::Goose(string trackNum, string name, int numEggs) {
	this->name = name;
	this->trackNum = trackNum;
	this->numberOfEggs = numEggs;
}

// Formats a stream and then saves into string. Return string to caller
string Goose::OutputData() {
	stringstream tempString;
	tempString << trackNum << "      "
			<< setw(15) << setfill(' ') << left << name
			<< setw(15) << "  Oviparous"
			<< setw(15) << "    Goose             "
			<< numberOfEggs << "        0";


	return tempString.str();
}
