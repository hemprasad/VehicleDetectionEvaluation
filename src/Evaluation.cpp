/*
 * Evaluation.cpp
 *
 *  Created on: Nov 20, 2014
 *      Author: lpan
 */

#include "Evaluation.h"
#include "ReadFromFile.h"
#include <iostream>
#include <bitset>
#include "RectArea.h"
#include "OverlapArea.h"
#include "CheckInput.h"

using namespace std;

Evaluation::Evaluation() {
	// TODO Auto-generated constructor stub

}

Evaluation::~Evaluation() {
	// TODO Auto-generated destructor stub
}

void Evaluation::printhelp(){
	cout << "------------------ run parameters: -------------------" << endl;
	cout << "---------parameter: 1. human labeled file 2. detect result file" << endl;
	cout << "------------------file input format: -----------------" << endl;
	cout << "---------example: 1.jpg 0,0,10,10 100,100,50,50 " << endl;
	cout << "------------------------------------------------------" << endl;
}

int main(int argc, char**argv){

	Evaluation e = Evaluation();

	string labeled_file = "/home/lpan/workspace/computervision/resource/videolabel/labeled/labeled.txt";
//	string detect_file = "/home/lpan/workspace/computervision/resource/videolabel/labeled/labeled.txt";
	string detect_file = "/home/lpan/workspace/computervision/resource/detect.txt";

	if (argc == 3) {
		labeled_file = argv[1];
		detect_file = argv[2];
	}
	else{
		e.printhelp();
	}

	ReadFromFile rff = ReadFromFile();
	cout << "reading " << labeled_file << endl;
	map<string, vector<RectObject> > label_map = rff.read(labeled_file);
	cout << "reading " << detect_file << endl;
	map<string, vector<RectObject> > detect_map = rff.read(detect_file);
	if(label_map.empty() || detect_map.empty()){
		cout << "read fail." << endl;
		return -1;
	}
	else{
		cout << "labeled sample size: " << label_map.size() << endl;
		cout << "detect sample size: " << detect_map.size() << endl;
	}

	CheckInput ci = CheckInput();
	int count = ci.check(label_map, detect_map);
	int size = label_map.size();
	if(count == 0){
		cout << "picture names do not match. " << endl;
		return -1;
	}
	else if(count != size){
		cout << (size - count) << " pictures do not match" << endl;
	}

//	RectArea ra = RectArea();
//	double label_area = ra.GetAllPicRectArea(label_map);
//	cout << "labeled rects area: " << label_area << endl;
//	double detect_area = ra.GetAllPicRectArea(detect_map);
//	cout << "detect rects area: " << detect_area << endl;

	OverlapArea oa = OverlapArea();
	AREA allArea;
	allArea.dArea = 0;
	allArea.lArea = 0;
	allArea.oArea = 0;
	oa.getOverlapArea(label_map, detect_map, allArea);

	cout << "labeled rects area: " << allArea.lArea << endl;
	cout << "detect rects area: " << allArea.dArea << endl;
	cout << "overlap_area rects area: " << allArea.oArea << endl;

	double precise = (double)allArea.oArea/allArea.dArea;
	double recall = (double)allArea.oArea/allArea.lArea;
	cout << "--------------------------------------------" << endl;
	cout << "precise: " << precise << endl;
	cout << " recall: " << recall << endl;
}


