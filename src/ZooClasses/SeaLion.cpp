#include "../ZooClasses/SeaLion.h"

SeaLion::SeaLion(string trackNum, string name, int nurse) {
	this->name = name;
	this->trackNum = trackNum;
	this->nurse = nurse;
}

// Formats a stream and then saves into string. Return string to caller
string SeaLion::OutputData() {
	stringstream tempString;
	tempString << trackNum << "      "
			<< setw(15) << setfill(' ') << left << name
			<< setw(15) << "  Mammal"
			<< setw(15) << "    SeaLion"
			<< "       0        " << nurse;


	return tempString.str();
}
