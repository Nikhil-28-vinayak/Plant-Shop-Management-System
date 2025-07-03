#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class Enter
{
public:
     char id[20];
     char passward[10];

private:
     char name[10];

public:
     void Si_in_or_lo_in()
     {
          cout << "Enter your name: ";
          cin >> name;

          cout << "Emai-id: ";
          cin >> id;

          cout << "Passard: ";
          cin >> passward;
     }
};

class Welcome
{
public:
     char option1;
     void Welcome_screen()
     {
          cout << endl
               << "********WELCOME TO PCTE PLANT SHOP**********" << endl
               << endl;
          cout << "Enter A for (Plant Catalog)" << endl;
          cout << "Enter B for (Customer Record)" << endl;
          cout << "Enter C for (Plant Care Guide)" << endl;

          cout << "Enter: ";
          cin >> option1;
     }
};

class Plant_Catalog : public virtual Welcome
{
public:
     char option2;
     void showCatalog()
     {
          cout << "        CATALOG        " << endl
               << endl;
          cout << "Enter A for Outdoor Plants" << endl;
          cout << "Enter B for Indoor Plants" << endl;
          cout << "Enter: ";
          cin >> option2;
     }
};

class Outdoor_plants : public virtual Plant_Catalog
{
public:
     char option3;
     void Plant1()
     {
          cout << endl
               << "Outdoor Plants" << endl
               << endl;
          cout << "Enter A for Flowering Plants" << endl;
          cout << "Enter B for Medicinal Plants" << endl;
          cout << "Enter C for Fruiting Plants" << endl;
          cout << "Enter: ";
          cin >> option3;
     }
};

class Flowering_plants : public virtual Outdoor_plants
{
public:
     int r_prise = 200, h_price = 150, j_price = 100;
     int r_quantity = 100, h_quantity = 100, j_quantity = 100;
     void Plant3()
     {
          cout << endl
               << "Flowering Plants" << endl
               << endl;
          cout << "Rose" << endl;
          cout << "Price: " << r_prise << " per plant" << endl;
          cout << "Quantity:" << r_quantity << endl
               << endl;
          cout << "Hibiscus" << endl;
          cout << "Price: " << h_price << " per plant" << endl;
          cout << "Quantity:" << h_quantity << endl
               << endl;
          cout << "Jasmine" << endl;
          cout << "Price:" << j_price << " per plant" << endl;
          cout << "Quantity:" << j_quantity << endl
               << endl;
          ;
     }
};

class Medicinal_plants : public virtual Outdoor_plants
{
public:
     int a_price = 100, n_price = 150, t_price = 120;
     int a_quantity = 100, n_quantity = 100, t_quantity = 100;
     void Plant4()
     {
          cout << endl
               << "Medicinal Plants" << endl
               << endl;
          cout << "Aloe Vera" << endl;
          cout << "Price: " << a_price << " per plant" << endl;
          cout << "Quantity:" << a_quantity << endl
               << endl;
          cout << "Neem" << endl;
          cout << "Price: " << n_price << " per plant" << endl;
          cout << "Quantity:" << n_quantity << endl
               << endl;
          cout << "Tulsi" << endl;
          cout << "Price: " << t_price << " per plant" << endl;
          cout << "Quantity:" << t_quantity << endl
               << endl;
     }
};

class Fruiting_plants : public virtual Outdoor_plants
{
public:
     int a_price = 120, o_price = 90;
     int a_quantity = 100, o_quantity = 100;
     void Plant5()
     {
          cout << endl
               << "Fruiting Plants" << endl
               << endl;
          cout << "Apple" << endl;
          cout << "Price: " << a_price << " per plant" << endl;
          cout << "Quantity:" << a_quantity << endl
               << endl;
          cout << "Orange" << endl;
          cout << "Price: " << o_price << " per plant" << endl;
          cout << "Quantity:" << o_quantity << endl
               << endl;
     }
};

