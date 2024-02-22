#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void print_vector(std::vector<int>);
void bubble_sort(std::vector<int>&);
void selection_sort(std::vector<int>&);

typedef void (*ptr_sort_func)(std::vector<int>&);

enum SortingStrategy{BUBBLE_SORT,SELECTION_SORT};

struct SortingOption{
	SortingStrategy strategy;
	ptr_sort_func ptr;
	
};

int main(){
	std::vector<int> arr;
	
	std::ifstream file_r("numbers.txt");
	
	std::string line;
	while(std::getline(file_r,line)){
		arr.push_back(stoi(line));
	}

	file_r.close();

	int size = arr.size();
	
	SortingOption alg[] = {{BUBBLE_SORT,bubble_sort},{SELECTION_SORT,selection_sort}};
	
	int choice;
	std::cout<<"Select a sorting algorithm(1 -> Bubble Sort|2 -> Selector Sort):";
	std::cin>>choice;

	SortingOption SelectedOption = alg[choice-1];
	
	SelectedOption.ptr(arr);

	std::ofstream file_w("sorted_numbers.txt");
	for(int num : arr){
		file_w << num << std::endl;
	}

	file_w.close();
	

	return 0;
}


void selection_sort(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size-1; ++i) {
        int minIndex = i;
        for (int j = i+1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}


void bubble_sort(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}


void print_vector(std::vector<int> arr){
	int size = arr.size();
	for(int i = 0;i < size;++i){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

