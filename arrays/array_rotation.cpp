#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

void leftRotateByOne(vector<int> &arr){

	// int temp = arr[0];
	int i;

	int size = arr.size();
	for(i = 0; i < size-1; i++){
		arr[i] = arr[i+1];
	}

	// arr[i] = temp;
}

void print_array(vector<int> &arr){

	int size = arr.size();
	for(int i = 0 ; i < size; i++){
                cout << arr[i] << "\t";
        }
}	


void rotate_array(vector<int> &arr, int d){

	for(int i = 0; i < d; i++){
		cout << "After" << i << "iteration \n";
		leftRotateByOne(arr);
		// print_array(arr);
	}	

}	

int find_gcd(int a, int b){

	if(b == 0)
		return a;

	return find_gcd(b, a % b);
}	

void swap(int a, int b){

	int temp = a;
	a = b;
	b= temp;
}	

void reserve_array(vector<int> &arr, int start, int d){

	int i = start;
	while(i < d){
		// swap(arr[i], arr[d]);
		int temp = arr[i];
		arr[i] = arr[d];
		arr[d] = temp;
		i++;
		d--;
	}	

}

void rotate_array_optimized_reversal(vector<int> &arr, int b){

	int size = arr.size();
	reserve_array(arr, 0, b-1);
	reserve_array(arr, b, size-1);
	reserve_array(arr, 0, size-1);
}	

int main(){

	
	vector<int> arr;

	// Taking an example of 12 elements in the array
	for(int i = 1; i < 12; i++){
		arr.push_back(i);
	}

	int size = arr.size();
	rotate_array_optimized_reversal(arr, 9);
        print_array(arr);
	cout << "\n";
	return 1;
}
