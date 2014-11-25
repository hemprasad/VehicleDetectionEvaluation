/*
 * ReadFromFile.cpp
 *
 *  Created on: Nov 20, 2014
 *      Author: lpan
 */

#include "ReadFromFile.h"
#include "Util.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

ReadFromFile::ReadFromFile() {
	// TODO Auto-generated constructor stub

}

ReadFromFile::~ReadFromFile() {
	// TODO Auto-generated destructor stub
}

map<string, vector<RectObject> > ReadFromFile::read(string dir){
	map<string, vector<RectObject> > result;
	ifstream infile;
	infile.open(dir.c_str());
	if(!infile){
		cerr << "error: unable to open input file." << dir << endl;
	}
	string s;
	string picname;
	Util util = Util();
	int count = 1;
	while(getline(infile, s)){
		vector<string> items;
		s = util.trim(s);
		util.split(s, " ", items);
		if(items.size() < 2){
			cerr << "error: format is wrong, check it in line " <<  count << endl;
			break;
		}
		else{
			picname = util.trim(items[0]);
			vector<RectObject> rects;
			for(vector<string>::size_type i = 1; i < items.size(); i++){
				vector<string> rectElements;
				RectObject rb = RectObject();
				util.split(items[i], ",", rectElements);
				if(rectElements.size() == 4){
					rb.x = std::atoi(util.trim(rectElements[0]).c_str());
					rb.y = std::atoi(util.trim(rectElements[1]).c_str());
					rb.width = std::atoi(util.trim(rectElements[2]).c_str());
					rb.height = std::atoi(util.trim(rectElements[3]).c_str());
					rects.push_back(rb);
				}
			}
			if(!rects.empty()){
				result[picname] = rects;
			}
		}
	}

	return result;
}


