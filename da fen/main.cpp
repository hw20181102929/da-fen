#include <iostream>
#include <fstream>
#include <algorithm>

struct student{
    char num[10];//学号
    char academy[100];//学院
    char name[30];//姓名
    int score1;//裁判一的打分
    int score2;//裁判二的打分
    int score3;//裁判三的打分
    int score4;//裁判四的打分
    int score5;//裁判五的打分
    int score6;//裁判六的打分
    int score7;//c裁判七的打分
    double average;//学生的平均分
};
bool cmp(const student &stu1,const student &stu2){
    return stu1.average>stu2.average;
}//算法sort的结构体排序；
using namespace std;
void print(){
    int begin;
    for(begin=0;begin<46;begin++){
        cout<<"*";
    }
}//打印函数；
void print1(){
    int start;
   for(start=0;start<46;start++){
       cout<<"*";
    }
    cout<<endl;
    for(start=0;start<46;start++)
        cout<<"*";
}//打印函数；
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
    cout<<"下面将为你呈现本次比赛中的一些基本信息："<<endl;//在输出框输出基本信息
    for(begin=0;begin<46;begin++){
        cout<<"*";
    }
    cout<<endl<<endl;
    student players[number];
    ifstream folder2("/Users/s20181102929/Desktop/比赛打分表/学生的基本信息.txt");
    for(begin=0;begin<number;begin++){
        folder2>>players[begin].num>>players[begin].academy>>players[begin].name;
    }//从文本输入每个学生的基本信息；
    ifstream folder4("/Users/s20181102929/Desktop/比赛打分表/裁判打分.txt");
    for(begin=0;begin<number;begin++){
 folder4>>players[begin].score1>>players[begin].score2>>players[begin].score3>>players[begin].score4>>players[begin].score5>>players[begin].score6>>players[begin].score7;
    }//从文本输入每个学生的分数！；
    cout<<"各位裁判的对选手的打分如下： "<<endl;
    for(begin=0;begin<number;begin++){
        cout<<begin+1<<"号选手的得分为：";
        cout<<players[begin].score1<<" " <<players[begin].score2<<" "<<players[begin].score3<<" "<<players[begin].score4<<" "<<players[begin].score5<<" "<<players[begin].score6<<" "<<players[begin].score7<<endl<<endl;
    }//在屏幕输出每个裁判对学生的打分！；
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
        }//找最大值；
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
    }//找最小值；
    for(begin=0;begin<number;begin++){
        double sumscore=0;
        sumscore=players[begin].score1+players[begin].score2+players[begin].score3+players[begin].score4+players[begin].score5+players[begin].score6+players[begin].score7;
        sumscore=1.0*sumscore/5;
        players[begin].average=sumscore;
    }//求每个学生的平均成绩；
    sort(players,players+number,cmp);//根据平均分进行排序；
    ofstream folder3("/Users/s20181102929/Desktop/比赛打分表/比赛信息.txt");
    if(folder3.is_open()){//向文件夹里输入基本信息；
        for(int start=0;start<56;start++){
            folder3<<"*";
        }
        folder3<<endl;
        folder3<<"本次的比赛结果如下："<<endl<<endl;
        for(begin=0;begin<56;begin++){
            folder3<<"*";
        }
        folder3<<endl<<endl;
        for(begin=0;begin<number;begin++){
            folder3<<"获得本次比赛第"<<begin+1<<"名的是："<<endl;
            folder3<<"他是来自:"<<"     "<<players[begin].academy<<"       "<<"学号为："<<"  "<<players[begin].num<<"     "<<" 的"<<" "<<players[begin].name<<" "<<"同学"<<endl;
            folder3<<"他的最后得分为："<<endl<<endl<<players[begin].average<<endl<<endl;
            for(int start=0;start<56;start++){
                folder3<<"*";
            }
            folder3<<endl;
        }
            folder3.close();
    }
    return 0;
}
