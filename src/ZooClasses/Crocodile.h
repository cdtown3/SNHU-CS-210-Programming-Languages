#ifndef CLASS_DEFINITIONS_CROCODILE_H_
#define CLASS_DEFINITIONS_CROCODILE_H_

#include "../ZooClasses/Oviparous.h"

class Crocodile: public Oviparous {
public:
	Crocodile(string trackNum, string name, int numEggs);
	string OutputData();
};

#endif /* CLASS_DEFINITIONS_CROCODILE_H_ */
