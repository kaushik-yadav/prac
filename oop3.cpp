#include <iostream>

using namespace std;
class publication 
{   public:
     float price;
     string name;
     publication()
     {
          name="none";
          price=0.0;
     }
     void getdata(string s)
     {
         cout<<"\n Enter the name of the"<<s<<":";
         cin>>name;
         bool flag=false;
         while(flag==false)
         {
             cout<<"\n Enter the price of the"<<s<<":";
             cin>>price;
            
            try
            {
                if(price<=0)
                throw price;
                else
                flag=true;
                
            }
            catch(float x)
            {
                price=0.0;
                cout<<"\n You have entered price is invalid ";
                cout<<"\n The price has set to "<<price;
                cout<<"\n Enter valid input";
            }
         }
         
     }
    
inline string getname()
{
    return name;
}
inline float getprice()
{
    return price;   
}

};
class book: public publication
{
   public:
  int pages;
  book()
  {
      pages=0;
  }
  void getpages()
     {
         
         bool flag=false;
         while(flag==false)
         {
             cout<<"\n Enter the no of pages";
             cin>>pages;
            
            try
            {
                if(pages<=0)
                throw pages;
                else
                flag=true;
                
            }
            catch(int x)
            {
                pages=0;
                cout<<"\n You have entered no of pages  is invalid ";
                cout<<"\n The no of pages  has set to "<<pages;
                cout<<"\n Enter valid input";
            }
         }
         
     }
     void display()
     { cout<<"\t\n book is Found";
       cout<<"\t\n Details of book";
       cout<<"\t\n Name of the Book"<<getname();
       cout<<"\t\n No of pages"<<pages;
       cout<<"\t\n The price is"<<getprice();
         
     }
     
  
};
class tape: public publication
{
  public:
  float time;
  tape()
  {
      time=0.0;
  }
  void gettime()
     {
        
         bool flag=false;
         while(flag==false)
         {
            cout<<"\n Enter the playing time of tape in mins";
            cin>>time;
            
            try
            {
                if(time<=0)
                throw time;
                else
                flag=true;
                
            }
            catch(float x)
            {
                time=0.0;
                cout<<"\n You have entered time is invalid ";
                cout<<"\n The time has set to "<<time;
                cout<<"\n Enter valid input";
            }
         }
         
     }
void display()
     { cout<<"\t\n Audio cassette is Found";
       cout<<"\t\n Details of Audio cassette";
       cout<<"\t\n Name of the Tape "<<getname();
       cout<<"\t\n Playing time"<<time<<"Mins";
       cout<<"\t\n The price is"<<getprice();
         
     }
    
};
int main()
{
  int choice;
  string n;
  book objb;
  tape objt;
  cout<<"\t\n  Welcome to inheritance Program";
  do
  {
       cout<<"\n Menu";
       cout<<"\t1.Insert a book\n\t2.Insert an audio cassette\n\t3.Display Book Details";
       cout<<"\n\t4.Display audio cassttee details\n\t5.Exit";
       cout<<"\t\n Enter the choice";
       cin>>choice;
       switch(choice)
       {    case 1:  objb.getdata("book");
                     objb.getpages();
                     cout<<"\t\n book is being searched"<<endl;
                     break;
            case 2: objt.getdata("Audio Cassttee"); 
                    objt.gettime();
                    cout<<"\t\n Audio Cassttee is being searched"<<endl;
                    break;
            case 3: try
                    {   
                        if(objb.getname()=="NONE")
                           throw 3;
                        else
                        {
                          objb.display();
                          cout<<"\t\n We will hope that you purchase book again";
                        }
                    }
                    catch(int x)
                    {
                      cout<<"\t\n No book has been searched yet";
                      cout<<"\t\n choose correct option";
                    }
                    break;
            case 4: try
                    {   
                        if(objt.getname()=="NONE")
                           throw 3;
                        else
                        {
                          objt.display();
                          cout<<"\t\n We will hope that you purchase audio Cassttee again";
                        }
                    }
                    catch(int x)
                    {
                      cout<<"\t\n No audio cassette has been searched yet";
                      cout<<"\t\n choose correct option";
                    }
                    break;
            case 5: cout<<"\t\n ..........VISIT AGAIN..........";
                    break;
        
            }
       
      
    }while(choice!=5);
  cout<<"\t\n End of the program";
  cout<<"\t\n Thnak you";

    return 0;
}