//
//  main.cpp
//  quick_sort
//
//  Created by iseki on 2013/03/27.
//  Copyright (c) 2013年 iseki. All rights reserved.
//

#include <iostream>
#include <vector>

#define SENTINEL 10e8

using namespace std;

vector<int> set(vector<int>&vec,int size,int pos){
	vector<int> container(size);
	int i = 0;
	for (vector<int>::iterator it = container.begin(); it != container.end(); ++it) {
		*it = vec.at(pos + i);
		++i;
	}
	return container;
}

void quick_sort(vector<int>& vec,int size ,int pos){
	if (size < 2) {
		return;
	}
	int pivot = vec.at(pos);
	vector<int> tmp(set(vec,size,pos));
	
	int leftSize = 0,rightSize = 0;
	for (vector<int>::const_iterator cit = tmp.cbegin(); cit != tmp.cend(); ++cit) {
		if(cit == tmp.cbegin()){
			continue;
		}
		if(pivot > *cit){
			vec[pos + leftSize] = *cit;
			++leftSize;
		}
		else{
			vec[(pos + size -1) - rightSize] = *cit;
			++rightSize;
		}
	}
	vec[leftSize + pos] = pivot;
	quick_sort(vec, leftSize, pos);
	quick_sort(vec, rightSize, (leftSize + 1) + pos);
}

int main(int argc, const char * argv[])
{
	int size;
	cin >> size;
	vector<int> vec(size);
	for (vector<int>::iterator it = vec.begin() ; it != vec.end() ; ++it) {
		cin >> *it;
	}
	
	quick_sort(vec,size,0);
	
	for (vector<int>::const_iterator cit = vec.cbegin() ; cit != vec.cend(); ++cit) {
		if (cit == vec.cbegin()) {
			cout << *cit;
		}
		else {
			cout << " " << *cit;
		}
	}
	
}

