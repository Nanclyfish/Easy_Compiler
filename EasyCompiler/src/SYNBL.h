#pragma once
#ifndef _SYNBL_H_
#define _SYNBL_H_

//    定义符号表类

#include"lexanalyse.h"

class synbl :public LexAnalyser //符号表
{
public:

	struct symbol {
		string name;		//name
		char type;		//类型
		char cat;	//属性
		int offset;  //区距
	};
	vector<symbol>sym;
	int sym_search(string str);
	void init_symbol();
	void enter(string id, char type, char cat, int offset);
	void synbl_print();
};


#endif
