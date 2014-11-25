/*
 * CheckInput.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: lpan
 */

#include "CheckInput.h"
#include <vector>
#include <string>
#include <map>
#include "RectObject.h"

using namespace std;

CheckInput::CheckInput() {
	// TODO Auto-generated constructor stub

}

CheckInput::~CheckInput() {
	// TODO Auto-generated destructor stub
}

int CheckInput::check(map<string, vector<RectObject> > label_map, map<string, vector<RectObject> > detect_map){
	int count = 0;
	map<string, vector<RectObject> >::const_iterator map_it = label_map.begin();
	string picname;
	while(map_it != label_map.end()){
		picname = map_it->first;
		map<string, vector<RectObject> >::const_iterator find_it = detect_map.find(picname);
		if(find_it != detect_map.end()){
			count++;
		}
		map_it++;
	}
	return count;
}
