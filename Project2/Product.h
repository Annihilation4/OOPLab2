#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


class Product {
private:
    std::string name; //назва
    int productID; //ID
    double price; //ціна
    int quantity; //кількість
    std::string category; //категорія
    std::string brand; //бренд
    int rating; //рейтинг
    bool availability; //доступність
    static int productCount; // Статичне поле для підрахунку кількості продуктів

public:
    Product(std::string name, int id, double price) : name(name), productID(id), price(price) {}

    Product(std::string name, int id) : name(name), productID(id) {}
    // конструктор без параметрів
    Product()
        : name(""), productID(0), price(0.0), quantity(0),
        category(""), brand(""), rating(0), availability(true) {}

    // конструктор з параметрами
    Product(std::string n, int id, double p, int q, std::string c,
        std::string b, int r, bool a)
        : name(n), productID(id), price(p), quantity(q),
        category(c), brand(b), rating(r), availability(a) {}

    // конструктор копіювання
    Product(const Product& other)
        : name(other.name), productID(other.productID),
        price(other.price), quantity(other.quantity),
        category(other.category), brand(other.brand),
        rating(other.rating), availability(other.availability) {}

    // Деструктор
    ~Product() {
        /*std::cout << "Product destroyed: " << name << std::endl;*/
    }

    //гет,сет
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
    
    bool operator<(const Product& other) const {
        return productID < other.productID;  // Порівняння за ID
    }
    void display() const {
        std::cout << "Product: " << name << ", Price: " << price << std::endl;
    }
    //3)
    // Алгоритм 1: Сортування продуктів за ціною
    static void sortByPrice(std::vector<Product>& products) {
        std::sort(products.begin(), products.end(), compareByPrice);
    }

    static bool compareByPrice(const Product& a, const Product& b) {
        return a.getPrice() < b.getPrice();
    }

    // Алгоритм 2: Пошук продукту за ID
    static Product* findProductByID(std::vector<Product>& products, int id) {
        for (size_t i = 0; i < products.size(); i++) {
            if (products[i].getProductID() == id) {
                return &products[i];
            }
        }
        return nullptr;
    }

    // Алгоритм 3: Фільтрація продуктів за категорією
    static std::vector<Product> filterByCategory(const std::vector<Product>& products, const std::string& category) {
        std::vector<Product> filteredProducts;
        for (size_t i = 0; i < products.size(); i++) {
            if (products[i].getCategory() == category) {
                filteredProducts.push_back(products[i]);
            }
        }
        return filteredProducts;
    }

    // Алгоритм 4: Оновлення кількості продукту
    static bool updateProductQuantity(std::vector<Product>& products, int productID, int newQuantity) {
        for (size_t i = 0; i < products.size(); i++) {
            if (products[i].getProductID() == productID) {
                products[i].setQuantity(newQuantity);
                return true;
            }
        }
        return false;
    }

    // Алгоритм 5: Підрахунок середньої ціни продуктів
    static double calculateAveragePrice(const std::vector<Product>& products) {
        double totalPrice = 0;
        for (size_t i = 0; i < products.size(); i++) {
            totalPrice += products[i].getPrice();
        }
        if (products.size() > 0) {
            return totalPrice / products.size();
        }
        return 0;
    }
    //4)
    //Функтори
    class Plus {
    public:
        Product operator()(const Product& lhs, const Product& rhs) const {
            return Product(lhs.name, lhs.productID, lhs.price + rhs.price, lhs.quantity + rhs.quantity, lhs.category, lhs.brand, lhs.rating, lhs.availability);
        }
    };

    class Minus {
    public:
        Product operator()(const Product& lhs, const Product& rhs) const {
            return Product(lhs.name, lhs.productID, lhs.price - rhs.price, lhs.quantity - rhs.quantity, lhs.category, lhs.brand, lhs.rating, lhs.availability);
        }
    };

    class Times {
    public:
        Product operator()(const Product& lhs, int factor) const {
            return Product(lhs.name, lhs.productID, lhs.price * factor, lhs.quantity * factor, lhs.category, lhs.brand, lhs.rating, lhs.availability);
        }
    };

    class Divides {
    public:
        Product operator()(const Product& lhs, int divisor) const {
            if (divisor == 0) {
                throw std::invalid_argument("Division by zero!");
            }
            return Product(lhs.name, lhs.productID, lhs.price / divisor, lhs.quantity / divisor, lhs.category, lhs.brand, lhs.rating, lhs.availability);
        }
    };

    class Modulus {
    public:
        Product operator()(const Product& lhs, int divisor) const {
            if (divisor == 0) {
                throw std::invalid_argument("Modulo by zero!");
            }
            return Product(lhs.name, lhs.productID, lhs.price, lhs.quantity % divisor, lhs.category, lhs.brand, lhs.rating, lhs.availability);
        }
    };

    class Negate {
    public:
        Product operator()(const Product& lhs) const {
            return Product(lhs.name, lhs.productID, -lhs.price, -lhs.quantity, lhs.category, lhs.brand, lhs.rating, lhs.availability);
        }
    };
    class EqualTo {
    public:
        bool operator()(const Product& lhs, const Product& rhs) const {
            return lhs.productID == rhs.productID;
        }
    };

    class NotEqualTo {
    public:
        bool operator()(const Product& lhs, const Product& rhs) const {
            return lhs.productID != rhs.productID;
        }
    };

    class Greater {
    public:
        bool operator()(const Product& lhs, const Product& rhs) const {
            return lhs.price > rhs.price;
        }
    };

    class Less {
    public:
        bool operator()(const Product& lhs, const Product& rhs) const {
            return lhs.price < rhs.price;
        }
    };

    class GreaterEqual {
    public:
        bool operator()(const Product& lhs, const Product& rhs) const {
            return lhs.price >= rhs.price;
        }
    };

    class LessEqual {
    public:
        bool operator()(const Product& lhs, const Product& rhs) const {
            return lhs.price <= rhs.price;
        }
    };
    class LogicalAnd {
    public:
        bool operator()(const Product& lhs, const Product& rhs) const {
            return lhs.availability && rhs.availability;
        }
    };

    class LogicalOr {
    public:
        bool operator()(const Product& lhs, const Product& rhs) const {
            return lhs.availability || rhs.availability;
        }
    };

    class LogicalNot {
    public:
        bool operator()(const Product& lhs) const {
            return !lhs.availability;
        }
    };
};

#endif

