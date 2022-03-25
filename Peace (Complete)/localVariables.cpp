/*
 * localVariables.cpp
 *
 *  Created on: May 15, 2019
 *      Author: jasper
 */

#include "localVariables.h"


localVariables::localVariables()
{
	varName = "";
	varType = "";
	varSlot = 0;
}

localVariables::localVariables(string n, string t, int s)
{
	varName = n;
    varType = t;
    varSlot = s;
}

string localVariables::getName()
{
	return varName;
}

string localVariables::getType()
{
	return varType;
}

int localVariables::getSlot()
{
	return varSlot;
}

void localVariables::print()
{
	cout << "variable name " << varName << endl;
	cout << "variable type " << varType << endl;
	cout << "slot number " << varSlot << endl;
}

