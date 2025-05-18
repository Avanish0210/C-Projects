#include <iostream>
#include <fstream>
using namespace std;


class BankAccount{
    public:
        string Account_holder_name;
        int Account_number;
        float Account_balance;

};

void addAccount(){
    cout<<"Enter details of the account"<<endl;
    BankAccount b;
    cout<<"Enter account holder name:";
    cin>>b.Account_holder_name;
    cout<<"Enter account number:";
    cin>>b.Account_number;
    cout<<"Enter account balance:";
    cin>>b.Account_balance;
    ofstream file("Account.txt",ios::app); // Open file in append mode
    file<<b.Account_holder_name<<" "<<b.Account_number<<" "<<b.Account_balance<<endl; // Write data to file
    file.close();
    cout<<"Data saved to file successfully."<<endl;
}

void displayAccount(){
    ifstream file("Account.txt"); // Open file in read mode
    if(!file){
        cout<<"No account data found"<<endl;
        return;

    }

    BankAccount b;
    cout<<"Account details:"<<endl;
    while(file>>b.Account_holder_name>>b.Account_number>>b.Account_balance){
        cout<<"Account Holder Name:"<<b.Account_holder_name<<endl;
        cout<<"Account Number:"<<b.Account_number<<endl;
        cout<<"Account Balance:"<<b.Account_balance<<endl;

    }
    file.close();
    cout<<"End of account details."<<endl;
}

void serchAccount(){
    BankAccount b;
    cout<<"Enter thr account number to search:";
    cin>>b.Account_number;
    ifstream file("Account.txt");
    if(!file){
        cout<<"No account data found"<<endl;
        return;
    }

    while(file>>b.Account_holder_name>>b.Account_number>>b.Account_balance){
        if(b.Account_number==b.Account_number){
            cout<<"Account Holder Name:"<<b.Account_holder_name<<endl;
            cout<<"Account Number:"<<b.Account_number<<endl;
            cout<<"Account Balance:"<<b.Account_balance<<endl;
            break;
        }
    }
    file.close();

}

void deleteAccount(){
    BankAccount b;
    ofstream tempfile("temp.txt", ios::app); // Open temporary file in append mode
    cout<<"Enter the account number to delte";
    cin>>b.Account_number;
    ifstream file("Account.txt");
    if(!file){
        cout<<"No account data found"<<endl;
        return;
    }

    while(file>>b.Account_holder_name>>b.Account_number>>b.Account_balance){
        if(b.Account_number==b.Account_number){
            cout<<"account found"<<endl;
            cout<<"Account Holder Name:"<<b.Account_holder_name<<endl;  
            cout<<"Account Number:"<<b.Account_number<<endl;
            cout<<"Account Balance:"<<b.Account_balance<<endl;
            tempfile<<b.Account_holder_name<<" "<<b.Account_number<<" "<<b.Account_balance<<endl; // Write data to file
        }
        else{
            tempfile<<b.Account_holder_name<<" "<<b.Account_number<<" "<<b.Account_balance<<endl; // Write data to file
        }

    }
    file.close();
    tempfile.close();
    remove("Account.txt"); // Delete the original file
    rename("temp.txt", "Account.txt"); // Rename the temporary file to original file name
    cout<<"Account deleted successfully."<<endl;

}

void deposite(){
    BankAccount b;
    cout<<"Enter the coount number to deposite:";
    cin>>b.Account_number;
    cout<<"Enter the amount to deposite:";
    float amount;
    cin>>amount;
    ifstream file("Account.txt");
    if(!file){
        cout<<"No account data found"<<endl;
        return;
    }
    ofstream tempfile("temp.txt", ios::app); // Open temporary file in append mode
    while(file>>b.Account_holder_name>>b.Account_number>>b.Account_balance){
        if(b.Account_number==b.Account_number){
            cout<<"Account found"<<endl;
            cout<<"Account Holder Name:"<<b.Account_holder_name<<endl;
            cout<<"Account Number:"<<b.Account_number<<endl;    
            cout<<"Account Balance:"<<b.Account_balance<<endl;
            b.Account_balance=b.Account_balance+amount;
            cout<<"New Account Balance:"<<b.Account_balance<<endl;
            tempfile<<b.Account_holder_name<<" "<<b.Account_number<<" "<<b.Account_balance<<endl; // Write data to file

        }else{
            tempfile<<b.Account_holder_name<<" "<<b.Account_number<<" "<<b.Account_balance<<endl; // Write data to file
        }

    }
    file.close();
    tempfile.close();
    remove("Account.txt"); // Delete the original file
    rename("temp.txt", "Account.txt"); // Rename the temporary file to original file name
    cout<<"Amount deposited successfully."<<endl;
}

void withdraw(){
    BankAccount b;
    cout<<"Enter the account number to withdraw:";
    cin>>b.Account_number;
    cout<<"Enter the amount to withdraw:";
    float amount;
    cin>>amount;
    ifstream file("Account.txt");
    if(!file){
        cout<<"No account data found"<<endl;
        return;
    }
    ofstream tempfile("temp.txt", ios::app); // Open temporary file in append mode
    while(file>>b.Account_holder_name>>b.Account_number>>b.Account_balance){
        if(b.Account_number==b.Account_number){
            cout<<"Account found"<<endl;
            cout<<"Account Holder Name:"<<b.Account_holder_name<<endl;
            cout<<"Account Number:"<<b.Account_number<<endl;    
            cout<<"Account Balance:"<<b.Account_balance<<endl;
            b.Account_balance=b.Account_balance-amount;
            cout<<"New Account Balance:"<<b.Account_balance<<endl;
            tempfile<<b.Account_holder_name<<" "<<b.Account_number<<" "<<b.Account_balance<<endl; // Write data to file

        }else{
            tempfile<<b.Account_holder_name<<" "<<b.Account_number<<" "<<b.Account_balance<<endl; // Write data to file
        }

    }
    file.close();
    tempfile.close();
    remove("Account.txt"); // Delete the original file
    rename("temp.txt", "Account.txt"); // Rename the temporary file to original file name
    cout<<"Amount withdrawn successfully."<<endl;

}

int main(){
    int choice;
    cout<<"Welcome to the Banking System"<<endl;
    cout<<"1. Add Account"<<endl;   
    cout<<"2. Display Account"<<endl;
    cout<<"3. Search Account"<<endl;
    cout<<"4. Delete Account"<<endl;
    cout<<"5. Deposit Amount"<<endl;
    cout<<"6. Withdraw Amount"<<endl;
    cout<<"7. Exit"<<endl;
    while(true){
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
            addAccount();
            break;
            case 2:
            displayAccount();
            break;
            case 3:
            serchAccount();
            break;
            case 4:
            deleteAccount();
            break;
            case 5:
            deposite();
            break;
            case 6:
            withdraw();
            break;
            case 7:
            cout<<"Exiting the program."<<endl;
            return 0;
            default:
            cout<<"Invalid choice. Please try again."<<endl;
            break;

        }
    }
}