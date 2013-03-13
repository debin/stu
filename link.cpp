#include"link.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;

Node::Node()
{
	next=NULL;
}
//主界面输出函数
void menu(){   
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"*"<<"     "<<"1.查询"<<"     "<<"2.增加"<<"     "<<"3.删除"<<"    "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl; 
	cout<<"*"<<"     "<<"4.修改"<<"     "<<"5.统计"<<"     "<<"6.退出"<<"    "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
	cout<<"----其他输入无效-----"<<endl;
	cout<<"请选择功能:";
}

//打开文件，读取记录函数,生成链表，返回头结点
Node *fopen(){
	ifstream stu("d:\\Record.dat");
	if(!stu){                                    //若打开旧记录失败
		cout<<endl<<"----不存在记录文件，系统将创建一个新的记录文件----"<<endl<<endl;
	    ofstream stu("d:\\Record.dat");
		stu<<"**";
		stu.close();
        Sleep(5000);
        return NULL;
	}
	string a;
	stu>>a;
    if(a=="**")        //若文件内容为空
	{
		return NULL;
	}
	Node *h=new Node();
    h->num=a;
	stu>>h->name ;
	stu>>h->course ;
	stu>>h->grade  ;
	stu>>h->term ;

	Node *p1,*p2;
	p1=p2=h;

	string tempnum;
	stu>>tempnum;
	while(tempnum!="**"){         //记录转为链表
		p2=new Node();
	    p2->num=tempnum;
      	stu>>p2->name ;
    	stu>>p2->course ;
        stu>>p2->grade  ;
    	stu>>p2->term ;	

        p1->next=p2;
		p1=p2;
		stu>>tempnum;
	}
    stu.close();	
    return h;
}

//更新文件，从头结点开始，把链表保存到文件
void save(Node *head)
{
	ofstream stu("d:\\Record.dat");
	if(!stu)
	{
		cout<<"文件更新失败,将退出系统"<<endl;
		system("pause");
		exit(1);
	}
     
	Node *p1;
	stu<<head->num <<" "<<head->name <<" "<<head->course <<" "<<head->grade <<" "<<head->term <<endl;
	p1=head->next ;
    while(p1!=NULL)
	{
		stu<<p1->num <<" "<<p1->name <<" "<<p1->course <<" "<<p1->grade <<" "<<p1->term <<endl;
		p1=p1->next;
	}
	stu<<"**";
	cout<<"----更新成功----"<<endl;
}

//查询主界面
void find(Node *head){ 
    void showAll(Node *head);       //输出全部学生成绩
    void findByName(Node *head);              //按姓名查询
    void findByNum(Node *head);              //按学号查询
    void findByCourse(Node *head);           //按科目查询

	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-查询功能-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
    cout<<"*"<<"   "<<"1.按照姓名查询"<<"   "<<"2.按照学号查询"<<"   "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl;
    cout<<"*"<<"           "<<"5.返回系统界面"<<"            "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl;
    cout<<"*"<<"   "<<"3.按照科目查询"<<"   "<<"4.显示所有成绩"<<"   "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;

	cout<<"----其他输入无效-----"<<endl;
    cout<<"请选择：";
  
	char choice;
	cin>>choice;
	switch(choice)
	{
    	case '1':findByName(head);break;
	    case '2':findByNum(head);break;
    	case '3':findByCourse(head);break;
     	case '4':showAll(head);break;
    	case '5':system("cls");menu();break;
        default:system("cls");find(head);break;
	}
}

void showAll(Node *head){  //输出全部学生成绩
	system("cls");
	cout<<"---------以下是所有成绩单---------"<<endl<<endl;
	cout<<left<<setw(12)<<"  学号"<<setw(8)<<"  姓名"<<setw(12)<<"  科目"<<setw(6)<<"  成绩"<<setw(6)<<"  学期"<<endl;
    Node *p3;
    p3=head;
    while(p3!=NULL)
	{		
		cout<<left<<setw(12)<<p3->num<<" "<<setw(8)<<p3->name <<" "<<setw(12)<<p3->course<<" "<<setw(6)<<p3->grade<<" "<<setw(6)<<p3->term <<endl;
	 	p3=p3->next;
	}
    cout<<endl<<"---------成绩单输出完毕---------"<<endl;
	find(head);    //返回查询界面
}

