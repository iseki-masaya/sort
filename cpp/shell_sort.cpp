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


void insertion_sort(vector<int>& vec,int start,int step){
	int size = (int)vec.size();
	int insertion;
	for (int i = start + step; i < size; i += step) {
		insertion = vec.at(i);
		for (int j = start; j < i; j += step) {
			if (vec.at(j) > insertion) {
				migration(vec, j, i);
				break;
			}
		}
	}
}

void shell_sort(vector<int>& vec)
{
	int step = 1;
	int size = (int)vec.size();
	while (size > step) {
		step = 3*step + 1;
	}
	step = (step - 1)/3;
	while (step > 0) {
		for (int i=0; i<step; ++i) {
			insertion_sort(vec, i, step);
		}
		step = (step - 1)/3;
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
	
	shell_sort(vec);
	
	for (int i = 0; i < length; ++i){
		cout << vec[i] << " ";
	}
}

