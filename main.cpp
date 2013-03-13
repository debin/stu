#include"link.h"
#include <iostream>
#include<string>
using namespace std;
	
int main(){
	Node *head=fopen();    //打开记录文件,转为链表
//	cout<<endl<<"----正在进入学生成绩管理系统，请稍等----"<<endl;
//	Sleep(2000);
    system("cls");

	menu();                //打开主界面
    char choice;
    cin>>choice;
	while(choice!='6'){        //主界面功能处理
		switch(choice)
		{
	    	case '1':system("cls");find(head);break;
			case '2':head=insert(head);break;
			case '3':head=del(head);break;
			case '4':system("cls");update(head);break;
			case '5':system("cls");tongji(head);break;
            default:system("cls");menu();break;
		}
		cin>>choice;
	}
  
    system("cls");
    cout<<endl<<"已安全退出系统"<<endl<<endl;;
    system("pause");
	return 0;
}














