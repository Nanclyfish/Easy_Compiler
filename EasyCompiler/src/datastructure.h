#pragma once
#ifndef _DATASTRUCTURE_H_
#define _DATASTRUCTURE_H_

// �����������͵Ķ���������

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct TokenNode {  
	string name;     //Token����
	int location{};  //��ʼ��location��ֵ��locationΪToken�ڱ��е�λ��
}TokenNode;

typedef struct Objective {   // ����������
	string name;
	string type;  //1 ����ʱ����  2 ��ʱ����  3 ����  
	Objective(string Name = "", string Type = "")   //ȱʡʱ��Ϊ��
	{
		name = Name;
		type = Type;
	}
}Objective;

typedef struct QuaternionNode {     //��Ԫʽ��
	int block;      //����������  init 0
	int type;       //����  init 0

	string op;      //���
	Objective objective1;   //����1
	Objective objective2;   //����2
	Objective result;       //���
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