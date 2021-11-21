#include <bits/stdc++.h>
using namespace std;
struct node{
    int roll;
    string name;
    string dept;
    int marks;
    node* next;
}*head;
// Check Function to check if some record already exists or not
bool check(int x){
    if(head==NULL)//empty list
        return false;
    node *t=new node();
    t=head;
    while(t!=NULL){//Traversing the Linked List
        if(t->roll == x)
            return true;
        t = t->next;
    }
    return false;
}
//Insert record function
void Insert_Record(int roll, string name,string dept, int marks){
    if(check(roll)){//check(roll) is true if record already exists
        cout<<"Student with this record already exists"<<endl;
        return;
    }
    // Create new Node to Insert Record
    node *n = new node();
    n->roll = roll;
    n->name = name;
    n->dept = dept;
    n->marks = marks;
    n->next = NULL;
    // Insert at Begin
    if(head == NULL || (head->roll >= n->roll)){
        n->next=head;
        head=n;
    }
    // Insert at middle or End
    else{
        node *s = head;
        while(s->next!=NULL && s->next->roll < n->roll){
            s = s->next;
        }
        n->next = s->next;
        s->next = n;
    }
    cout<<"Record Inserted Successfully"<<endl;
}
//Search student by roll no function
void Search_Record(int roll){
    if(!head){//head is NULL
        cout<<"No such record available"<<endl;
        return;
    }
    else{
        node *p = head;
        while(p){
            if(p->roll == roll){
                cout<<"Roll Number\t" << p->roll <<endl;
                cout<<"Name\t\t" << p->name <<endl;
                cout<<"Department\t" << p->dept <<endl;
                cout<<"Marks\t\t" << p->marks <<endl;
                return;
            }
            p = p->next;
        }
        if(p==NULL)
            cout<<"No such record available"<<endl;
    }
}
//Delete student record function
int Delete_Record(int roll){
    node *t = head;
    node *p = NULL;
    // Deletion at Begin
    if(t!=NULL && t->roll==roll){
        head=t->next;
        delete t;
        cout<<"Record deleted successfully"<<endl;
        return 0;
    }
    // Deletion Other than Begin
    while(t!=NULL && t->roll!=roll){
        p=t;
        t=t->next;
    }
    if(t==NULL){
        cout<<"Record doesn't exist"<<endl;
        return -1;
        p->next=t->next;
        delete t;
        cout<<"Record Deleted "<<endl;
        return 0;
    }
}
//Display record function
void Show_Record(){
    node *p = head;
    if(p==NULL){
        cout<<"No record available"<<endl;
    }
    else{
        cout<<"Roll No.\tName\tCourse\tMarks"<<endl;
        while(p!=NULL){
            cout<<p->roll<< "\t\t"<<p->name<<"\t"<< p->dept<<"\t"<< p->marks<<endl;
            p=p->next;
        }
    }
}
int main(){
    head = NULL;
    string name,course;
    int roll_no,marks;
    while(true){
        cout << "\n\t\t\tWelcome to Student Record Management System\n\n\tChoices:\n\t1.Create a new Record\n\t2.Delete a student record\n";
        cout<<"\t3.View a Student Record\n\t4.View all students record\n\t5.Exit\n";
        cout<<"\nEnter your choice: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter name of Student: ";
                    cin>>name;
                    cout<<"Enter roll number of Student: ";
                    cin>>roll_no;
                    cout<<"Enter course of Student: ";
                    cin>>course;
                    cout<<"Enter total marks of Student: ";
                    cin>>marks;
                    Insert_Record(roll_no, name, course, marks);
                break;
            case 2: cout<<"Enter Roll Number of Student whose record is to be deleted"<<endl;
                    cin>>roll_no;
                    Delete_Record(roll_no);
                break;
            case 3: cout<<"Enter Roll Number of Student whose record you want to Search"<<endl;
                    cin>>roll_no;
                    Search_Record(roll_no);
                break;
            case 4: Show_Record();
                break;
            case 5: exit(0);
                break;
            default: cout<<"Invalid choice... Try Again\n";
        }
    }
    return 0;
}