class Indoor_plants : public virtual Plant_Catalog
{
public:
     int f_price = 120, c_price = 150, m_price = 85, p_price = 90;
     int f_quantity = 100, c_quantity = 100, m_quantity = 100, p_quantity = 100;
     void Plant2()
     {
          cout << endl
               << "Indoor Plants" << endl
               << endl;
          cout << "Ferns" << endl;
          cout << "Price: " << f_price << " per plant" << endl;
          cout << "Quantity:" << f_quantity << endl
               << endl;
          cout << "Cactus" << endl;
          cout << "Price:" << c_price << " per plant" << endl;
          cout << "Quantity:" << c_quantity << endl
               << endl;
          cout << "Money Plant" << endl;
          cout << "Price:" << m_price << " per plant" << endl;
          cout << "Quantity:" << m_quantity << endl
               << endl;
          cout << "Peace Lily" << endl;
          cout << "Price:" << p_price << " per plant" << endl;
          cout << "Quantity:" << p_quantity << endl
               << endl;
     }
};

class payment : public Flowering_plants, public Medicinal_plants, public Fruiting_plants, public Indoor_plants
{
public:
     char payment_option;
     char customer_name[10];
     void Select()
     {
          cout << endl
               << "Payment Options" << endl
               << endl;
          cout << "Enter A for Cash Payment" << endl
               << endl;
          cout << "Enter B for Online Payment" << endl
               << endl;
          cout << "Enter: ";
          cin >> payment_option;
     }

     void writeToFile(const char *paymentMode, const char *plantName, int quantity)
     {
          ofstream Myfile("record.txt");
          Myfile << "Customer name: " << customer_name << endl;
          Myfile << "Product name: " << plantName << endl;
          Myfile << "Quantity: " << quantity << endl;
          Myfile << "Mode of payment: " << paymentMode << endl
                 << endl;
          Myfile.close();
     }
     void cash(int a, char name[10], payment pa)
     {
          cout << "Enter your name: ";
          cin >> customer_name;
          writeToFile("Cash", name, a);

          if (strcmp(name, "Rose") == 0)
          {
               cout << "Total amount is: " << a * r_prise << endl;
          }
          else if (strcmp(name, "Hibiscus") == 0)
          {
               cout << "Total amount is: " << a * h_price << endl;
          }
          else if (strcmp(name, "Jasmine") == 0)
          {
               cout << "Total amount is: " << a * j_price << endl;
          }
          else if (strcmp(name, "Aloe Vera") == 0)
          {
               cout << "Total amount is: " << a * Medicinal_plants::a_price << endl;
          }
          else if (strcmp(name, "Neem") == 0)
          {
               cout << "Total amount is: " << a * n_price << endl;
          }
          else if (strcmp(name, "Tulsi") == 0)
          {
               cout << "Total amount is: " << a * t_price << endl;
          }
          else if (strcmp(name, "Apple") == 0)
          {
               cout << "Total amount is: " << a * Fruiting_plants::a_price << endl;
          }
          else if (strcmp(name, "Orange") == 0)
          {
               cout << "Total amount is: " << a * o_price << endl;
          }
          else if (strcmp(name, "Ferns") == 0)
          {
               cout << "Total amount is: " << a * f_price << endl;
          }
          else if (strcmp(name, "Cactus") == 0)
          {
               cout << "Total amount is: " << a * c_price << endl;
          }
          else if (strcmp(name, "Money Plant") == 0)
          {
               cout << "Total amount is: " << a * m_price << endl;
          }
          else if (strcmp(name, "Peace Lily") == 0)
          {
               cout << "Total amount is: " << a * p_price << endl;
          }
          else
          {
               cout << "Invalid plant name!" << endl;
          }
          cout << "Your order is successfully placed!" << endl;
          cout << endl
               << "When the product is delivered then give the money to the delivery man!" << endl
               << endl;
          cout << "Thank you so much! again visit to our shop" << endl;
     }

