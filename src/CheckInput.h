/*
 * CheckInput.h
 *
 *  Created on: Nov 21, 2014
 *      Author: lpan
 */

#ifndef CHECKINPUT_H_
#define CHECKINPUT_H_

#include <vector>
#include <string>
#include <map>
#include "RectObject.h"

using namespace std;

class CheckInput {
public:
	CheckInput();
	virtual ~CheckInput();

	int check(map<string, vector<RectObject> > label_map, map<string, vector<RectObject> > detect_map);
};

#endif /* CHECKINPUT_H_ */
