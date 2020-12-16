#ifndef CLASS_DEFINITIONS_OVIPAROUS_H_
#define CLASS_DEFINITIONS_OVIPAROUS_H_

#include "../ZooClasses/Animal.h"

class Oviparous: public Animal {
public:
	Oviparous();
	void SetNumEggs(int numberOfEggs);
	int GetNumEggs() { return numberOfEggs; }

protected:
	int numberOfEggs;
};

#endif /* CLASS_DEFINITIONS_OVIPAROUS_H_ */
