#include <iostream>
#include <string>

using namespace std;

class node{
public:
    node* next;
    node* pre;
    long long x;
    int ox;
};

node* H = new node;
node* T = new node;
int cmp(node* ol, node* nw){
    if(ol->x < nw->x) return 1;
    else if(ol->x == nw->x) return 2;
    else return 3;
}

void inser(long long a){
    node* temp = H;
    while(temp->x < a){
        temp = temp->next;
    }
    if(temp->x==a) return;

        node* hi = new node;
        hi->x = a;
        hi->next = temp;
        hi->pre = temp->pre;
        temp->pre->next = hi;
        temp->pre = hi;
    
}
void boob(long long a,long long b){
    node* temp = H->next;
    while(temp!=T){
        if(temp->x>=a && temp->x<=b){
            node* f = temp;
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            temp = temp->next;
            delete f;
        }
        else
        temp = temp->next;
    }
}
void print(int oder){
    if(oder==1){
        node* temp = H->next;
        while(temp!=T){
            cout<<temp->x<<"\n";
            temp = temp->next;
        }
    }
    else{
        node* temp = T->pre;
        while(temp!=H){
            cout<<temp->x<<"\n";
            temp = temp->pre;
        }
    }
}

int main(){
    H->next = T;
    H->pre = NULL;
    H->x = -10000000005;
    T->next = NULL;
    T->pre = H;
    T->x = 10000000000;
    
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0]=='P'){
            if(s[5]=='F'){
                cout<<"PrintFront\n";
                print(1);
            }
            else if(s[5]=='E'){
                cout<<"PrintEnd\n";
                print(0);
            }
            
        }
        else if(s[0]=='H'){
            long long a;
            cin>>a;
            inser(a);
            
        }
        else if(s[0]=='B'){
            //算一下x範圍
            long long a,b;
            long long aa,bb;
            cin>>a>>b;
            aa = a - b;
            bb = a + b;
            boob(aa,bb);
        }
    }
    return 0;
}
