#include <iostream>
using namespace std;

class Shop {
    string orderName;
    int orderPrice;
    int orderQty;
public:

    string getOrderName() { return orderName; }
    int getOrderPrice() { return orderPrice; }
    int getOrderQty() { return orderQty; }

    void printMainMenu()
    {
        cout << "================================" << endl;
        cout << "[a] order Food\n[b] order Drinks\n";
        cout << "[c] view Cart  \n[d] Exit\n";
        cout << "================================" << endl;

    }

    void printFoodMenu()
    {
        cout << "================================" << endl;
        cout << "   Food                 price" << endl;
        cout << "[a] chicken             200\n";
        cout << "[b] burger              150\n";
        cout << "[c] pizza               250 \n";
        cout << "[d] back\n";
        cout << "================================" << endl;
    }

    void printDrinksMenu()
    {
        cout << "================================" << endl;
        cout << "  Drinks             price" << endl;
        cout << "[a] coke             20\n";
        cout << "[b] royal            25\n";
        cout << "[c] sprite           15 \n";
        cout << "[d] back\n";
        cout << "================================" << endl;
    }

    void foodOrder(char order, int qty, string type)
    {
        string name;
        int total;
        int index = (type == "food") ? 0 : 1;
        string productNames[2][3] = {
            {"chicken  ", "burger   ", "pizza   "},
            {"coke     ", "royal    ", "sprite   "}
        };

        int productPrices[2][3] = {
            {200, 150, 250},
            {20, 15, 25}
        };

        switch (order)
        {
        case 'a':
            name = productNames[index][0];
            total = productPrices[index][0] * qty;
            break;

        case 'b':
            name = productNames[index][1];
            total = productPrices[index][1] * qty;
            break;

        case 'c':
            name = productNames[index][2];
            total = productPrices[index][2] * qty;
            break;
        }

        this->orderName = name;
        this->orderPrice = total;
        this->orderQty = qty;
    }

    int getTotal(int* arr, int size)
    {
        int total = 0;

        for (int i = 0; i < size; i++)
        {
            total += arr[i];
        }

        return total;
    }

    void printRecipt(string* name, int* qty, int* price, int size, int total, int payment, string reciptDate)
    {

        cout << "================================" << endl;
        cout << "item:           qty:  total:" << endl;
        for (int i = 0; i < size; i++) {
            cout << name[i] << "        x" << qty[i] << "    " << price[i] << endl;
        }
        cout << "================================" << endl;
        cout << "item sold     " << size << endl;
        cout << "total:        " << total << endl;
        cout << "================================" << endl;
        cout << "cash:         " << payment << endl;
        cout << "change:       " << payment - total << endl;
        cout << "================================" << endl;
        cout << reciptDate << endl;
        cout << "================================" << endl;
    }

};

class Recipt {
public:
    string names[100];
    int price[100];
    int qty[100];
    string date;
    int total;
    string cashier;
    int size;

    Recipt() {
        total = 0;
        date = "";
        for (int i = 0; i < 100; i++) {
            names[i] = "";
            price[i] = 0;
            qty[i] = 0;
        }
    }

    Recipt(string names[], int price[], int qty[], int size, string date, int total, string cashier)
    {  
        this->date = date;
        this->total = total;
        this->cashier = cashier;
        this->size = size;

        for (int i = 0; i < size; i++)
        {
            this->names[i] = names[i];
            this->price[i] = price[i];
            this->qty[i] = qty[i];
        }
    }


};

void clear()
{
    system("cls");
}

string getDate()
{
    time_t ct = time(0);
    tm localTime;
    localtime_s(&localTime, &ct);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);

    string receiptDate(buffer);
    return receiptDate;
}



int reciptCount = 0;
Recipt recipt[100];


void printReciptHistory()
{
    cout << "================================" << endl;

    for (int i = 0; i < reciptCount; i++)
    {
        cout << "--------------------------------" << endl;
        cout << "cashier:" << recipt[i].cashier << "  " << endl;
        for (int j = 0; j < recipt[i].size; j++)
        {
            cout << recipt[i].names[j] << "     x" << recipt[i].qty[j] << "    " << recipt[i].price[j] << endl;
        }    
        cout << "\nTotal: " << recipt[i].total << endl << endl;
        cout << recipt[i].date << endl;
        cout << "--------------------------------" << endl;
        cout << endl << endl;
    }
  
    cout << "================================" << endl;
}

int main()
{
    string orderName[100];
    int orderPrice[100];
    int orderQty[100];
    int count = 0;

    char choice;

    Shop shop;
    string cashier;

    cout << "[a] login\n[b] history" << endl;

    cout << "enter: ";
    cin >> choice;

    clear();
    
    switch (choice)
    {
    case 'a':
        
        cout << "login: ";
        cin >> cashier;
        clear();

        if (cashier == "krel" || cashier == "earl")
        {
            while (true)
            {
                shop.printMainMenu();
                cout << "enter: ";
                cin >> choice;
                clear();

                switch (choice)
                {
                case 'a':
                    int qty;
                    shop.printFoodMenu();
                    cout << "enter: ";
                    cin >> choice;
                    if (choice != 'd')
                    {
                        cout << "Quantity: ";
                        cin >> qty;
                        shop.foodOrder(choice, qty, "food");
                        orderName[count] = shop.getOrderName();
                        orderPrice[count] = shop.getOrderPrice();
                        orderQty[count] = shop.getOrderQty();
                        count++;
                        cout << "\n add order successfully!!\n" << endl;
                        system("pause");
                    }
                    break;

                case 'b':
                    shop.printDrinksMenu();
                    cout << "enter: ";
                    cin >> choice;
                    if (choice != 'd')
                    {
                        cout << "Quantity: ";
                        cin >> qty;
                        shop.foodOrder(choice, qty, "drinks");
                        orderName[count] = shop.getOrderName();
                        orderPrice[count] = shop.getOrderPrice();
                        orderQty[count] = shop.getOrderQty();
                        count++;
                        cout << "\n add order successfully!!\n" << endl;
                        system("pause");
                    }
                break;

                case 'c':
                    cout << "================================" << endl;
                    cout << "your order:        \t price:" << endl;
                    for (int i = 0; i < count; i++)
                    {
                        cout << "[" << i + 1 << "] x" << orderQty[i] << " " << orderName[i] << "  \t" << orderPrice[i] << endl;
                    }
                    cout << "\ntotal:" << shop.getTotal(orderPrice, count) << endl << endl;
                    cout << "================================" << endl;
                    cout << "[a] proceed to payment\n[b] back\n";
                    cout << "enter: ";
                    cin >> choice;
                    if (choice == 'a')
                    {
                        int payment;
                        do {
                            cout << "enter payment: ";
                            cin >> payment;
                        } while (payment < shop.getTotal(orderPrice, count));
                        clear();
                        string date = getDate();
                        shop.printRecipt(orderName, orderQty, orderPrice, count, shop.getTotal(orderPrice, count), payment, date);
                        recipt[reciptCount] = Recipt(orderName, orderPrice, orderQty, count, date, shop.getTotal(orderPrice, count), cashier);
                        reciptCount++;
                        system("pause");
                        clear();
                        main();
                    }
                break;

                case 'd':
                    clear();
                    main();
                break;
                }
                clear();
            }

        }
        else
        {   
            clear();
            main();
        }
        break;

        case 'b':
            printReciptHistory();
            system("pause");
            system("cls");
            main();
        break;
    }


}

