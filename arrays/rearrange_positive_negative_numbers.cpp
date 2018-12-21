#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

void print_arr(const vector<int> arr){

	int size = arr.size();

	for(int i = 0; i < size; i++){
		cout << arr[i] << "\t";
	}

	cout << "\n";
}

int partition_helper(vector<int> &arr, int low, int high){

	int pivot = 0;
	int i = low -1;

	int k = 0;
	for(int j = high; j >= low; j--){
		if(arr[j] >= pivot){

			i++;
			swap(arr[i], arr[j]);
		}	
	}	
	
	swap(arr[i+1], arr[low]);

	return (i+1);
}

int partition(vector<int> &arr){

	int size = arr.size();

	return partition_helper(arr, 0, size-1);
}	

void rearrange_arr(vector<int> &arr){


	int size = arr.size() - 1;
	
	int start = 0;

	while(size >= start){
		
		if((arr[size] > 0 && arr[start] < 0) || (arr[size] < 0 && arr[start] > 0)){
			swap(arr[size], arr[start]);
			cout << "Coming with start " << start << "and end " << size << "\n";
			start++;
			size--;
		} 
		else if(arr[size] > 0 && arr[start] >0 ){
			start++;
		}
		else if (arr[size] < 0 && arr[start] < 0 ){
			size--;
		}	
		else {
			start++;
			size--;
		}	
	}	
}	

void rearrange_negative_positive(vector<int> &arr){

	int size = arr.size();

	int start = 0;
	int end = size-1;

	while(start <= end){
		swap(arr[start], arr[end]);
		start += 2;
		end -= 2;
	}	

}	

int main(){

	vector<int> arr;
	arr.push_back(10);
	arr.push_back(-1);
	arr.push_back(-100);
	arr.push_back(21);
	arr.push_back(37);
	arr.push_back(-90);
	arr.push_back(-17);
	arr.push_back(13);
	
	cout << "Before partitioning" << "\n";
	print_arr(arr);
	cout << "After partitioning" << "\n";
	int ret = partition(arr);
	print_arr(arr);

	rearrange_arr(arr);
	cout << "Arry after rearranging\n";
	print_arr(arr);

	cout << "After positive and negative rearrangement\n";
	rearrange_negative_positive(arr);
	print_arr(arr);

        return 1;
}
