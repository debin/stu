#ifndef LIAO_H
#define LIAO_H
#include <iomanip>
#include<iostream>
#include<string>
using namespace std;

class Node{     //链表节点
public:
	Node();
	string num;
	string name;
	string course;
	string grade;
	string term;
	Node *next;
};

void menu();            //主界面
void find(Node *head);  //查询功能的界面
Node *insert(Node *head);  //增加功能的界面
Node *del(Node *head);     //删除功能的界面
void tongji(Node *head); //统计界面
void update(Node *head); //修改功能的界面
    
Node *fopen();                    //读文件，文件读到链表
void save(Node *head);            //写文件，链表数据更新到文件

#endif