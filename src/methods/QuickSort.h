#include <iostream>
#include <string>

using namespace std;

template<class T>
void swp(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template<class T>
void showArray(T data[], int n) {
	for(int i=0;i<n;i++)
		cout << data[i] << " ";
}

template<class T>
int partition(T data[], int low, int high) {
	int pivot_index = (low+high)/2;
	swp(data[pivot_index], data[high]);

	int i = low;

	for(int j=low;j<high;j++) {
		if( data[j] <= data[high] ) {
			swp(data[i], data[j]);
			i++;
		}
	}

	swp(data[i], data[high]);

	return i;
}

template<class T>
void quicksort(T data[], int low, int high) {

	if( low >= high) {
		return;
	}

	int pivot_index = partition(data, low, high);
	quicksort(data, low, pivot_index-1);
	quicksort(data, pivot_index+1, high);
}

template<class T>
void sort(T data[], int n) {
	quicksort(data, 0, n-1);
}

main()
{

	string data[] = {"Balazs","Daniel","Adam","Adaam"};
	int n = sizeof(data)/sizeof(data[0]);

	sort(data, n);
	showArray(data, n);
}