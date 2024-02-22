#include <iostream>
#include <fstream>

int main(){
	std::string names[] = {"James","Robert","John","Michael","David"};
	int size = std::end(names) - std::begin(names);

	std::ofstream file_w("names.txt");
	for(int i = 0; i < size; ++i){
		file_w<<names[i]<<std::endl;
	}

	file_w.close();

	std::ifstream file_r("names.txt");
	std::string line;

	while(std::getline(file_r,line)){
		std::cout<<line<<std::endl;
	}

	file_r.close();
	return 0;
}
