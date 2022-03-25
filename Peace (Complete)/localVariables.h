/*
 * localVariables.h
 *
 *  Created on: May 15, 2019
 *      Author: jasper
 */

#ifndef LOCALVARIABLES_H_
#define LOCALVARIABLES_H_

#include <iostream>
#include <string>
using namespace std;

class localVariables
{
private:
	string varName;
	string varType;
	int varSlot;

public:
	localVariables();
	localVariables(string n, string t, int s);
	string getName();
	string getType();
	int getSlot();
	void print();
};



#endif /* LOCALVARIABLES_H_ */
