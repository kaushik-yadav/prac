#include <iostream>
#include <map>
using namespace std;
class Map{
    string name;
    float population;
    public:
        Map(){
            name="None";
            population=0.0;
        }
        void accept(){
            cout<<"\nEnter name : ";
            cin>>name;
            cout<<"\npopulation : ";
            cin>>population;
        }
        void display(map<string,float>::iterator it,int x){
            cout<<"\nRecord "<<x+1<<endl;
            cout<<"\nName of state : "<<it->first;
            cout<<"\nPopulation : "<<it->second<<" crores";
        }
        inline string getname(){
            return name;
        }
        inline float getpop(){
            return population;
        }

};

int main(){
    int i,ch;
    float population;
    string state;
    Map obj;
    map <string,float> mobj;
    map <string,float>::iterator it;
    do{
        cout<<"1)Enter data\n2)Delete data\n3)Display\n4)Exit\nEnter your choice : ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            obj.accept();
            state=obj.getname();
            population=obj.getpop();
            mobj.insert(pair<string,float>(state,population));
            break;
        case 2:
            if(!mobj.empty()){
                cout<<"\nEnter state name to be deleted : ";
                cin>>state;
                it=mobj.find(state);
                if(it!=mobj.end()){
                    mobj.erase(state);
                    cout<<"\nDeleted";
                }
                else
                    cout<<"\nRecord not found";
            }
            else
                cout<<"container is empty cannot delete";
            break;
        case 3:
            if(!mobj.empty()){
                cout<<"\nDisplaying data";
                for(i=0,it=mobj.begin();i<mobj.size(),it!=mobj.end();it++,i++){
                    obj.display(it,i);
                }
            }
            else{
                cout<<"Container empty nothing to show";
            }
            break;
        case 4:
            cout<<"\nExiting";
            break;
        default:
            break;
        }
    }while(ch!=4);
   
    return 0;
}