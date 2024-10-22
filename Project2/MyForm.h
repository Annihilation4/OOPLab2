#pragma once
#include "Product.h"
#include "Client.h"
#include "Order.h"
#include "Cart.h"
#include "Warehouse.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

namespace Project {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->SuspendLayout();
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(538, 400);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);

        }
        void displayProductDetails(Product* product) {
            if (product) {
                cout << "Product Name: " << product->getName() << endl;
            }
        }
        // Функція поза межами класу
        void displayOrderDetailsL2(const Order& order) {
            std::cout << "Order ID: " << order.getOrderID() << std::endl;
            std::cout << "Product: " << order.getProduct().getName() << std::endl;
            std::cout << "Quantity: " << order.getQuantity() << std::endl;
            std::cout << "Total Price: " << order.getTotalPrice() << std::endl;
        }
        // Функція, яка приймає адресу об'єкта класу Order
        void displayOrderDetailsL2(const Order* order) {
            if (order != nullptr) {
                std::cout << "Order ID: " << order->getOrderID() << std::endl;
                std::cout << "Product: " << order->getProduct().getName() << std::endl;
                std::cout << "Quantity: " << order->getQuantity() << std::endl;
                std::cout << "Total Price: " << order->getTotalPrice() << std::endl;
            }
            else {
                std::cout << "Invalid order reference!" << std::endl;
            }
        }

        // Функція поза межами класу
        void calculateTotalCost(const Product& product) {
            double totalCost = product.getPrice() * product.getQuantity();
            std::cout << "Product: " << product.getName() << std::endl;
            std::cout << "Quantity: " << product.getQuantity() << std::endl;
            std::cout << "Total cost: " << totalCost << std::endl;
        }
        // Функція, яка приймає адресу об'єкта класу Product
        void calculateTotalCost(const Product* product) {
            if (product != nullptr) {
                double totalCost = product->getPrice() * product->getQuantity();
                std::cout << "Product: " << product->getName() << std::endl;
                std::cout << "Quantity: " << product->getQuantity() << std::endl;
                std::cout << "Total cost: " << totalCost << std::endl;
            }
            else {
                std::cout << "Invalid product reference!" << std::endl;
            }
        }

        Product createProductWithDiscount(const Product& original, double discountPercent, int additionalQuantity) {
            // Використовуємо метод класу для створення нового продукту
            return original.createDiscountedProduct(discountPercent, additionalQuantity);
        }

        void printOrderDetails(const Order& order, const Client& client) {
            std::cout << "Order ID: " << order.getOrderID() << std::endl;
            std::cout << "Client: " << client.getName() << std::endl;
            std::cout << "Product: " << order.getProduct().getName() << std::endl;
            std::cout << "Quantity: " << order.getQuantity() << std::endl;
            std::cout << "Total Price: " << order.getTotalPrice() << std::endl;
        }

