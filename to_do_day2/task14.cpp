#include <iostream>
#include <string>

class Shape{
	public:
		virtual double calculate_area() = 0;
};

class Circle : public Shape{
	private:
		double radius;
	public:
		Circle(int radius):radius(radius){}

		double calculate_area() override{
			return 3.14 * radius * radius;
		}
};

class Rectangle : public Shape{
	private:
		double length;
		double width;
	public:
		Rectangle(double length,double width):length(length),width(width){}

		double calculate_area()override{
			return width * length;
		}
};

void print_area(Shape& ob){
	std::cout<<"Area of "<<((std::string)typeid(ob).name()).erase(0,1)<<": "<<ob.calculate_area()<<std::endl;
}


int main(){
	Circle circle1(5);
	Rectangle rectangle1(8,6);
	
	print_area(circle1);
	print_area(rectangle1);


	return 0;
}
