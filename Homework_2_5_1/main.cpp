#include <iostream>

class Figure{
    protected:
        std::string figureName;
        int side;
    public:
        Figure(int side = 0){
            this->side = side;
        }
    virtual void getSide(){
            std::cout << "Фигура: "<< side << std::endl;
        }
};

class Triangle: public Figure{
    public:
    Triangle(): Figure(3){}
    void getSide() override{
            std::cout << "Трехугольник: "<< side << std::endl;
        }
};

class Quadriangle: public Figure{
    public:
    Quadriangle(): Figure(4){}
    void getSide() override{
            std::cout << "Четырехугольник: "<< side << std::endl;
        }
};

int main(){
    Figure figure;
    figure.getSide();
    Triangle triangle;
    triangle.getSide();
    Quadriangle quadriangle;
    quadriangle.getSide();
}