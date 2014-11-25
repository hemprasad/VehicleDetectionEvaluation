/*
 * OverlapArea.h
 *
 *  Created on: Nov 20, 2014
 *      Author: lpan
 */

#ifndef OVERLAPAREA_H_
#define OVERLAPAREA_H_

#include <vector>
#include <map>
#include <string>
#include <bitset>

#include "RectObject.h"

using namespace std;

const int BITLENGTH = 1000000;
const int PIC_WIDTH = 1280;
const int PIC_HEIGHT = 720;

typedef struct AREA{
	int lArea;
	int dArea;
	int oArea;
}AREA;

class OverlapArea {

public:

	OverlapArea();
	virtual ~OverlapArea();

	void getOverlapArea(map<string, vector<RectObject> >& labeledMap, map<string, vector<RectObject> >& detectMap, AREA& allArea);

	void getOnePicOA(vector<RectObject>& labeledPic, vector<RectObject>& detectPic, AREA& area);

	void getOneBitset(RectObject& rect, bitset<BITLENGTH>& bits);

	void getBitsets(vector<RectObject>& pic, bitset<BITLENGTH>& bits);
	//vector<bitset<BITLENGTH> > getBitsets(vector<RectObject> pic);
	//bitset<BITLENGTH> getOneBitset(RectObject rect);


};

#endif /* OVERLAPAREA_H_ */
