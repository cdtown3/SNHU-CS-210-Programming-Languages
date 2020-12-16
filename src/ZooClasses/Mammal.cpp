#include "../ZooClasses/Mammal.h"

Mammal::Mammal() {
	this->nurse = 0;
}

void Mammal::SetNurse(int nurse) {
	while ((nurse != 0) || (nurse != 1)) {
		cout << "Is the animal nursing? 0 for no, 1 for yes: ";
		cin >> nurse;
	}

	this->nurse = nurse;
}
