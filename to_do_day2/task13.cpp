#include <iostream>

class Shape{
	public:
		double calculate_area(){
			return 0;
		}
};

class Circle : public Shape{
	private:
		double radius;
	public:
		Circle(int radius):radius(radius){}

		double calculate_area(){
			return 3.14 * radius * radius;
		}
};

class Rectangle : public Shape{
	private:
		double length;
		double width;
	public:
		Rectangle(double length,double width):length(length),width(width){}

		double calculate_area(){
			return width * length;
		}
};


int main(){
	Circle circle1(5);
	Rectangle ractangle1(8,6);

	std::cout<<"Area of circle(radius=5): "<<circle1.calculate_area()<<std::endl;
	std::cout<<"Area of ractangle(length=8,width=6): "<<ractangle1.calculate_area()<<std::endl;

	return 0;
}
