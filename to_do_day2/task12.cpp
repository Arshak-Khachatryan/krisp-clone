#include <iostream>

class Book{
	private:
		std::string title;
		std::string author;
		int ISBN;
	public:
		std::string getTitle(){
			return title;
		}

		std::string getAuthor(){
			return author;
		}

		int getISBN(){
			return ISBN;
		}

		void setTitle(std::string title){
			this -> title = title;
		}

		void setAuthor(std::string author){
			this -> author = author;
		}
		
		void setISBN(int ISBN){
			this -> ISBN = ISBN;
		}
};

int main(){
	Book book_1;
	book_1.setTitle("Philosopher's Stone");
	book_1.setAuthor("J. K. Rowling");
	book_1.setISBN(19971997);

	std::cout<<"-----BOOK-INFO-----"<<std::endl;
	std::cout<<"Title: "<<book_1.getTitle()<<std::endl;
	std::cout<<"Author: "<<book_1.getAuthor()<<std::endl;
	std::cout<<"ISBN: "<<book_1.getISBN()<<std::endl;


	return 0;
}
