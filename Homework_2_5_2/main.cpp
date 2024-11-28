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
        Triangle(int a, int b, int c, 
        int A, int B, int C): Figure(3){
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
        }
    void getSide() override{
        std::cout << "Треугольник:" << std::endl;
        std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c << std::endl;
        std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << std::endl;
        }
    protected:
        int a;
        int b;
        int c;
        int A;
        int B;
        int C;
};

class IsoscelesTriangle: public Triangle{
    public:
        IsoscelesTriangle(int a, int b, 
            int A, int B) : Triangle(a, b, a, A, B, A){};
        void getSide() override{
            std::cout << "Равнобедренный треугольник:" << std::endl;
            std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c << std::endl;
            std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << std::endl;
        }
};

class RightTriangle: public Triangle{
    public:
        RightTriangle(int a, int b, int c, 
            int A, int B) : Triangle(a, b, c, A, B, 90){};
        void getSide() override{
            std::cout << "Прямоугольный треугольник:" << std::endl;
            std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c << std::endl;
            std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << std::endl;
        }
};

class EquilateralTriangle: public Triangle{
    public:
        EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60){};
        void getSide() override{
            std::cout << "Равносторонний треугольник:" << std::endl;
            std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c << std::endl;
            std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << std::endl;
        }
};

class Quadriangle: public Figure{
    public:
        Quadriangle(int a, int b, int c, int d, 
        int A, int B, int C, int D): Figure(4){
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }
        void getSide() override{
            std::cout << "Четырехугольник:" << std::endl;
            std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c <<" d="<< this->d << std::endl;
            std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << " D="<< this->D << std::endl;
        }
    protected:
        int a;
        int b;
        int c;
        int d;
        int A;
        int B;
        int C;
        int D;
};

class Rectangle: public Quadriangle{
    public:
        Rectangle(int a, int b) : Quadriangle(a, b, a, b, 90, 90, 90, 90){};
        void getSide() override{
            std::cout << "Прямоугольник:" << std::endl;
            std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c <<" d="<< this->d << std::endl;
            std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << " D="<< this->D << std::endl;
        }
};

class Square: public Quadriangle{
    public:
        Square(int a) : Quadriangle(a, a, a, a, 90, 90, 90, 90){};
        void getSide() override{
            std::cout << "Квадрат:" << std::endl;
            std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c <<" d="<< this->d << std::endl;
            std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << " D="<< this->D << std::endl;
        }
};

class Parallelogram: public Quadriangle{
    public:
        Parallelogram(int a, int b, int A, int B) : Quadriangle(a, b, a, b, A, B, A, B){};
        void getSide() override{
            std::cout << "Параллелограмм:" << std::endl;
            std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c <<" d="<< this->d << std::endl;
            std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << " D="<< this->D << std::endl;
        }
};

class Rhombus: public Quadriangle{
    public:
        Rhombus(int a, int A, int B) : Quadriangle(a, a, a, a, A, B, A, B){};
        void getSide() override{
            std::cout << "Ромб:" << std::endl;
            std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c <<" d="<< this->d << std::endl;
            std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << " D="<< this->D << std::endl;
        }
};

void printInfo(Figure* figure){
    figure->getSide();
    std::cout << std::endl;
}

int main(){
    Triangle triangle(10, 20, 30, 50, 60, 90);
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isoscelesTriangle(10,20,50,60);
    EquilateralTriangle equilateralTriangle(30);
    Quadriangle quadriangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10,20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30,30,40);

    printInfo(&triangle);
    printInfo(&rightTriangle);
    printInfo(&isoscelesTriangle);
    printInfo(&equilateralTriangle);
    printInfo(&quadriangle);
    printInfo(&square);
    printInfo(&parallelogram);
    printInfo(&rhombus);
}