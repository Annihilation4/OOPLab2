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
#include "ClientOrder.h"
#include "CartOrder.h"
#include "OrderHistory.h"
#include "Administrator.h"
#include "Guest.h"
#include "Statistics.h"
#include "Comparison.h"
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
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
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        //1)
        //1.1 vector
        std::vector<Product> products1;

        products1.push_back(Product("Product1", 1));
        products1.push_back(Product("Product2", 2));

        // Додавання елемента на початок
        products1.insert(products1.begin(), Product("Product0", 0));

        for (const auto& product : products1) {
            std::cout << "Product Name: " << product.getName()
                << ", ID: " << product.getProductID() << std::endl;
        }

        //1.2 list
        std::list<Product> products2;

        // Додавання елементів
        products2.push_back(Product("Product1", 1));
        products2.push_front(Product("Product0", 0));

        // Перебір елементів
        for (const auto& product : products2) {
            std::cout << "Product Name: " << product.getName() << ", ID: " << product.getProductID() << std::endl;
        }

        // Видалення елементу
        products2.pop_front();  // Видалення першого елемента

        std::cout << "After pop_front, size: " << products2.size() << std::endl;

        //1.3 deque
        std::deque<Product> products3;

        // Додавання елементів на початок і кінець
        products3.push_back(Product("Product1", 1));
        products3.push_front(Product("Product0", 0));

        // Перебір елементів
        for (const auto& product : products3) {
            std::cout << "Product Name: " << product.getName() << ", ID: " << product.getProductID() << std::endl;
        }

        // Видалення елемента з кінця та початку
        products3.pop_back();
        products3.pop_front();

        std::cout << "After pop operations, size: " << products3.size() << std::endl;

        //1.4 set
        std::set<Product> products4;

        // Додавання елементів
        products4.insert(Product("Product1", 1));
        products4.insert(Product("Product2", 2));

        // Перебір елементів
        for (const auto& product : products4) {
            std::cout << "Product Name: " << product.getName() << ", ID: " << product.getProductID() << std::endl;
        }

        //1.5 multiset
        std::multiset<Product> products5;

        // Додавання елементів
        products5.insert(Product("Product1", 1));
        products5.insert(Product("Product1", 1));

        // Перебір елементів
        for (const auto& product : products5) {
            std::cout << "Product Name: " << product.getName() << ", ID: " << product.getProductID() << std::endl;
        }

        //1.6 map
        std::map<int, Product> products6;

        // Додавання елементів
        products6[1] = Product("Product1", 1);
        products6[2] = Product("Product2", 2);

        // Доступ за ключем
        std::cout << "Product with ID 1: " << products6[1].getName() << std::endl;

        // Перебір елементів
        for (const auto& pair : products6) {
            std::cout << "Product ID: " << pair.first << ", Name: " << pair.second.getName() << std::endl;
        }

        //1.7 multimap
        std::multimap<int, Product> products7;

        // Додавання елементів з однаковим ключем
        products7.insert({ 1, Product("Product1", 1) });
        products7.insert({ 1, Product("Product2", 2) });

        // Перебір елементів
        for (const auto& pair : products7) {
            std::cout << "Product ID: " << pair.first << ", Name: " << pair.second.getName() << std::endl;
        }

        //1.8 stack
        std::stack<Product> productStack;

        // Додавання елементів
        productStack.push(Product("Product1", 1));
        productStack.push(Product("Product2", 2));

        // Виймання елементів
        while (!productStack.empty()) {
            Product p = productStack.top();
            std::cout << "Product Name: " << p.getName() << ", ID: " << p.getProductID() << std::endl;
            productStack.pop();
        }

        //1.9 queue
        std::queue<Product> productQueue1;

        // Додавання елементів
        productQueue1.push(Product("Product1", 1));
        productQueue1.push(Product("Product2", 2));

        // Виймання елементів
        while (!productQueue1.empty()) {
            Product p = productQueue1.front();
            std::cout << "Product Name: " << p.getName() << ", ID: " << p.getProductID() << std::endl;
            productQueue1.pop();
        }

        //1.10 priority queue
        std::priority_queue<Product> productQueue2;
        
        // Додавання елементів
        productQueue2.push(Product("Product1", 1));
        productQueue2.push(Product("Product3", 3));
        productQueue2.push(Product("Product2", 2));

        // Виймання елементів за пріоритетом
        while (!productQueue2.empty()) {
            Product p = productQueue2.top();
            std::cout << "Product Name: " << p.getName()
                << ", ID: " << p.getProductID() << std::endl;
            productQueue2.pop();
        }
        //2)
        // 1. Використовуємо input iterator для перебору
        std::vector<Product>::iterator it1 = products1.begin();
        while (it1 != products1.end()) {
            it1->display();  // Доступ лише для читання
            ++it1;
        }

        // 2. Використовуємо output iterator для змінення цін
        std::vector<Product>::iterator it2 = products1.begin();
        while (it2 != products1.end()) {
            it2->setPrice(it2->getPrice() * 1.1);  // Збільшуємо ціну на 10%
            ++it2;
        }

        // 3. Виведемо нові ціни
        for (const auto& product : products1) {
            product.display();
        }

        // 4. Використовуємо forward iterator для перебору (для list)
        std::list<Product> products = {
            Product("Apple", 1.2),
            Product("Nokia", 0.8),
            Product("Xiaomi", 1.5)
        };

        std::list<Product>::iterator it3 = products2.begin();
        while (it3 != products2.end()) {
            it3->display();  // Доступ лише для читання
            ++it3;  // Рухаємося вперед
        }

        // 5. Використовуємо bidirectional iterator для перебору вперед
        std::list<Product>::iterator it4 = products2.begin();
        while (it4 != products2.end()) {
            it4->display();  // Доступ лише для читання
            ++it4;
        }

        std::cout << "\nReverse enumeration:\n";

        // 6. Перебір назад (bidirectional iterator)
        --it4;  // Повертаємося до останнього елементу
        while (it4 != products2.begin()) {
            it4->display();  // Доступ лише для читання
            --it4;
        }
        it4->display();  // Виводимо перший елемент

        // 7. Використовуємо random access iterator для доступу до елементів за індексом (для vector)
        std::vector<Product>::iterator it5 = products1.begin();
        std::cout << "First product: ";
        it5->display();  // Перший продукт

        it5 += 2;  // Переміщаємося на два елементи вперед
        std::cout << "Third product: ";
        it5->display();  // Третій продукт

        // 8. Можна також доступати елементи як масив
        std::cout << "Product on the position 1: ";
        std::cout << products1[1].getPrice() << std::endl;
        //3)
        // Створення вектору продуктів
        std::vector<Product> products123 = {
            Product("Product1", 1, 10.0, 5, "Electronics", "Brand1", 4, true),
            Product("Product2", 2, 20.0, 2, "Furniture", "Brand2", 3, true),
            Product("Product3", 3, 15.0, 10, "Electronics", "Brand3", 5, false),
            Product("Product4", 4, 5.0, 8, "Toys", "Brand4", 2, true)
        };

        // Сортування продуктів за ціною
        Product::sortByPrice(products123);

        // Пошук продукту за ID
        Product* p = Product::findProductByID(products123, 2);
        if (p) {
            p->display();  // Виведення інформації про знайдений продукт
        }

        // Фільтрація за категорією
        std::vector<Product> electronics = Product::filterByCategory(products123, "Electronics");

        // Оновлення кількості
        Product::updateProductQuantity(products123, 1, 12);

        // Підрахунок середньої ціни
        double avgPrice = Product::calculateAveragePrice(products123);
        std::cout << "Average price: " << avgPrice << std::endl;
        //4)
        // Використання функторів
        Product product1("Product1", 1, 10.5, 5, "Category1", "Brand1", 4, true);
        Product product2("Product2", 2, 20.0, 3, "Category2", "Brand2", 5, false);

        Product::NotEqualTo notEqualToFunctor;
        bool isNotEqual = notEqualToFunctor(product1, product2);

        Product::Less lessFunctor;
        bool isLess = lessFunctor(product1, product2);

        Product::Plus plusFunctor;
        Product resultPlus = plusFunctor(product1, product2);

        Product::Minus minusFunctor;
        Product resultMinus = minusFunctor(product1, product2);

        Product::Times timesFunctor;
        Product resultTimes = timesFunctor(product1, 2);

        Product::Divides dividesFunctor;
        Product resultDivides = dividesFunctor(product1, 2);

        Product::Modulus modulusFunctor;
        Product resultModulus = modulusFunctor(product1, 2);

        Product::Negate negateFunctor;
        Product resultNegate = negateFunctor(product1);

        return;
    }
    };
}

