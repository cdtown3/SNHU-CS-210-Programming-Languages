#ifndef CLASS_DEFINITIONS_PELICAN_H_
#define CLASS_DEFINITIONS_PELICAN_H_

#include "../ZooClasses/Oviparous.h"

class Pelican: public Oviparous {
public:
	Pelican(string trackNum, string name, int numEggs);
	string OutputData();
};

#endif /* CLASS_DEFINITIONS_PELICAN_H_ */
