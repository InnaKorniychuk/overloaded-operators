#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class Vector {
    double x ,y ;//��������� ����-����������
    double angle, length;//��������� ���� ��� �� �������
  
public:
    int tempx , tempy;
    bool res;//6 zavd
    Vector(int angle, int length) {
        //����� ���������
        this->angle = angle;
        this->length = length;
        x = cos(angle * (M_PI / 180)) * length;
        y = sin(angle * (M_PI / 180)) * length;   
    }
    

    Vector(const Vector &other) {//����������� ���������
        this->angle = other.angle;
        this->length = other.length;
        x = cos(other.angle * (M_PI / 180)) * other.length;
        y = sin(other.angle * (M_PI / 180)) * other.length;
        //cout << "���������� ����� 2:(" << x << " ; " << y << ")" << endl << endl;
    }

    Vector(double length, double change) {//��������� ������� �� ���� ��������
        this->length = length - change;
       
    }

    double GetLength() {
        return this->length;
    }
  
    Vector() {
        x = 0;
        y = 0;
    }
    Vector operator + ( Vector& another) {//����������� ��������� �������
        Vector temp;
        temp.x =this->x+ another.x;
        temp.y = another.y+ this->y;
        cout << "���� ���������: (" << temp.GetX() << " ; " << temp.GetY() << " )" << endl;
        return temp;
    }

   

    bool operator > (const Vector &other) {//������� ���� ��������

        return this->length > other.length;
    }

    //Vector& operator --(int value) {
    //    Vector temp(*this);// �����'������� �������� ���� ��'����
    //    this->x--;
    //    this->y--;
    //    //cout <<"("<< this->x << " ; " << this->y <<" )"<< endl;
    //    return temp;
    //}
    void operator --(int) {//�������� ���������� �� 1
        this->x--;
        this->y--;
    }
    

    bool operator ! () {//���������� �� ���� �� ��������� 0
        
        this->res = (angle == 0 && length == 0);//false
        return res;
    }
    double GetX() {//��������� �
        return x;
    }
    double GetY() {//��������� �
        return y;
    }


};




