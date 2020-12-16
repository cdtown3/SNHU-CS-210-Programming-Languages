#ifndef CLASS_DEFINITIONS_WHALE_H_
#define CLASS_DEFINITIONS_WHALE_H_

#include "../ZooClasses/Mammal.h"

class Whale: public Mammal {
public:
	Whale(string trackNum, string name, int nurse);
	string OutputData();
};

#endif /* CLASS_DEFINITIONS_WHALE_H_ */
