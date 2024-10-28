#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


class Product {
private:
    std::string name; //�����
    int productID; //ID
    double price; //����
    int quantity; //�������
    std::string category; //��������
    std::string brand; //�����
    int rating; //�������
    bool availability; //����������
    static int productCount; // �������� ���� ��� ��������� ������� ��������

public:
    // ����������� ��� ���������
    Product()
        : name(""), productID(0), price(0.0), quantity(0),
        category(""), brand(""), rating(0), availability(true) {}

    // ����������� � �����������
    Product(std::string n, int id, double p, int q, std::string c,
        std::string b, int r, bool a)
        : name(n), productID(id), price(p), quantity(q),
        category(c), brand(b), rating(r), availability(a) {}

    // ����������� ���������
    Product(const Product& other)
        : name(other.name), productID(other.productID),
        price(other.price), quantity(other.quantity),
        category(other.category), brand(other.brand),
        rating(other.rating), availability(other.availability) {}

    // ����������
    ~Product() {
        std::cout << "Product destroyed: " << name << std::endl;
    }



    //���,���
    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }

    void setProductID(int id) { productID = id; }
    int getProductID() const { return productID; }

    void setPrice(double p) { price = p; }
    double getPrice() const { return price; }

    void setQuantity(int q) { quantity = q; }
    int getQuantity() const { return quantity; }

    void setCategory(std::string c) { category = c; }
    std::string getCategory() const { return category; }

    void setBrand(std::string b) { brand = b; }
    std::string getBrand() const { return brand; }

    void setRating(int r) { rating = r; }
    int getRating() const { return rating; }

    void setAvailability(bool a) { availability = a; }
    bool isAvailable() const { return availability; }
    
};

#endif

