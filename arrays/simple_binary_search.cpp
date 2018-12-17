#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

#define NUM_ELEM 10
#define ELEM_FIND 8

using namespace std;

void print_array(const vector<int> arr){

	int size = arr.size();

	cout << "\n" << "Array is: " << "\n";
	for(int i = 0; i < size; i++){
		cout << arr[i] << "\t";
	}
		cout << "\n";
}	

int binary_search_help(const vector<int> arr, int start, int end, int x){

	if(start > end){
		return -1;
	}	

	if(start == end){
		return start;
	}	

	int mid = (start + end) / 2;

	if(arr[mid] == x){
		return mid;
	}	

	if(arr[mid] < x){
		return binary_search_help(arr, mid + 1, end, x);
	}

	return binary_search_help(arr, start, mid-1, x);

}

int binary_search(const vector<int> arr, int x){

	int size = arr.size();

	if(size < 0 || size == 0){
		return -1;
	}	

	if(size == 1){
		return 0;
	}	

	return binary_search_help(arr, 0, size-1, x);
}	

int main(){

	vector<int> arr;

	for(int i = 1; i < NUM_ELEM+1; i++){
		arr.push_back(i);
	}	

	print_array(arr);
	int ret = binary_search(arr, ELEM_FIND);

	if(ret != -1){
		cout << "Element found at : " << ret << "\n";
	} else {
		cout << "Element couldn't be found : " << "\n";	
	}

        return 1;
}
