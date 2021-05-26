#include <iostream>
#include "13144.h"
#define max 2147483647
using namespace std;


void comb(int* &s ,int L,int R){
    int M = (L + R)/2;
    int* s1;
    int* s2;
    int s1_size = M - L + 1;
    int s2_size = R - M;
    s1 = new int[s1_size + 1];
    s2 = new int[s2_size + 1];
    for(int i=0;i<s1_size;i++){
        s1[i] = s[L + i];
    }
    for(int i=0;i<s2_size;i++){
        s2[i] = s[M + 1 + i];
    }
    s1[s1_size] = max;
    s2[s2_size] = max;
    int L_pos = 0;
    int R_pos = 0;
    for(int i=L;i<=R;i++){
        if(s1[L_pos] < s2[R_pos]){
            s[i] = s1[L_pos++];
        }
        else{
            s[i] = s2[R_pos++];
        }
    }
    delete [] s1;
    delete [] s2;
}

void mrge(int* &s,int L,int R){
    int M = (L + R)/2;
    if(L < R){
        mrge(s, L, M);
        mrge(s, M+1, R);
        comb(s, L, R);
    }
}


template < class T >
void mysort(T arr[], int l, int r){
    //do nothing because i used my function which is mreg.
    return;
}


void solve(){
        int size,ls,rs,cost;
        cin>>size>>ls>>rs>>cost;

        int* arr1 = new int[ls];
        int* arr2 = new int[rs];
        
        for(int i=0;i<ls;i++) cin>>arr1[i];
        for(int i=0;i<rs;i++) cin>>arr2[i];
        
        mrge(arr1, 0, ls - 1);
        mrge(arr2, 0, rs - 1);
        
        //step1 remove correrect pair
        int Lpos = 0;
        int Rpos = 0;
        int L_count = ls;
        int R_count = rs;
    /*
    cout<<"a1 = ";
    for(int i=0;i<L_count;i++) cout<<arr1[i]<<" ";
    cout<<"\n";
    cout<<"a2 = ";
    for(int i=0;i<R_count;i++) cout<<arr2[i]<<" ";
    cout<<"\n";
    */
        while( Lpos != ls && Rpos != rs){
            if(arr1[Lpos] > arr2[Rpos]){
                Rpos++;
            }
            else if(arr1[Lpos] < arr2[Rpos]){
                Lpos++;
            }
            else if(arr1[Lpos] == arr2[Rpos]){
                //cout<<"zz\n";
                arr1[Lpos] = max;
                arr2[Rpos] = max;
                Lpos++;
                Rpos++;
                L_count--;
                R_count--;
                
            }
        }
    /*
    cout<<"a1 = ";
        for(int i=0;i<L_count;i++) cout<<arr1[i]<<" ";
        cout<<"\n";
        cout<<"a2 = ";
        for(int i=0;i<R_count;i++) cout<<arr2[i]<<" ";
        cout<<"\n";
    */
        mrge(arr1, 0, ls - 1);
        mrge(arr2, 0, rs - 1);
        //test
    
        //step2
        long long step = 0;
        int Lc = L_count;
        int Rc = R_count;
        if(L_count > R_count){
            for(int i=1;i<L_count;i++){
                if(Lc - 2 >= Rc){
                    if(arr1[i]==arr1[i-1]){
                        arr1[i] = max - i;
                        arr1[i-1] = max - i - 1;
                        i++;
                        Lc -= 2;
                        step++;
                    }
                }
                else break;
            }
        }
        else if(L_count < R_count){
            for(int i=1;i<R_count;i++){
                if(Rc - 2 >= Lc){
                    if(arr2[i]==arr2[i-1]){
                        arr2[i] = max - i;
                        arr2[i-1] = max - i - 1;
                        i++;
                        Rc -= 2;
                        step++;
                    }
                }
                else break;
            }
        }
        //step3
        if(Rc > Lc){
            step += (Rc - Lc)/2;
            step += (Rc + Lc)/2;
        }
        else if(Rc < Lc){
            step += (Lc - Rc)/2;
            step += (Lc + Rc)/2;
        }
        else if(Rc == Lc){
            step += Rc;
        }
        
        step *= cost;
        cout<<step<<"\n";
        
        delete [] arr1;
        delete [] arr2;
}


