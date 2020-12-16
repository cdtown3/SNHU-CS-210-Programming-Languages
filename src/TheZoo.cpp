/*
 * Author: Drew Townsend
 * Date: 12/13/2020
 * Description: Allows users to generate and open ZooData.txt. Users can add and remove animal records to program.
 * 				Users can then save that data back into ZooData.txt to manage animal records
 */
#include <iostream>
#include <jni.h>
#include <vector>
#include <fstream>

#include "ZooClasses/Animal.h"
#include "ZooClasses/Bat.h"
#include "ZooClasses/Crocodile.h"
#include "ZooClasses/Goose.h"
#include "ZooClasses/Mammal.h"
#include "ZooClasses/Oviparous.h"
#include "ZooClasses/Pelican.h"
#include "ZooClasses/SeaLion.h"
#include "ZooClasses/Whale.h"

using namespace std;

vector<Animal *> ZooList; // Vector to load animal data into

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

// Added parameters so I could use AddAnimal in multiple functs. Checks that data is valid, creates pointer to new object, appends
// new object to ZooList
void AddAnimal(string trackNum, string name, string type, string subType, int numEgg = 0, int nursing = 0)
{
	bool check = true;

	// Various checks for type and subtype.
	while (check) {
			if (type == "Mammal") {
				if (subType == "Bat") {
					Bat *newBat = new Bat(trackNum, name, nursing); // Creates pointer to object with given variables.
					ZooList.push_back(newBat); // Appends pointer to list of pointers, ZooList
					check = false; // Stop loop
				} else if (subType == "Whale") {
					Whale *newWhale = new Whale(trackNum, name, nursing);
					ZooList.push_back(newWhale);
					check = false;
				} else if (subType == "SeaLion") {
					SeaLion *newSeaLion = new SeaLion(trackNum, name, nursing);
					ZooList.push_back(newSeaLion);
					check = false;
				} else {
					cout << "Please enter Bat, Whale, or SeaLion " << name << ": " << endl;
					cin >> subType;
				}
			} else if (type == "Oviparous") {
				if (subType == "Crocodile") {
					Crocodile *newCrocodile = new Crocodile(trackNum, name, numEgg);
					ZooList.push_back(newCrocodile);
					check = false;
				} else if (subType == "Goose") {
					Goose *newGoose = new Goose(trackNum, name, numEgg);
					ZooList.push_back(newGoose);
					check = false;
				} else if (subType == "Pelican") {
					Pelican *newPelican = new Pelican(trackNum, name, numEgg);
					ZooList.push_back(newPelican);
					check = false;
				} else {
					cout << "Please enter Crocodile, Goose, or Pelican for " << name << ": " << endl;
					cin >> subType;
				}
			} else {
				cout << "Please enter Mammal or Oviparous: " << endl;
				cin >> type;
			}
		}
		 cout << "Animal added" << endl;
}

// New function for code reusability. Gets input from user, checking validity for each variable, and calls AddAnimal
void GetAnimalInfo() {
	 string name, trackNum, type, subType;
	 int eggs, nursing;

	 cout << "Add an animal record: " << endl;
	 cout << "Tracking number: ";
	 cin >> trackNum;

	 try { // Try string to integer to ensure non-negative, and 1-6 in length
		 int testNum = stoi(trackNum);
		 while ((trackNum.empty()) || (trackNum.length() < 1) || (trackNum.length() > 6) || (testNum < 0)) {
			 cout << "Please enter a non-negative number, maximum of 6 digits: ";
			 cin >> trackNum;
			 testNum = stoi(trackNum);
		 }
	 }
	 catch (invalid_argument const &e)
	 {
		 cout << "Please enter a non-negative number, maximum of 6 digits: ";
		 cin >> trackNum;
	 }

	 cout << "Animal Name: ";
	 cin >> name;
	 while (name.empty()) { // while animal's name is null...
		 cout << "Please enter the animal's name: ";
		 cin >> name;
	 }

	 // Validating animal type...
	 cout << "Animal Type (Mammal or Oviparous): ";
	 cin >> type;
	 while ((type.empty()) || ((type != "Mammal") && (type != "Oviparous"))) {
		 cout << "Please enter the animal's type (Mammal or Oviparous): ";
		 cin >> type;
	 }

	 // Getting subtype based on Type, and validating animal subtype...
	 if (type == "Mammal") {
		 cout << "Animal Sub-Type (Bat, SeaLion, or Whale): ";
		 cin >> subType;

		 while ((subType.empty()) || ((subType != "Bat") && (subType != "SeaLion") && (subType != "Whale"))) {
			 cout << "Please enter the animal's sub-type (Bat, SeaLion, or Whale): ";
			 cin >> subType;
		 }

		 cout << "Is the animal nursing? (0 for no, 1 for yes): ";
		 cin >> nursing;

		 while ((nursing != 0) && (nursing != 1)) {
			 cout << "Is the animal nursing? (0 for no, 1 for yes): ";
			 cin >> nursing;
		 }

		 stringstream tempString;
		 tempString << setw(6) << setfill('0') << right << trackNum; // Padding tracknum with 0's

		 trackNum = tempString.str();

		 char userChar;

		cout << "Are you sure you want to add " << name << " to the database? (Y for yes): ";
		cin >> userChar;

		if ((userChar == 'Y') || (userChar == 'y')) {
			AddAnimal(trackNum, name, type, subType, eggs, nursing);
		}
	 }
	 else {
		 cout << "Animal Sub-Type (Crocodile, Goose, or Pelican): ";
		 cin >> subType;

		 while ((subType.empty()) || ((subType != "Crocodile") && (subType != "Goose") && (subType != "Pelican"))) {
			 cout << "Please enter the animal's sub-type (Crocodile, Goose, or Pelican): ";
			 cin >> subType;
		 }

		 cout << "Enter amount of eggs: ";
		 cin >> eggs;

		 while ((eggs == NULL) || (eggs < 0)) {
			 cout << "Enter amount of eggs: ";
			 cin >> eggs;
		 }

		 stringstream tempString;
		 tempString << setw(6) << setfill('0') << right << trackNum;

		 trackNum = tempString.str();

		 char userChar;

		cout << "Are you sure you want to add " << name << " to the database? (Y for yes): ";
		cin >> userChar;

		if ((userChar == 'Y') || (userChar == 'y')) {
			AddAnimal(trackNum, name, type, subType, eggs, nursing);
		}
	 }
}