#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

        // Статичні об'єкти Product
        Product p1("Laptop", 101, 1500.99, 10, "Electronics", "Dell", 5, true);
        Product p2("Phone", 102, 799.49, 25, "Electronics", "Apple", 4, true);
        Product p3("Tablet", 103, 299.99, 15, "Electronics", "Samsung", 4, true);
        Product p4("Headphones", 104, 99.99, 50, "Accessories", "Sony", 5, true);
        Product p5("Smartwatch", 105, 199.99, 30, "Wearables", "Garmin", 5, true);

        // Статичні об'єкти Order
        Order o1(201, p1, 2, "Credit Card", true, "123 Main St, City", "Processing");
        Order o2(202, p2, 1, "E-wallet", false, "456 Elm St, City", "Pending");
        Order o3(203, p3, 3, "Cash", false, "789 Oak St, City", "Shipped");
        Order o4(204, p4, 4, "Debit Card", true, "321 Pine St, City", "Delivered");
        Order o5(205, p5, 5, "Credit Card", true, "654 Cedar St, City", "Cancelled");

        // Динамічні об'єкти Product
        Product* dynamicProducts = new Product[5]{
            Product("Monitor", 106, 199.99, 20, "Electronics", "LG", 4, true),
            Product("Keyboard", 107, 49.99, 100, "Accessories", "Logitech", 5, true),
            Product("Mouse", 108, 29.99, 150, "Accessories", "Razer", 5, true),
            Product("Charger", 109, 19.99, 80, "Accessories", "Anker", 5, true),
            Product("Webcam", 110, 79.99, 60, "Accessories", "Logitech", 5, true)
        };

        // Динамічні об'єкти Order
        Order* dynamicOrders = new Order[5]{
            Order(206, dynamicProducts[0], 2, "Credit Card", true, "123 Main St, City", "Processing"),
            Order(207, dynamicProducts[1], 3, "Cash", false, "456 Elm St, City", "Pending"),
            Order(208, dynamicProducts[2], 4, "E-wallet", true, "789 Oak St, City", "Shipped"),
            Order(209, dynamicProducts[3], 1, "Debit Card", true, "321 Pine St, City", "Delivered"),
            Order(210, dynamicProducts[4], 5, "Credit Card", false, "654 Cedar St, City", "Cancelled")
        };

        cout << "~Product methods demo:\n";

        // Виведення початкових даних продукту
        cout << "\nInitial Product p1:\n";
        cout << "Name: " << p1.getName() << ", Price: " << p1.getPrice() << ", Quantity: " << p1.getQuantity() << endl;

        // Вивід даних із перевантаженими функціями restock
        cout << "\nOverloaded function:\n";
        p1.restock(5);
        p1.restock(10, false);

        // Перевірка на дорожчий продукт
        cout << "\nIs p1 more expensive than p2? " << (p1.isMoreExpensiveThan(p2) ? "Yes" : "No") << endl;

        Product discountedProduct = p1.createDiscountedProduct(10);
        cout << "\nDiscounted Product Price: " << discountedProduct.getPrice() << endl;

        // Використання динамічного масиву
        cout << "\nProducts in dynamicProducts:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Name: " << dynamicProducts[i].getName() << ", Price: " << dynamicProducts[i].getPrice() << endl;
        }

        cout << "\n~Order methods demo:\n";

        // Виведення початкових даних замовлення
        cout << "\nInitial Order o1:\n";
        cout << "Order ID: " << o1.getOrderID() << ", Total Price: " << o1.getTotalPrice() << endl;

        // Оновлення замовлення
        o1.updateOrder(o1, 2);
        cout << "\nUpdated Order Quantity: " << o1.getQuantity() << endl;

        // Оплата замовлення
        o1.makePayment("Debit Card");
        cout << "\nPayment Method: " << o1.getPaymentMethod() << ", Is Paid: " << (o1.getIsPaid() ? "Yes" : "No") << endl;

        // Збереження та завантаження з файлу
        p1.saveToFile("product.txt");
        o1.saveToFile("order.txt");
        cout << "\nData saved to files.\n";

        // Виведення інформації про динамічні замовлення
        cout << "\nDynamic Orders:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Order ID: " << dynamicOrders[i].getOrderID() << ", Product: " << dynamicOrders[i].getProduct().getName() << endl;
        }

        cout << "\n~Between products demo:\n";

        cout << "\nInitial quantity of " << p1.getName() << ": " << p1.getQuantity() << endl;
        cout << "Initial quantity of " << p2.getName() << ": " << p2.getQuantity() << endl;

        // Замовлення товару
        cout << "\nProcessing order o1 for product p1\n";
        if (o1.getQuantity() <= p1.getQuantity()) {
            // Оновлення кількості товару
            p1.restock(-o1.getQuantity()); // Витрачаємо кількість товару
            o1.makePayment("Credit Card");  // Обробка платежу
            cout << "Order o1 processed. Payment successful!\n";
        }
        else {
            cout << "Not enough stock for " << p1.getName() << "!\n";
        }

        cout << "\nProcessing order o2 for product p2\n";
        if (o2.getQuantity() <= p2.getQuantity()) {
            p2.restock(-o2.getQuantity()); // Витрачаємо кількість товару
            o2.makePayment("Cash");         // Обробка платежу
            cout << "Order o2 processed. Payment successful!\n";
        }
        else {
            cout << "Not enough stock for " << p2.getName() << "!\n";
        }

        // Виведення оновлених кількостей
        cout << "\nUpdated quantities:\n";
        cout << p1.getName() << ": " << p1.getQuantity() << ", " << p2.getName() << ": " << p2.getQuantity() << endl;

        // Використання покажчика на екземпляр класу
        cout << "\nUsing pointer:\n";
        Product* ptrProduct = &p1;
        displayProductDetails(ptrProduct);



        // Виклик функцій з уже існуючими продуктами та замовленнями
        std::cout << "Total products: " << Product::getProductCount() << std::endl;
        std::cout << "Total orders: " << Order::getOrderCount() << std::endl;

        displayOrderDetailsL2(o3); // виклик функції
        calculateTotalCost(p3);

        displayOrderDetailsL2(&o3); // виклик функції
        calculateTotalCost(&p3);

        // За допомогою зовнішньої функції
        Product anotherDiscountedProduct = createProductWithDiscount(p3, 15.0, 3);

        // Виводимо інформацію про нові продукти 
        discountedProduct.saveToFile("products.txt");
        anotherDiscountedProduct.saveToFile("products.txt");

        // 1. Простий спосіб створення об'єкта (без параметрів)
        Product product1; // Викликається конструктор без параметрів
        product1.display(); // Виведе значення за замовчуванням

        // 2. Явний спосіб створення об'єкта (з параметрами)
        Product product2("Laptop", 101, 1500.99, 10, "Electronics", "Dell", 5, true); // Викликається конструктор з параметрами
        product2.display(); // Виведе введені значення

        // 3. Скорочений спосіб (використання конструктора копіювання)
        Product product3(product2); // Викликається конструктор копіювання
        product3.display(); // Виведе значення, аналогічні product2

        std::cout << "Creation Products with constr:" << std::endl;

        // 1. Використання конструктора без параметрів
        Product defaultProduct; // Виклик конструктора без параметрів
        defaultProduct.display(); // Виведення значень за замовчуванням

        // 2. Використання конструктора з параметрами
        Product parameterizedProduct("Laptop", 101, 1500.99, 10, "Electronics", "Dell", 5, true);
        parameterizedProduct.display(); // Виведення значень параметризованого продукту

        // 3. Використання конструктора копіювання
        Product copiedProduct(parameterizedProduct); // Виклик конструктора копіювання
        copiedProduct.display(); // Виведення значень скопійованого продукту

        // Продемонструвати сценарій взаємодії трьох об’єктів за допомогою класу асоціацій
        // Створення об'єктів
        Product productWithClient("Laptop", 1, 1000.0, 5, "Electronics", "BrandX", 5, true);
        Client client("John Doe");

        // Створення замовлення
        Order orderWithClient(1, p1, 2, "Credit Card", false, "123 Street", "Pending");

        // Виведення деталей замовлення
        printOrderDetails(orderWithClient, client);

        // Продемонструвати сценарій взаємодії двох об’єктів за композиції
        // Створення продуктів
        Product productComp1("Apple", 1, 0.5, 10, "Fruits", "BrandA", 5, true);
        Product productComp2("Banana", 2, 0.3, 15, "Fruits", "BrandB", 4, true);

        // Створення кошика
        Cart cart;

        // Додавання продуктів до кошика
        cart.addProduct(productComp1);
        cart.addProduct(productComp2);

        // Показати зміст кошика
        cart.showCartContents();

        // Створення об'єктів товарів
        Product productAgg1("Laptop", 1, 999.99, 10, "Electronics", "BrandA", 5, true);
        Product productAgg2("Smartphone", 2, 499.99, 20, "Electronics", "BrandB", 4, true);

        // Створення складу
        Warehouse warehouse;

        // Додавання товарів на склад
        warehouse.addProduct(productAgg1);
        warehouse.addProduct(productAgg2);

        // Відображення товарів на складі
        warehouse.displayProducts();

        delete[] dynamicProducts;
        delete[] dynamicOrders;

        return;
    }
    };
}

