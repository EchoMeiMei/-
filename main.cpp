#include <iostream>
#include<fstream>
#include <string>
#include<cstdlib>
using namespace std;
const int COURSE=3;
static int Num=1;//充当数组角标
static int number=0;//学生人数

//*******************创建学生类
class Student
{
private:
    string StudentID;
    string Name;
    int Calculus;//定义高数成绩变量
    int enDrawing;//定义工图成绩变量
    int Physics;//定义物理成绩变量
    int Sum;
public:
    string getStudentID();
    string getName();
    int setCalculus(int calculus);
    int getCalculus();
    int setenDrawing(int endrawing);
    int getenDrawing();
    int setPhysics(int physics);
    int getPhysics();
    int getSum();//学生总分
    int getAverage();//学生平均分
    //typeIn（）函数录入学生信息
    void typeIn(string studentID,string name,int calculus,int endrawing,int physics);
    void Print();
    void Print1();
    void Print2();
    //sum()函数获取总分
    void sum(int Calculus,int enDrawing,int Physics);
    void upCalsum(int temp);//修改微积分成绩后的总分核算
    void upDrasum(int temp);//修改工图成绩后的总分核算
    void upPhysum(int temp);//修改物理成绩后的总分核算
};

//Student学生类的方法实现
string Student::getStudentID()
{
    return StudentID;
}
string Student::getName()
{
    return Name;
}
int Student::setCalculus(int calculus)
{
    Calculus=calculus;
    return Calculus;
}
int Student::getCalculus()
{
    return Calculus;
}
int Student::setenDrawing(int endrawing)
{
    enDrawing=endrawing;
    return enDrawing;
}
int Student::getenDrawing()
{
    return enDrawing;
}
int Student::setPhysics(int physics)
{
    Physics=physics;
    return Physics;
}
int Student::getPhysics()
{
    return Physics;
}
int Student::getSum()
{
    return Sum;
}
int Student::getAverage()
{
    return (Calculus+enDrawing+Physics)/3;
}
void Student::typeIn(string studentID,string name,int calculus,int endrawing,int physics)
{
    //将参数传递给学生对象
    StudentID=studentID;
    Name=name;
    Calculus=calculus;
    enDrawing=endrawing;
    Physics=physics;
}
void Student:: Print()
{

    cout<<"\t"<<StudentID<<"\t"<<Name<<"\t"<<Calculus<<"\t"<<enDrawing<<"\t"<<Physics<<"\t"<<Sum<<endl;
}
void Student:: Print1()
{
    cout<<"\t"<<StudentID<<"\t"<<Name<<"\t"<<Calculus<<"\t"<<enDrawing<<"\t"<<Physics<<"\t"<<getAverage()<<"\t"<<Sum<<endl;
}
void Student:: Print2()
{
    cout<<"\t"<<StudentID<<"\t"<<Name<<"\t"<<Sum<<"\t";
}
void Student::sum(int Calculus,int enDrawing,int Physics)
{
    Sum=Calculus+enDrawing+Physics;
}
void Student::upCalsum(int temp)
{
    Sum=temp+enDrawing+Physics;
}
void Student::upDrasum(int temp)
{
    Sum=Calculus+temp+Physics;
}
void Student::upPhysum(int temp)
{
    Sum=Calculus+enDrawing+temp;
}


