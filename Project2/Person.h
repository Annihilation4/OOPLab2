#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    std::string email;

public:
    Person() : name(""), email("") {}
    Person(const std::string& name, const std::string& email) : name(name), email(email) {}

    // ³�������� ������� ��� ��������� ����������
    virtual void displayInfo() const = 0;  // ����� ��������� �������, �� �� ���� ���������� � �������� ������

    virtual ~Person() {}  // ³��������� ����������
};

#endif

