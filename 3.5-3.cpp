// 3.5-3.cpp :
// 15.07.23
#include <iostream>
#include <Windows.h>


class Figure {
public:
    std::string name;
    int number_sides;
 

    Figure(int a, int b, int c, int A, int B, int C) {
        name = "Фигура: ";
        number_sides = 0;

    }

    virtual bool check() {
        if(number_sides == 0) return true;//    1 = true
        if (number_sides != 0) return false;//  0 = false
    }
       
    virtual void print(){ // : Figure(a, b, c, A, B, C) {
        std::cout << name << "\n";
        check() == 1 ? std::cout << "Правильная\n" : std::cout << "Неправильная\n";
        std::cout  <<"Количество сторон: " << number_sides << "\n\n";
    }
};


class Triangle : public Figure {
public:
    int a;
    int b;
    int c;
    //int d;
    int A;
    int B;
    int C;
    //int D;
    Triangle(int a, int b, int c, int A, int B, int C) : Figure(a,b,c,A,B,C){
        name = "Треугольник: ";
        number_sides = 3;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    bool check() override{
        if (A + B + C == 180 && number_sides == 3)
            return 1;
        else
        {
            return 0;
        }
    }


    void print()  override {
        //check();
        std::cout << name << "\n";
        check() == 1 ? std::cout << "Правильная\n" : std::cout << "Неправильная\n";
        std::cout << "Количество сторон: " << number_sides << "\n";
        std::cout << "Стороны: a = " << a << " b = " << b << " c = " << c ;
        std::cout << "\nУглы: A=" << A << " B=" << B << " C=" << C  <<"\n\n";
    };
};

class Triangle_p : public Triangle {
public:

    Triangle_p(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C){
        name = "Прямоугольный треугольник: ";
        //C = 90;
        //B = 180 - (A + C);
    }
    bool check() override {
        if (C == 90 && Triangle :: check()) // && A+B+C==180)
            return 1;
        else
        {
            return 0;
        }
    }
};

class Triangle_rb : public Triangle {
public:

    Triangle_rb(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        name = "Равнобедренный треугольник: ";
        //a = c;
        //A = C;
        //B = 180 - C * 2;
    }
    bool check() override {
        if (a == c && A == C && Triangle::check()) // && A+B+C==180)
            return 1;
        else {
            return 0;
        }
    }
};

class Triangle_rs : public Triangle {
public:

    Triangle_rs(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        name = "Равносторонний треугольник: ";
    //    a = c;
    //    b = c;
    //    A = 60;
    //    B = A;
    //    C = A;
    }
    bool check() override {
        if (a == c && c == b && A == C && A == B && Triangle::check()) // && A+B+C==180)
            return 1;
        else {
            return 0;
        }
    }
};




class Quadrangle : public Triangle {
public:
    int d;
    int D;
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Triangle(a, b, c, A, B, C) {
        name = "Четырёхугольник: ";
        number_sides = 4;
        this-> d=d;
        this-> D=D;
    }
    
    bool check() override {

        if (A + B + C + D == 360 )
            return 1;
        else {
            return 0;
        }
    }
    void print() {
        std::cout << name << "\n";
        check() == 1 ? std::cout << "Правильная\n" : std::cout << "Неправильная\n";
        std::cout << "Количество сторон: " << number_sides << "\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};
class Quadrangle_p : public Quadrangle {
public:
    Quadrangle_p(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {
        name = "Параллелограмм: ";
        //a = c;
        //b = d;
        //C = A;
        //D = B;
    }
    bool check() override {
        if (a == c && b == d && A == C && B == D && Quadrangle::check())
            return 1;
        else {
            return 0;
        }
    }
};
class Quadrangle_r : public Quadrangle {
public:
    Quadrangle_r(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {
        name = "Ромб: ";
        //b = a;
        //d = a;
    }
    bool check() override {
        if (a == c && b == d && c == b && A == C && B == D && Quadrangle::check())
            return 1;
        else {
            return 0;
        }
    }
};
class Quadrangle_par : public Quadrangle {
public:
    Quadrangle_par(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {
        name = "Прямоугольник: ";
        //A = B = C = D = 90;
    }
    bool check() override {
        if (a == c && b == d && A == 90 && B == 90 && D == 90 && C == 90)// && Quadrangle::check())
            return 1;
        else {
            return 0;
        }
    }
};
class Quadrangle_kv : public Quadrangle {
public:
    Quadrangle_kv(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {
        name = "Квадрат: ";
        //b = d = a = c ;
    }
    bool check() override {
        if (a == c && b == d && c == b && A == 90 && B == 90 && D == 90 && C == 90)// && Quadrangle::check())
            return 1;
        else {
            return 0;
        }
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Figure f (20, 20, 30, 50, 60, 70);
    f.print();

    Triangle t (10,20,30,50,60,70);
    Figure* par_Triangle = &t;
     par_Triangle ->print();
   
    Triangle_p tp(10, 20, 30, 30, 60, 90);
    Figure* par_Triangle_p = &tp;
   /* par_Triangle_p->check();*/
    par_Triangle_p->print();

    Triangle_rb rb(20, 30, 20, 45, 90, 45);
    Figure* par_Triangle_rb = &rb;
  /*  par_Triangle_rb->check();*/
    par_Triangle_rb->print();

    Triangle_rs rs(20, 20, 20, 60, 60, 60);
    Figure* par_Triangle_rs = &rs;
  /*  par_Triangle_rs->check();*/
    par_Triangle_rs->print();


    Quadrangle q(20, 30, 40, 60, 30, 140, 130, 60);
    Figure* par_Quadrangle = &q;
    //par_Quadrangle->check();
    par_Quadrangle->print();

    Quadrangle_p p(20, 30, 20, 30, 30, 150, 30, 150);
    Figure* par_Quadrangle_p = &p;
    //par_Quadrangle_p->check();
    par_Quadrangle_p->print();

    Quadrangle_r r(30, 30, 30, 30, 30, 150, 30, 150);
    Figure* par_Quadrangle_r = &r;
    par_Quadrangle_r->print();


    Quadrangle_par par(20, 30, 20, 30, 90, 90, 90, 90);
    Figure* par_Quadrangle_par = &par;
    par_Quadrangle_par->print();

    Quadrangle_kv kv(20, 20, 20, 20, 90, 90, 90, 90);
    Figure* par_Quadrangle_kv = &kv;
     par_Quadrangle_kv->print();

    std::cout << "Конец файла!\n";
  
    return 0;
}