#pragma once
#ifndef _DATASTRUCTURE_H_
#define _DATASTRUCTURE_H_

// 基本数据类型的定义与声明

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct TokenNode {  
	string name;     //Token类型
	int location{};  //初始化location的值，location为Token在表中的位置
}TokenNode;

typedef struct Objective {   // 变量对象类
	string name;
	string type;  //1 非临时变量  2 临时变量  3 常数  
	Objective(string Name = "", string Type = "")   //缺省时均为空
	{
		name = Name;
		type = Type;
	}
}Objective;

typedef struct QuaternionNode {     //四元式类
	int block;      //所属基本块  init 0
	int type;       //类型  init 0

	string op;      //算符
	Objective objective1;   //对象1
	Objective objective2;   //对象2
	Objective result;       //结果
	QuaternionNode(int Block, int Type, string Op, Objective Obj1, Objective Obj2, Objective Result)
	{
		block = Block;
		type = Type;
		op = Op;
		objective1 = Obj1;
		objective2 = Obj2;
		result = Result;
	}
}QuaternionNode;



#endif