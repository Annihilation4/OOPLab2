#ifndef GUEST_H
#define GUEST_H
#include "Person.h"
#include <iostream>
#include <fstream>

class Guest : virtual public Person { // ³�������� �����������
public:
    // ��������� �����������
    Guest() : Person() {
        // �������� ������������, ���� �������
    }
    // ����������� ����� Guest, ���� ������� ����������� ����� Person
    Guest(const std::string& name) : Person(name, email) {
        // �������� ������������, ���� �������
    }

};

#endif

