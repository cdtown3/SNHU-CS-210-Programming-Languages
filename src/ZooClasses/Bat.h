#ifndef CLASS_DEFINITIONS_BAT_H_
#define CLASS_DEFINITIONS_BAT_H_

#include "../ZooClasses/Mammal.h"

class Bat: public Mammal {
public:
	Bat(string trackNum, string name, int nurse);
	string OutputData();

};

#endif /* CLASS_DEFINITIONS_BAT_H_ */
