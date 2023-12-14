#include <iostream>
#include <string>
using namespace std;

class Complex{
    int real,img;
    public:
        Complex(){
            real=0;
            img=0;
        }
        Complex operator +(Complex obj){
            Complex temp;
            temp.real=real+obj.real;
            temp.img=img+obj.img;
            return temp;
        }
        Complex operator *(Complex obj){
            Complex temp;
            temp.real=(real*obj.real)-(img*obj.img);
            temp.img=(real*obj.img)+(img*obj.real);
            return temp;
        }

        friend istream& operator>>(istream&,Complex&);
        friend ostream& operator <<(ostream&,Complex&);

        void display(string ch){
            cout<<"The "<<ch<<" number is "<<real<<"+"<<img<<"i";
        }

};

istream& operator >>(istream& in,Complex& obj){
    in>>obj.real;
    in>>obj.img;

    return in;
}

ostream& operator <<(ostream& out,Complex& obj){
    out<<obj.real<<"+"<<obj.img<<"i";    
    return out;
}

int main(){
    int r,i;
    int choice;
    Complex obj1,obj2,result;
    cout<<"Enter first number \n";
    cin>>obj1;
    cout<<"Enter second number \n";
    cin>>obj2;
    obj1.display("First");
    cout<<"\n";
    obj2.display("Second");
    result=obj1+obj2;
    cout<<"result : "<<result<<endl;
    result=obj1*obj2;
    cout<<"result : "<<result<<endl;
    return 0;
}