//*******************创建学生成绩信息管理类
class studentManage
{
private:
    Student str[10001];//学生对象数组，设置1-10000的人数范围
    int num;
public:
    void typeIn();//录入学生信息
    void update();//修改学生信息
    void locate();//查找学生信息
    void analyze();//分析学生成绩
    int logOut()//退出程序
    {
        cout <<"欢迎下次使用学生成绩管理系统!"<<endl;
        return 0;
    }

};
//studentManage学生成绩信息管理类的实现
void studentManage::typeIn()
{
    //学生信息的录入
    string StudentID,Name;
    int Calculus,enDrawing,Physics;
    cout<<"请输入学生学号：";
    cin>>StudentID;
    cout<<"请输入学生姓名：";
    cin>>Name;
    cout<<"请输入学生高数成绩(0~100)：";
    cin>>Calculus;
    while(Calculus<0||Calculus>100)
    {
        cout<<"输入成绩不合法!"<<endl;
        cout<<"请输入学生高数成绩(0~100)：";
        cin>>Calculus;
    }
    cout<<"请输入学生工图成绩(0~100)：";
    cin>>enDrawing;
    while(enDrawing<0||enDrawing>100)
    {
        cout<<"输入成绩不合法!"<<endl;
        cout<<"请输入学生工图成绩(0~100)：";
        cin>>enDrawing;
    }
    cout<<"请输入学生物理成绩(0~100)：";
    cin>>Physics;
    while(Physics<0||Physics>100)
    {
        cout<<"输入成绩不合法!"<<endl;
        cout<<"请输入学生物理成绩(0~100)：";
        cin>>Physics;
    }

    //向typeIn和()sum()函数传递参数
    str[Num].typeIn(StudentID,Name,Calculus,enDrawing,Physics);
    str[Num].sum(Calculus,enDrawing,Physics);

    //创建文件对学生信息进行存储
    ofstream outfile("studentManage.dat",ios::out);
    if(outfile.fail())
    {
        cerr<<"未能打开文件studentManage.dat，存储失败！"<<endl;
    }

    for(int i=1; i<=number; i++)
    {
        outfile.write(reinterpret_cast<char*>(&str[i]),sizeof(str[i]));
        outfile.flush();
    }
    outfile.close();

    Num++;
    number++;
}
void studentManage:: update()
{
    string StudentID;
    int n,temp;
    cout<<"**************************************"<<endl;
    bool found=false;
THIS:
    cout<<"请输入需要修改成绩的学生学号: ";
    cin>>StudentID;
    for(int i=1; i<=number; i++)
    {
        if(StudentID.compare(str[i].getStudentID())==0)
        {
            //found=true;
            cout<<"**************************************"<<endl;
            cout<<"请输入需要修改的成绩序号："<<endl;
            cout<<"1.高数；2.工图；3.物理"<<endl;
            cin>>n;
            switch(n)
            {
            case 1://修改微积分成绩
                cout<<"**************************************"<<endl;
                cout<<"请输入修改后的高数成绩："<<endl;
                cin>>temp;
                while(temp<0||temp>100)
                {
                    cout<<"输入成绩不合法!"<<endl;
                    cout<<"请输入学生高数成绩(0~100)：";
                    cin>>temp;
                }

                str[i].setCalculus(temp);
                str[i].upCalsum(temp);
                found=true;
                break;
            case 2:
                cout<<"**************************************"<<endl;
                cout<<"请输入修改后的工图成绩："<<endl;
                cin>>temp;
                while(temp<0||temp>100)
                {
                    cout<<"输入成绩不合法!"<<endl;
                    cout<<"请输入学生工图成绩(0~100)：";
                    cin>>temp;
                }
                str[i].setenDrawing(temp);
                str[i].upDrasum(temp);
                found=true;
                break;
            case 3:
                cout<<"**************************************"<<endl;
                cout<<"请输入修改后的物理成绩："<<endl;
                cin>>temp;
                while(temp<0||temp>100)
                {
                    cout<<"输入成绩不合法!"<<endl;
                    cout<<"请输入学生物理成绩(0~100)：";
                    cin>>temp;
                }
                str[i].setPhysics(temp);
                str[i].upPhysum(temp);
                found=true;
                break;
            default:
                cout<<"输入序号有误！"<<endl;
                break;
            }
        }

    }
    if(found==false)
    {
        cout<<"您输入的学生学号不存在！"<<endl;
        cout<<"请重新输入！"<<endl;
        goto THIS;
    }
}
void studentManage::locate()
{
    string StudentID;
    string Name;
    int n;
    cout<<"**************************************"<<endl;
    cout<<"请输入您的需求序号：1.按学生学号查询成绩：2.按学生姓名查询成绩"<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
    {
        int i;
        bool found=false;
HERE:
        cout<<"请输入您想要查询的学生学号：";
        cin>>StudentID;
        for(i=1; i<=number; i++)
        {
            if(StudentID.compare(str[i].getStudentID())==0)
            {
                cout<<"\t学号\t"<<"姓名\t"<<"高数\t"<<"工图\t"<<"物理\t"<<"总分"<<endl;
                str[i].Print();
                found=true;
            }

        }
        if(found==false)
        {
            cout<<"您输入的学生学号不存在！"<<endl;
            cout<<"请重新输入！"<<endl;
            goto HERE;
        }
        break;
    }

    case 2:

    {
        int i;
        bool found=false;
        cout<<"请输入您想要查询的学生姓名：";
POSITION:
        cin>>Name;
        for(i=1; i<=number; i++)
        {
            if(Name.compare(str[i].getName())==0)
            {
                cout<<"\t学号\t"<<"姓名\t"<<"高数\t"<<"工图\t"<<"物理\t"<<"总分"<<endl;
                str[i].Print();
                found=true;
            }
        }
        if(found==false)
        {
            cout<<"您输入的学生姓名不存在！"<<endl;
            cout<<"请重新输入！"<<endl;
            goto POSITION;
        }
        break;
    }
    default:
        cout<<"输入序号有误！"<<endl;
        break;
    }

}
void studentManage::analyze()
{
    int n;
    cout<<"**************************************"<<endl;
    cout<<"请输入您想要分析的学生成绩数据序号："<<endl;
    cout<<"1.每门课程的平均分"<<endl;
    cout<<"2.每个学生的总分"<<endl;
    cout<<"3.按学号由小到大排列成绩表"<<endl;
    cout<<"4.按总分由大到小排列成绩表"<<endl;
    cout<<"5.按总分由小到大排列成绩表"<<endl;
    cout<<"6.总分成绩等级排序及比例统计"<<endl;
    cout<<"7.学生信息、成绩及每门课程平均分"<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
    {


        int sum1=0,sum2=0,sum3=0;
        //float average[COURSE];
        //cout<<"课程1.高数；课程2.工图；课程3.物理"<<endl;

        for(int i=1; i<=number; i++)
        {
            sum1+=str[i].getCalculus();
            sum2+=str[i].getenDrawing();
            sum3+=str[i].getPhysics();
        }
        cout<<"高数\t平均分\t"<<(float)sum1/number<<endl;
        cout<<"工图\t平均分\t"<<(float)sum2/number<<endl;
        cout<<"物理\t平均分\t"<<(float)sum3/number<<endl;
        break;
    }
    case 2:
    {
        int sum;
        float average;
        cout<<"学号\t"<<"姓名\t"<<"总分\t"<<"平均分\t"<<endl;
        for(int i=1; i<=number; i++)
        {
            sum=str[i].getCalculus()+str[i].getenDrawing()+str[i].getPhysics();
            average=sum/COURSE;
            cout<<str[i].getStudentID()<<"\t"<<str[i].getName()<<"\t"<<sum<<"\t"<<average<<endl;
        }
        break;
    }
    case 3:
    {
        for(int i=1; i<=number; i++)
        {
            for(int j=1; j<=number-i; j++)
            {
                if(str[j].getStudentID()>str[j+1].getStudentID())
                {
                    swap(str[j],str[j+1]);
                }
            }
        }
        cout<<"\t学号\t"<<"姓名\t"<<"高数\t"<<"工图\t"<<"物理\t"<<"平均分\t"<<"总分"<<endl;
        for(int i=1; i<=number; i++)
        {
            str[i].Print1();
        }
        break;
    }
    case 4:
    {
        for(int i=1; i<=number; i++)
        {
            for(int j=1; j<=number-i; j++)
            {
                if(str[j].getSum()<str[j+1].getSum())
                {
                    swap(str[j],str[j+1]);
                }
            }
        }
        cout<<"\t学号\t"<<"姓名\t"<<"高数\t"<<"工图\t"<<"物理\t"<<"平均分\t"<<"总分"<<endl;
        for(int i=1; i<=number; i++)
        {
            str[i].Print1();
        }
    }
    break;
    case 5:
    {
        for(int i=1; i<=number; i++)
        {
            for(int j=1; j<=number-i; j++)
            {
                if(str[j].getSum()>str[j+1].getSum())
                {
                    swap(str[j],str[j+1]);
                }
            }
        }
        cout<<"\t学号\t"<<"姓名\t"<<"高数\t"<<"工图\t"<<"物理\t"<<"平均分\t"<<"总分"<<endl;
        for(int i=1; i<=number; i++)
        {
            str[i].Print1();
        }
        break;
    }
    case 6:
    {
        cout<<"\t学号\t"<<"姓名\t"<<"总分\t"<<"等级"<<endl;
        int m=0,n=0,p=0,q=0,r=0;
        for(int i=1; i<=number; i++)
        {
            if(str[i].getSum()<=300&&str[i].getSum()>=270)
            {
                str[i].Print2();
                cout<<"优秀"<<endl;
                m++;
            }
            else if(str[i].getSum()>=240&&str[i].getSum()<270)
            {
                str[i].Print2();
                cout<<"良好"<<endl;
                n++;
            }
            else if(str[i].getSum()>=210&&str[i].getSum()<240)
            {
                str[i].Print2();
                cout<<"中等"<<endl;
                p++;
            }
            else if(str[i].getSum()>=180&&(str[i].getSum()<210))
            {
                str[i].Print2();

                cout<<"及格"<<endl;
                q++;
            }
            else
            {
                str[i].Print2();
                cout<<"不及格"<<endl;
                r++;
            }
        }
        cout<<"优秀总人数："<<m<<"\t优秀率："<<(float)m/number<<endl;
        cout<<"良好总人数："<<n<<"\t良好率："<<(float)n/number<<endl;
        cout<<"中等总人数："<<p<<"\t中等率："<<(float)p/number<<endl;
        cout<<"不及格总人数："<<r<<"\t不及格率："<<(float)r/number<<endl;
        break;
    }
    case 7:
    {
        cout<<"\t学号\t"<<"姓名\t"<<"高数\t"<<"工图\t"<<"物理\t"<<"总分"<<endl;
        for(int i=1; i<=number; i++)
        {
            str[i].Print();
        }
        int sum1=0,sum2=0,sum3=0;
        //float average[COURSE];
        //cout<<"课程1.高数；课程2.工图；课程3.物理"<<endl;

        for(int i=1; i<=number; i++)
        {
            sum1+=str[i].getCalculus();
            sum2+=str[i].getenDrawing();
            sum3+=str[i].getPhysics();
        }
        cout<<"高数\t平均分\t"<<(float)sum1/number<<endl;
        cout<<"工图\t平均分\t"<<(float)sum2/number<<endl;
        cout<<"物理\t平均分\t"<<(float)sum3/number<<endl;
        break;
    }
    }
}
void menu()
{
    cout<<"*请选择您想要进行的系统操作序号："<<endl;
    cout<<"*1.学生信息录入"<<endl;
    cout<<"*2.学生成绩修改"<<endl;
    cout<<"*3.学生成绩查询"<<endl;
    cout<<"*4.学生成绩分析"<<endl;
    cout<<"*5.退出学生成绩管理系统"<<endl;
}

