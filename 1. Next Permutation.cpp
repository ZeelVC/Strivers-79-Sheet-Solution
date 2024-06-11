/* Comments Section */

/*
	
	1. First method that comes in the mind, is to find out and 
	store all possible permutation of an array and then sorting 
	that permutation array in an ascending way. Now we can do
	linear search and find next permutation.
	Time Complexity: - O(n * n!) * log(O(n * n!)) - as there are n! 
	permutation possible and O(n) time wil required to print each 
	permutation.
	Space complexity: - O(n * n!)
	
	2. Second approach has three subparts: - 
	2.1 First part is to find the break point, we wil traverse the
	array from right side (index = n - 2), and break point will occur
	when array[i] < array[i + 1].
	If we do not find any break point, that means array is in
	decreasing order hence we just need to reverse the array and
	return.
	
	2.2 Second part is to find next greater element in right part
	of array (right part form index i where break point comes), and
	then swaping next greater element with array[i].
	
	2.3 Third part is to reverse the right part of array from index
	i.
	
	Time Complexity: - O(3 * n)
	Space ComplexityL: - O(1) 
		
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; // Represents size of an array
	cin >> n; // Taking input of size
	vector<int> arr(n);
	for(int i = 0; i < n; i++ ){
		cin >> arr[i];
	}
	
	int index = -1; // Represents break point index, iniially
			        // assign -1.
	for(int i = n - 2; i >= 0; i--){
		if(arr[i] < arr[i + 1]){
			index = i;
			break;
		}
	}
	
	if(index == -1){
		reverse(arr.begin(), arr.end());
		for(int i = 0; i < n; i++ ){
			cout << arr[i] << ' ';
		}
		cout << endl;
	}else{
		for(int i = n - 1; i > index; i--){
			if(arr[i] > arr[index]){
				swap(arr[i], arr[index]);
				break;
			}
		}
		
		reverse(arr.begin() + index + 1, arr.end());
		for(int i = 0; i < n; i++ ){
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	return 0;
} 