#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
#define maxs 999999999;
class vex{
public:
    int step;
    int path;
};

vex map[105][105];
double cen[105] = {0};
stringstream ss;


void prp(int s,int t){
    for(int i=s ; i!=t ; i=map[i][t].path){
        cout<<i;
    }
    cout<<t;
}

void prp2(int s,int t){
    cout<<s;
    if(s!=t){
        cout<<"->";
        prp2(map[s][t].path, t);
    }
}

int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            if(i==j){
                map[i][j].step = maxs;
            }
            else{
                if(temp == 0){
                    map[i][j].step = maxs;
                }
                else{
                    map[i][j].step = temp;
                }
            }
            map[i][j].path = j;
        }
    }
    //test
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //if(map[i][j].step==999999999) cout<<"X ";
            //else
                cout<<map[i][j].path<<" ";
        }
        cout<<"\n";
    }
    */
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    //cout<<"k = "<<k<<" i = "<<i<<" j = "<<j<<"\n";
                    if(map[i][k].step + map[k][j].step == map[i][j].step){
                        if(map[i][k].path < map[i][j].path){
                            map[i][j].path = map[i][k].path;
                        }
                    }
                    else if(map[i][k].step + map[k][j].step < map[i][j].step){
                        map[i][j].path = map[i][k].path;
                        map[i][j].step = map[i][k].step + map[k][j].step;
                    }
                }
            }
        }
        /*
        cout<<"k = "<<k<<"\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<map[i][j].path<<" ";
            }
            cout<<"\n";
         
        }
         */
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j].step != 0 && map[i][j].step!= 999999999 && i!=j){
                cout<<"Path("<<i<<","<<j<<"):";
                prp2(i,j);
                cout<<"\n";
                cout<<"Difficulty:"<<map[i][j].step<<"\n";
                cen[j] += (double)1/map[i][j].step;
                
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<"Centrality("<<i<<"):";
        cout<<fixed<<setprecision(3)<<cen[i];
        cout<<"\n";
    }
    
    //test
    /*
    cout<<"path\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j].path<<" ";
        }
        cout<<"\n";
    }
    cout<<"step\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j].step<<" ";
        }
        cout<<"\n";
    }
     */
    /*
    5
    0 4 0 9 0
    8 0 1 5 0
    4 2 0 0 9
    1 0 0 0 0
    7 8 7 5 0
    */
    return 0;
}
