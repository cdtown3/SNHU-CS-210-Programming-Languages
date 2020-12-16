#ifndef CLASS_DEFINITIONS_ANIMAL_H_
#define CLASS_DEFINITIONS_ANIMAL_H_

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Animal {
public:
	void SetName(string name);
	void SetTrackNum(string trackNum);
	string GetName();
	string GetTrackNum();

	// Allows other object's OutputData to be called instead of base class's
	virtual string OutputData() {}

protected:
	string name, trackNum;
};

#endif /* CLASS_DEFINITIONS_ANIMAL_H_ */
