// 3.5-3.cpp :
//
#include <iostream>
#include <Windows.h>

//

class Figure {
public:
    std::string name;
    bool info_check=1;
    int number_sides;

    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;
    Figure() {
        name = "Фигура: ";
        info_check = 0;
        number_sides = 0;
        
    }

    virtual bool check() {
      /*  if(number_sides == 0) info_check = 0;*/
        return 0;
    }
       
    virtual void print() {
        //check();
        std::cout << name << "\n";
        info_check == 0 ? std::cout << "Правильная\n" : std::cout << "Неправильная\n";
        std::cout  <<"Количество сторон: " << number_sides << "\n\n";

    }


};


class Triangle : public Figure {
public:
    Triangle() {
        name = "Треугольник: ";
        info_check = 1;
        number_sides = 3;

        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 70;
    }

    bool check() override {
        //if (A + B + C == 180 && number_sides == 3)
        //    info_check = 0;
        //else
        //{
        //    info_check = 1;
        //}
        A + B + C == 180 && number_sides == 3 ? info_check =0  : info_check =1 ;
        return info_check;
    }


    void print()  override {
        check();
        std::cout << name << "\n";
        info_check == 0 ? std::cout << "Правильная\n" : std::cout << "Неправильная\n";
        std::cout << "Количество сторон: " << number_sides << "\n";
        std::cout << "Стороны: a = " << a << " b = " << b << " c = " << c ;
        std::cout << "\nУглы: A=" << A << " B=" << B << " C=" << C  <<"\n\n";
    };
};

class Triangle_p : public Triangle {
public:

    Triangle_p() {
        name = "Прямоугольный треугольник: ";
        C = 90;
        B = 180 - (A + C);
    }
    bool check() override {
        C == 90 ? info_check = 0 : info_check = 1;
        return info_check;
    }
};

class Triangle_rb : public Triangle {
public:

    Triangle_rb() {
        name = "Равнобедренный треугольник: ";
        a = c;
        A = C;
        B = 180 - C * 2;
    }
    bool check() override {
        a == c && A == C? info_check = 0 : info_check = 1;
        return info_check;
    }
};

class Triangle_rs : public Triangle {
public:

    Triangle_rs() {
        name = "Равносторонний треугольник: ";
        a = c;
        b = c;
        A = 60;
        B = A;
        C = A;
    }
    bool check() override {
        a == c && c== b && A == C && A==B ? info_check = 0 : info_check = 1;
        return info_check;
    }
};
class Quadrangle : public Figure {
public:
    Quadrangle() {
        name = "Четырёхугольник: ";
        number_sides = 4;
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 40;
        B = 30;
        C = 110;
        D = 12;//180
    }
    
    bool check() override {
        A + B + C + D == 360 ? info_check = 0 : info_check = 1;
        return info_check;
    }
    void print() {
        std::cout << name << "\n";
        info_check == 0 ? std::cout << "Правильная\n" : std::cout << "Неправильная\n";
        std::cout << "Количество сторон: " << number_sides << "\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};
class Quadrangle_p : public Quadrangle {
public:
    Quadrangle_p() {
        name = "Параллелограмм: ";
        a = c;
        b = d;
        //c = 30;
        //d = 40;
        //A = 40;
        //B = 30;
        C = A;
        D = B;
    }
    bool check() override {
        a == c && b == d && A == C && B + D ? info_check = 0 : info_check = 1;
        return info_check;
    }
};
class Quadrangle_r : public Quadrangle_p {
public:
    Quadrangle_r() {
        name = "Ромб: ";
        //a = c;
        b = a;
        d = a;
        //C = A;
        //D = B;
    }
    bool check() override {
        a == c && b == d && c == b && A == C && B == D ? info_check = 0 : info_check = 1;
        return info_check;
    }
};
class Quadrangle_par : public Quadrangle_p {
public:
    Quadrangle_par() {
        name = "Прямоугольник: ";
        A = B = C = D = 90;
    }
    bool check() override {
        a == c && b == d && A == 90 && B == 90 && D==90 && C==90 ? info_check = 0 : info_check = 1;
        return info_check;
    }
};
class Quadrangle_kv : public Quadrangle_par {
public:
    Quadrangle_kv() {
        name = "Квадрат: ";
        b = d = a = c ;
    }
    bool check() override {
        a == c && b == d && c == b && A == C && B == D ? info_check = 0 : info_check = 1;
        return info_check;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Figure f;
    f.print();

    Triangle t;
    //t.print();
    Figure* par_Triangle = &t;
     par_Triangle->check();
     par_Triangle ->print();
   
    Triangle_p tp;
    //tp.print();
    Figure* par_Triangle_p = &tp;
    par_Triangle_p->check();
    par_Triangle_p->print();

    Triangle_rb rb;
    //rb.print();
    Figure* par_Triangle_rb = &rb;
    par_Triangle_rb->check();
    par_Triangle_rb->print();

    Triangle_rs rs;
    rs.check();
    rs.print();
    //Figure* par_Triangle_rs = &rs;
    //par_Triangle_rs->check();
    //par_Triangle_rs->print();


    Quadrangle q;
    //q.check();
    //q.print();
    Figure* par_Quadrangle = &q;
    par_Quadrangle->check();
    par_Quadrangle->print();

    Quadrangle_p p;
    //p.check();
    //p.print();
    Figure* par_Quadrangle_p = &p;
    par_Quadrangle_p->check();
    par_Quadrangle_p->print();

    Quadrangle_r r;
    r.check();
    r.print();

    Quadrangle_par par;
    par.check();
    par.print();

    Quadrangle_kv kv;
    kv.check();
    kv.print();
    //Figure* par_Quadrangle_kv = &kv;
    //par_Quadrangle_kv->check();
    //par_Quadrangle_kv->print();

    std::cout << "Конец файла!\n";
  
    return 0;
}