     void online(int a, char name[10], payment pa)
     {
          cout << "Enter your name: ";
          cin >> customer_name;
          cout << "Enter your ATM no: ";
          cin >> atm_no;
          cout << "Enter your ATM pin: ";
          cin >> atm_pin;

          writeToFile("Online", name, a);

          if (strcmp(name, "Rose") == 0)
          {
               total_amount = a * r_prise;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "Hibiscus") == 0)
          {
               total_amount = a * h_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "Jasmine") == 0)
          {
               total_amount = a * j_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "Aloe Vera") == 0)
          {
               total_amount = a * Medicinal_plants::a_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "Neem") == 0)
          {
               total_amount = a * n_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "Tulsi") == 0)
          {
               total_amount = a * t_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "Apple") == 0)
          {
               total_amount = a * Fruiting_plants::a_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "Orange") == 0)
          {
               total_amount = a * o_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "Ferns") == 0)
          {
               total_amount = a * f_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "Cactus") == 0)
          {
               total_amount = a * c_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "MoneyPlant") == 0)
          {
               total_amount = a * m_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else if (strcmp(name, "PeaceLily") == 0)
          {
               total_amount = a * p_price;
               cout << "Total amount is: " << total_amount << endl;
          }
          else
          {
               cout << "Invalid plant name!" << endl;
          }
          cout << endl
               << "Your order is successfully placed!" << endl;
          cout << endl
               << "Swipe your card!" << endl;
          cout << "Thank you so much!" << endl
               << "again visit to our shop" << endl;
     }

private:
     int atm_no;
     int atm_pin;

public:
     int total_amount;
};

class Plant_Guide
{
public:
     char name[10];

     void Plant_Information()
     {
          cout << "Enter the name of the plant you want to know about: ";
          cin >> name;

          if (strcmp(name, "Rose") == 0)
          {
               cout << "1. Rose is a sunloving plant." << endl;
               cout << "2. This plant can grow without fertilizers." << endl;
               cout << "3. This Plant can grow in every type of soil." << endl;
               cout << "4. No need to give too much water to the plant." << endl;
          }
          else if (strcmp(name, "Hibiscus") == 0)
          {
               cout << "1. Hibiscus is sunloving plant." << endl;
               cout << "2. This plant need some fertilizers." << endl;
               cout << "3. This Plant can grow in every type of soil." << endl;
               cout << "4. This plant not love dry soil." << endl;
          }
          else if (strcmp(name, "Jasmine") == 0)
          {
               cout << "1. Jasmine needs sunlight for only 4 hours" << endl;
               cout << "2. It require heavy fertilizers" << endl;
               cout << "3. It need heavy fertile soil" << endl;
               cout << "4. Need less water" << endl;
          }
          else if (strcmp(name, "Aloe Vera") == 0)
          {
               cout << "1. Aloe vera needs shade loving plant" << endl;
               cout << "2. No need of fertilizers" << endl;
               cout << "3. Grow in any type of soil" << endl;
               cout << "4. Need less water" << endl;
          }
          else if (strcmp(name, "Neem") == 0)
          {
               cout << "1. Neem is sunloving plant" << endl;
               cout << "2. there is no need of fertilizers" << endl;
               cout << "3. Grow in any type of soil" << endl;
               cout << "4. Need less water" << endl;
          }
          else if (strcmp(name, "Tulsi") == 0)
          {
               cout << "1. Tulsi needs sunlight for only 6 hours" << endl;
               cout << "2. It require some fertilizers" << endl;
               cout << "3. Grow in any type of soil" << endl;
               cout << "4. Need sufficient amount of water" << endl;
          }
          else if (strcmp(name, "Apple") == 0)
          {
               cout << "1. Apple needs sunlight for only 5 hours" << endl;
               cout << "2. It require heavy fertilizers" << endl;
               cout << "3. It need heavy fertile soil" << endl;
               cout << "4. Need less water" << endl;
          }
          else if (strcmp(name, "Orange") == 0)
          {
               cout << "1. Orange needs sunlight for only 7 hours" << endl;
               cout << "2. It require some fertilizers" << endl;
               cout << "3. It need heavy fertile soil" << endl;
               cout << "4. Need sufficient water" << endl;
          }
          else if (strcmp(name, "Ferns") == 0)
          {
               cout << "1. Ferns needs shade" << endl;
               cout << "2. It require heavy fertilizers" << endl;
               cout << "3. Grow in any type of soil" << endl;
               cout << "4. Need less water" << endl;
          }
          else if (strcmp(name, "PeaceLily") == 0)
          {
               cout << "1. Peace Lily needs shade" << endl;
               cout << "2. No need of fertilizers" << endl;
               cout << "3. It need heavy fertile soil" << endl;
               cout << "4. Need Sufficient water" << endl;
          }
          else if (strcmp(name, "MoneyPlant") == 0)
          {
               cout << "1. Money Plant is shade loving plant" << endl;
               cout << "2. It require some fertilizers" << endl;
               cout << "3. Grow in any type of soil" << endl;
               cout << "4. Need more water" << endl;
          }
          else if (strcmp(name, "Cactus") == 0)
          {
               cout << "1. Cactus is sun loving plant" << endl;
               cout << "2. No need of fertilizers" << endl;
               cout << "3. Grow in any type of soil" << endl;
               cout << "4. Need very less water" << endl;
          }
          else
          {
               cout << "Invalid plant name!" << endl;
          }
     }
};

