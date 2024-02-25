#include <iostream>


template <typename T>
class Shape{
	public:
		virtual T calculate_area() = 0;
};

template <typename T>
class Circle : public Shape<T>{
	private:
		T radius;
	public:
		Circle(T radius){
			if(radius <= 0){
				throw std::invalid_argument("Invalid input");
			}else{
				this -> radius = radius;
			}
		}

		T calculate_area() override{
			return 3.14 * radius * radius;
		}
};

template <typename T>
class Rectangle : public Shape<T>{
	private:
		T length;
		T width;
	public:
		Rectangle(T length,T width){
			if(length <= 0 || width <= 0){
				throw std::invalid_argument("Invalid input");
			}else{
				this -> length = length;
				this -> width = width;
			}
		}

		T calculate_area() override{
			return width * length;
		}
};


int main(){
	Circle<int> circle1(5);
	Rectangle<float> ractangle1(0.5,1.5);

	std::cout<<"Area of circle(radius=5): "<<circle1.calculate_area()<<std::endl;
	std::cout<<"Area of ractangle(length=8,width=6): "<<ractangle1.calculate_area()<<std::endl;

	return 0;
}