// Loop that checks if tracking number is in. If so, remove animal from ZooList. Alert user if animal is not found
void RemoveAnimal()
{
	string numToDel;
	int count = 0;
	char userChar;
	cout << "Please enter the animal's tracking number: ";
	cin >> numToDel;

	for (unsigned int i = 0; i < ZooList.size(); ++i) {
		if (ZooList.at(i)->GetTrackNum() == numToDel) {
			cout << "Record found. Are you sure you want to delete the record? (Y for yes)" << endl;
			cin >> userChar;

			if ((userChar == 'Y') || (userChar == 'y')) {
				ZooList.erase(ZooList.begin() + i);
				count++;
			}

		}
	}

	if (count > 0) {
		cout << "Animal successfully deleted" << endl;
	}


}

// Opens txt file, reads word by word into 6 variables, and then creates pointer to animal object based off of those variables.
void LoadDataFromFile()
{
	string trackNum, name, type, subType;
	int numEgg, nursing;

	fstream file;

	file.open("zoodata.txt");

	if (file.is_open()) {
		string tempString = "";
		while(!file.eof()) {
			file >> trackNum;
			file >> name;
			file >> type;
			file >> subType;
			file >> numEgg;
			file >> nursing;

			// Had a duplication error. Suspected .eof() to be the issue.
			// tempString is previous tracking number. Checks if current trackNum and previous trackNum are the same.
			if (!(trackNum == tempString)) {
				AddAnimal(trackNum, name, type, subType, numEgg, nursing);
			}

			tempString = trackNum;

		}
		file.close();
	}
	else {
		cout << "ERROR: Cannot load data from file..." << endl;
	}


}

// Open txt file with trunc, which erases all data, and then loop through ZooList, saving each object on new line
void SaveDataToFile()
{
	fstream file;
	file.open("zoodata.txt", ios::out | ios::trunc);

	if (!file.is_open()) {
		cout << "ERROR: Could not find or open zoodata.txt" << endl;
	}
	else {

		for (unsigned int i = 0; i < ZooList.size(); ++i) {
			file << ZooList.at(i)->OutputData() << endl;
			cout << i << endl;
		}

		cout << "Save successfully completed" << endl;
	}

	file.close();
}

// Print OutputData from each object
void DisplayAnimalData() {
	cout << "Track#      Name             Type             Sub-Type          Eggs     Nursing" << endl;
	for (unsigned int i = 0; i < ZooList.size(); ++i) {
		cout << ZooList.at(i)->OutputData() << endl;
	}
}

// Displays user menu in while loop until user enters 0.
void DisplayMenu()
{
	 int userChoice = -1;

	 while (userChoice != 0) {

		 cout << "What would you like to do?" << endl;
		 cout << "1. Load Animal Data" << endl;
		 cout << "2. Generate Data" << endl;
		 cout << "3. Display Animal Data" << endl;
		 cout << "4. Add Record" << endl;
		 cout << "5. Delete Record" << endl;
		 cout << "6. Save Animal Data" << endl;
		 cout << "0. Exit" << endl;

		 cin >> userChoice;

		 switch(userChoice) {
		 	 case 0:
		 		 // Deletes pointers before exiting program
		 		 for (unsigned int i = 0; i < ZooList.size(); ++i) {
		 			 delete ZooList.at(i);
		 		 }
		 		 break;

			 case 1:
				 cout << "Loading animal data..." << endl;
				 LoadDataFromFile();
				 cout << "Done." << endl << endl;
				 break;

			 case 2:
				 cout << "Generating data..." << endl;
				 GenerateData();
				 cout << "Done." << endl << endl;
				 break;

			 case 3:
				 cout << "Displaying Animal Data:" << endl;
				 DisplayAnimalData();
				 cout << endl;
				 break;

			 case 4:
				 GetAnimalInfo();
				 cout << endl;
				 break;

			 case 5:
				 cout << "Deleting animal record:" << endl;
				 RemoveAnimal();
				 cout << endl;
				 break;

			 case 6:
				 cout << "Saving data to file..." << endl;
				 SaveDataToFile();
				 cout << "Done." << endl << endl;
				 break;

			 default:
				 cout << "Please enter a number, 0-6: " << endl;
				 break;
		 }
     }
}


int main()
{
	DisplayMenu();
}
