#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

class SortingStrategy{
	public:
		virtual void sort(std::vector<int>&) = 0;
}; 

class BubbleSort : public SortingStrategy{
	public:
		void sort(std::vector<int>& arr) override{
			int size = arr.size();
    			for (int i = 0; i < size-1; ++i) {
        			for (int j = 0; j < size-i-1; ++j) {
            				if (arr[j] > arr[j+1]) {
                				std::swap(arr[j], arr[j+1]);
            				}
        			}
    			}

		}
};

class SelectionSort : public SortingStrategy{
	public:
		void sort(std::vector<int>& arr) override{
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
};

class FileHandler{
	public:
		std::vector<int> readArrayFromFile(std::string fileName){
			std::vector<int> arr;

        		std::ifstream file_r(fileName);

        		std::string line;
        		while(std::getline(file_r,line)){
                		arr.push_back(stoi(line));
        		}

        		file_r.close();
			return arr;
		}

		void saveArrayToFile(std::string fileName,std::vector<int> arr){
			std::ofstream file_w(fileName);
        		for(int num : arr){
                		file_w << num << std::endl;
        		}

        		file_w.close();
		}
};

class SortingApplication{
	private:
		SortingStrategy* strategy = nullptr;
		FileHandler fileHandler;
		std::string inputFileName;
		std::string outputFileName;
	public:
		~SortingApplication(){
			delete strategy;
		}

		void selectFileNames(){
			std::cout<<"Enter input file name: ";
			std::cin>>inputFileName;
			std::cout<<"Enter output file name: ";
			std::cin>>outputFileName;
		}

		void selectSortingStrategy(){
			int choice;
			std::cout<<"Select a sorting algorithm(1 -> Bubble Sort|2 -> Selector Sort):";
        		std::cin>>choice;
			if(choice == 1){
				strategy = new BubbleSort;
			}else{
				strategy = new SelectionSort;
			}
		}

		void startSorting(){
			std::vector<int> arr = fileHandler.readArrayFromFile(inputFileName);
			strategy -> sort(arr);
			fileHandler.saveArrayToFile(outputFileName,arr);
		}
};


int main(){
	SortingApplication app;
	app.selectFileNames();
	app.selectSortingStrategy();
	app.startSorting();

	return 0;
}


