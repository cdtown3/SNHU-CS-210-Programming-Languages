#ifndef CLASS_DEFINITIONS_GOOSE_H_
#define CLASS_DEFINITIONS_GOOSE_H_

#include "../ZooClasses/Oviparous.h"

class Goose: public Oviparous {
public:
	Goose(string trackNum, string name, int numEggs);
	string OutputData();
};

#endif /* CLASS_DEFINITIONS_GOOSE_H_ */
