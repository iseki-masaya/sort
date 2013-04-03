//
//  main.cpp
//  quick_sort
//
//  Created by iseki on 2013/03/27.
//  Copyright (c) 2013年 iseki. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& vec,int left ,int right){
	if(right <= left){
		return;
	}
	
	//ピボットの選択
	int pivot = vec.at(left);
	
	//乱択にした際のためにleftから始める
	int i=left,j=right,work;
	while(1){
		while(vec.at(i) < pivot){
			++i;
		}
		while (vec.at(j) > pivot) {
			--j;
		}
		if(i>=j){
			break;
		}
		
		work = vec.at(i);
		vec[i] = vec.at(j);
		vec[j] = work;
		
		++i;
		--j;
	}
	
	quick_sort(vec, left, i-1);
	quick_sort(vec, j+1, right);
}

int main(int argc, const char * argv[])
{
	int size;
	cin >> size;
	vector<int> vec(size);
	for (vector<int>::iterator it = vec.begin() ; it != vec.end() ; ++it) {
		cin >> *it;
	}
	
	quick_sort(vec,0,size - 1);
	
	for (vector<int>::const_iterator cit = vec.cbegin() ; cit != vec.cend(); ++cit) {
		if (cit == vec.cbegin()) {
			cout << *cit;
		}
		else {
			cout << " " << *cit;
		}
	}
	
}

