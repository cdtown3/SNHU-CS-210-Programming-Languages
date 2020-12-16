#ifndef CLASS_DEFINITIONS_MAMMAL_H_
#define CLASS_DEFINITIONS_MAMMAL_H_

#include "../ZooClasses/Animal.h"

class Mammal: public Animal {
public:
	Mammal();
	void SetNurse(int nurse);
	int GetNurse() { return nurse; }

protected:
	int nurse;
};

#endif /* CLASS_DEFINITIONS_MAMMAL_H_ */
