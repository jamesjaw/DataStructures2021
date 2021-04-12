#include "function.h"
#include <iostream>
#include <string>
BaseQueue<char> xxx[105];
BaseStack<string>  zzz;

template<class T>
BaseStack<T>::BaseStack(){
    _top = -1;
    capacity = 10005;
    _stack = new T[capacity];
}

template<class T>
BaseStack<T>::~BaseStack(){
    delete [] _stack;
}

template<class T>
bool BaseStack<T>::empty(){
    if(_top==-1) return true;
    else return false;
}

template<class T>
int BaseStack<T>::size(){
    return _top+1;
}

template<class T>
T& BaseStack<T>::top(){
    return _stack[_top];
}

template<class T>
void BaseStack<T>::push(const T& item){
    _stack[++_top] = item;
}

template<class T>
void BaseStack<T>::pop(){
    if(empty()==true) return;
    _top--;
}


template<class T>
BaseQueue<T>::BaseQueue(){
    _front = 0;
    _rear = 0;
    capacity = 10001;
    _queue = new T[capacity];
}

template<class T>
BaseQueue<T>::~BaseQueue(){
    delete [] _queue;
}

template<class T>
bool BaseQueue<T>::empty(){
    if(_front==_rear) return true;
    else return false;
}

template<class T>
int BaseQueue<T>::size(){
    if(_rear >= _front)
        return (_rear - _front);
    else
        return (capacity - _front + _rear);
}

template<class T>
T& BaseQueue<T>::front(){
    return _queue[(_front+1)%capacity];
}

template<class T>
void BaseQueue<T>::push(const T& item){
    if((_rear+1)%capacity == _front){
        //std::cout<<"dou";
        T* newq = new T[capacity*2];
        int f = _front;
        int s = size();
        for (int i=1;i<=s;i++) {
            newq[i] = _queue[++f%capacity];
        }
        
        _rear = BaseQueue<T>::size();
        _front = 0;
		capacity*=2;
        delete [] _queue;
        _queue = newq;
        
    }
    _rear = (_rear+1)%capacity;
    _queue[_rear] = item;
}

template<class T>
void BaseQueue<T>::pop(){
    if(empty()==true) return;
    _front = (_front+1)%capacity;
}


void insert(int L){
    
    int pos;
    string str;
    cin>>pos>>str;
    int len = (int)str.size();
    int max = -87;
    for(int i=pos;i<pos+len;i++){
        if(xxx[i].size()>max) max = xxx[i].size();
    }
    for(int i=pos;i<pos+len;i++){
        if(xxx[i].size()<max){
            int dif = max-xxx[i].size();
            for(int j=0;j<dif;j++){
                xxx[i].push('@');
            }
        }
    }
    for(int i=pos;i<pos+len;i++){
        xxx[i].push(str[i-pos]);
    }
}
string first_row(int L, bool print){
    cout<<"BOTTOM_ROW"<<"\n";
    for(int i=0;i<L;i++){
        if(xxx[i].empty()) cout<<"~";
        else{
            cout<<xxx[i].front();
        }
    }
    cout<<"\n";
    
    string wtf;
    return wtf;
}
void query(int L){
    string str;
    cin>>str;
    int len = (int)str.size();
    //cout<<"strlen is"<<len<<"\n";
    int flag = 0;
    int pos = 0;
    
    for(int i=0;i<105;i++){
        if(str[0]==(xxx[i].empty()==false? xxx[i].front():' ')){
            for(int j=0;j<len;j++){
                if(str[j]==(xxx[i+j].empty()==false? xxx[i+j].front():' ')) flag = 1;
                else{
                    flag = 0;
                    break;
                }
            }
        }
        
        if(flag==1){
            pos = i;
            break;
        }
    }
    
    if(flag==1){
        string an;
        for(int i=pos;i<pos+len;i++){
            an += xxx[i].front();
            xxx[i].pop();
        }
        zzz.push(an);
    }
}
void flush(){
    cout<<"FLUSH"<<"\n";
    while(zzz.size()!=0){
        cout<<zzz.top()<<"\n";
        zzz.pop();
    }
}
void reset(int L){

    for(int i=0;i<105;i++){
        while(xxx[i].size()!=0) xxx[i].pop();
    }
        
    while(zzz.size()!=0) zzz.pop();
    
    //cout<<"zzz size = "<<zzz.size()<<"\n";
    //cout<<"xxx size = "<<xxx[0].size()<<"\n";
}

