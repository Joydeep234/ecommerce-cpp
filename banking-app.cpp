#include<bits/stdc++.h>
using namespace std;

class Banking{
    private:
        string name,email,contact_no;
        int account_no;
        double amount;
        float min_balance;
    public:
        void setname(string newname){
            name= newname;
        }
        void setemail(string newemail){
            email= newemail;
        }
        void setcontact_no(string newcontact_no){
            contact_no= newcontact_no;
        }
        void setamount(double newamount){
            amount= newamount;
        }
        void setaccountNo(){
            srand(time(0));
            account_no = 10000+(rand()%9000+1);
            // cout<<account_no;
        }
        void setminBalance(double newminBalance){
            min_balance= newminBalance;
        }

        int getaccountNo(){
            return account_no;
        }
        string getname(){
            return name;
        }
        string getemail(){
            return email;
        }
        string getcontact_no(){
            return contact_no;
        }
        double getamount(){
            return amount;
        }
        float getminBalance(){
          return min_balance;
        }
        
        void createAccount(){
            string newname,newemail,newcontact_no;
            int newaccount_no;
            double newamount;
            float newmin_balance;
            cout<<"\nEnter your name => ";
            getline(cin,newname);
            setname(newname);
            cout<<"\nEnter your Contact_Number => ";
            cin>>newcontact_no;
            // if()
            setcontact_no(newcontact_no);
            cout<<"\nEnter your Email => ";
            cin>>newemail;
            setemail(newemail);
            cout<<"\nEnter Balance => ";
            cin>>newamount;
            setamount(newamount);
            cout<<"\nEnter Min_Balance => ";
            cin>>newmin_balance;
            setminBalance(newmin_balance);
            cout<<"\nAccount Created Successfully\n";
        }

        void displayAccount(){
            cout<<"\nyour Account\n";
            cout<<"NAME : "<<getname();
            cout<<"\nContact No : "<<getcontact_no();
            cout<<"\nEmail : "<<getemail();
            cout<<"\nAccount No : "<<getaccountNo();
            cout<<"\nbalance : "<<getamount();
            cout<<"\nMin Balance : "<<getminBalance();
            cout<<"\n\n";
        }
    void depositAmount(double amt){
        double amont_present = getamount();
        double updated_amt = amont_present+amt;
        setamount(updated_amt);
    }
    void withdrawMoney(double amt){
        double amont_present = getamount();
        double updated_amt = amont_present-amt;
        if(getminBalance()>updated_amt)cout<<"\n\nBalance is lower than Min Balance\n\n";
        if(updated_amt<0)cout<<"\n\nInsufficient Balance\n\n";
        else setamount(updated_amt);
    }

};

int main(){
    vector<Banking> bankDetails;
    cout<<"\nWelcome to the Bank \n\n";
    int n;
    while(true){
        Banking bank;
        bank.setaccountNo();
        cout<<"\nEnter your optons \n\n";
        cout<<"1. Create Account\n2. Deposit\n3. Withdraw\n4. Display Amount\n5. Exit\n";
        cin>>n;
        if(n==5)break;
        switch(n){
            case 1:
                {
                cout<<"your choice : 1\n";
                cin.ignore();
                bank.createAccount();
                bankDetails.push_back(bank);
                int n = bankDetails.size();
                bankDetails[n-1].displayAccount();
                }
                break;
            case 2:
                {
                cout<<"your choice : 2\n";
                double amt;
                int acc;
                cout<<"\nEnter Account Number : ";cin>>acc;
                for(auto &a: bankDetails){
                    if(a.getaccountNo()==acc){
                        cout<<"\nEnter Amount : ";cin>>amt;
                        a.depositAmount(amt);
                        a.displayAccount();
                    }else {
                        cout<<"\nBank Account not present\n";
                    }
                }
                
                }
                break;
            case 3:
                {
                    cout<<"your choice : 3\n";
                    double amt;
                    int acc;
                    cout<<"\nEnter Account Number : ";cin>>acc;
                    for(auto &a: bankDetails){
                        if(a.getaccountNo()==acc){
                            cout<<"\nEnter Amount to Withdraw: ";cin>>amt;
                            a.withdrawMoney(amt);
                            a.displayAccount();
                        }else {
                            cout<<"\nBank Account not present\n";
                        }
                    }
                }
                break;
            case 4:
                {
                    cout<<"your choice : 4\n";
                    int acc;
                    cout<<"\nEnter Account Number : ";cin>>acc;
                    for(auto &a: bankDetails){
                        if(a.getaccountNo()==acc){
                            a.displayAccount();
                        }else {
                            cout<<"\nBank Account not present\n";
                        }
                    }
                }
            break;
            default:
            {
                cout<<"\nSelect from options\n";
                break;
            }
        }
    }cout<<"\nLogging out from Banking App\n";
    return 0;
}