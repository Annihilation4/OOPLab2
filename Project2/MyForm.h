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
        // 9) ...
        // Доступ до публічного поля і методу
        Product prod("Laptop", 1, 999.99, 10, "Electronics", "BrandX", 4.5, true);
        std::cout << "Public ID: " << prod.getProductID() << std::endl;

        // Створення об'єкта PaymentMethod
        PaymentMethod paymentMethod(1, "Credit Card", 2.5, true, "USD", 1000, "Visa", 0.05f);

        // Створення об'єкта Order
        Order order(1, prod, 1, paymentMethod, true, "123 Main St", "Shipped");

        // Створення об'єкта Client
        Client client("John Doe", 1001, "johndoe@example.com", "123-456-7890", "456 Elm St", paymentMethod, "Gold", 5000.0f);

        // 3) Створення об'єкта ClientOrder, використовуючи дані з Client і Order
        ClientOrder clientOrder(client.getName(), client.getClientID(), client.getEmail(), client.getPhone(),
            client.getAddress(), paymentMethod, client.getMembershipType(), client.getTotalSpent(),
            order.getOrderID(), order.getProduct(), order.getQuantity(),
            order.getPaymentMethod(), order.getIsPaid(), order.getDeliveryAddress(), order.getOrderStatus());

        // 4) Виклик методу для відображення інформації про клієнта і замовлення
        clientOrder.displayClientOrderInfo();

        // 5) Створення об'єкта OrderHistory
        OrderHistory orderHistory1 (client.getName(), client.getClientID(), client.getEmail(),
            client.getPhone(), client.getAddress(), paymentMethod,
            client.getMembershipType(), client.getTotalSpent());

        // 2,5)
        OrderHistory orderHistory("Ambrello", "wenoinowe@wegn", 123);

        // Додавання замовлення до історії
        orderHistory.addOrder(order);

        // Відображення історії замовлень
        orderHistory.displayOrderHistory();

        // 2)
        orderHistory.showClientDetails();

        // 6) using
        orderHistory.displayInfo();

        return;
    }
    };
}

