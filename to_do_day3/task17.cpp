#include <iostream>

class Shape{
	public:
		virtual double calculate_area() = 0;
};

class Circle : public Shape{
	private:
		double radius;
	public:
		Circle(double radius){
			if(radius <= 0){
				throw std::invalid_argument("Invalid input");
			}else{
				this -> radius = radius;
			}
		}

		double calculate_area() override{
			return 3.14 * radius * radius;
		}
};

class Rectangle : public Shape{
	private:
		double length;
		double width;
	public:
		Rectangle(double length,double width){
			if(length <= 0 || width <= 0){
				throw std::invalid_argument("Invalid input");
			}else{
				this -> length = length;
				this -> width = width;
			}
		}

		double calculate_area() override{
			return width * length;
		}
};


int main(){
	Circle circle1(5);
	Rectangle ractangle1(8,-6);

	std::cout<<"Area of circle(radius=5): "<<circle1.calculate_area()<<std::endl;
	std::cout<<"Area of ractangle(length=8,width=6): "<<ractangle1.calculate_area()<<std::endl;

	return 0;
}