//按姓名查询
void findByName(Node *head){
	Node *p1;
	p1=head;
	string name;
	cout<<"按姓名查询，请输入姓名:";
	cin>>name;
	system("cls");
	cout<<"----以下是学生 "<<name<<" 的成绩单----"<<endl<<endl;
	cout<<left<<setw(12)<<"  学号"<<setw(12)<<" 科目"<<setw(6)<<" 成绩"<<setw(6)<<" 学期"<<endl;
	while(p1!=NULL){
		if(p1->name==name)
		{
			cout<<left<<setw(12)<<p1->num<<" "<<setw(12)<<p1->course<<" "<<setw(6) <<p1->grade<<" "<<setw(6) <<p1->term<<endl;
		}
		p1=p1->next;
	}
	cout<<endl<<endl<<"----查询完毕,若成绩单为空则表示无此学生----"<<endl;
	find(head);    //返回查询界面
}

//按学号查询
void findByNum(Node *head){
	Node *p1;
	p1=head;
	string num;
	cout<<"按学号查询,输入学号:";
	cin>>num;
	system("cls");
	cout<<"---以下学号为 "<<num<<"  的学生的成绩单----"<<endl<<endl;
    cout<<left<<setw(8)<<" 姓名"<<setw(12)<<" 科目"<<setw(6)<<" 成绩"<<setw(6)<<" 学期"<<endl;
	while(p1!=NULL){
		if(p1->num==num)
		{
			cout<<left<<setw(8)<<p1->name<<" "<<setw(12)<<p1->course<<" "<<setw(6)<<p1->grade<<" "<<p1->term <<endl;
		}
		p1=p1->next;
	}
	cout<<endl<<endl<<"---查询完毕,若成绩单为空则表示无此学号----"<<endl;
	find(head);    //返回查询界面
}

//按科目查询
void findByCourse(Node *head){
	Node *p1;
	p1=head;
	string course,term;
	cout<<"输入科目:";
	cin>>course;
	cout<<"输入学期:";
    cin>>term;
	
	system("cls");
	cout<<"---以下是第 "<<term<<"  学期 "<<course<<" 课的成绩单----"<<endl<<endl;
	cout<<left<<setw(12)<<" 学号"<<setw(8)<<" 姓名"<<setw(6)<<" 成绩"<<endl;
	while(p1!=NULL){
		if(p1->course==course && p1->term==term)
		{
			cout<<left<<setw(12)<<p1->num<<" "<<setw(8)<<p1->name<<" "<<setw(6) <<p1->grade<<endl;
		}
		p1=p1->next;
	}

	cout<<endl<<endl<<"----查询完毕----"<<endl<<endl;
	find(head);    //返回查询界面
}

//增加功能的主界面
Node *insert(Node *head){
	system("cls");
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-增加记录-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
    
	string tempNum,tempName,tempCourse,tempGrade,tempTerm;



	Node *p2;
	p2=head;
    cout<<"输入学号：";
    cin >>tempNum ;  
	cout<<"输入姓名：";
	cin >>tempName  ;
	cout<<"输入科目：";
	cin >>tempCourse ;
	cout<<"输入成绩：";
	cin >>tempGrade ;
	cout<<"输入学期：";
	cin >>tempTerm ;  


    while(p2!=NULL){           //若输入的信息已存在,返回主界面
		if(tempNum==p2->num && tempName==p2->name && tempCourse==p2->course && tempTerm==p2->term )
		{
			system("cls");
			cout<<endl<<"你所输入的学号、姓名、科目、学期已存在!"<<endl;
			cout<<"----系统返回主界面----"<<endl;
		    menu();
			return head;
		}
		else
			p2=p2->next;
	}

	Node *p1=new Node();     //插入头结点
	p1->next=head;
	p1->num=tempNum;
	p1->name=tempName;
	p1->course=tempCourse;
	p1->term =tempTerm;
	p1->grade=tempGrade;


	system("cls");
	cout<<endl<<"操作：录入新的成绩记录 "<<tempNum<<" "<<p1->name<<" "<<p1->course<<" "<<p1->grade<<" "<<p1->term<<endl;
	save(p1);      //更新文件
	menu();              //返回主界面
	return p1;
}

