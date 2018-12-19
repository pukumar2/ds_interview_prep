#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

void print_array(vector<int> arr){
	int size = arr.size();

	for(int i = 0; i < size; i++){
		cout << arr[i] << "\t";
	}	
	cout << "\n";
}	

void rearrange_array(vector<int> &arr){

	int size = arr.size();
	vector<int> copy_arr;

	// copy(arr.begin(), arr.end(), copy_arr.begin());
	for(int i = 0; i < size; i++){
		copy_arr.push_back(arr[i]);
	}	

	int evenPos = size / 2;
	int oddPos = size - evenPos;

	sort(copy_arr.begin(), copy_arr.end());
	// print_array(copy_arr);
	int j = oddPos-1;

	for(int i = 0; i < size; i += 2){
		arr[i] = copy_arr[j];
		j--;
	}	
	j = oddPos;
	for(int i = 1; i < size; i +=2){
		arr[i] = copy_arr[j];
		j++;
	}
}

int main(){

	vector<int> arr;

	arr.push_back(21);
	arr.push_back(23);
	arr.push_back(20);
	arr.push_back(11);
	arr.push_back(15);
	arr.push_back(9);
	arr.push_back(17);
	
	rearrange_array(arr);
	print_array(arr);
	
        return 1;
}
