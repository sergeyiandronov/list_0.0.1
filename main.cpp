#include <iostream>
#include <sstream>
using namespace std;
struct node_t {
    int value;
    node_t * next= nullptr;
};



void add_to_list(node_t *&listfirst,node_t *&listlast,int valueadd,int &size){

    if (listlast== nullptr){
        listlast=new node_t;
        listlast->value=valueadd;
        listlast->next= nullptr;
        listfirst=listlast;
        size++;
        return;
    }
    listlast->next=new node_t;

    listlast->next->value=valueadd;
    listlast->next->next=nullptr;
    listlast=listlast->next;
    size++;


}
void deletefirst(node_t *&listfirst,node_t *&listlast,int &size){
    if(size==0){
        return;
    }
    node_t *nh=listfirst;
    listfirst=listfirst->next;
    if(listfirst== nullptr){
        listlast= nullptr;
    }
    delete(nh);
    size--;
}
void cout_list(node_t *listfirst,int size){
    for(int counter=0;counter<size;counter++){
        cout<<"+---+    ";
    }
    cout<<"\n";

    for(node_t *counter=listfirst;counter!= nullptr;counter=counter->next){
        cout<<"| "<<counter->value<<" |";
        if(counter->next!= nullptr){
            cout<<"--->";
        }
    }
    cout<<"\n";
    for(int counter=0;counter<size;counter++){
        cout<<"+---+    ";
    }
    cout<<"\n";

}
/*void reverse_list(node_t *&listfirst,node_t* &listlast,int size){
    for(node_t *counter=listlast->next;counter!= nullptr;counter=counter->next){

    }
}*/
int main() {
 node_t* listfirstptr= nullptr;
 node_t* listlastptr= nullptr;
 int size=0;
 char op;
    cin>>op;
 while(op!='q'){
     switch(op){
         case '+':
             int nw;
             cin>>nw;
             add_to_list(listfirstptr,listlastptr,nw,size);
             break;
         case '-':
             deletefirst(listfirstptr,listlastptr,size);
             break;
         case '=':
             cout_list(listfirstptr,size);
             break;
         case '/':
             break;

     }
     cin>>op;
 }



}








