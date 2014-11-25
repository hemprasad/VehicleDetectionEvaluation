/*
 * OverlapArea.cpp
 *
 *  Created on: Nov 20, 2014
 *      Author: lpan
 */

#include "OverlapArea.h"
#include <bitset>
#include <iostream>

using namespace std;

OverlapArea::OverlapArea() {
	// TODO Auto-generated constructor stub

}

OverlapArea::~OverlapArea() {
	// TODO Auto-generated destructor stub
}
/**
 * 获取所有图片的所有重合面积（标注图片vs检测图片）
 */
void OverlapArea::getOverlapArea(map<string, vector<RectObject> >& labeledMap,
		map<string, vector<RectObject> >& detectMap,
		AREA& allArea){
	map<string, vector<RectObject> >::const_iterator map_it = labeledMap.begin();
	string picname;
	while(map_it != labeledMap.end()){
		picname = map_it->first;
		vector<RectObject> labeledPic = map_it->second;
		map<string, vector<RectObject> >::const_iterator find_it = detectMap.find(picname);
		if(find_it != detectMap.end()){
			vector<RectObject> detectPic = detectMap[picname];
			AREA area;
			getOnePicOA(labeledPic, detectPic, area);
			allArea.dArea += area.dArea;
			allArea.lArea += area.lArea;
			allArea.oArea += area.oArea;
		}
		map_it++;
	}
}


/**
 * 获取一张图片的所有重合面积（标注图片vs检测图片）
 */
void OverlapArea::getOnePicOA(vector<RectObject>& labeledPic, vector<RectObject>& detectPic, AREA& area){
	bitset<BITLENGTH> lBitsets;
	getBitsets(labeledPic, lBitsets);
	bitset<BITLENGTH> dBitsets;
	getBitsets(detectPic, dBitsets);

	area.lArea = lBitsets.count();
	area.dArea = dBitsets.count();
	bitset<BITLENGTH> tbits = lBitsets & dBitsets;

	area.oArea = tbits.count();
}
/**
 * 获取一张图片中所有矩形所对应的比特集
 * 矩形所框范围都为1，其他位置为0
 */
void OverlapArea::getBitsets(vector<RectObject>& vects, bitset<BITLENGTH>& bits){
	for(vector<RectObject>::size_type i = 0; i < vects.size(); i++){
		getOneBitset(vects[i], bits);
	}
}
/**
 * 获取一个矩形框的比特集
 */
void OverlapArea::getOneBitset(RectObject& rect, bitset<BITLENGTH>& bits){
	int width = rect.width;
	int height = rect.height;
	int x = rect.x;
	int y = rect.y;
//	cout << "area:" << width*height << endl;
	for(int i = x; i < x + width; i++){
		for(int j = y; j < y + height; j++){
			bits.set(j*PIC_WIDTH + i);
		}
	}
//	cout << "bits count:" << bits.count() << endl;
//	cout << "--------------------------------" << endl;
}

