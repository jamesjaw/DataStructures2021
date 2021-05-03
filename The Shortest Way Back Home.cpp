#include <iostream>

using namespace std;

class node{
public:
    node* top = nullptr;
    node* down = nullptr;
    node* right = nullptr;
    node* left = nullptr;
    int row;
    int col;
    int val;
    int used = 0;
};

long long minn = 21470000000;

void cal(node* root,long long sum){
    if((root->top==nullptr||root->top->used == 1) && (root->down==nullptr||root->down->used == 1) && (root->right==nullptr||root->right->used == 1) && (root->left==nullptr||root->left->used == 1)){
        //cout<<"final step\n";
        
        if(sum<minn) minn = sum;
        //cout<<"end at "<<sum<<"\n";
        return;
    }

    if( root->top!=nullptr && root->top->used==0 &&root->top->val!=-1){
        //cout<<"top\n";
        root->top->used = 1;
        if(root->top->val==-1)
            cal(root->top,sum + 999999999);
        else
            cal(root->top,sum + root->top->val);
    }
    if( root->down!=nullptr&&root->down->used==0  &&root->down->val!=-1){
        //cout<<"down\n";
        root->down->used = 1;
        if(root->down->val==-1)
            cal(root->down,sum + 999999999);
        else
            cal(root->down,sum + root->down->val);
    }
    if( root->right!=nullptr&& root->right->used==0 &&root->right->val!=-1){
        //cout<<"right\n";
        root->right->used = 1;
        if(root->right->val==-1)
            cal(root->right,sum + 999999999);
        else
            cal(root->right,sum + root->right->val);
    }
    if( root->left!=nullptr &&root->left->used==0  &&root->left->val!=-1){
        //cout<<"left\n";
        root->left->used = 1;
        if(root->left->val==-1)
            cal(root->left,sum + 999999999);
        else
            cal(root->left,sum + root->left->val);
    }
    return;
}

int map[100005];
node* fu[100005];
node* head;

int main(){
    int row;
    int col;
    cin>>row>>col;
    int rowpos;
    int colpos;
    cin>>colpos>>rowpos;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>map[j];
            if(map[j]!=0){
                node* temp = new node;
                temp->row = i;
                temp->col = j;
                temp->val = map[j];
                if(i-1>=0 && fu[j]!=nullptr){
                    temp->top = fu[j];
                    temp->top->down = temp;
                }
                
                fu[j] = temp;
                if(j-1>=0 && map[j-1]!=0){
                    temp->left = fu[j-1];
                    temp->left->right = temp;
                }
                if(i==rowpos && j==colpos){
                    //cout<<"find head row = "<<i<<" col = "<<j<<"\n";
                    head = temp;
                }
                
            }
            else{
                fu[j] = nullptr;
            }
        }
    }
    //cout<<head->val<<" "<< head->row<<" " << head->col<<" \n";
    head->used = 1;
    cal(head,head->val);
    cout<<minn<<"\n";
    
    return 0;
}
