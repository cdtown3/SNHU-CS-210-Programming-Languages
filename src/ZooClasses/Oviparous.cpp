#include "../ZooClasses/Oviparous.h"

Oviparous::Oviparous() {
	this->numberOfEggs = 0;
}

void Oviparous::SetNumEggs(int numberOfEggs) {
	while (numberOfEggs < 0) {
		cout << "Please enter number of eggs, 0 or more: ";
		cin >> numberOfEggs;
	}

	this->numberOfEggs = numberOfEggs;
}
