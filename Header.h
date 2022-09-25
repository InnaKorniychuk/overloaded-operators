#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class Vector {
    double x ,y ;//створюємо змінні-координати
    double angle, length;//створюємо змінні кут та довжину
  
public:
    int tempx , tempy;
    bool res;//6 zavd
    Vector(int angle, int length) {
        //пошук координат
        this->angle = angle;
        this->length = length;
        x = cos(angle * (M_PI / 180)) * length;
        y = sin(angle * (M_PI / 180)) * length;   
    }
    

    Vector(const Vector &other) {//конструктор копіювання
        this->angle = other.angle;
        this->length = other.length;
        x = cos(other.angle * (M_PI / 180)) * other.length;
        y = sin(other.angle * (M_PI / 180)) * other.length;
        //cout << "Координати точки 2:(" << x << " ; " << y << ")" << endl << endl;
    }

    Vector(double length, double change) {//зменшення довжини на дабл значення
        this->length = length - change;
       
    }

    double GetLength() {
        return this->length;
    }
  
    Vector() {
        x = 0;
        y = 0;
    }
    Vector operator + ( Vector& another) {//математичне додавання векторів
        Vector temp;
        temp.x =this->x+ another.x;
        temp.y = another.y+ this->y;
        cout << "Сума координат: (" << temp.GetX() << " ; " << temp.GetY() << " )" << endl;
        return temp;
    }

   

    bool operator > (const Vector &other) {//порівння двох елементів

        return this->length > other.length;
    }

    //Vector& operator --(int value) {
    //    Vector temp(*this);// запам'ятовуємо тепершній стан об'єкту
    //    this->x--;
    //    this->y--;
    //    //cout <<"("<< this->x << " ; " << this->y <<" )"<< endl;
    //    return temp;
    //}
    void operator --(int) {//зменшуємо координати на 1
        this->x--;
        this->y--;
    }
    

    bool operator ! () {//перевіряємо чи поля не дорівнюють 0
        
        this->res = (angle == 0 && length == 0);//false
        return res;
    }
    double GetX() {//повертаємо х
        return x;
    }
    double GetY() {//повертаємо у
        return y;
    }


};