//删除功能的界面
Node *del(Node *head){

	if(head==NULL)     //若为空
	{
		cout<<endl<<"----无成绩记录,无法进行删除操作----"<<endl;
		return head;
	}
	string tempName,tempCourse,tempTerm;
	Node *temp,*temp2;
    int isOrNot=0;     //0表示系统中找不到待删除信息
	system("cls");
	cout<<endl;
    cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-删除成绩-"<<"                "<<"*"<<endl;	
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
    cout<<"输入姓名:";
	cin>>tempName;
	cout<<"输入科目:";
	cin>>tempCourse;
	cout<<"输入学期:";
	cin>>tempTerm;

	while(head->name ==tempName && head->course ==tempCourse && head->term==tempTerm) //删除的是第一个节点
	{
		head=head->next;
		isOrNot=1;
	}
	
	temp=temp2=head;       //删除的不是第一个节点
	temp2=temp2->next;
	while(temp2!=NULL){
		if(temp2->name==tempName && temp2->course ==tempCourse && temp2->term==tempTerm){
			temp->next=temp2->next;
			isOrNot=1;
		}
		temp=temp2;
		temp2=temp2->next;
	}
	system("cls");
	if(isOrNot==0)	{            //找不到要删除的信息
		cout<<endl<<"----输入的信息有误，返回系统主界面----"<<endl;
        menu();
		return head;
	}
	else{                 //删除成功
        cout<<"操作：删除学生 "<<tempName<<" 的 "<<tempCourse<<" 成绩"<<endl;
    	save(head);         //更新文件
    	menu();
    	return head;
	}
}

//修改功能的主界面
void update(Node *head){
    void updateName(Node *head);
    void updateNum(Node *head);
	void updateGrade(Node *head);

	char choice;
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-修改功能-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"*"<<"     "<<"1.修改姓名"<<"      "<<"2.修改学号"<<"      "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl; 
	cout<<"*"<<"     "<<"3.修改成绩"<<"      "<<"4.返回系统"<<"      "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
    cout<<"其他输入无效，请选择功能:";

	cin>>choice;
	switch(choice){
    	case '1':system("cls");updateName(head);break;
		case '2':system("cls");updateNum(head);break;
		case '3':updateGrade(head);break;
		case '4':system("cls");menu();break;
		default:
			system("cls");update(head);break;
	}
}

//修改姓名函数
void updateName(Node *head){
	string name1,name2;
	int isOrNot=0;      //0表示要修改的姓名不存在
	Node *p1;
	p1=head;
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-修改姓名-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
	cout<<"输入原姓名:";
	cin>>name1;
	cout<<"输入新姓名:";
	cin>>name2;
    while(p1!=NULL)
	{
        if(p1->name ==name1){
			p1->name=name2;
			isOrNot=1;
		}
		p1=p1->next ;
	}
	system("cls");
	if(isOrNot==0){         //修改失败
		cout<<endl<<"----待删除姓名不存在，返回修改界面----"<<endl;
		update(head);

	}
    else{                  //修改成功

    	cout<<endl<<"操作：把学生 "<<name1<<" 的姓名更改为："<<name2<<endl;
    	save(head);             //更新文件
    	update(head);
	}
}

