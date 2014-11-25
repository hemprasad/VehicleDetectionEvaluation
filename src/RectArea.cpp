/*
 * RectArea.cpp
 *
 *  Created on: Nov 20, 2014
 *      Author: lpan
 */

#include "RectArea.h"

RectArea::RectArea() {
	// TODO Auto-generated constructor stub

}

RectArea::~RectArea() {
	// TODO Auto-generated destructor stub
}
/**
 * 获取一个矩形框面积
 */
double RectArea::OneRectArea(RectObject rect){

	return (rect.width)*(rect.height);

}
/**
 * 获取一单张图片的所有矩形框面积
 */
double RectArea::GetOnePicRectArea(vector<RectObject> rects){

	if(rects.empty()){
		return 0;
	}
	else{
		double area = 0;
		for(vector<RectObject>::size_type i = 0; i < rects.size(); i++){
			area = area + OneRectArea(rects[i]);
		}
		return area;
	}
}
/**
 * 获取所有图片的所有矩形面积
 */
double RectArea::GetAllPicRectArea(map<string, vector<RectObject> > picMap){

	if(picMap.empty()){
		return 0;
	}
	else{
		double area = 0;
		map<string, vector<RectObject> >::const_iterator map_it = picMap.begin();

		while(map_it != picMap.end()){
			area = area + GetOnePicRectArea(map_it->second);
			map_it++;
		}
		return area;
	}

}
