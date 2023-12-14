#include<iostream>
#include <fstream>
using namespace std;

class Employee{
    string name,designation;
    int salary,id;
    public:
        Employee(){
            name="None";
            designation="None";
            salary=0;
            id=0;
        }
        void accept(int x){
            cout<<"Enter the details for employee "<<x+1<<" :"<<endl;
            cout<<"\nName : ";
            cin>>name;
            cout<<"\nDesgination : ";
            cin>>designation;
            cout<<"\nsalary : ";
            cin>>salary;
            cout<<"\nid : ";
            cin>>name;
        }

        void display(int x){
            cout<<"Details for employee "<<x+1<<" :"<<endl;
            cout<<"\nName : "<<name;
            cout<<"\nDesgination : "<<designation;
            cout<<"\nsalary : "<<salary;
            cout<<"\nid : "<<id;
        }
};

int main(){
    int ch,i,n;
    cout<<"Enter how many exmployees details to enter : ";
    cin>>n;
    Employee obj[n];
    ofstream fout;
    ifstream fin;
    do{
        cout<<"\n1)Enter data into file\n2)Read data from file\n3)Exit\nEnter your choice : ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            fout.open("employee.txt",ios::out);
            cout<<"\nWriting info\n";
            for(i=0;i<n;i++){
                obj[i].accept(i);
                fout.write((char*)&obj[i],sizeof(obj[i]));
            }
            fout.close();
            break;
        case 2:
            fin.open("employee.txt",ios::in);
            cout<<"\nReading data from file\n";
            for(i=0;i<n;i++){
                fin.read((char*)&obj[i],sizeof(obj[i]));
                obj[i].display(i);
                
            }
            fout.close();
            break;
        case 3:
            cout<<"\nExiting the program";
        default:
            break;
        }
    }while(ch!=3);
    return 0;
}