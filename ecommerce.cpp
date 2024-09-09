#include <bits/stdc++.h>
using namespace std;

class Users
{
private:
    string name, email, password;

public:
    Users()
    {
        cout << "\nEnter your name\n";
        getline(cin, name);
        cout << "\nEnter email\n";
        getline(cin, email);
        cout << "\nEnter password\n";
        getline(cin, password);
    }
    string getname()
    {
        return name;
    }
    string getemail()
    {
        return email;
    }
    string getpassword()
    {
        return password;
    }
};
class Admin
{
private:
    string name, email, password;

public:
    Admin()
    {
        name = "ADMIN";
        email = "admin@gmail.com";
        password = "Admin123";
    }
    string getname()
    {
        return name;
    }
    string getemail()
    {
        return email;
    }
    string getpassword()
    {
        return password;
    }
};
class checklogin : public Admin
{
private:
    string email, password;

public:
    bool checkAdminloggedIn()
    {
        if (this->email == Admin::getemail())
        {
            if (this->password == Admin::getpassword())
            {
                return true;
            }
        }
        return false;
    }

    bool checkCustmerloggedIn(string e, string p)
    {
        if (this->email == e)
        {
            if (this->password == p)
            {
                return true;
            }
        }
        return false;
    }
    checklogin()
    {
        cout << "\n------LOGIN SYSTEM-----------\n";
        cout << "\nEnter email\n";
        getline(cin, email);
        cout << "\nEnter password\n";
        getline(cin, password);
    }
};

class Product
{
private:
    string name;
    float price;
    int quantity;
    int id;

public:
    void setname(string n)
    {
        name = n;
    }
    void setprice(float p)
    {
        price = p;
    }
    void setquantity(int q)
    {
        quantity = q;
    }
    void setId()
    {
        srand(time(0));
        id = 1000 + (rand() % 900 + 1);
    }

    string getname()
    {
        return name;
    }
    float getprice()
    {
        return price;
    }
    int getquantity()
    {
        return quantity;
    }
    int getid()
    {
        return id;
    }

    void addingProducts()
    {
        
        string prod_name;
        float price;
        int quantity;
        cout << "\nenter product name\n";
        getline(cin, prod_name);
        setname(prod_name);
        cout << "\nenter product price\n";
        cin >> price;
        setprice(price);
        cout << "\nentr quantity\n";
        cin >> quantity;
        setquantity(quantity);
    }
    void increaseProducts(int n){
        cin.ignore();
       
    
        
        setquantity(getquantity()+n);
    }

    void decreaseProducts(int n){
        cin.ignore();
        
        setquantity(getquantity()-n);
    }

    void displayProduct(){
        cout<<"\nproduct Name : "<<getname()<<endl;
        cout<<"\nPrice : "<<getprice()<<endl;
        cout<<"\nquantity : "<<getquantity()<<endl;
    }
};

class Order : public Product
{
private:
    int order_id, product_id, quantity;
    float price;
    string name, cust_name;

public:
    void setname(string n)
    {
        name = n;
    }
    string getname()
    {
        return name;
    }
    void setcust_name(string cn)
    {
        cust_name = cn;
    }
    string getcust_name()
    {
        return cust_name;
    }
    void setorder_id()
    {
        srand(time(0));
        order_id = 100 + (rand() % 90 + 1);
    }
    int getorder_id()
    {
        return order_id;
    }
    void setproduct_id(int p_id)
    {
        product_id = p_id;
    }
    int getproduct_id()
    {
        return product_id;
    }

    void setprice(float p)
    {
        price = p;
    }
    void setquantity(int q)
    {
        quantity = q;
    }

    float getprice()
    {
        return price;
    }
    int getquantity()
    {
        return quantity;
    }

    void addingorders(float p,string n,string cn,int q)
    {
        cin.ignore();
        
        
        setname(n);
       setcust_name(cn);
        setprice(p);
        
        setquantity(quantity);
    }
    void increaseorderProducts(float p,string n){
         cin.ignore();
        int quantity;
        
        setname(n);
       
        setprice(p);
        cout << "\nentr quantity\n";
        cin >> quantity;
        setquantity(getquantity()+quantity);
    }

    void decreaseorderProducts(float p,string n){
         cin.ignore();
        int quantity;
        
        setname(n);
       
        setprice(p);
        cout << "\nentr quantity\n";
        cin >> quantity;
        setquantity(getquantity()-quantity);
    }

