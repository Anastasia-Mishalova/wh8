// wh8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;
// Задача на взаимодействие между классами. Разработать систему «Интернет - магазин». Товаровед добавляет информацию о Товаре.
// Клиент делает и оплачивает Заказ на Товары. Товаровед регистрирует Продажу и может занести неплательщика в «черный список».




// не могу понять, как исправить ошибку с аргументами
class Administrator
{
protected:
    vector<Administrator> products;
    string name;
    float price;
    int id;
    bool payment = false;

public:

    int getId() { return id; }
    void setId(int _id) { id = _id; }

    string getName() { return name; }
    void setName(int _name) { name = _name; }

    float getPrice() { return price; }
    void setPrice(int _price) { price = _price; }


    void createNewProduct(int _id, string _name, float _price)
    {
        name = _name;
        price = _price;
        id = _id;

        products.emplace_back(id, name, price);
    }

    void printProducts()
    {
        for (Administrator& a : products)
        {
            cout << '№' << a.id << ' ' << a.name << ' - ' << a.price << '$' << endl;
        }
    }

    void Blacklist()
    {
        cout << "\n\n ЗАКАЗ НЕ ОПЛАЧЕН";
        cout << "\n Вы занесены в черный список";
    }

    void payment_order(bool payment)
    {
        this->payment = payment;

        if (payment == true)
        {
            cout << "\n\n ЗАКАЗ ОПЛАЧЕН";
        }
        else
        {
            Blacklist();
        }
    }

};

class Order : public Administrator
{
protected:
    vector<Order> orderlist;
    string name;
    float price, sum = 0;
    int id;

public:
    void addProdToOrder(int _id)
    {
        for (Administrator& a : products)
        {
            if (a.getId() == _id)
            {
                id = _id;
                name = a.getName();
                price = a.getPrice();

                orderlist.emplace_back(id, name, price);
            }
        }
    }

    void showOrder()
    {
        cout << "\nЧек\n";

        for (Order& o : orderlist)
        {
            cout << '\n№' << o.id << ' ' << o.name << ' - ' << o.price << '$';
            sum += o.price;
        }
        cout << "\n\n Оплата: " << sum << " $";
    }
};

class Client : public Administrator, public Order
{
public:
    void showwOrder()
    {
        showOrder();
    }

    void showProducts()
    {
        Administrator::printProducts();
    }

};
int main() 
{
    setlocale(LC_ALL, "ru");

    Administrator admin;
    admin.createNewProduct(1, "Milk", 2);
    admin.createNewProduct(2, "Bread", 0.99);
    admin.createNewProduct(3, "Tomatoes 1 kg", 1.99);
    admin.createNewProduct(4, "Cucumbers 1 kg", 2.50);
    admin.createNewProduct(5, "Avocado 1 kg", 4.90);
    admin.createNewProduct(6, "Juice", 1.25);
    admin.createNewProduct(7, "Water", 0.25);
    admin.createNewProduct(8, "Bacon", 4.50);

    Client client1;
    client1.showProducts();
    client1.addProdToOrder(1);
    client1.addProdToOrder(1);
    client1.addProdToOrder(4);
    client1.addProdToOrder(8);
    client1.addProdToOrder(5);
    client1.addProdToOrder(6);
    client1.addProdToOrder(3);

    client1.showwOrder();

    client1.Administrator::payment_order(true);
}

