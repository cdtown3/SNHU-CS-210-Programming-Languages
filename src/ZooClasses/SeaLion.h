#ifndef CLASS_DEFINITIONS_SEALION_H_
#define CLASS_DEFINITIONS_SEALION_H_

#include "../ZooClasses/Mammal.h"

class SeaLion: public Mammal {
public:
	SeaLion(string trackNum, string name, int nurse);
	string OutputData();
};

#endif /* CLASS_DEFINITIONS_SEALION_H_ */
