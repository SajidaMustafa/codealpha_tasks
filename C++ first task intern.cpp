#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
using namespace std;

class TodoItem {
public:
    int id;
    string task;
    bool isCompleted;
    
    TodoItem(const string &t, int id) : id(id), task(t), isCompleted(false) {}
};

class TodoList {
private:
    vector<TodoItem> items;

public:
    void addTask(const string &task) {
        int itemSize = items.size() + 1;
        TodoItem newItem(task, itemSize);
        items.push_back(newItem);
        cout << "Task named as " << task << " has been added...!" << endl;
    }
    void ChangeTodoItemStatus(int id,bool status){
 		if (items.empty()) {
            cout << "No task added yet." << endl;
        } else if (id > 0 && id <= items.size()) {
            items[id - 1].isCompleted = status;
            cout << "Status of task with Sr Number " << id << " has been changed to " << (status ? "Completed." : "Pending.") << endl;
        } else {
            cout << "No task added with this Sr Number: " << id << endl;
        }
	}

	void displayTasks() {

        if(!items.empty())
		{
        int size = items.size();
		cout << "_________________________________________________________________________" << endl;
        cout << "| " << setw(10) << "Sr Number" << " | " << setw(23) << "Task" << " | " << setw(30) << "Status" << " |" << endl;
        cout << "|____________|_________________________|________________________________|" << endl<<endl;
        for (size_t i = 0; i < size; i++) {
            cout << setw(10) << items[i].id << setw(30) << items[i].task << setw(30);
            if (items[i].isCompleted) {
                cout << "Completed";
            } else {
                cout << "Pending";
            }
            cout << endl;
        }
cout << "_______________________________________________________________" << endl;        	
		}
		else{
    cout << "No task added yet" << endl;	
		}

    }
    bool isTodoListEmpty(){
    	if(items.size()<=0){
    		return true;
		}
		else{
			return false;
		}
	}
	bool checkSrNumberPresentInList(int id){
		int total=items.size();
		if(id<=total){
    		return true;
		}
		else{
			return false;
		}
	}
	void deleteTask(int id) {
        if (id > 0 && id <= items.size()) {
            items.erase(items.begin() + id - 1);
            cout << "Task with Sr Number " << id << " has been deleted." << endl;
            this->displayTasks();
            
        } else {
            cout << "No task found with Sr Number: " << id << ". Nothing deleted." << endl;
        }
    }
    void updateTask(int id, string &newTask) {
        if (id > 0 && id <= items.size()) {
            items[id - 1].task = newTask;
            cout << "Task with Sr Number " << id << " has been updated to: " << newTask << endl;
            this->displayTasks();
        } else {
            cout << "No task found with Sr Number: " << id << ". Nothing updated." << endl;
        }
    }


};

int main() {
    TodoList todoList;
    int choice,id,newStatus,newStatusChoice;
    string task,updateTask;
    bool run=true;
    while(run!=false){
    	cout<<"Press 1 to Add Todo Task."<<endl;
    	cout<<"Press 2 to Display Todo Task List."<<endl;
		cout<<"Press 3 to Change Todo Task Status."<<endl;
		cout<<"Press 4 to Delete Task."<<endl;
		cout<<"Press 5 to Update Task."<<endl;
		cout<<"Press 6 to exit."<<endl;
		cout << "_________________________________________________________________________" << endl;  
		cout<<"Enter your choice: ";
		cin>>choice;
		if(choice==1){
			cout<<"Enter your task : ";
			cin>>task;
			todoList.addTask(task);
			todoList.displayTasks();
		}
		else if(choice==2){
			    todoList.displayTasks();
		}
else if(choice==3){
if(todoList.isTodoListEmpty()){
cout << "No task added yet" << endl;		
			}
			else{
cout<<"Enter Sr Number: ";
				cin>>id;
				if(id>0){
if(todoList.checkSrNumberPresentInList(id)){
	cout<<"Enter 1 to mark task as Completed."<<endl;
	cout<<"Enter 2 to mark task as Pending."<<endl;
	cout<<"Enter your choice: ";
		cin>>newStatusChoice;
		if(newStatusChoice==1){
	todoList.ChangeTodoItemStatus(id,true);
	todoList.displayTasks();
					}
else if(newStatusChoice==2){
	todoList.ChangeTodoItemStatus(id,false);
	    todoList.displayTasks();							
			}
			else{
	cout<<"You entered a wrong choice...!"<<endl;	
					}						
	}
					else{
	cout << "This Sr Number is not present in the task list." << endl;		
					}
					
				}
				else{
	cout << "Sr Number must be greater than 0." << endl;
				}
				
			}

		}
		else if(choice==4){
			if(todoList.isTodoListEmpty()){
	cout << "No task added yet" << endl;		
			}
			else{
				cout<<"Enter Sr Number: ";
				cin>>id;
				if(id>0){
	if(todoList.checkSrNumberPresentInList(id)){
		todoList.deleteTask(id);			
		}
			else{
	cout << "This Sr Number is not present in the task list." << endl;		
					}
					
				}
				else{
	cout << "Sr Number must be greater than 0." << endl;
				}
				
			}
		}
		else if(choice==5){
			if(todoList.isTodoListEmpty()){
		cout << "No task added yet" << endl;		
			}
			else{
				cout<<"Enter Sr Number: ";
				cin>>id;
				if(id>0){
		if(todoList.checkSrNumberPresentInList(id)){
	cout << "Enter the new task description: ";
	cin>>updateTask;
	todoList.updateTask(id,updateTask);			
					}
					else{
	cout << "This Sr Number is not present in the task list." << endl;		
					}
					
				}
				else{
	cout << "Sr Number must be greater than 0." << endl;
				}
				
			}
		}      	
		else if(choice==6){
			run=false;
			break;
		}  
		else{
	cout<<"You entered a wrong choice...!"<<endl;
		}  

	}

    return 0;
}
