#include <iostream>
#include <fstream>
#include <algorithm>

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
bool cmp(const student &s1,const student &s2){
    return s1.avg>s2.avg;
}
using namespace std;
void print(){
    int begin;
    for(begin=0;begin<46;begin++){
        cout<<"*";
    }
}
void print1(){
    int i;
   for(i=0;i<46;i++){
       cout<<"*";
    }
    cout<<endl;
    for(i=0;i<46;i++)
        cout<<"*";
}
int main()
{
    int number; int begin;
    ifstream folder1("/Users/s20181102929/Desktop/比赛打分表/参赛人数.txt");
    folder1>>number;
    print();
    cout<<endl;
    cout<<"本次参赛的选手共有 "<<number<<"名"<<"!"<<endl;
    for(begin=0;begin<46;begin++){
        cout<<"*";
    }
    cout<<endl;
    cout<<"他们的详细比赛成绩我已经放到了本地比赛打分文件夹下！"<<endl<<endl;
    cout<<"如果您想浏览比赛结果，请到本地文件夹下查看"<<endl<<endl;
    cout<<"下面将为你呈现本次比赛中的一些基本信息："<<endl;
    for(begin=0;begin<46;begin++){
        cout<<"*";
    }
    cout<<endl<<endl;
    student players[number];
    ifstream folder2("/Users/s20181102929/Desktop/比赛打分表/学生的基本信息.txt");
    for(begin=0;begin<number;begin++){
        folder2>>players[begin].num>>players[begin].academy>>players[begin].name;
    }
    ifstream folder4("/Users/s20181102929/Desktop/比赛打分表/裁判打分.txt");
    for(begin=0;begin<number;begin++){
 folder4>>players[begin].score1>>players[begin].score2>>players[begin].score3>>players[begin].score4>>players[begin].score5>>players[begin].score6>>players[begin].score7;
    }
    cout<<"各位裁判的对选手的打分如下： "<<endl;
    for(begin=0;begin<number;begin++){
        cout<<begin+1<<"号选手的得分为：";
        cout<<players[begin].score1<<" " <<players[begin].score2<<" "<<players[begin].score3<<" "<<players[begin].score4<<" "<<players[begin].score5<<" "<<players[begin].score6<<" "<<players[begin].score7<<endl<<endl;
    }
    print();
    cout<<endl;
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
        for(int middlechange=0;middlechange<number;middlechange++){
            if(players[middlechange].score1!=0){
                middle=players[middlechange].score1;
            }
            if(players[middlechange].score2!=0){
                middle=players[middlechange].score2;
            }
            if(players[middlechange].score3!=0){
                middle=players[middlechange].score3;
            }
            if(players[middlechange].score4!=0){
                middle=players[middlechange].score4;
            }
            if(players[middlechange].score5!=0){
                middle=players[middlechange].score5;
            }
            if(players[middlechange].score6!=0){
                middle=players[middlechange].score6;
            }
            if(players[middlechange].score7!=0){
                middle=players[middlechange].score7;
            }
        }
        for(int middlechange=0;middlechange<7;middlechange++){
            if(instead[middlechange]!=0)
                if(instead[middlechange]<middle){
                    middle=instead[middlechange];
                }
        }
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
    sort(players,players+number,cmp);
    
    ofstream folder3("/Users/s20181102929/Desktop/比赛打分表/比赛信息.txt");
    if(folder3.is_open()){
        for(int start=0;start<50;start++){
            folder3<<"*";
        }
        folder3<<endl;
        folder3<<"在经过精彩而又激烈的竞争后，本次比赛也拉下帷幕"<<endl<<endl<<"各位选手也在本次比赛中取得了优异的成绩！！！！"<<endl<<endl<<endl;
        folder3<<"本次的比赛结果如下："<<endl<<endl;
        folder3<<"下面由我来给大家揭晓："<<endl<<endl<<endl<<endl;
        for(begin=0;begin<number;begin++){
            folder3<<"获得本次比赛第"<<begin+1<<"名的是："<<endl;
            folder3<<"他是来自:"<<"     "<<players[begin].academy<<"       "<<"学号为："<<"  "<<players[begin].num<<"     "<<" 的"<<players[begin].name<<"同学"<<endl;
            folder3<<"去掉一个最高分去掉一个最低分他的最后得分为："<<endl<<endl<<players[begin].avg<<endl<<endl;
            if(begin==0){
                folder3<<"希望他能再接再厉！祝贺他本次取得好成绩！"<<endl;
            }
            else{
                folder3<<"希望他能在下次的比赛中取得更加优异的成绩！"<<endl;
            }
            folder3<<"感谢他的参与！"<<endl<<endl<<endl;
            folder3<<endl;
        }
        for(int start=0;start<50;start++){
            folder3<<"*";
        }
        folder3.close();
    }
    return 0;
}
