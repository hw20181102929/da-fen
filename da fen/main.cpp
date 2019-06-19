#include <iostream>
#include <fstream>
struct student{
    char num[10];
    char xueyuan[100];
    char name[30];
    int score1;
    int score2;
    int score3;
    int score4;
    int score5;
    int score6;
    int score7;
};
struct caipan{
    int num;
    int score;
};
using namespace std;
int main()
{
    int n;
    cin>>n;
    student b[n];
    
    ifstream a("/Users/s20181102929/Desktop/xue sheng xin xi.txt");
    int i;
    for(i=0;i<n;i++){
        a>>b[i].num>>b[i].xueyuan>>b[i].name>>b[i].score1>>b[i].score2>>b[i].score3>>b[i].score4>>b[i].score5>>b[i].score6>>b[i].score7;
    }
    for(i=0;i<n;i++){
        int t=b[i].score1;
        if(b[i].score2>t){
            t=b[i].score2;
        }
        if(b[i].score3>t){
            t=b[i].score3;
        }
        if(b[i].score4>t){
            t=b[i].score4;
        }
        if(b[i].score5>t){
            t=b[i].score5;
        }
        if(b[i].score6>t){
            t=b[i].score6;
        }
        if(b[i].score7>t){
            t=b[i].score7;
        }
        for(int j=0;j<n;j++){
            if(b[j].score2==t){
                b[j].score2=0;
            }
            if(b[j].score3==t){
                b[j].score3=0;
            }
            if(b[j].score4==t){
                b[j].score4=0;
            }
            if(b[j].score5==t){
                b[j].score5=0;
            }
            if(b[j].score6==t){
                b[j].score6=0;
            }
            if(b[j].score7==t){
                b[j].score7=0;
            }
        }
    }
    for(i=0;i<n;i++){
        int t=b[i].score1;
        if(b[i].score3<t){
            t=b[i].score3;
        }
        if(b[i].score4<t){
            t=b[i].score4;
        }
        if(b[i].score5<t){
            t=b[i].score5;
        }
        if(b[i].score6<t){
            t=b[i].score6;
        }
        if(b[i].score7<t){
            t=b[i].score7;
        }
        for(int j=0;j<n;j++){
            if(b[j].score1==t){
                b[j].score1=0;
            }
            if(b[j].score2==t){
                b[j].score2=0;
            }
            if(b[j].score3==t){
                b[j].score3=0;
            }
            if(b[j].score4==t){
                b[j].score4=0;
            }
            if(b[j].score5==t){
                b[j].score5=0;
            }
            if(b[j].score6==t){
                b[j].score6=0;
            }
            if(b[j].score7==t){
                b[j].score7=0;
            }
        }
    }
    ofstream c("/Users/s20181102929/Desktop/cucunxinxi.txt");
    if(c.is_open()){
        for(i=0;i<n;i++){
            c<<b[i].num<<" "<<b[i].xueyuan<<" "<<b[i].name<<" "<<b[i].score1<<" "<<b[i].score2<<" "<<b[i].score3<<" "<<b[i].score4<<" "<<b[i].score5<<" "<<b[i].score6<<" "<<b[i].score7<<endl;
        }
        c.close();
    }
    return 0;
}
