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

int cnt=0;

vector<int> set(vector<int>& vec,int size,int pos){
	vector<int> contain(size);
	int i=0;
	for (vector<int>::iterator it=contain.begin(); it!=contain.end(); ++it) {
		*it = vec.at(pos+i);
		++i;
	}
	return contain;
}

void merge(vector<int>& vec,int left,int mid,int right){
	vector<int> L(set(vec,mid-left + 1,left));
	L.push_back(10e8);
	vector<int> R(set(vec, right-mid,mid+1));
	R.push_back(10e8);
	int l=0,r=0;
	for (int i=left; i <= right; ++i) {
		if(L[l] <= R[r]){
			//イコールにすることで安定的になる。
			vec[i] = L[l];
			++l;
		}
		else{
			vec[i] = R[r];
			++r;
		}
		++cnt;
	}
}

void merge_sort(vector<int>& vec,int left,int right){
	if(right <= left){
		return;
	}
	int mid = (int)(right+left)/2;
	merge_sort(vec,left,mid);
	merge_sort(vec, mid+1,right);
	merge(vec,left,mid,right);
}

int main(int argc, const char * argv[])
{
	int size;
	cin >> size;
	vector<int> vec(size);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cin >> *it;
	}
	
	merge_sort(vec,0,(int)vec.size()-1);
	
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		if (it == vec.begin()) {
			cout << *it;
		}
		else{
			cout << " " << *it;
		}
	}
	cout << endl << cnt << endl;
}

