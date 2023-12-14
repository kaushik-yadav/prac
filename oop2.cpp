#include <iostream>
#include <string>
using namespace std;

class Personal;
class Database{
    int roll_no;
    string lic,div,name,address,tel,dob,blood,class_name;
    public:
        static int count;
        Database(){
            name="ABC";
            roll_no=69;
            class_name="FE";
            div="A";
        }
        void accept(string name,string class_name,string div,int roll_no){
            count++;
            this->name=name;
            this->class_name=class_name;
            this->div=div;
            this->roll_no=roll_no;
        }
        inline void display(){
            cout<<"\nName : "<<name<<endl;
            cout<<"\nClass name : "<<class_name<<endl;
            cout<<"\nDiv : "<<div<<endl;
            cout<<"\nRoll no : "<<roll_no<<endl;
        }
        ~Database(){

        }
        static int show_count();
        friend class Personal;

};
int Database::count=0;
int Database::show_count()
{
    return count;
}
class Personal{
    public:
        void initialize(Database *ptr){
            ptr->dob="DD/MM//YYYY";
            ptr->address="XYZ";
            ptr->blood="O+ve";
            ptr->tel="1234567891";
            ptr->lic="123456";
        }
        void accept(Database*ptr){
            cout<<"\nEnter dob : ";
            cin>>ptr->dob;
            cout<<"\nEnter add : ";
            cin>>ptr->address;
            cout<<"\nEnter blood : ";
            cin>>ptr->blood;
            cout<<"\nEnter tel : ";
            cin>>ptr->tel;
            cout<<"\nEnter lic : ";
            cin>>ptr->lic;
        }

        void display(Database*ptr){
            cout<<"\nDob : "<<ptr->dob;
            cout<<"\nadd : "<<ptr->address;
            cout<<"\nblood : "<<ptr->blood;
            cout<<"\ntel : "<<ptr->tel;
            cout<<"\nlic : "<<ptr->lic;

        }
};

int main(){
    int i,n,choice,perno;
    string perclass,pername,perdiv;
    Database objdata;
    Database *ptr=NULL,*temp=NULL;
    Personal objper;
    do{
            cout<<"1)Enter records\n2)Display records\n3)Exit\nEnter yout choice : ";
            cin>>choice;
            switch (choice)
            {
            case 1:
                cout<<"How many records do you want to enter : ";
                cin>>n;
                ptr=new Database[n];
                for (temp=ptr,i=0;temp!=NULL,i<n;temp++,i++){
                    cout<<"\nEnter Data for student no. "<<i+1<<endl;
                    cout<<"\nName : ";
                    cin>>pername;
                    cout<<"\nClass name : ";
                    cin>>perclass;
                    cout<<"\nDiv : ";
                    cin>>perdiv;
                    cout<<"\nRoll no : ";
                    cin>>perno;
                    temp->accept(pername,perclass,perdiv,perno);
                    objper.initialize(temp);
                    objper.accept(temp);
                }
                
                break;
            case 2:
                cout<<"The database has total "<<Database::show_count()<<" records";
                for(temp=ptr,i=0;temp!=NULL,i<n;temp++,i++){
                    cout<<"\nDetails of student no. "<<i+1<<" : "<<endl;
                    temp->display();
                    cout<<"\nPersonal details : "<<endl;
                    objper.display(temp);
                }
                break;
            case 3:
                cout<<"\nExiting the program";
                break;
            default:
                cout<<"\nEnter a valid choice";
                break;
            }
    }while(choice!=3);
    return 0;
}