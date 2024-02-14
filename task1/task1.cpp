#include <iostream>
#include <fstream>

void strrev(std::string& str){
	int n = str.length();
	for(int i = 0;i < n/2;i++){
		std::swap(str[i], str[n - i - 1]);
	}
}

void writing_in_file(const std::string& file_name,const std::string& s){
	std::ofstream file(file_name);
	file << s;
	file.close();
}

void reading_from_file(const std::string& file_name){
	std::string line;

	std::ifstream file(file_name);

	while(std::getline(file,line)){
		std::cout<<line<<std::endl;
	}
	file.close();
}

void remove_second_line(const std::string& file_name){
	std::string line;
	std::string s = "";

	std::ifstream file(file_name);

	int line_index = 0;
	while(std::getline(file,line)){
		if(line_index % 2 == 0){
			s += (line + '\n');
		}
		line_index++;
	}

	writing_in_file(file_name,s);
	file.close();
}

void revers_words_in_line(const std::string& file_name){
	std::ifstream file(file_name);
	std::string line;
	std::string s = "";
	std::string word = "";
	while(std::getline(file,line)){
		line += ' ';
		for(char ch : line){
			if(ch == ' '){
				strrev(word);
				s += (word + ' ');
				word = "";
			}
			word += ch;
		}
		s.pop_back();
		s += '\n';
	}
	s.pop_back();


	writing_in_file(file_name,s);
	file.close();
}









int main(){
	std::string file_name;
	std::string s;
	
	file_name = "test.txt";
	s = "1.Hello world\n2.Hello world\n3.Hello world";

	writing_in_file(file_name,s);
	
	reading_from_file(file_name);

	remove_second_line(file_name);
	
	revers_words_in_line(file_name);

	std::string wav_file_name = "file_example_WAV_2MG.wav";

	reading_from_file(wav_file_name);

	return 0;
}
