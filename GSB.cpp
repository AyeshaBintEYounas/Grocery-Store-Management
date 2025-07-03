#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class shopping
{
    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

    struct Product
    {
        int code;
        string name;
        float price;
        float discount;
    };
};

void shopping :: menu()
{
 while(true)
 {
    int choice;
    string email;
    string password;

    cout<<"\t\t\t_______________________________________\n";
    cout<<"\t\t\t                                       \n";
    cout<<"             Grocery Store Main Menu           ";
    cout<<"\t\t\t                                       \n";
    cout<<"\t\t\t_______________________________________\n";
    cout<<"\t\t\t                                       \n";

    cout<<"\t\t\t\t|   1) Administrator    |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t|   2) Buyer            |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t|   3) Exit             |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\n\t\t\t  Please Select: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        cout<<"\t\t\t Please Login\n";
        cout<<"\t\t\t Enter Email:";
        cin>>email;
        cout<<"\n\t\t\tEnter Password:";
        cin>>password;

        if(email=="admin123@gmail.com" && password=="admin123")
        {
            administrator();
            break;
        }
        else
        {
            cout<<"Invalid Email/Password";
            break;
        }
        case 2:
        {
            buyer();
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            cout<<"Please Select from Given Options";
        }
    } 
 } 
}
void shopping :: administrator()
{
 while(true)
 {
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n                             ";
    cout<<"\n\t\t\t|_____1) Add The Product_____|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____2) Modify The Product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____3) Delete The Product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to  Main Menu__|";
    cout<<"\n\n\t Please Enter Your Choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            rem();
            break;
        }
        case 4:
        {
            menu();
            break;
        }
        default:
        {
            cout<<"Invalid choice";
        }
    }
 }
}
void shopping :: buyer()
{
 while(true)
 {
    int choice;
    cout<<"\t\t\t   Buyer  \n";
    cout<<"\t\t\t__________\n";
    cout<<"\t\t\t          \n";
    cout<<"\t\t\t 1)Buy Product  \n";
    cout<<"\t\t\t          \n";
    cout<<"\t\t\t 2)Go Back\n";
    cout<<"Enter Your Choice:\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            receipt();
            break;
        }
        case 2:
        {
            menu();
            break;
        }
        default:
        {
            cout<<"Invalid Choice";
        }
    }
 }
}
void shopping :: add()
{
    fstream data;
    Product prod;
    int token=0;
    
    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t Code of Product: ";
    cin>>prod.code;
    cout<<"\n\n\t Name of Product: ";
    cin>>prod.name;
    cout<<"\n\n\t Price of Product: ";
    cin>>prod.price;
    cout<<"\n\n\t Discount on Product: ";
    cin>>prod.discount;

    data.open("database.txt",ios::in);

    if(data)
    {
        Product temp;
        while(data>>temp.code>>temp.name>>temp.price>>temp.discount)
        {
            if(temp.code==prod.code)
            {
                token=1;
                break;
            }
        }
        data.close();
    }
   
    if(token==1)
    {
        cout<<"\n Product Code already exist";
    }

    data.open("database.txt",ios::app);
    data<<prod.code<<" "<<prod.name<<" "<<prod.price<<" "<<prod.discount<<"\n";
    data.close();
    cout<<"\n\n\t\t Record Inserted";
}
void shopping :: edit()
{
    fstream data;
    vector<Product> products;
    Product temp;
    int pkey;
    int found=0;
    
    cout<<"\n\t\t\t Modify Record";
    cout<<"\n\t\t\t Product Code";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile Does Not Exist";
    }
    while(data>>temp.code>>temp.name>>temp.price>>temp.discount)
    {
        if(pkey==temp.code)
        {
                cout<<"\n\t\t Product New Code:";
                cin>>temp.code;
                cout<<"\n\t\t Name of Product:";
                cin>>temp.name;
                cout<<"\n\t\t Price of Product";
                cin>>temp.price;
                cout<<"\n\t\t Discount on Product";
                cin>>temp.discount;
                found=1;
                cout<<"\n\t\t Record Edited";
        }
            products.push_back(temp);
           
    }
    data.close();

    if(!found)
    {
        cout<<"Sorry! Record not found";
    }

    data.open("database.txt",ios::out);

    for( const auto& prod : products)
    {
        data<<prod.code<<" "<<prod.name<<" "<<prod.price<<" "<<prod.discount<<"\n";
    }
    data.close();
}
void shopping :: rem()
{
    fstream data;
    vector<Product> products;
    Product temp;
    int pkey;
    int found=0;
     
    cout<<"\n\t\t Delete Product";
    cout<<"\n\t\t Product Code:";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\n\nFile Does Not Exist";
    }
    while(data>>temp.code>>temp.name>>temp.price>>temp.discount)
    {
        if(temp.code==pkey)
           {
              found=1;
              cout<<"\n\t\t Product Deleted Successfully";
              continue;
           }
        products.push_back(temp);  
    }
    data.close();
        
    if(!found)
    {
            cout<<"Sorry! Record not found";
    }

    data.open("database.txt",ios::out);

    for(auto & prod : products)
    {
        data<<prod.code<<" "<<prod.name<<" "<<prod.price<<" "<<prod.discount<<"\n";
    }
    data.close();
}
void shopping :: list()
{
    fstream data;
    Product temp;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"Product Not Found";
    }

    cout<<"\n\n|________________________________\n";
    cout<<"Code\t\tName\t\tPrice\n";
    cout<<"\n\n|________________________________\n";

    while(data>>temp.code>>temp.name>>temp.price>>temp.discount)
    {
        cout<<temp.code<<"\t\t"<<temp.name<<"\t\t"<<temp.price<<"\n";
    }

    data.close();
}
void shopping :: receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float total=0;

    list();
    cout<<"\n______________________________\n";
    cout<<"\n                              \n";
    cout<<"\n      Please Place Order      \n";
    cout<<"\n                              \n";
    cout<<"\n______________________________\n";

    do
    {
        bool duplicate=false;
        cout<<"\n\n Enter Product Code:";
        cin>>arrc[c];
        
        for(int i=0;i<c;i++)
        {
            if(arrc[c]==arrc[i])
            {
                cout<<"\n\n Duplicate Product Code. Please Try Again!";
                duplicate=true;
                break;
            }
        }
        if(duplicate) continue;
        cout<<"\n\n Enter Product Quantity:";
        cin>>arrq[c];
        c++;

        cout<<"Do You want To Buy Another Product?(y/n): ";
        cin>>choice;
     }
     while(choice=='y'||choice=='Y');

     cout<<"\n\n\t\t\t___________________RECEIPT_____________________________\n";
     cout<<"\nCode\t Name\t Quantity\t Price\t Amount\t Net\n";

     for(int i=0;i<c;i++)
     {
        data.open("database.txt",ios::in);
        Product temp;
        while(data>>temp.code>>temp.name>>temp.price>>temp.discount)
        {
            if(temp.code==arrc[i])
            {
                float amount=temp.price*arrq[i];
                float net=amount-(amount*temp.discount/100);
                total=total+net;
                cout<<"\n"<<temp.code<<"\t\t"<<temp.name<<"\t\t"<<arrq[i]<<"\t\t"<<temp.price<<"\t\t"<<amount<<"\t\t"<<net<<"\n";
                break;
            }
        }
        data.close();
    }
    cout<<"\n\n___________________________________________|";
    cout<<"\n Total Amount: "<<total<<"\n";
}
int main()
{
    shopping s; 
    s.menu();
}