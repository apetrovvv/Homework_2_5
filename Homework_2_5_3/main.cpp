#include <iostream>

class Figure{
    protected:
        std::string figureName; 
        int side;
        bool isTrue = true;
        std::string correct(){
            if(this->isTrue) return "Правильная";
            return "Неправильная";
        }
        
    public:
        Figure(int side = 0){
            this->side = side;
            this->figureName = "Фигура";
        }
        virtual void getSide(){
            std::cout << figureName << ": "<< side << std::endl;
            std::cout << correct() << std::endl;
            std::cout << "Количество сторон: "<< side << std::endl;
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
            if(this->A+this->B+this->C!=180) this->isTrue = false;
            this->figureName = "Треугольник";
        }
    void getSide() override{
        std::cout << figureName << ": "<< side << std::endl;
        std::cout << correct() << std::endl;
        std::cout << "Количество сторон: "<< side << std::endl;
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
            int A, int B) : Triangle(a, b, a, A, B, A){
                this->figureName = "Равнобедренный треугольник";
            };
        IsoscelesTriangle(int a, int b, int c, 
            int A, int B, int C) : Triangle(a, b, c, A, B, C){
                if((this->A!=this->C) && (this->a!=this->c)) this->isTrue =false;
                this->figureName = "Равнобедренный треугольник";
        };
        // void getSide() override{
        //     std::cout << "Равнобедренный треугольник:" << std::endl;
        //     std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c << std::endl;
        //     std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << std::endl;
        // }
};

class RightTriangle: public Triangle{
    public:
        RightTriangle(int a, int b, int c, 
            int A, int B) : Triangle(a, b, c, A, B, 90){
                this->figureName = "Прямоугольный треугольник";
        };
        RightTriangle(int a, int b, int c, 
            int A, int B, int C) : Triangle(a, b, c, A, B, C){
                if(this->C!=90) this->isTrue =false;
                this->figureName = "Прямоугольный треугольник";
        };
        // void getSide() override{
        //     std::cout << "Прямоугольный треугольник:" << std::endl;
        //     std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c << std::endl;
        //     std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << std::endl;
        // }
};

class EquilateralTriangle: public Triangle{
    public:
        EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60){
            this->figureName = "Равносторонний треугольник";
        };
        EquilateralTriangle(int a, int b, int c, 
            int A, int B, int C) : Triangle(a, b, c, A, B, C){
                if((this->C!=this->A) && (this->B!=this->A)) this->isTrue =false;
                if(this->a!=60 && this->b!=60 && this->c!=60) this->isTrue =false;
                this->figureName = "Равносторонний треугольник";
        };
        // void getSide() override{
        //     std::cout << "Равносторонний треугольник:" << std::endl;
        //     std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c << std::endl;
        //     std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << std::endl;
        // }
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
            this->figureName = "Четырехугольник";
            if(this->A+this->B+this->C+this->D!=360) this->isTrue = false;
        }
        void getSide() override{
            std::cout << figureName << ": "<< side << std::endl;
            std::cout << correct() << std::endl;
            std::cout << "Количество сторон: "<< side << std::endl;
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
        Rectangle(int a, int b) : Quadriangle(a, b, a, b, 90, 90, 90, 90){
            this->figureName = "Прямоугольник";
        };
        Rectangle(int a, int b, int c, int d, 
        int A, int B, int C, int D) : Quadriangle(a, b, c, d, A, B, C, D){
            this->figureName = "Прямоугольник";
            if(this->a!=this->c && this->b!=this->d) this->isTrue = false;
            if(this->A!=90 && this->B!=90 && this->C!=90 && this->D!=90) this->isTrue = false;
        }
        // void getSide() override{
        //     std::cout << "Прямоугольник:" << std::endl;
        //     std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c <<" d="<< this->d << std::endl;
        //     std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << " D="<< this->D << std::endl;
        // }
};

class Square: public Quadriangle{
    public:
        Square(int a) : Quadriangle(a, a, a, a, 90, 90, 90, 90){
            this->figureName = "Квадрат";
        };
        Square(int a, int b, int c, int d, 
        int A, int B, int C, int D) : Quadriangle(a, b, c, d, A, B, C, D){
            this->figureName = "Квадрат";
            if(this->a!=this->b && this->a!=this->c && this->a!=this->d) this->isTrue = false;
            if(this->A!=90 && this->B!=90 && this->C!=90 && this->D!=90) this->isTrue = false;
        }
        // void getSide() override{
        //     std::cout << "Квадрат:" << std::endl;
        //     std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c <<" d="<< this->d << std::endl;
        //     std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << " D="<< this->D << std::endl;
        // }
};

class Parallelogram: public Quadriangle{
    public:
        Parallelogram(int a, int b, int A, int B) : Quadriangle(a, b, a, b, A, B, A, B){
            this->figureName = "Параллелограмм";
            if(this->a!=this->c && this->b!=this->d) this->isTrue = false;
            if(this->A!=this->C && this->B!=this->D) this->isTrue = false;
        };
        Parallelogram(int a, int b, int c, int d, 
        int A, int B, int C, int D) : Quadriangle(a, b, c, d, A, B, C, D){
            this->figureName = "Параллелограмм";
        }
        // void getSide() override{
        //     std::cout << "Параллелограмм:" << std::endl;
        //     std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c <<" d="<< this->d << std::endl;
        //     std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << " D="<< this->D << std::endl;
        // }
};

class Rhombus: public Quadriangle{
    public:
        Rhombus(int a, int A, int B) : Quadriangle(a, a, a, a, A, B, A, B){
            this->figureName = "Ромб";
        };
        Rhombus(int a, int b, int c, int d, 
        int A, int B, int C, int D) : Quadriangle(a, b, c, d, A, B, C, D){
            this->figureName = "Ромб";
            if(this->a!=this->b && this->a!=this->c && this->a!=this->d) this->isTrue = false;
            if(this->A!=this->C && this->B!=this->D) this->isTrue = false;
        };
        // void getSide() override{
        //     std::cout << "Ромб:" << std::endl;
        //     std::cout << "Стороны: a="<< this->a <<" b="<< this->b <<" c="<< this->c <<" d="<< this->d << std::endl;
        //     std::cout << "Углы: A="<< this->A <<" B="<< this->B <<" C="<< this->C << " D="<< this->D << std::endl;
        // }
};

void printInfo(Figure* figure){
    figure->getSide();
    std::cout << std::endl;
}

int main(){
    Figure figure(0);
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20, 30, 50, 60, 90);
    RightTriangle rightTriangle2(10, 20, 30, 50, 40, 90);
    IsoscelesTriangle isoscelesTriangle(10, 20, 10, 50, 60, 50);
    EquilateralTriangle equilateralTriangle(30, 30, 30, 60, 60, 60);
    Quadriangle quadriangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    Square square(20, 20, 20, 20, 90, 90, 90, 90);
    Parallelogram parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
    Rhombus rhombus(30, 30, 30, 30, 30, 40, 30, 40);
    printInfo(&figure);
    printInfo(&triangle);
    printInfo(&rightTriangle);
    printInfo(&rightTriangle2);
    printInfo(&isoscelesTriangle);
    printInfo(&equilateralTriangle);
    printInfo(&quadriangle);
    printInfo(&square);
    printInfo(&parallelogram);
    printInfo(&rhombus);
}