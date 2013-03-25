//
//  main.cpp
//  bubble_sort
//
//  Created by iseki on 2013/03/25.
//  Copyright (c) 2013年 eveneko. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int bubble_sort(vector<int>& vec){
	int length = (int)vec.size();
	int tmp=0;
	int cnt=0;
	for (int i=0; i<length; ++i) {
		for (int j=1; j<length; ++j) {
			if(vec[j-1] > vec[j]){
				tmp = vec[j-1];
				vec[j-1] = vec[j];
				vec[j] = tmp;
				tmp = 0;
				++cnt;
			}
		}
	}
	
	return cnt;
}

int main(int argc, const char * argv[])
{
	int size;
	cin >> size;
	vector<int> vec(size);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cin >> *it;
	}
	
	int cnt;
	cnt = bubble_sort(vec);
	
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl << cnt << endl;
}

