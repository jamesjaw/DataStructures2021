#include <iostream>

using namespace std;

class node{
public:
    node* up = nullptr;
    node* down = nullptr;
    node* right = nullptr;
    node* left = nullptr;
    int used;
};

node* root = nullptr;
node* eexx = nullptr;

node* ch[100005];
int map[100005];

int cal(node* root,int step){
    if(root == eexx){
        cout<<step<<"\n";
        return 1;
    }
    if((root->down==nullptr||root->down->used==1)&&(root->up==nullptr||root->up->used==1)&&(root->left==nullptr||root->left->used==1)&&(root->right==nullptr||root->right->used==1)){
        //cout<<"cant find";
        return 0;
    }
    if(root->up!=nullptr&&root->up->used==0){
        //cout<<"up\n";
        root->up->used = 1;
        cal(root->up,step+1);
    }
    if(root->down!=nullptr&&root->down->used==0){
        //cout<<"down\n";
        root->down->used = 1;
        cal(root->down,step+1);
    }
    if(root->left!=nullptr&&root->left->used==0){
        //cout<<"left\n";
        root->left->used = 1;
        cal(root->left,step+1);
    }
    if(root->right!=nullptr&&root->right->used==0){
        //cout<<"right\n";
        root->right->used = 1;
        cal(root->right,step+1);
    }
    return 1;
}


int main(){
    for(int i=0;i<100005;i++) ch[i] = nullptr;
    
    int row,col;
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>map[j];
            node* temp;
            if(map[j]==1){
                temp = new node;
                temp->used = 0;
                if(i==0 && j==0) root = temp;
                if(i==row-1 && j==col-1) eexx = temp;
                if(i-1>=0 && ch[j]!=nullptr){
                    temp->up = ch[j];
                    ch[j]->down = temp;
                }
                
                if(j-1>=0 && map[j-1]==1){
                    temp->left = ch[j-1];
                    ch[j-1]->right = temp;
                }
                
                ch[j] = temp;
            }
            else{
                ch[j] = nullptr;
            }
        }
    }
    
    if(eexx == nullptr){
        cout<<"0"<<"\n";
    }
    else{
        root->used = 1;
        if(cal(root,1)==0){
            cout<<"0"<<"\n";
        }
    }
    return 0;
}
