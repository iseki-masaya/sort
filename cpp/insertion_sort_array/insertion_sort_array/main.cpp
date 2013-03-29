//
//  main.cpp
//  insertion_sort
//
//  Created by iseki on 2013/03/28.
//  Copyright (c) 2013年 iseki. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void migration(vector<int>& vec,int start,int end){
	int work = vec.at(end);
	int workTmp;

	for (int i = start; i <= end; ++i) {
		workTmp = vec.at(i);
		vec[i] = work;
		work = workTmp;
	}
}


void insertion_sort(vector<int>& vec,int size){
	int insertion;
	for (int i = 1; i < size; ++i) {
		insertion = vec.at(i);
		for (int j = 0; j < i; ++j) {
			if (vec.at(j) > insertion) {
				migration(vec, j, i);
				break;
			}
		}
	}
}

int main(int argc, const char * argv[])
{
	int length;
	cin >> length;
	vector<int> vec(length);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cin >> *it;
	}
	
	insertion_sort(vec,length);
	
	for (int i = 0; i < length; ++i){
		cout << vec[i] << " ";
	}
}

