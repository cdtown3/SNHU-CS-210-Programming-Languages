#include "../ZooClasses/Animal.h"

void Animal::SetName(string name) {
	while (name.empty()) {
		cout << "Please enter a name: ";
		cin >> name;
	}

	this->name = name;
}

void Animal::SetTrackNum(string trackNum) {
	while ((trackNum.length() > 6) || trackNum.length() < 0) {
		cout << "Please enter a tracking number between 1 to 6 digits in length: ";
		cin >> trackNum;
	}

	this->trackNum = trackNum;
}

string Animal::GetName() {
	return name;
}

string Animal::GetTrackNum() {
	return trackNum;
}
