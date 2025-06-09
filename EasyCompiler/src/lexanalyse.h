#pragma once
#ifndef _LEXANALYSE_H_
#define _LEXANALYSE_H_

//      ����ʷ���������

#include"datastructure.h"
class LexAnalyser {
protected:
	void lexAnalyse(string file_name); //����Դ�ļ����ݣ������ʷ�������������
	void Print();  //��ӡToken��
	vector<TokenNode> Token;  //�洢Token���У��Ա���к�������
	vector<string> KT = { "program","var","integer","real","char","begin","end","if","then","else","while","do" };//�ؼ��ʱ�
	vector<string> PT = { ",",":",";",":=","*","/","+","-",".","(",")" ,"<",">","<=",">=","=="};//�����
	vector<string> IT;       //��ʶ����
	vector<string> CT;       //��������
	vector<string> RT;       //ʵ����С����
	vector<string> cT;       //�ַ���
	vector<string> ST;       //�ַ�����
private:
	int IfLetter(char ch);        //�ж���ĸ
	int IfDigit(char ch);         //�ж�����
	string Convert(double Num);   //floatתstring
	string Convert2(ll Num);      //llתstring
	void constant(string s);      //����ʶ��� ʶ����(CT) �� ��ʵ��(RT)
	int reserve(char* strt);      //���ҹؼ��ֲ�����location (KT)
	int reserve2(char* strt);     //���ҽ��������location (PT)
	int InsertIT(char* strt);     //��ʶ��ʶ���������location (IT)
	int InsertcT(char* strt);     //�ַ�ʶ���������location (cT)
	int InsertST(char* strt);     //�ַ���ʶ���������location (ST)
	void lexical(string line);    // �ʷ�����������
};



#endif
