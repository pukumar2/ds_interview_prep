#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

#define MAX_ELEM 	10

void print_array(const vector<int> arr){

	int size = arr.size();

	for(int i = 0; i < size; i++){
		cout << arr[i] << "\t";
	}	

	cout << "\n";
}	


int max_value(vector<int> arr){

	int arr_sum = 0;
	int curr_val = 0;
	int max_val = 0;

	for(int i = 0; i < MAX_ELEM; i++){
		arr_sum = arr_sum + arr[i];
		curr_val = curr_val + (i * arr[i]);
	}

	max_val = curr_val;

	for(int i = 1; i < MAX_ELEM; i++){
		curr_val = curr_val + arr_sum - MAX_ELEM * arr[MAX_ELEM - i];
		if(curr_val > max_val){
			max_val = curr_val;
		}
	}
	return max_val;
}	

int main(){


	vector<int> arr;

	for(int i = 0; i < MAX_ELEM; i++){
		arr.push_back(i);
	}	

	int ret = max_value(arr);
	cout << "Maximum value is :" << ret << "\n";
	return 1;
}


