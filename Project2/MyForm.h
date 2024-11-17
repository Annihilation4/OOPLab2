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
        //        // ������ ������ Write ��� ������ �����
        //        client.Write(filename);
        //        std::cout << "Data is successfully written to file: " << filename << std::endl;

        //        // ������ ������ Read ��� ���������� �����
        //        client.Read(filename);
        //        std::cout << "Data is successfully read from file: " << filename << std::endl;

        //        // ³���������� ������� ����������
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

        //// ������� ��� ����������� ����
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

        //// ������� ��� ��������� ������ ��'���� Client
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

        //// ������� ��� ��������� ��'���� Client �� ��������
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

        //// ������� ��� ������ ���������� ��� ��� �볺���
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
        //    // ������� displayInfo() ������� �� ���� ��'����
        //    person->displayInfo();  // ϳ�� ��'�������� (��������)
        //}
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        //1)
        Product p("Laptop", 101, 1500.0, 10, "Electronics", "BrandX", 5, true);

        std::cout << "Before operations:\n";
        p.display();

        ++p; // ��������� ����� ++
        std::cout << "\nAfter ++ (prefix):\n";
        p.display();

        p++; // ���������� ����� ++
        std::cout << "\nAfter ++ (postfix):\n";
        p.display();

        --p; // ��������� ����� --
        std::cout << "\nAfter -- (prefix):\n";
        p.display();

        p--; // ���������� ����� --
        std::cout << "\nAfter -- (postfix):\n";
        p.display();
        //2)
        PaymentMethod paymentMethod = PaymentMethod::CARD(); 

        // ��� ���������� ������ ��������
        Order order1(1, p, 2, paymentMethod, true, "123 Main St", "Shipped");
        Order order2(2, p, 2, paymentMethod, true, "123 Main St", "Shipped");

        // ���� ���������� �����
        std::cout << "Initial Orders:\n";
        order1.display();
        order2.display();

        // ��'������� ���������
        Order combinedOrder = order1 + order2;
        std::cout << "\nCombined Order:\n";
        combinedOrder.display();

        // ����������� ������� ������
        Order reducedOrder = order1 - order2;
        std::cout << "\nReduced Order:\n";
        reducedOrder.display();
        //3)
        Cart cart;
        cart += Product("Laptop123", 101, 1500.0, 10, "Electronics", "BrandX", 5, true);
        cart *= 0.9; // ������ 10%
        Product p1 = cart[0];
        float totalCost = cart * cart; // �������� �������
        std::cout << "Total cost: " << totalCost << std::endl;
        //4)
        Warehouse warehouse;

        // ��������� ��������
        warehouse.addProduct(Product("Laptop2", 1, 1500.99, 10, "Electronics", "Dell", 5, true));
        warehouse.addProduct(Product("Phone", 2, 799.49, 20, "Electronics", "Samsung", 4, true));
        warehouse.addProduct(Product("Tablet", 3, 499.99, 15, "Electronics", "Apple", 5, true));

        // ��������� ��������
        warehouse.displayProducts();

        // ����� �������� �� ����������� ����
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
        // ��������� ���� ������ �� �����
        Product moreExpensive = comparePrice(p, p1);

        // ��������� ����������
        std::cout << "More expensive product:" << std::endl;
        moreExpensive.display();

        return;
    }
    };
}

