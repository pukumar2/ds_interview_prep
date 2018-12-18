#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

#define MAX_ELEM		10

void print_array(vector<int> arr){

	cout << "\n";
	int size = arr.size();
	for(int i = 0; i < size; i++){
		cout << arr[i] << "\t";
	}	
	cout << "\n";
}	

void reverse_algo(vector<int> &arr, int start, int end){

	if(start > end){
		return;
	}

	while(start < end){
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}	
}

#if 0 Internet solution
int countRotations(vector<int> arr, int low, int high)
{
    // This condition is needed to handle the case
    // when array is not rotated at all
    if (high < low)
        return 0;

    // If there is only one element left
    if (high == low)
        return low;

    // Find mid
    int mid = low + (high - low)/2; /*(low + high)/2;*/

    // Check if element (mid+1) is minimum element.
    // Consider the cases like {3, 4, 5, 1, 2}
    if (mid < high && arr[mid+1] < arr[mid])
       return (mid+1);

    // Check if mid itself is minimum element
    if (mid > low && arr[mid] < arr[mid - 1])
       return mid;

    // Decide whether we need to go to left half or
    // right half
    if (arr[high] > arr[mid])
       return countRotations(arr, low, mid-1);

    return countRotations(arr, mid+1, high);
}
#endif

int help_pivot(vector<int> arr, int start, int end){

	if(start > end){
		return -1;
	}	

	int mid = (start + end) / 2;

	if(mid < end && arr[mid] > arr[mid+1])
		return mid;

	if(mid > start && arr[mid] < arr[mid-1])
		return mid-1;

	if(arr[start] >= arr[mid]){
		return help_pivot(arr, 0, mid-1);
	}	

	return help_pivot(arr, mid+1, end);
}


int find_pivot(vector<int> arr){

	int size = arr.size();

	return help_pivot(arr, 0, size-1);
}	

void rotate_array(vector<int> &arr, int d){

	int n = arr.size();
	reverse_algo(arr, 0, d-1);
	reverse_algo(arr, d, n-1);
	reverse_algo(arr, 0, n-1);
}

int main(){

	vector<int> arr;
	
//	for(int i = 0; i < MAX_ELEM; i++){
//		arr.push_back(i);
//	 }	
	arr.push_back(215);
	arr.push_back(218);
	arr.push_back(22);
	arr.push_back(23);
	arr.push_back(26);
	arr.push_back(212);
	//rotate_array(arr, 3);
	//cout << "Rotated array" << "\n";
	print_array(arr);
	
	// int ret = countRotations(arr, 0, MAX_ELEM-1);

	int ret = find_pivot(arr);
	if(ret == -1)
		ret = 0;

	cout << "Number of rotations are" << ret+1 << "\n";

        return 1;
}
