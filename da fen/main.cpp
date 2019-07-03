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
    double average;
};
bool cmp(const student &stu1,const student &stu2){
    return stu1.average>stu2.average;
}
using namespace std;
void print(){
    int i;
    for(i=0;i<46;i++){
        cout<<"*";
    }
}
void print1(){
    int i;
    for(i=0;i<46;i++)
    cout<<"*";
    cout<<endl;
    for(i=0;i<46;i++)
    cout<<"*";
}
int main()
{
    int number; int i;
    ifstream folder1("/Users/s20181102929/Desktop/比赛打分表/参赛人数.txt");
    folder1>>number;
    print();
    cout<<endl;
    cout<<"本次参赛的选手共有 "<<number<<"名"<<"!"<<endl;
    for(i=0;i<46;i++){
        cout<<"*";
    }
    cout<<endl;
    cout<<"他们的详细比赛成绩我已经放到了本地比赛打分文件夹下！"<<endl<<endl;
    cout<<"如果您想浏览比赛结果，请到本地文件夹下查看"<<endl<<endl;
    cout<<"下面将为你呈现本次比赛中的一些基本信息："<<endl;
    for(i=0;i<46;i++){
        cout<<"*";
    }
    cout<<endl<<endl;
    student players[number];
    ifstream folder2("/Users/s20181102929/Desktop/比赛打分表/学生的基本信息.txt");
    for(i=0;i<number;i++){
        folder2>>players[i].num>>players[i].academy>>players[i].name;
    }
    ifstream folder4("/Users/s20181102929/Desktop/比赛打分表/裁判打分.txt");
    for(i=0;i<number;i++){
 folder4>>players[i].score1>>players[i].score2>>players[i].score3>>players[i].score4>>players[i].score5>>players[i].score6>>players[i].score7;
    }
    cout<<"各位裁判的对选手的打分如下： "<<endl;
    for(i=0;i<number;i++){
        cout<<i+1<<"号选手的得分为：";
        cout<<players[i].score1<<" " <<players[i].score2<<" "<<players[i].score3<<" "<<players[i].score4<<" "<<players[i].score5<<" "<<players[i].score6<<" "<<players[i].score7<<endl<<endl;
    }
    print();
    cout<<endl;
    for(i=0;i<number;i++){
        int instead[7];
        instead[0]=players[i].score1;
        instead[1]=players[i].score2;
        instead[2]=players[i].score3;
        instead[3]=players[i].score4;
        instead[4]=players[i].score5;
        instead[5]=players[i].score6;
        instead[6]=players[i].score7;
        int middle=0;
        for(int j=0;j<7;j++){
            if(instead[j]>middle){
                middle=instead[j];
            }
        }
        if(players[i].score1==middle){
            players[i].score1=0;
        }
        if(players[i].score2==middle){
            players[i].score2=0;
        }
        if(players[i].score3==middle){
            players[i].score3=0;
        }
        if(players[i].score4==middle){
            players[i].score4=0;
        }
        if(players[i].score5==middle){
            players[i].score5=0;
        }
        if(players[i].score6==middle){
            players[i].score6=0;
        }
        if(players[i].score7==middle){
            players[i].score7=0;
        }
    }
    for(i=0;i<number;i++){
        int instead[7];
        instead[0]=players[i].score1;
        instead[1]=players[i].score2;
        instead[2]=players[i].score3;
        instead[3]=players[i].score4;
        instead[4]=players[i].score5;
        instead[5]=players[i].score6;
        instead[6]=players[i].score7;
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
        if(players[i].score1==middle){
            players[i].score1=0;
        }
        if(players[i].score2==middle){
            players[i].score2=0;
        }
        if(players[i].score3==middle){
            players[i].score3=0;
        }
        if(players[i].score4==middle){
            players[i].score4=0;
        }
        if(players[i].score5==middle){
            players[i].score5=0;
        }
        if(players[i].score6==middle){
            players[i].score6=0;
        }
        if(players[i].score7==middle){
            players[i].score7=0;
        }
    }
    for(i=0;i<number;i++){
        double sumscore=0;
        sumscore=players[i].score1+players[i].score2+players[i].score3+players[i].score4+players[i].score5+players[i].score6+players[i].score7;
        sumscore=1.0*sumscore/5;
        players[i].average=sumscore;
    }
    sort(players,players+number,cmp);
    ofstream folder3("/Users/s20181102929/Desktop/比赛打分表/比赛信息.txt");
    if(folder3.is_open()){
        for(int start=0;start<56;start++){
            folder3<<"*";
        }
        folder3<<endl;
        folder3<<"本次的比赛结果如下："<<endl<<endl;
        for(i=0;i<56;i++){
            folder3<<"*";
        }
        folder3<<endl<<endl;
        for(i=0;i<number;i++){
            folder3<<"获得本次比赛第"<<i+1<<"名的是："<<endl;
            folder3<<"他是来自:"<<"     "<<players[i].academy<<"       "<<"学号为："<<"  "<<players[i].num<<"     "<<" 的"<<" "<<players[i].name<<" "<<"同学"<<endl;
            folder3<<"他的最后得分为："<<endl<<endl<<players[i].average<<endl<<endl;
            for(int start=0;start<56;start++){
                folder3<<"*";
            }
            folder3<<endl;
        }
            folder3.close();
    }
    return 0;
}
