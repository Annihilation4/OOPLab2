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
        void Service(Client& client, const std::string& filename) {
            try {
                // Виклик методу Write для запису даних
                client.Write(filename);
                std::cout << "Data is successfully written to file: " << filename << std::endl;

                // Виклик методу Read для зчитування даних
                client.Read(filename);
                std::cout << "Data is successfully read from file: " << filename << std::endl;

                // Відображення зчитаної інформації
                client.displayInfo();
            }
            catch (const std::ios_base::failure& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        // Функція для відображення меню
        void displayMenu() {
            std::cout << "\n=== Menu ===\n";
            std::cout << "1. Create a new Client object\n";
            std::cout << "2. Delete a Client object\n";
            std::cout << "3. Display information about clients\n";
            std::cout << "4. Save client data to file\n";
            std::cout << "5. Load client data from file\n";
            std::cout << "0. Exit\n";
            std::cout << "Your choice: ";
        }

        // Функція для створення нового об'єкта Client
        void createClient(std::vector<std::unique_ptr<Client>>& clients) {
            std::string name, email, phone, address, membershipType;
            int clientID;
            float totalSpent;

            std::cout << "Enter client name: ";
            std::cin >> name;
            std::cout << "Enter client ID: ";
            std::cin >> clientID;
            std::cout << "Enter client email: ";
            std::cin >> email;
            std::cout << "Enter client phone: ";
            std::cin >> phone;
            std::cout << "Enter client address: ";
            std::cin >> address;
            std::cout << "Enter client membership type: ";
            std::cin >> membershipType;
            std::cout << "Enter total amount spent by client: ";
            std::cin >> totalSpent;

            clients.push_back(std::make_unique<Client>(name, clientID, email, phone, address, PaymentMethod(), membershipType, totalSpent));
            std::cout << "Client created successfully.\n";
        }

        // Функція для видалення об'єкта Client за індексом
        void deleteClient(std::vector<std::unique_ptr<Client>>& clients) {
            int index;
            std::cout << "Enter the index of the client to delete: ";
            std::cin >> index;

            if (index < 0 || index >= clients.size()) {
                std::cerr << "Invalid index.\n";
                return;
            }

            clients.erase(clients.begin() + index);
            std::cout << "Client deleted successfully.\n";
        }

        // Функція для показу інформації про всіх клієнтів
        void showClients(const std::vector<std::unique_ptr<Client>>& clients) {
            if (clients.empty()) {
                std::cout << "No clients to display.\n";
                return;
            }

            for (size_t i = 0; i < clients.size(); ++i) {
                std::cout << "Client " << i << ": ";
                clients[i]->displayInfo();
            }
        }
        void demonstratePolymorphism(Person* person) {
            // Викликає displayInfo() залежно від типу об'єкта
            person->displayInfo();  // Пізнє зв'язування (динамічне)
        }
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        //3)
        std::cout << "Creating Administrator object through Person pointer:" << std::endl;
        Person* person1 = new Administrator("John Doe", "admin@example.com", "admin123", 1, 5000.0f, 20.0f, 100, 5);
        person1->displayInfo(); //9)
        delete person1; // Викликається віртуальний деструктор

        std::cout << "\nCreating Client object through Person pointer:" << std::endl;
        Person* person2 = new Client("Alice Smith", "alice@example.com", 150.0f);
        person2->displayInfo(); //9)
        delete person2; // Викликається лише деструктор Client (невіртуальний деструктор у Person)
        //4)
        // Створюємо об'єкт Administrator через вказівник на Person
        Person* person3 = new Administrator("John Doe", "admin@example.com", "admin123", 1, 5000.0f, 20.0f, 100, 5);
        person3->displayInfo();  //9)
        delete person3;  // Викликається віртуальний деструктор

        std::cout << "\n";

        // Створюємо об'єкт Client через вказівник на Person
        Person* person4 = new Client("Alice Smith", "alice@example.com", 150.0f);
        person4->displayInfo();  // Викликається метод displayInfo() з класу Client
        delete person4;  // Викликається віртуальний деструктор
        //5)
        try {
            std::cout << "Creating static clients:" << std::endl;

            // Створення статичних клієнтів
            Client client1("Alice", 1, "alice@example.com", "Unknown", "Unknown", PaymentMethod(), "Unknown", 0.0f);
            Client client2("Bob", 2, "bob@example.com", "Unknown", "Unknown", PaymentMethod(), "Unknown", 0.0f);
            Client client3("Charlie", 3, "charlie@example.com", "Unknown", "Unknown", PaymentMethod(), "Unknown", 0.0f);
            Client client4("David", 4, "david@example.com", "Unknown", "Unknown", PaymentMethod(), "Unknown", 0.0f);
            Client client5("Eve", 5, "eve@example.com", "Unknown", "Unknown", PaymentMethod(), "Unknown", 0.0f);

            // Демонстрація інформації про клієнтів
            client1.displayInfo();
            client2.displayInfo();
            client3.displayInfo();
            client4.displayInfo();
            client5.displayInfo();

            std::cout << "Total clients created (static): " << Client::getClientCount() << std::endl;

            // Спроба створити 6 клієнта (повинен викинути помилку)
            std::cout << "\nTrying to create another static client (will throw exception)..." << std::endl;
            // Викличе виключення через перевищення ліміту
            Client client6("Frank", 6, "frank@example.com", "Unknown", "Unknown", PaymentMethod(), "Unknown", 0.0f);

        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        //6)
        try {
            std::cout << "\nCreating dynamic clients:" << std::endl;

            // Створення динамічних клієнтів
            Client* client7 = Client::createDynamicClient(7, "Grace", "grace@example.com");
            Client* client8 = Client::createDynamicClient(8, "Hank", "hank@example.com");
            Client* client9 = Client::createDynamicClient(9, "Ivy", "ivy@example.com");
            Client* client10 = Client::createDynamicClient(10, "Jack", "jack@example.com");
            Client* client11 = Client::createDynamicClient(11, "Kenny", "kenny@example.com");

            // Демонстрація інформації про динамічних клієнтів
            client7->displayInfo();
            client8->displayInfo();
            client9->displayInfo();
            client10->displayInfo();
            client11->displayInfo();

            std::cout << "Total clients created (dynamic): " << Client::getClientCount() << std::endl;

            // Спроба створити 6-го клієнта, коли максимальна кількість вже досягнута
            std::cout << "\nTrying to create another dynamic client (will throw exception)..." << std::endl;
            Client* client12 = Client::createDynamicClient(12, "Lily", "lily@example.com");

            // Видалення динамічних клієнтів
            delete client7;
            delete client8;
            delete client9;
            delete client10;
            delete client11;

        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        //7)
        std::string filename;
        std::cout << "Enter the name for file: ";
        std::cin >> filename;

        Client client("John Doe", 123, "johndoe@example.com", "123456789", "123 Main St", PaymentMethod(), "Premium", 100.0f);

        try {
            Service(client, filename);
        }
        catch (const std::exception& e) {
            std::cerr << "Error in main: " << e.what() << std::endl;
        }

        std::vector<std::unique_ptr<Client>> clients;
        int choice;

        do {
            displayMenu();
            std::cin >> choice;

            switch (choice) {
            case 1:
                createClient(clients);
                break;
            case 2:
                deleteClient(clients);
                break;
            case 3:
                showClients(clients);
                break;
            case 4: {
                int index;
                std::string filename;
                std::cout << "Enter the index of the client to save to file: ";
                std::cin >> index;
                if (index >= 0 && index < clients.size()) {
                    std::cout << "Enter file name: ";
                    std::cin >> filename;
                    clients[index]->Write(filename);
                }
                else {
                    std::cerr << "Invalid index.\n";
                }
                break;
            }
            case 5: {
                int index;
                std::string filename;
                std::cout << "Enter the index of the client to load from file: ";
                std::cin >> index;
                if (index >= 0 && index < clients.size()) {
                    std::cout << "Enter file name: ";
                    std::cin >> filename;
                    clients[index]->Read(filename);
                }
                else {
                    std::cerr << "Invalid index.\n";
                }
                break;
            }
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cerr << "Invalid choice. Please try again.\n";
                break;
            }

        } while (choice != 0);
        //8)
        // Поліморфний виклик через вказівник на базовий клас
        Person* personPtr = new Client("John Doe2", 1232, "johndoe@example.com", "123456789", "123 Main St", PaymentMethod(), "Premium", 100.0f);
        personPtr->displayInfo();  // Виклик методу Client::displayInfo() через Person*
        delete personPtr;

        // Поліморфний виклик через посилання на базовий клас
        Administrator admin;
        Person& personRef = admin;
        personRef.displayInfo();  // Виклик методу Administrator::displayInfo() через Person&

        // Поліморфний виклик через вектор вказівників на базовий клас (динамічний масив)
        std::vector<std::unique_ptr<Person>> people;
        people.push_back(std::make_unique<Client>("John Doe2", 1232, "johndoe@example.com", "123456789", "123 Main St", PaymentMethod(), "Premium", 100.0f));
        people.push_back(std::make_unique<Guest>());
        people.push_back(std::make_unique<Administrator>());

        for (const auto& person : people) {
            person->displayInfo();  // Виклик відповідного методу displayInfo() кожного типу об'єкта
        }
        //10)
        // Статичне зв'язування (раннє зв'язування)
        Client client2("John Doe2", 1232, "johndoe@example.com", "123456789", "123 Main St", PaymentMethod(), "Premium", 100.0f);
        Guest guest2;
        Administrator admin2;

        // Викликаємо методи без використання віртуальних функцій:
        // Оскільки це статичне зв'язування, викликається метод на основі типу об'єкта вказівника
        client2.displayInfo(); // Виведе "Client Name: Alice, Client ID: 1"
        guest2.displayInfo();  // Виведе "Guest info"
        admin2.displayInfo();  // Виведе "Administrator info"

        // Динамічне зв'язування (пізнє зв'язування)
        Person* personPtr2;

        personPtr2 = &client2;
        personPtr2->displayInfo(); // Викликається Client::displayInfo() через Person*

        personPtr2 = &guest2;
        personPtr2->displayInfo();  // Викликається Guest::displayInfo() через Person*

        personPtr2 = &admin2;
        personPtr2->displayInfo();  // Викликається Administrator::displayInfo() через Person*

        // Створюємо об'єкти за допомогою вектору та динамічного зв'язування
        std::vector<std::unique_ptr<Person>> people2;
        people2.push_back(std::make_unique<Client>("John Doe2", 1232, "johndoe@example.com", "123456789", "123 Main St", PaymentMethod(), "Premium", 100.0f));
        people2.push_back(std::make_unique<Guest>());
        people2.push_back(std::make_unique<Administrator>());

        for (const auto& person2 : people2) {
            person2->displayInfo();  // Викликається відповідний метод через поліморфізм
        }
        //11)
        // Створюємо вказівники на об'єкти похідних класів
        Person* p1 = new Guest("Jane Guest");
        Person* p2 = new Administrator("John Doe", "admin@example.com", "admin123", 1, 5000.0f, 20.0f, 100, 5);

        std::cout << "Using polymorphism:" << std::endl;
        demonstratePolymorphism(p1);  // Викликається displayInfo() для Guest
        demonstratePolymorphism(p2);  // Викликається displayInfo() для Administrator

        // Очищення пам'яті
        delete p1;
        delete p2;

        return;
    }
    };
}

