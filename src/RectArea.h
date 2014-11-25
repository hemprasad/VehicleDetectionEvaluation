/*
 * RectArea.h
 *
 *  Created on: Nov 20, 2014
 *      Author: lpan
 */

#ifndef RECTAREA_H_
#define RECTAREA_H_

#include "RectObject.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class RectArea {
public:
	RectArea();
	virtual ~RectArea();
	double OneRectArea(RectObject rect);
	double GetOnePicRectArea(vector<RectObject> rects);
	double GetAllPicRectArea(map<string, vector<RectObject> > picMap);
};

#endif /* RECTAREA_H_ */
