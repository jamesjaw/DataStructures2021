#include <iostream>
#include <string>
using namespace std;

class node{
public:
    node* next;
    node* pre;
    long long  x;
    long long  y;
    int val;
};

node* H = new node;
node* T = new node;

int cmp(node* o,node* n){
    if(o->y > n->y) return 0;
    else if(o->y == n->y){
        if(o->x > n->x) return 0;
        else if(o->x == n->x) return 87;
        else return 1;
    }
    else return 1;
}

void house(long long x,long long y){
    node* nn = new node;
    nn->x = x;
    nn->y = y;
    nn->val = 1;
    node* temp = H;
    while(cmp(temp,nn)==1){
        temp = temp->next;
    }
    if(cmp(temp,nn)==87){
        temp->val = 1;
    }
    else{
        nn->next = temp;
        nn->pre = temp->pre;
        temp->pre->next = nn;
        temp->pre = nn;
    }
    
}

void boob(long long x,long long y){
    node* temp = H->next;
    while(temp!=T){
        //if(temp->y > y) break;
        if(temp->x==x && temp->y==y-1){
            temp->val = 0;
        }
        else if(temp->x==x-1 && temp->y==y){
            temp->val = 0;
        }
        else if(temp->x==x && temp->y==y){
            temp->val = 0;
        }
        else if(temp->x==x+1 && temp->y==y){
            temp->val = 0;
        }
        else if(temp->x==x && temp->y==y+1){
            temp->val = 0;
        }

        temp = temp->next;
    }
}
void print(int oder){
    node* temp;
    if(oder==1){
        cout<<"PrintFront\n";
        temp = H->next;
        while(temp!=T){
            if(temp->val==1){
                cout<<"("<<temp->x<<","<<temp->y<<")"<<"\n";
            }
            temp = temp->next;
        }
    }
    else if(oder==0){
        cout<<"PrintEnd\n";
        temp = T->pre;
        while(temp!=H){
            if(temp->val==1){
                cout<<"("<<temp->x<<","<<temp->y<<")"<<"\n";
            }
            temp = temp->pre;
        }
    }
}

int main(){
    H->x = -10000000005; T->x = 10000000005;
    H->y = -10000000005; T->y = 10000000005;
    H->next = T;         T->next = H;
    H->pre = T;          T->pre = H;
    H->val = 0;          T->val = 0;
    long long n , x, y;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0]=='P'){
            if(s[5]=='E'){
                print(0);
            }
            else if(s[5]=='F'){
                print(1);
            }
        }
        else if(s[0]=='H'){
            cin>>x>>y;
            house(x, y);
        }
        else if(s[0]=='B'){
            cin>>x>>y;
            boob(x, y);
        }
    }
    return 0;
}
