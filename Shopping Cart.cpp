//Arya Dhole ENTC-A2 22070123027

#include <iostream>
#include <string>
using namespace std;

const int MAX_DEVICES = 20;
class Products 
{
    public:
    string name;
    float price;
    int quantity;

    Products() : name(""), price(0), quantity(0) {}
    Products(const string& n, float p) : name(n), price(p), quantity(0) {}

    float getTotalPrice() const 
	{
        return price * quantity;
    }
};

class ShoppingSystem
{
    public:
    Products devices[MAX_DEVICES];
    int Item;
    int discountThreshold;
    int discountThreshold1;
    float baseDiscountRate;
    float DiscountRate1;

    ShoppingSystem() : Item(0), discountThreshold(2), discountThreshold1(4), baseDiscountRate(0.05), DiscountRate1(0.1)
	{
		
        devices[Item++] = Products("iPhone 15", 80000);
        devices[Item++] = Products("iPhone 15 Pro", 120000);
        devices[Item++] = Products("Samsung S23", 85000);
        devices[Item++] = Products("Samsung S23 Plus", 95000);
        devices[Item++] = Products("Google Pixel 8", 75000);
        devices[Item++] = Products("Google Pixel 8 Pro", 95000);
     
        devices[Item++] = Products("Samsung Z Fold 6", 180000);
        devices[Item++] = Products("Samsung Z Flip 6", 100000);
        devices[Item++] = Products("OnePlus Open ", 135000);
        devices[Item++] = Products("Google Pixel Fold", 150000);
        
        devices[Item++] = Products("AirPods", 10000);
        devices[Item++] = Products("AirPods Pro", 15000);
        devices[Item++] = Products("Samsung Buds", 8500);
        devices[Item++] = Products("Samsung Buds Pro", 14000);
        devices[Item++] = Products("Pixel Buds", 8000);
        devices[Item++] = Products("Pixel Buds Plus", 13500);
        
        devices[Item++] = Products("Apple Watch Series 8", 55000);
        devices[Item++] = Products("Apple Watch Ultra", 85000);
        devices[Item++] = Products("Galaxy Watch 4", 35000);
        devices[Item++] = Products("Pixel Watch 2", 45000);	   
    }

    void displayMenu()
	{
        cout << "Product Menu:\n";
        cout << "\nSmartphones\n"<<endl;
        for (int i = 0; i < 6; i++) 
		{
            cout << i + 1 << ". " << devices[i].name<<" - " << devices[i].price << " INR"  <<endl;
        }
        cout << "\nFoldables\n"<<endl;
        for (int i = 6; i < 10; i++) 
		{
           cout << i + 1 << ". " << devices[i].name<<" - "  << devices[i].price << " INR"  <<endl;
		}
        cout << "\nHeadphones\n"<<endl;
        for (int i = 10; i < 16; i++) 
		{
            cout << i + 1 << ". " << devices[i].name<<" - "  << devices[i].price << " INR"  <<endl;
        }
        cout << "\nSmart Watches\n"<<endl;
        for (int i = 16; i < 20; i++) 
		{
            cout << i + 1 << ". " << devices[i].name<<" - "  << devices[i].price << " INR"  <<endl;
        }
        cout << "\n0. Checkout\n";
        cout << "-------------------------------\n";
    }

    void purchaseDevice(int choice, int quantity) 
	{
        if (choice >= 1 && choice <= Item) 
		{
            devices[choice - 1].quantity += quantity;
            cout << quantity << " " << devices[choice - 1].name << " added to the cart.\n";
        }
		else
		{
			cout << "Invalid choice. Please try again.\n";
        }
    }

    float calculateTotalPrice()
	{
        float total = 0;
        for (int i = 0; i < Item; ++i)
		{
            total += devices[i].getTotalPrice();
        }
        return total;
    }

    float calculateDiscount()
	{
        float totalQuantity = 0;
        for (int i = 0; i < Item; ++i)
		{
            totalQuantity += devices[i].quantity;
        }

        float totalDiscount = 0;
        if (totalQuantity >= discountThreshold && totalQuantity < discountThreshold1)
		{
            totalDiscount = baseDiscountRate * calculateTotalPrice();
        }
        else if (totalQuantity >= discountThreshold1)
		{
            totalDiscount = DiscountRate1 * calculateTotalPrice();
        }
        return totalDiscount;
    }
};

int main()
{
    ShoppingSystem shoppingSystem;
    char choice;
    do
	{
        shoppingSystem.displayMenu();

        int deviceChoice;
        int quantity;

        cout << "Enter the number of the device you want to purchase (or 0 to finish): ";
        cin >> deviceChoice;

        if (deviceChoice == 0)
		{
            break;
        }

        if (deviceChoice < 0 || deviceChoice > MAX_DEVICES)
		{
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        cout << "Enter the quantity: ";
        cin >> quantity;

        shoppingSystem.purchaseDevice(deviceChoice, quantity);

        cout << "Do you want to continue shopping? (Y/N): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    double totalBill = shoppingSystem.calculateTotalPrice();
    double discount = shoppingSystem.calculateDiscount();
    double finalBill = totalBill - discount;
    
    cout << "-------------------------------\n";
    cout << "Cart Contents:\n"<<endl;
    for (int i = 0; i < shoppingSystem.Item; ++i)
	{
        if (shoppingSystem.devices[i].quantity > 0)
		{
            cout << shoppingSystem.devices[i].name << " - Quantity: " << shoppingSystem.devices[i].quantity << endl;
        }
    }
    
    cout << "\nTotal Bill Amount: " << totalBill <<" INR"<<  endl;
    cout << "Discount Applied: " << discount <<" INR"<< endl;
    cout << "Final Bill Amount: " << finalBill <<" INR"<< endl;
    return 0;
}

