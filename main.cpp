#include <iostream>
#include<fstream>
#include <string>
#include<cstdlib>
using namespace std;
const int COURSE=3;
static int Num=1;//�䵱����Ǳ�
static int number=0;//ѧ������

//*******************����ѧ����
class Student
{
private:
    string StudentID;
    string Name;
    int Calculus;//��������ɼ�����
    int enDrawing;//���幤ͼ�ɼ�����
    int Physics;//��������ɼ�����
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
    int getSum();//ѧ���ܷ�
    int getAverage();//ѧ��ƽ����
    //typeIn��������¼��ѧ����Ϣ
    void typeIn(string studentID,string name,int calculus,int endrawing,int physics);
    void Print();
    void Print1();
    void Print2();
    //sum()������ȡ�ܷ�
    void sum(int Calculus,int enDrawing,int Physics);
    void upCalsum(int temp);//�޸�΢���ֳɼ�����ֺܷ���
    void upDrasum(int temp);//�޸Ĺ�ͼ�ɼ�����ֺܷ���
    void upPhysum(int temp);//�޸�����ɼ�����ֺܷ���
};

//Studentѧ����ķ���ʵ��
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
    //���������ݸ�ѧ������
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


//*******************����ѧ���ɼ���Ϣ������
class studentManage
{
private:
    Student str[10001];//ѧ���������飬����1-10000��������Χ
    int num;
public:
    void typeIn();//¼��ѧ����Ϣ
    void update();//�޸�ѧ����Ϣ
    void locate();//����ѧ����Ϣ
    void analyze();//����ѧ���ɼ�
    int logOut()//�˳�����
    {
        cout <<"��ӭ�´�ʹ��ѧ���ɼ�����ϵͳ!"<<endl;
        return 0;
    }

};
//studentManageѧ���ɼ���Ϣ�������ʵ��
void studentManage::typeIn()
{
    //ѧ����Ϣ��¼��
    string StudentID,Name;
    int Calculus,enDrawing,Physics;
    cout<<"������ѧ��ѧ�ţ�";
    cin>>StudentID;
    cout<<"������ѧ��������";
    cin>>Name;
    cout<<"������ѧ�������ɼ�(0~100)��";
    cin>>Calculus;
    while(Calculus<0||Calculus>100)
    {
        cout<<"����ɼ����Ϸ�!"<<endl;
        cout<<"������ѧ�������ɼ�(0~100)��";
        cin>>Calculus;
    }
    cout<<"������ѧ����ͼ�ɼ�(0~100)��";
    cin>>enDrawing;
    while(enDrawing<0||enDrawing>100)
    {
        cout<<"����ɼ����Ϸ�!"<<endl;
        cout<<"������ѧ����ͼ�ɼ�(0~100)��";
        cin>>enDrawing;
    }
    cout<<"������ѧ������ɼ�(0~100)��";
    cin>>Physics;
    while(Physics<0||Physics>100)
    {
        cout<<"����ɼ����Ϸ�!"<<endl;
        cout<<"������ѧ������ɼ�(0~100)��";
        cin>>Physics;
    }

    //��typeIn��()sum()�������ݲ���
    str[Num].typeIn(StudentID,Name,Calculus,enDrawing,Physics);
    str[Num].sum(Calculus,enDrawing,Physics);

    //�����ļ���ѧ����Ϣ���д洢
    ofstream outfile("studentManage.dat",ios::out);
    if(outfile.fail())
    {
        cerr<<"δ�ܴ��ļ�studentManage.dat���洢ʧ�ܣ�"<<endl;
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
    cout<<"��������Ҫ�޸ĳɼ���ѧ��ѧ��: ";
    cin>>StudentID;
    for(int i=1; i<=number; i++)
    {
        if(StudentID.compare(str[i].getStudentID())==0)
        {
            //found=true;
            cout<<"**************************************"<<endl;
            cout<<"��������Ҫ�޸ĵĳɼ���ţ�"<<endl;
            cout<<"1.������2.��ͼ��3.����"<<endl;
            cin>>n;
            switch(n)
            {
            case 1://�޸�΢���ֳɼ�
                cout<<"**************************************"<<endl;
                cout<<"�������޸ĺ�ĸ����ɼ���"<<endl;
                cin>>temp;
                while(temp<0||temp>100)
                {
                    cout<<"����ɼ����Ϸ�!"<<endl;
                    cout<<"������ѧ�������ɼ�(0~100)��";
                    cin>>temp;
                }

                str[i].setCalculus(temp);
                str[i].upCalsum(temp);
                found=true;
                break;
            case 2:
                cout<<"**************************************"<<endl;
                cout<<"�������޸ĺ�Ĺ�ͼ�ɼ���"<<endl;
                cin>>temp;
                while(temp<0||temp>100)
                {
                    cout<<"����ɼ����Ϸ�!"<<endl;
                    cout<<"������ѧ����ͼ�ɼ�(0~100)��";
                    cin>>temp;
                }
                str[i].setenDrawing(temp);
                str[i].upDrasum(temp);
                found=true;
                break;
            case 3:
                cout<<"**************************************"<<endl;
                cout<<"�������޸ĺ������ɼ���"<<endl;
                cin>>temp;
                while(temp<0||temp>100)
                {
                    cout<<"����ɼ����Ϸ�!"<<endl;
                    cout<<"������ѧ������ɼ�(0~100)��";
                    cin>>temp;
                }
                str[i].setPhysics(temp);
                str[i].upPhysum(temp);
                found=true;
                break;
            default:
                cout<<"�����������"<<endl;
                break;
            }
        }

    }
    if(found==false)
    {
        cout<<"�������ѧ��ѧ�Ų����ڣ�"<<endl;
        cout<<"���������룡"<<endl;
        goto THIS;
    }
}
void studentManage::locate()
{
    string StudentID;
    string Name;
    int n;
    cout<<"**************************************"<<endl;
    cout<<"����������������ţ�1.��ѧ��ѧ�Ų�ѯ�ɼ���2.��ѧ��������ѯ�ɼ�"<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
    {
        int i;
        bool found=false;
HERE:
        cout<<"����������Ҫ��ѯ��ѧ��ѧ�ţ�";
        cin>>StudentID;
        for(i=1; i<=number; i++)
        {
            if(StudentID.compare(str[i].getStudentID())==0)
            {
                cout<<"\tѧ��\t"<<"����\t"<<"����\t"<<"��ͼ\t"<<"����\t"<<"�ܷ�"<<endl;
                str[i].Print();
                found=true;
            }

        }
        if(found==false)
        {
            cout<<"�������ѧ��ѧ�Ų����ڣ�"<<endl;
            cout<<"���������룡"<<endl;
            goto HERE;
        }
        break;
    }

    case 2:

    {
        int i;
        bool found=false;
        cout<<"����������Ҫ��ѯ��ѧ��������";
POSITION:
        cin>>Name;
        for(i=1; i<=number; i++)
        {
            if(Name.compare(str[i].getName())==0)
            {
                cout<<"\tѧ��\t"<<"����\t"<<"����\t"<<"��ͼ\t"<<"����\t"<<"�ܷ�"<<endl;
                str[i].Print();
                found=true;
            }
        }
        if(found==false)
        {
            cout<<"�������ѧ�����������ڣ�"<<endl;
            cout<<"���������룡"<<endl;
            goto POSITION;
        }
        break;
    }
    default:
        cout<<"�����������"<<endl;
        break;
    }

}
void studentManage::analyze()
{
    int n;
    cout<<"**************************************"<<endl;
    cout<<"����������Ҫ������ѧ���ɼ�������ţ�"<<endl;
    cout<<"1.ÿ�ſγ̵�ƽ����"<<endl;
    cout<<"2.ÿ��ѧ�����ܷ�"<<endl;
    cout<<"3.��ѧ����С�������гɼ���"<<endl;
    cout<<"4.���ܷ��ɴ�С���гɼ���"<<endl;
    cout<<"5.���ܷ���С�������гɼ���"<<endl;
    cout<<"6.�ֳܷɼ��ȼ����򼰱���ͳ��"<<endl;
    cout<<"7.ѧ����Ϣ���ɼ���ÿ�ſγ�ƽ����"<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
    {


        int sum1=0,sum2=0,sum3=0;
        //float average[COURSE];
        //cout<<"�γ�1.�������γ�2.��ͼ���γ�3.����"<<endl;

        for(int i=1; i<=number; i++)
        {
            sum1+=str[i].getCalculus();
            sum2+=str[i].getenDrawing();
            sum3+=str[i].getPhysics();
        }
        cout<<"����\tƽ����\t"<<(float)sum1/number<<endl;
        cout<<"��ͼ\tƽ����\t"<<(float)sum2/number<<endl;
        cout<<"����\tƽ����\t"<<(float)sum3/number<<endl;
        break;
    }
    case 2:
    {
        int sum;
        float average;
        cout<<"ѧ��\t"<<"����\t"<<"�ܷ�\t"<<"ƽ����\t"<<endl;
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
        cout<<"\tѧ��\t"<<"����\t"<<"����\t"<<"��ͼ\t"<<"����\t"<<"ƽ����\t"<<"�ܷ�"<<endl;
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
        cout<<"\tѧ��\t"<<"����\t"<<"����\t"<<"��ͼ\t"<<"����\t"<<"ƽ����\t"<<"�ܷ�"<<endl;
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
        cout<<"\tѧ��\t"<<"����\t"<<"����\t"<<"��ͼ\t"<<"����\t"<<"ƽ����\t"<<"�ܷ�"<<endl;
        for(int i=1; i<=number; i++)
        {
            str[i].Print1();
        }
        break;
    }
    case 6:
    {
        cout<<"\tѧ��\t"<<"����\t"<<"�ܷ�\t"<<"�ȼ�"<<endl;
        int m=0,n=0,p=0,q=0,r=0;
        for(int i=1; i<=number; i++)
        {
            if(str[i].getSum()<=300&&str[i].getSum()>=270)
            {
                str[i].Print2();
                cout<<"����"<<endl;
                m++;
            }
            else if(str[i].getSum()>=240&&str[i].getSum()<270)
            {
                str[i].Print2();
                cout<<"����"<<endl;
                n++;
            }
            else if(str[i].getSum()>=210&&str[i].getSum()<240)
            {
                str[i].Print2();
                cout<<"�е�"<<endl;
                p++;
            }
            else if(str[i].getSum()>=180&&(str[i].getSum()<210))
            {
                str[i].Print2();

                cout<<"����"<<endl;
                q++;
            }
            else
            {
                str[i].Print2();
                cout<<"������"<<endl;
                r++;
            }
        }
        cout<<"������������"<<m<<"\t�����ʣ�"<<(float)m/number<<endl;
        cout<<"������������"<<n<<"\t�����ʣ�"<<(float)n/number<<endl;
        cout<<"�е���������"<<p<<"\t�е��ʣ�"<<(float)p/number<<endl;
        cout<<"��������������"<<r<<"\t�������ʣ�"<<(float)r/number<<endl;
        break;
    }
    case 7:
    {
        cout<<"\tѧ��\t"<<"����\t"<<"����\t"<<"��ͼ\t"<<"����\t"<<"�ܷ�"<<endl;
        for(int i=1; i<=number; i++)
        {
            str[i].Print();
        }
        int sum1=0,sum2=0,sum3=0;
        //float average[COURSE];
        //cout<<"�γ�1.�������γ�2.��ͼ���γ�3.����"<<endl;

        for(int i=1; i<=number; i++)
        {
            sum1+=str[i].getCalculus();
            sum2+=str[i].getenDrawing();
            sum3+=str[i].getPhysics();
        }
        cout<<"����\tƽ����\t"<<(float)sum1/number<<endl;
        cout<<"��ͼ\tƽ����\t"<<(float)sum2/number<<endl;
        cout<<"����\tƽ����\t"<<(float)sum3/number<<endl;
        break;
    }
    }
}
void menu()
{
    cout<<"*��ѡ������Ҫ���е�ϵͳ������ţ�"<<endl;
    cout<<"*1.ѧ����Ϣ¼��"<<endl;
    cout<<"*2.ѧ���ɼ��޸�"<<endl;
    cout<<"*3.ѧ���ɼ���ѯ"<<endl;
    cout<<"*4.ѧ���ɼ�����"<<endl;
    cout<<"*5.�˳�ѧ���ɼ�����ϵͳ"<<endl;
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
    cout<<"\t\t\t**���ÿһ�ݸ��ţ������������ղأ�****\t\t"<<endl;
    cout<<"\t\t\t**��ӭʹ��:\t\t\t******"<<endl;
    cout<<"\t\t\t**ѧ���ɼ�����ϵͳ\t\t******"<<endl;
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
            cout<<"������Ĳ�������������������룡"<<endl;
        }
    }
    while(n<1||n>5);
    switch(n)
    {
    case 1:
    {
        cout<<"***ѧ����Ϣ¼��***"<<endl;
        char ch;
        do
        {
            s.typeIn();
            cout<<"ѧ����Ϣ¼��ɹ������Ѵ洢���ļ�studentManage.dat��"<<endl;
            cout<<"�Ƿ���Ҫ��������ѧ����Ϣ����y||n��"<<endl;
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
        cout<<"***ѧ����Ϣ�޸�***"<<endl;
        char ch;
        do
        {
            s.update();
            cout<<"ѧ����Ϣ�޸ĳɹ������Ѵ洢���ļ�studentManage.dat��"<<endl;
            cout<<"�Ƿ���Ҫ�����޸�ѧ����Ϣ����y||n��"<<endl;
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
        cout<<"***ѧ����Ϣ��ѯ***"<<endl;
        char ch;
        do
        {
            s.locate();
            cout<<"�Ƿ���Ҫ������ѯѧ����Ϣ����y||n��"<<endl;
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
        cout<<"***ѧ����Ϣ����***"<<endl;
        char ch;
        do
        {
            s.analyze();
            cout<<"�Ƿ���Ҫ��������ѧ����Ϣ����y||n��"<<endl;
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