//修改学号函数
void updateNum(Node *head){
	int isOrNot=0;      //0表示要修改的学号不存在
	string num1,num2;
	Node *p1;
	p1=head;
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-修改学号-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
	cout<<"输入原学号:";
	cin>>num1;
	cout<<"输入新学号:";
	cin>>num2;
    while(p1!=NULL)
	{
        if(p1->num ==num1){
			p1->num=num2;
			isOrNot=1;
		}
		p1=p1->next ;
	}
	system("cls");
	if(isOrNot==0){         //修改学号失败
		cout<<endl<<"----待修改学号不存在，返回修改界面----"<<endl;
		update(head);

	}

    else{
	    cout<<endl<<"操作:学号 "<<num1<<" 更改为:"<<num2<<endl;
    	save(head);             //更新文件
    	update(head); 
	}
}

//修改成绩函数
void updateGrade(Node *head){
	string numOrName,course,term,grade;
	Node *p1,*temp;
	temp=NULL;
	system("cls");
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-修改成绩-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
	cout<<"输入姓名或学号:";
	cin>>numOrName;
	cout<<"输入课程：";
	cin>>course;
	cout<<"输入学期:";
	cin>>term;
    
	p1=head;
	while(p1!=NULL)
	{
		if((p1->num==numOrName || p1->name ==numOrName) && p1->course==course && p1->term==term){
			temp=p1;
			break;
		}
		p1=p1->next;
	}
	if(temp==NULL){   //若输入有误
    	system("cls");
		cout<<endl<<"----待修改信息不存在，返回修改界面----"<<endl;
		update(head);
	}
	else{
    	cout<<"此人原来分数是:"<<temp->grade <<endl;
    	cout<<"输入新的分数:";
    	cin>>grade;
    	temp->grade=grade;
    	system("cls");
    	cout<<endl<<"操作：把学生 "<<temp->num <<" 第 "<<term<<" 学期 "<<course<<" 课的成绩改为: "<<grade<<endl;
    	save(head);
    	update(head);
	}
}

//统计界面
void tongji(Node *head){
	void tongjiAver(Node *head);

    if(head==NULL){       //成绩记录为空
		cout<<endl<<"----无成绩记录，无法统计----"<<endl;
		menu();
	}
    else{            //有成绩记录
    	char choice;
    	cout<<endl;
    	cout<<"***************************************"<<endl;
    	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
    	cout<<"*"<<"          "<<"-统计功能-"<<"                 "<<"*"<<endl;
    	cout<<"*"<<"                                     "<<"*"<<endl;
    	cout<<"*"<<"     "<<"1.统计平均分"<<"     "<<"2.返回系统"<<"     "<<"*"<<endl;
    	cout<<"*"<<"                                     "<<"*"<<endl;
    	cout<<"***************************************"<<endl;
        cout<<"其他输入无效，请选择功能:";
    	cin>>choice;
 
    	switch(choice){
	    	 case '1':tongjiAver(head);break;
	    	 case '2':system("cls");menu();break;
	    	 default:system("cls");tongji(head);break;
		}
	}
}

void tongjiAver(Node *head){
	Node *p1;
	p1=head;
	string term,course;
	double grade;
	int count=0;
	double sum=0;

	system("cls");
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"学生成绩管理系统 v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"         "<<"-统计平均分-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
    cout<<"输入学期：";
	cin>>term;
	cout<<"输入课程:";
	cin>>course;
    
	while(p1!=NULL){
		if(p1->term==term && p1->course==course)
		{
			count++;
			grade=atof( (p1->grade).c_str() );
            sum=sum+grade;
		}
		p1=p1->next;
	}
	system("cls");
	if(count==0){
		cout<<endl<<"----输入有误，无法统计----"<<endl;
	}
	else{
        cout<<endl<<"----平均分统计----"<<endl<<endl;
    	cout<<"第 "<<term<<" 学期 "<<course<<" 课程的平均分是:"<<endl;
    	cout<<"        "<<sum/count<<endl<<endl;
    	cout<<"----统计完毕----"<<endl;
	}
	tongji(head);
}