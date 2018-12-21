#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

void print_array(vector<int> arr){

	int size = arr.size();

	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}

	cout << "\n";
}

void rearrange_array_zero(vector<int> &arr){
	
	int size = arr.size();
	int start = 0;
	int end = size - 1;

	while(start <= end){
		if(arr[start] == 0 && (arr[end] > 0 || arr[end] < 0)){
			swap(arr[start], arr[end]);
			start ++;
			end--;
		} else if(arr[start] == 0 && arr[end] == 0){
			end--;
		} else if (arr[end] > 0 && arr[start] > 0){ 
			start++;
		}		
		else {
			start++;
			end--;
		}	
	}	
}

int main(){

	vector<int> arr;

	arr.push_back(1);
	arr.push_back(0);
	arr.push_back(-4);
	arr.push_back(3);
	arr.push_back(0);
	arr.push_back(-10);
	arr.push_back(0);
	
	cout << "Original array is \n";
	print_array(arr);	

	rearrange_array_zero(arr);
	cout << "Array after rearranging \n";
	print_array(arr);

        return 1;
}
