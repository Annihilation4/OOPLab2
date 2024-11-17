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
        //void Service(Client& client, const std::string& filename) {
        //    try {
        //        // Виклик методу Write для запису даних
        //        client.Write(filename);
        //        std::cout << "Data is successfully written to file: " << filename << std::endl;

        //        // Виклик методу Read для зчитування даних
        //        client.Read(filename);
        //        std::cout << "Data is successfully read from file: " << filename << std::endl;

        //        // Відображення зчитаної інформації
        //        client.displayInfo();
        //    }
        //    catch (const std::ios_base::failure& e) {
        //        std::cerr << "Error: " << e.what() << std::endl;
        //    }
        //    catch (const std::runtime_error& e) {
        //        std::cerr << "Error: " << e.what() << std::endl;
        //    }
        //    catch (const std::exception& e) {
        //        std::cerr << "Error: " << e.what() << std::endl;
        //    }
        //}

        //// Функція для відображення меню
        //void displayMenu() {
        //    std::cout << "\n=== Menu ===\n";
        //    std::cout << "1. Create a new Client object\n";
        //    std::cout << "2. Delete a Client object\n";
        //    std::cout << "3. Display information about clients\n";
        //    std::cout << "4. Save client data to file\n";
        //    std::cout << "5. Load client data from file\n";
        //    std::cout << "0. Exit\n";
        //    std::cout << "Your choice: ";
        //}

        //// Функція для створення нового об'єкта Client
        //void createClient(std::vector<std::unique_ptr<Client>>& clients) {
        //    std::string name, email, phone, address, membershipType;
        //    int clientID;
        //    float totalSpent;

        //    std::cout << "Enter client name: ";
        //    std::cin >> name;
        //    std::cout << "Enter client ID: ";
        //    std::cin >> clientID;
        //    std::cout << "Enter client email: ";
        //    std::cin >> email;
        //    std::cout << "Enter client phone: ";
        //    std::cin >> phone;
        //    std::cout << "Enter client address: ";
        //    std::cin >> address;
        //    std::cout << "Enter client membership type: ";
        //    std::cin >> membershipType;
        //    std::cout << "Enter total amount spent by client: ";
        //    std::cin >> totalSpent;

        //    clients.push_back(std::make_unique<Client>(name, clientID, email, phone, address, PaymentMethod(), membershipType, totalSpent));
        //    std::cout << "Client created successfully.\n";
        //}

        //// Функція для видалення об'єкта Client за індексом
        //void deleteClient(std::vector<std::unique_ptr<Client>>& clients) {
        //    int index;
        //    std::cout << "Enter the index of the client to delete: ";
        //    std::cin >> index;

        //    if (index < 0 || index >= clients.size()) {
        //        std::cerr << "Invalid index.\n";
        //        return;
        //    }

        //    clients.erase(clients.begin() + index);
        //    std::cout << "Client deleted successfully.\n";
        //}

        //// Функція для показу інформації про всіх клієнтів
        //void showClients(const std::vector<std::unique_ptr<Client>>& clients) {
        //    if (clients.empty()) {
        //        std::cout << "No clients to display.\n";
        //        return;
        //    }

        //    for (size_t i = 0; i < clients.size(); ++i) {
        //        std::cout << "Client " << i << ": ";
        //        clients[i]->displayInfo();
        //    }
        //}
        //void demonstratePolymorphism(Person* person) {
        //    // Викликає displayInfo() залежно від типу об'єкта
        //    person->displayInfo();  // Пізнє зв'язування (динамічне)
        //}
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        //1)
        Product p("Laptop", 101, 1500.0, 10, "Electronics", "BrandX", 5, true);

        std::cout << "Before operations:\n";
        p.display();

        ++p; // Префіксна форма ++
        std::cout << "\nAfter ++ (prefix):\n";
        p.display();

        p++; // Постфіксна форма ++
        std::cout << "\nAfter ++ (postfix):\n";
        p.display();

        --p; // Префіксна форма --
        std::cout << "\nAfter -- (prefix):\n";
        p.display();

        p--; // Постфіксна форма --
        std::cout << "\nAfter -- (postfix):\n";
        p.display();
        //2)
        PaymentMethod paymentMethod = PaymentMethod::CARD(); 

        // Два замовлення одного продукту
        Order order1(1, p, 2, paymentMethod, true, "123 Main St", "Shipped");
        Order order2(2, p, 2, paymentMethod, true, "123 Main St", "Shipped");

        // Вивід початкових даних
        std::cout << "Initial Orders:\n";
        order1.display();
        order2.display();

        // Об'єднання замовлень
        Order combinedOrder = order1 + order2;
        std::cout << "\nCombined Order:\n";
        combinedOrder.display();

        // Вирахування кількості товару
        Order reducedOrder = order1 - order2;
        std::cout << "\nReduced Order:\n";
        reducedOrder.display();
        //3)
        Cart cart;
        cart += Product("Laptop123", 101, 1500.0, 10, "Electronics", "BrandX", 5, true);
        cart *= 0.9; // Знижка 10%
        Product p1 = cart[0];
        float totalCost = cart * cart; // Загальна вартість
        std::cout << "Total cost: " << totalCost << std::endl;
        //4)
        Warehouse warehouse;

        // Додавання продуктів
        warehouse.addProduct(Product("Laptop2", 1, 1500.99, 10, "Electronics", "Dell", 5, true));
        warehouse.addProduct(Product("Phone", 2, 799.49, 20, "Electronics", "Samsung", 4, true));
        warehouse.addProduct(Product("Tablet", 3, 499.99, 15, "Electronics", "Apple", 5, true));

        // Виведення продуктів
        warehouse.displayProducts();

        // Пошук мінімальної та максимальної ціни
        try {
            double maxPrice = warehouse.findExtrema<double>(true);
            double minPrice = warehouse.findExtrema<double>(false);

            std::cout << "Max price: " << maxPrice << std::endl;
            std::cout << "Min price: " << minPrice << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        //5)
        Statistics<double, double, int, double, double> stats(10.5, 10.0, 5, 2.3, 1.5);
        stats.display();
        //6)
        // Порівняння двох товарів за ціною
        Product moreExpensive = comparePrice(p, p1);

        // Виведення результату
        std::cout << "More expensive product:" << std::endl;
        moreExpensive.display();

        return;
    }
    };
}