    void displayorderProduct(){
        cout<<"\nproduct Name : "<<getname()<<endl;
        cout<<"\nPrice : "<<getprice()<<endl;
        cout<<"\nquantity : "<<getquantity()<<endl;
    }
};

int main()
{
    Admin admin;
    vector<Users> Customers;
    vector<Order> order;
    vector<Product> product;

    int n;
    while (true)
    {
        Product prod;
        Order ord;
        cout << "\nwelcome to e-commerce application\n";
        cout << "\n1. login/create \n\n2. Exit\n";
        cin >> n;
        if (n == 2)
            break;
        int m;
        cout << "\n3. Login\n\n4. Create New account\n";
        cin >> m;
        if (m == 3)
        {
            bool torf = false;
            cin.ignore();
            checklogin chk;
            if (chk.checkAdminloggedIn())
            {
                cout << "\nSuccessfully Admin Logged in\n";
                while(true){
                    cout << "\n1.Add Products\n2. view products\n3. All orders\n 4.back\n";
                
                    int ch;
                    cin >> ch;
                    if(ch==4)break;
                    switch (ch)
                    {
                    case 1:
                    {   
                        if (product.size() == 0)
                        {   cin.ignore();
                            prod.addingProducts();
                            product.push_back(prod);
                        }else{
                            cin.ignore();
                            string prod_name;
                            cout<<"\nenter prod name\n";
                            getline(cin, prod_name);
                            
                            for(auto &a:product){
                                if(a.getname()==prod_name){
                                    int m;
                                    cout<<"\n1. want to increase\n2. want to decrease\n";
                                    cin>>m;
                                    if(m==1){
                                        int quantity;
                                        cout << "\nentr quantity\n";
                                cin >> quantity;
                                    a.increaseProducts(quantity); 
                                    }
                                    else if (m==2)
                                    {int quantity;
                                    cout << "\nentr quantity\n";
                                cin >> quantity;
                                        a.decreaseProducts(quantity);
                                    }
                                    
                                }else{
                                    prod.addingProducts();
                                    product.push_back(prod);
                                }
                            }
                        }
                    }
                    break;
                    case 2:
                    {
                        cout<<"\n1.dispaly selected product\n2.dispaly all product\n";
                        int n;
                        cin>>n;
                        if(n==1){
                            cin.ignore();
                            cout<<"\nenter PRODUCT NAME\n";
                            string prod_name;
                            getline(cin,prod_name);
                            for(auto a:product){
                                if(a.getname()==prod_name){a.displayProduct();break;}
                            }
                        }
                        else if (n==2)
                        {
                        for(auto a:product){
                                a.displayProduct();
                            }
                        }
                        
                    

                    }
                    break;
                    case 3:
                    {
                        if(order.size()!=0){
                            for(auto a:order)a.displayorderProduct();
                        }
                    }
                    break;
                    default:
                    {
                        cout << "\nEnter wrong option\n";
                    }
                    }
                }
            }
            else
            {
                for (auto a : Customers)
                {
                    if (chk.checkCustmerloggedIn(a.getemail(), a.getpassword()))
                    {
                        torf = true;
                        cout << "\nSuccessfully LoggedIn " << a.getname();
                       while(true){
                        cout<<"\nview products\n";
                             for(auto &a:product){
                            a.displayProduct();
                        }
                        cout<<"\n1. add orders from products shown\n2.back\n";
                            int ch;
                            cin>>ch;
                            cin.ignore();
                            if(ch==2)break;

                            
                            if(ch==1)
                            {cout<<"\nAdd Item\n";
                            string p_d;
                            getline(cin,p_d);
                            for(auto &o:product){
                            if(o.getname() ==p_d){
                                int quantity;
                                cout << "\nentr quantity\n";
                                cin >> quantity;
                                ord.addingorders(o.getprice(),p_d,a.getname(),quantity);
                                order.push_back(ord);
                                o.decreaseProducts(quantity);
                                cout<<"\nOrder Confirm\n";
                            }else{
                                cout<<"\nCAnt find product\n";
                            }
                            }
                        }
                       }
                    }
                }
            }
            if (!chk.checkAdminloggedIn() && !torf)
                cout << "\nInvalid Credentials\n";
        }
        else if (m == 4)
        {
            cin.ignore();
            Users user;
            Customers.push_back(user);
        }
        else
        {
            cout << "\nYou hahe choose wrong options\n";
        }
    }
    return 0;
}