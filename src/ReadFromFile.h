/*
 * ReadFromFile.h
 *
 *  Created on: Nov 20, 2014
 *      Author: lpan
 */

#ifndef READFROMFILE_H_
#define READFROMFILE_H_

#include <vector>
#include <map>
#include <string>
#include "RectObject.h"

using namespace std;

class ReadFromFile {
public:
	ReadFromFile();
	virtual ~ReadFromFile();

	map<string, vector<RectObject> > read(string dir);
};

#endif /* READFROMFILE_H_ */