void clearScreen()
{
    system("pause");
    system("cls");
}

int main()
{

    studentManage s;
    cout<<"\t\t\t**************************************"<<endl;
    cout<<"\t\t\t**你的每一份耕耘，都将在这里收藏！****\t\t"<<endl;
    cout<<"\t\t\t**欢迎使用:\t\t\t******"<<endl;
    cout<<"\t\t\t**学生成绩管理系统\t\t******"<<endl;
    cout<<"\t\t\t**************************************"<<endl;
    clearScreen();
THERE:
    menu();
    int n;
    do
    {
        cin>>n;
        if(n<1||n>5)
        {
            cout<<"您输入的操作序号有误，请重新输入！"<<endl;
        }
    }
    while(n<1||n>5);
    switch(n)
    {
    case 1:
    {
        cout<<"***学生信息录入***"<<endl;
        char ch;
        do
        {
            s.typeIn();
            cout<<"学生信息录入成功！（已存储至文件studentManage.dat）"<<endl;
            cout<<"是否需要继续输入学生信息？（y||n）"<<endl;
            cin>>ch;
            if(ch=='n')
            {
                clearScreen();
                goto THERE;
            }
        }
        while(ch=='y');
        break;
    }

    case 2:
    {
        cout<<"***学生信息修改***"<<endl;
        char ch;
        do
        {
            s.update();
            cout<<"学生信息修改成功！（已存储至文件studentManage.dat）"<<endl;
            cout<<"是否需要继续修改学生信息？（y||n）"<<endl;
            cin>>ch;
            if(ch=='n')
            {
                clearScreen();
                goto THERE;
            }
        }
        while(ch=='y');
        break;
    }
    case 3:
    {
        cout<<"***学生信息查询***"<<endl;
        char ch;
        do
        {
            s.locate();
            cout<<"是否需要继续查询学生信息？（y||n）"<<endl;
            cin>>ch;
            if(ch=='n')
            {
                clearScreen();
                goto THERE;
            }
        }
        while(ch=='y');
        break;
    }
    case 4:
    {
        cout<<"***学生信息分析***"<<endl;
        char ch;
        do
        {
            s.analyze();
            cout<<"是否需要继续分析学生信息？（y||n）"<<endl;
            cin>>ch;
            if(ch=='n')
            {
                clearScreen();
                goto THERE;
            }
        }
        while(ch=='y');
        break;
    }
    case 5:
        s.logOut();
    }

    return 0;
}
