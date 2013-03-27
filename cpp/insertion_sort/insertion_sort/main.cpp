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

void insertion_sort(vector<int>& vec,int size){
	int insertion;
	for (int i = 1; i < size; ++i) {
		insertion = vec.at(i);
		for (int j = 0; j < i; ++j) {
			if (vec.at(j) > insertion) {
				vec.erase(vec.begin() + i);
				vec.insert(vec.begin() + j, insertion);
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
	
	for (vector<int>::const_iterator cit = vec.cbegin(); cit != vec.cend(); ++cit) {
		cout << *cit << " ";
	}
}

