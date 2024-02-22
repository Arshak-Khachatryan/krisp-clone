#include <iostream>

void print_arr(int arr[],int size);
void bubble_sort(int arr[],int size);
void selection_sort(int arr[],int size);

typedef void (*ptr_sort_func)(int[],int);

enum SortingStrategy{BUBBLE_SORT,SELECTION_SORT};

struct SortingOption{
	SortingStrategy strategy;
	ptr_sort_func ptr;
	
};

int main(){
	int arr[] = {27,6,1,2,5,60,12,127,1,20};
	int size = sizeof(arr)/sizeof(arr[0]);

	SortingOption alg[] = {{BUBBLE_SORT,bubble_sort},{SELECTION_SORT,selection_sort}};
	
	int choice;
	std::cout<<"Select a sorting algorithm(1 -> Bubble Sort|2 -> Selector Sort):";
	std::cin>>choice;

	SortingOption SelectedOption = alg[choice-1];
	print_arr(arr,size);
	SelectedOption.ptr(arr,size);
	print_arr(arr,size);

	return 0;
}

void swap(int* n1,int* n2){
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void selection_sort(int arr[],int size){
	for(int i = 0;i < size;++i){
		int min_index = i;
		for(int j = i+1;j < size;++j){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		swap(&arr[min_index],&arr[i]);
	}
}



void bubble_sort(int arr[],int size){
	for(int i = 0;i < size ;++i){
		for(int j = 0;j < size-1;++j){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void print_arr(int arr[],int size){
	for(int i = 0;i < size;++i){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

