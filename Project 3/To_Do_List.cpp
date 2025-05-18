#include <iostream>
#include <fstream>
using namespace std;

class task{
    public:
        string task_name;
        string task_due_date;
        string task_status;
};

void addtask(){
    cout<<"Enter details of the task"<<endl;
    task t;
    cout<<"enter task name:";
    cin>>t.task_name;
    cout<<"enter task due date (YYYY-MM-DD):";
    cin>>t.task_due_date;
    cout<<"enter task status (completed/incomplete):";
    cin>>t.task_status;

    ofstream file("task.txt", ios::app); // Open file in append mode
    file<<" | Task "<<t.task_name<<" | Due date"<<t.task_due_date<<" | status "<<t.task_status<<endl;
    file.close();
    cout<<"Data saved to file successfully."<<endl;
}

void displaytask(){
    task t;
    cout<<"Task details:"<<endl;
    ifstream file("task.txt"); // Open file in read mode
    if(!file){
        cout<<"no task data found "<<endl;
        return;

    }

    while(file>>t.task_name>>t.task_due_date>>t.task_status){
        cout<<" | Task "<<t.task_name<<" | Due date"<<t.task_due_date<<" | status "<<t.task_status<<endl;
    }
    file.close();

}

void deletetask(){
    task t;
    ifstream tempfile("tempfile.txt", ios::app); // Open temporary file in append mode
    cout<<"enter the task name you want to delete:";
    cin>>t.task_name;
    ifstream file("task.txt");
    if(!file){
        cout<<"no task data found"<<endl;
        return;

    }
    while(file>>t.task_name>>t.task_due_date>>t.task_status){
        if(t.task_name==t.task_name){
            cout<<"task found"<<endl;
            cout<<"Task name:"<<t.task_name<<endl;
            cout<<"Task due date:"<<t.task_due_date<<endl;    
            cout<<"Task status:"<<t.task_status<<endl;
        }
        else{
            cout<<"task not found"<<endl;
        }
    }
    file.close();
    tempfile.close();
    remove("task.txt"); // Delete the original file)
    rename("tempfile.txt", "task.txt"); // Rename the temporary file to original file name
    cout<<"task deleted successfully."<<endl;
    
}

void changestatus(){
    task t;
    cout<<"Enter the task name to change status:";
    cin>>t.task_name;
    cout<<"enter the new status (completed/incomplete):";
    cin>>t.task_status;

    ifstream file("task.txt");
    if(!file){
        cout<<"no task data found"<<endl;
        return;
    }
    while(file>>t.task_name>>t.task_due_date>>t.task_status){
        if(t.task_name==t.task_name){
            cout<<"task found"<<endl;
            cout<<" | Task "<<t.task_name<<" | Due date"<<t.task_due_date<<" | status "<<t.task_status<<endl;
            t.task_status=t.task_status;
            cout<<"new task status:"<<t.task_status<<endl;
            cout<<"| Task "<<t.task_name<<" | Due date"<<t.task_due_date<<" | status "<<t.task_status<<endl;
            cout<<"task status changed successfully."<<endl;
        }

    }

    file.close();
}

int main(){
    int choice;
    cout<<"Welcome to the To Do List program"<<endl;
    cout<<"1. Add task"<<endl;
    cout<<"2. Display task"<<endl;
    cout<<"3. Delete task"<<endl;
    cout<<"4. Change task status"<<endl;
    cout<<"5. Exit"<<endl;
    
    while(true){
        cout<<"enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                addtask();
                break;
            case 2:
                displaytask();
                break;
            case 3:
                deletetask();
                break;
            case 4:
                changestatus();
                break;
            case 5:
                cout<<"Exiting the program."<<endl;
                return 0;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }

    }
}