int main()
{
     cout << endl
          << "        SIGN-IN OR LOGIN-IN        " << endl
          << endl;
     Enter e;
     e.Si_in_or_lo_in();
     payment p;
     p.Welcome_screen();
     Plant_Guide p2;

     char Plant_name[20];
     int quantity;

     if (p.option1 == 'A' || p.option1 == 'a')
     {
          p.showCatalog();
          if (p.option2 == 'A' || p.option2 == 'a')
          {
               p.Plant1();
               if (p.option3 == 'A' || p.option3 == 'a')
               {
                    p.Plant3();
                    cout << "Enter the name of the plant you want to buy: ";
                    cin >> Plant_name;
                    cout << "Enter Quantity: ";
                    cin >> quantity;
                    p.Select();
                    if (p.payment_option == 'A' || p.payment_option == 'a')
                    {
                         p.cash(quantity, Plant_name, p);
                    }
                    else
                    {
                         p.online(quantity, Plant_name, p);
                    }
               }
               else if (p.option3 == 'B' || p.option3 == 'b')
               {
                    p.Plant4();
                    cout << "Enter the name of the plant you want to buy: ";
                    cin >> Plant_name;
                    cout << "Enter Quantity: ";
                    cin >> quantity;
                    p.Select();
                    if (p.payment_option == 'A' || p.payment_option == 'a')
                    {
                         p.cash(quantity, Plant_name, p);
                    }
                    else
                    {
                         p.online(quantity, Plant_name, p);
                    }
               }
               else if (p.option3 == 'C' || p.option3 == 'c')
               {
                    p.Plant5();
                    cout << "Enter the name of the plant you want to buy: ";
                    cin >> Plant_name;
                    cout << "Enter Quantity: ";
                    cin >> quantity;
                    p.Select();
                    if (p.payment_option == 'A' || p.payment_option == 'a')
                    {
                         p.cash(quantity, Plant_name, p);
                    }
                    else
                    {
                         p.online(quantity, Plant_name, p);
                    }
               }
          }
          else
          {
               p.Plant2();
               cout << "Enter the name of the plant you want to buy: ";
               cin >> Plant_name;
               cout << "Enter Quantity: ";
               cin >> quantity;
               p.Select();
               if (p.payment_option == 'A' || p.payment_option == 'a')
               {
                    p.cash(quantity, Plant_name, p);
               }
               else
               {
                    p.online(quantity, Plant_name, p);
               }
          }
     }
     else if (p.option1 == 'B' || p.option1 == 'b')
     {
          ifstream MyFile("record.txt");
          string line;
          while (getline(MyFile, line))
          {
               cout << line << endl;
          }
          MyFile.close();
     }
     else if (p.option1 == 'C' || p.option1 == 'c')
     {
          cout << "Plant Care Guide" << endl
               << endl;
          p2.Plant_Information();
     }
     else
     {
          cout << "Invalid attempt please try gain later" << endl;
     }
}
