#include <iostream>
#include <fstream>
struct student{
    char num[10];
    char academy[100];
    char name[30];
    int score1;
    int score2;
    int score3;
    int score4;
    int score5;
    int score6;
    int score7;
    double avg;
};
using namespace std;
int main()
{
    int number;
    ifstream folder1("/Users/s20181102929/Desktop/比赛打分表/xue shen ren shu.txt");
    folder1>>number;
    cout<<"本次参赛的选手共有 "<<number<<"名"<<"!"<<endl;
    cout<<"他们的比赛成绩我已经放到了本地文件夹里！"<<endl;
    cout<<"请注意查收！"<<endl;
    student players[number];
    
    ifstream folder2("/Users/s20181102929/Desktop/比赛打分表/xue sheng xin xi.txt");
    int begin;
    for(begin=0;begin<number;begin++){
        folder2>>players[begin].num>>players[begin].academy>>players[begin].name>>players[begin].score1>>players[begin].score2>>players[begin].score3>>players[begin].score4>>players[begin].score5>>players[begin].score6>>players[begin].score7;
    }
    for(begin=0;begin<number;begin++){
        int instead[7];
        instead[0]=players[begin].score1;
        instead[1]=players[begin].score2;
        instead[2]=players[begin].score3;
        instead[3]=players[begin].score4;
        instead[4]=players[begin].score5;
        instead[5]=players[begin].score6;
        instead[6]=players[begin].score7;
        int middle=0;
        for(int j=0;j<7;j++){
            if(instead[j]>middle){
                middle=instead[j];
            }
        }
        //cout<<middle<<endl;
        
            if(players[begin].score1==middle){
                players[begin].score1=0;
            }
            if(players[begin].score2==middle){
                players[begin].score2=0;
            }
            if(players[begin].score3==middle){
                players[begin].score3=0;
            }
            if(players[begin].score4==middle){
                players[begin].score4=0;
            }
            if(players[begin].score5==middle){
                players[begin].score5=0;
            }
            if(players[begin].score6==middle){
                players[begin].score6=0;
            }
            if(players[begin].score7==middle){
                players[begin].score7=0;
            }
        }
    for(begin=0;begin<number;begin++){
        int instead[7];
        instead[0]=players[begin].score1;
        instead[1]=players[begin].score2;
        instead[2]=players[begin].score3;
        instead[3]=players[begin].score4;
        instead[4]=players[begin].score5;
        instead[5]=players[begin].score6;
        instead[6]=players[begin].score7;
        int middle;
        for(int j=0;j<number;j++){
            if(players[j].score1!=0){
                middle=players[j].score1;
            }
            if(players[j].score2!=0){
                middle=players[j].score2;
            }
            if(players[j].score3!=0){
               middle=players[j].score3;
            }
            if(players[j].score4!=0){
                middle=players[j].score4;
            }
            if(players[j].score5!=0){
                middle=players[j].score5;
            }
            if(players[j].score6!=0){
                middle=players[j].score6;
            }
            if(players[j].score7!=0){
                middle=players[j].score7;
            }
        }
        for(int j=0;j<7;j++){
            if(instead[j]!=0)
                if(instead[j]<middle){
                    middle=instead[j];
                }
        }
       // cout<<middle<<endl;
        if(players[begin].score1==middle){
            players[begin].score1=0;
        }
        if(players[begin].score2==middle){
            players[begin].score2=0;
        }
        if(players[begin].score3==middle){
           players[begin].score3=0;
        }
        if(players[begin].score4==middle){
            players[begin].score4=0;
        }
        if(players[begin].score5==middle){
            players[begin].score5=0;
        }
        if(players[begin].score6==middle){
            players[begin].score6=0;
        }
        if(players[begin].score7==middle){
            players[begin].score7=0;
        }
    }
    for(begin=0;begin<number;begin++){
        double h=0;
        h=players[begin].score1+players[begin].score2+players[begin].score3+players[begin].score4+players[begin].score5+players[begin].score6+players[begin].score7;
        h=1.0*h/5;
        players[begin].avg=h;
    }
    student pm;
    for(begin=0;begin<number-1;begin++){
        for(int j=0;j<number-1;j++){
            if(players[j].avg<players[j+1].avg){
                pm=players[j];
               players[j]=players[j+1];
                players[j+1]=pm;
            }
        }
    }
    ofstream folder3("/Users/s20181102929/Desktop/比赛打分表/比赛结果.txt");
    if(folder3.is_open()){
         folder3<<"本次的比赛结果如下："<<endl;
        folder3<<"下面由我来给大家揭晓："<<endl;
        for(begin=0;begin<number;begin++){
            folder3<<"获得本次比赛第"<<begin+1<<"名的是："<<endl;
            folder3<<"他是来自:"<<players[begin].academy<<" "<<"学号为："<<players[begin].num<<"的"<<" "<<" "<<players[begin].name<<"同学"<<endl;
            folder3<<"去掉一个最高分去掉一个最低分他的最后得分为："<<players[begin].avg<<endl;
            if(begin==0){
                folder3<<"希望他能再接再厉！祝贺他本次取得好成绩！"<<endl;
            }
            else{
                folder3<<"希望他能在下次的比赛中取得更加优异的成绩！"<<endl;
            }
            folder3<<"感谢他的参与！"<<endl;
            folder3<<endl;
        }
        folder3.close();
    }
    return 0;
}
