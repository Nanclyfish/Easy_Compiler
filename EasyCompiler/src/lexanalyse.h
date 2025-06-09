#pragma once
#ifndef _LEXANALYSE_H_
#define _LEXANALYSE_H_

//      定义词法分析器类

#include"datastructure.h"
class LexAnalyser {
protected:
	void lexAnalyse(string file_name); //读入源文件内容，启动词法分析主程序函数
	void Print();  //打印Token表
	vector<TokenNode> Token;  //存储Token序列，以便进行后续操作
	vector<string> KT = { "program","var","integer","real","char","begin","end","if","then","else","while","do" };//关键词表
	vector<string> PT = { ",",":",";",":=","*","/","+","-",".","(",")" ,"<",">","<=",">=","=="};//界符表
	vector<string> IT;       //标识符表
	vector<string> CT;       //常整数表
	vector<string> RT;       //实数表（小数）
	vector<string> cT;       //字符表
	vector<string> ST;       //字符串表
private:
	int IfLetter(char ch);        //判断字母
	int IfDigit(char ch);         //判断数字
	string Convert(double Num);   //float转string
	string Convert2(ll Num);      //ll转string
	void constant(string s);      //常数识别机 识别常数(CT) 与 常实数(RT)
	int reserve(char* strt);      //查找关键字并返回location (KT)
	int reserve2(char* strt);     //查找界符并返回location (PT)
	int InsertIT(char* strt);     //标识符识别机并返回location (IT)
	int InsertcT(char* strt);     //字符识别机并返回location (cT)
	int InsertST(char* strt);     //字符串识别机并返回location (ST)
	void lexical(string line);    // 词法分析主程序
};



#endif
