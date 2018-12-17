#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

#define ELEM 5
#define MAX_ELEM 10

void print_array(const vector<int> arr){

	int size = arr.size();

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

	cout << "This should print" << "\n";

        int size = arr.size();

        if(size < 0 || size == 0){
                return -1;
        }

        if(size == 1){
                return 0;
        }

        return binary_search_help(arr, 0, size-1, x);
}

int find_pivot(vector<int> arr, int start, int end){

	if(start > end){
	   	
	   return -1;
	}	

	if(start == end)
		return start;

	int mid = (start + end) / 2;

	if(mid < end && arr[mid] > arr[mid+1]){
		return mid;
	}	

	if(mid > start && arr[mid] < arr[mid-1]){
		return mid-1;
	}	

	if(arr[start] >= arr[mid]){
		return find_pivot(arr, start, mid-1);
	}	

	return find_pivot(arr, mid+1, end);
}	

int find_element_rotated_sorted_array(const vector<int> arr, int x){
	
	int size = arr.size();

	int pivot = find_pivot(arr, 0, size-1); 

	if(pivot == -1){
		return binary_search(arr, x);
	}	

	if(arr[pivot] == x){
		return pivot;
	}	

	if(arr[0] <= x){
		return binary_search_help(arr, 0, pivot-1, x);
	}	

	return binary_search_help(arr, pivot+1, size-1, x);
}

int main(){

	vector<int> arr;

	for(int i = 0; i < MAX_ELEM; i++){
		arr.push_back(i);
	}	

	int ret = find_element_rotated_sorted_array(arr, ELEM);
	
	if(ret == -1){
		cout << "Element couldn't be found" << "\n";
	}
	else {
		cout << "Element found at " << ret << "\n";
	}		

        return 1;
}
