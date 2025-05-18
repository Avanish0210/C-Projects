#include <iostream> 
#include <fstream>
using namespace std;

class student {
    public:
        int roll_no;
        string name;
        float marks; 
};


void addstudents(){
    student s;
    cout<<"Enter details of student"<<endl;
    cout<<"Enter roll number:";
            cin>>s.roll_no;
            cout<<"Enter name:";
            cin >>s.name;
            cout<<"Enter marks:";
            cin>>s.marks;

    ofstream file("student.txt", ios::app);  // Open file in append mode
    file <<s.name <<" "<<s.roll_no<<" " <<s.marks<<"" <<endl; // Write data to file
    file.close();

    cout<<"Data saved to file successfully."<<endl;
}

void displaystudents(){
    
    ifstream file("student.txt"); // Open file in read mode
    if(!file){
        cout<<"No student data found"<<endl;
        return;
    }

    student s;
    cout<<"student details:"<<endl;
    while(file>>s.name>>s.roll_no>>s.marks){
        cout<<"Name:"<<s.name<<endl;
        cout<<"Roll No.:"<<s.roll_no<<endl;
        cout<<"Marks:"<<s.marks<<endl;
    }
    file.close();
    cout<<"End of student details."<<endl;
}

void deleteStudent(){
    student s;
    ofstream tempfile("temp.txt", ios::app); // Open temporary file in append mode
    cout<<"Enter the roll no of student:";
    cin>>s.roll_no;
    ifstream file("student.txt");
    if(!file){
        cout<<"No students data found"<<endl;
        return;
    }

    while(file>>s.name>>s.roll_no>>s.marks){
        if(s.roll_no==s.roll_no){
            cout<<"student found"<<endl;
            cout<<"Name:"<<s.name<<endl;
            cout<<"Roll No.:"<<s.roll_no<<endl;
            cout<<"Marks:"<<s.marks<<endl;
            tempfile<<s.name<<" "<<s.roll_no<<" " <<s.marks<<"" <<endl; // Write data to file
            
        }
    }
    file.close();
    tempfile.close();
    remove("student.txt"); // Remove the original file
    rename("temp.txt", "student.txt"); // Rename the temporary file to original file name
    cout<<"Student deleted successfully."<<endl;
    cout<<"Updated student details:"<<endl;
    
}   



int main(){
    student s;

    int choice;
    while(true){
        cout<<"Press 1 to add student"<<endl<<"Press 2 to view student"<<endl<<"Press 3 to exit"<<endl<<"Press 4 to delete student"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1: addstudents();
            break;

        case 2: displaystudents();
            break;
        case 3: cout<<"Exiting program."<<endl;
            break;

        case 4: deleteStudent();
            break;
        
    
        
        default:
            cout<<"Invalid button pressed";
            break;
            
        }
    }

}