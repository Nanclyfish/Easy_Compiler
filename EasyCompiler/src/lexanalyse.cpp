
//   实现 词法分析器

#include"lexanalyse.h"

//判断字母
int LexAnalyser::IfLetter(char ch)
{
	if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
		return 1;
	else
		return 0;
}

//判断数字
int LexAnalyser::IfDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return 1;
	else
		return 0;
}

//float转string
string LexAnalyser::Convert(double Num)
{
	/*ostringstream oss;
	oss << Num;
	string str(oss.str());*/
	string str = to_string(Num);
	return str;
}

//ll转string
string LexAnalyser::Convert2(ll Num)
{
	/*ostringstream oss;
	oss << Num;
	string str(oss.str());*/
	string str = to_string(Num);
	return str;
}

//常数识别机 ll存入CT double存入RT
void LexAnalyser::constant(string s)
{
	// s为源文件中读入的数据

	double ans = 0;//结果ans
	bool t = 0;//常数类型 整数0 实型1 
	ll e = 1;//指数的符号 1:+  -1:-
	ll f = 1;//常数的符号 
	ll p = 0, m = 0;//p是指数  m是小数位数 
	int i;

	for (i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			ans = ans * 10 + (s[i] - '0');
		else if (s[i] == '.')
		{
			t = 1;  //实数型常数
			break;
		}
		else if (s[i] == 'e')
		{
			break;  //带指数常数
		}
		else if (s[i] == '-')
			f = -1;  //常数符号为-
	}
	for (i = i; i < s.size(); i++)
	{
		if (t == 0) // 常数部分(指数之前的部分)无小数
			break;
		if (s[i] >= '0' && s[i] <= '9')
		{
			ans = ans * 10 + (s[i] - '0');
			m++; //记录小数位数
		}
		else if (s[i] == 'e')
		{
			break;
		}
	}
	for (i = i; i < s.size(); i++)
	{
		if (t == 0) // 该数是带指数的数且常数部分为整数
			t = 1;
		if (s[i] == '-')
			e = -1;   // 指数符号为-
		else if (s[i] >= '0' && s[i] <= '9')
		{
			p = p * 10 + (s[i] - '0');
		}
	}
	TokenNode token;
	if (t == 1)
	{
		ans = f * ans * pow(10, (e * p - m));//  常数符号 * 常数 * 10^(指数符号 * 指数 - 小数位数)
		string temp = Convert(ans);
		vector<string>::iterator i; //定义迭代器(广义容器指针)，指向vector<string>类型的元素
		i = RT.begin();             //迭代器指向RT表的表头
		int num = 0, bo = 0;
		while (i != RT.end())
		{
			num++;
			if (*i == temp)
			{
				bo = 1;  //实数表中已有该数
				break;
			}
			i++;
		}
		if (bo == 1)
		{
			token.name = "RT";
			token.location = num;
			Token.push_back(token);  //记录Token到总Token表中
		}
		else
		{
			token.name = "RT";
			token.location = num + 1;
			RT.push_back(temp);          //在实数表中加入新值temp
			Token.push_back(token);
		}
	}
	if (t == 0)
	{
		ans = ans * f;  // 常数 * 常数符号
		string temp = Convert2((ll)ans);
		vector<string>::iterator i;
		i = CT.begin();
		int num = 0, bo = 0;
		while (i != CT.end())
		{
			num++;
			if (*i == temp)
			{
				bo = 1;
				break;
			}
			i++;
		}
		if (bo == 1)
		{
			token.name = "CT";
			token.location = num;
			Token.push_back(token);
		}
		else
		{
			token.name = "CT";
			token.location = num + 1;
			CT.push_back(temp);
			Token.push_back(token);
		}
	}
}

//查找关键字并返回location(不是则返回0)
int LexAnalyser::reserve(char* strt)
{
	string str = strt;
	vector<string>::iterator i;
	i = KT.begin();
	int num = 0;
	while (i != KT.end())
	{
		num++;
		if (*i == str)
			return num;
		i++;
	}
	return 0;
}

//查找界符并返回location(不是则返回0)
int LexAnalyser::reserve2(char* strt)
{
	string str = strt;
	vector<string>::iterator i;
	i = PT.begin();
	int num = 0;
	while (i != PT.end())
	{
		num++;
		if (*i == str)
			return num;
		i++;
	}
	return 0;
}

//标识符识别机并返回location
int LexAnalyser::InsertIT(char* strt)   
{
	string str = strt;
	vector<string>::iterator i;
	i = IT.begin();
	int num = 0;
	string s = strt;
	while (i != IT.end())
	{
		num++;
		if (*i == s)
			return num;
		i++;
	}
	IT.push_back(s);
	return num + 1;
}

//字符识别机并返回location
int LexAnalyser::InsertcT(char* strt)
{
	string str = strt;
	vector<string>::iterator i;
	i = cT.begin();
	int num = 0;
	string s = strt;
	while (i != cT.end())
	{
		num++;
		if (*i == s)
			return num;
		i++;
	}
	cT.push_back(s);
	return num + 1;
}

//字符串识别机并返回location
int LexAnalyser::InsertST(char* strt)
{
	string str = strt;
	vector<string>::iterator i;
	i = ST.begin();
	int num = 0;
	string s = strt;
	while (i != ST.end())
	{
		num++;
		if (*i == s)
			return num;
		i++;
	}
	ST.push_back(s);
	return num + 1;
}

// 打印Token表
void LexAnalyser::Print()
{
	vector<TokenNode>::iterator i;
	i = Token.begin();
	TokenNode t;
	while (i != Token.end())
	{
		t = *i;
		cout << "(" << t.name << "," << t.location << ")" << endl;
		i++;
	}
}

// 词法分析主程序
void LexAnalyser::lexical(string line)
{

	int i_line;            //line中第i个字符，相当于文件内容指针，初始位于文件开始处
	char ch;               //当前文件指针位置的字符
	char strt[50] = {};         //存储当前识别的单词
	int i_str;      //当前识别的单词中的第i个字符 
	int value;      //存储函数返回值，一般为location
	TokenNode token;
	i_line = 0;
	ch = line[i_line++]; // i_line 为ch的下一个字符的位置
	while (ch)  // ch == '\0'时退出
	{
		i_str = 0;
		while (ch == ' ' || ch == '\n')  //跳过源文件中的空格与换行
			ch = line[i_line++];

		if (IfLetter(ch))				//字母开头的单词，识别为关键字或标识符
		{
			while (IfLetter(ch) || IfDigit(ch))   //若是字母或数字 
			{
				strt[i_str++] = ch;       //拼接到strt中
				ch = line[i_line++];
			}
			strt[i_str] = '\0';
			value = reserve(strt);     //查关键字表；

			if (value)				//不是关键字就是标识符 
			{
				token.name = "KT";
				token.location = value;
				Token.push_back(token);
			}
			else
			{
				value = InsertIT(strt);
				token.name = "IT";
				token.location = value;
				Token.push_back(token);
			}
		}

		else if (IfDigit(ch))           //常数开头的  识别为常数
		{
			int e_n = 0, d_n = 0;
			while (IfDigit(ch) || ch == 'e' || ch == '.')   //add error pending   -needing
			{
				if (ch == 'e')
				{
					if (e_n == 0)
						e_n = 1;
					else
					{
						cout << "词法错误error：CT/RT" << endl;  //存在多个'e'
						exit(0);
					}
				}
				if (ch == '.')
				{
					if (d_n == 0)
						d_n = 1;
					else
					{
						cout << "词法错误error：CT/RT" << endl;  //存在多个'.'
						exit(0);
					}
				}
				strt[i_str++] = ch;
				ch = line[i_line++];
			}
			strt[i_str++] = '\0';
			constant((string)strt);
		}
		else if (ch == 34 || ch == 39)      //34="   39='
		{
			if (ch == 39)//单  识别为字符
			{

				ch = line[i_line++];
				strt[0] = ch;
				ch = line[i_line++];
				ch = line[i_line++]; //令ch指向'*'后一位的字符
				strt[1] = '\0';
				value = InsertcT(strt);
				token.name = "cT";
				token.location = value;
				Token.push_back(token);
			}
			else  //双 识别为字符串
			{
				ch = line[i_line++];
				while (IfLetter(ch))
				{
					strt[i_str++] = ch;       //拼接到strt中
					ch = line[i_line++];
				}
				if (ch == 34)
				{
					ch = line[i_line++];
				}
				else
				{
					cout << "error: cT/ST" << endl;
					exit(0);
				}
				strt[i_str++] = '\0';
				value = InsertST(strt);
				token.name = "ST";
				token.location = value;
				Token.push_back(token);
			}
		}
		else  //识别为界符
		{
			strt[i_str++] = ch;
			if (ch == ':')
			{
				ch = line[i_line];
				if (ch == '=')
				{
					strt[i_str++] = ch;
					i_line++;
				}
			}
			if (ch == '>')
			{
				ch = line[i_line];
				if (ch == '=')
				{
					strt[i_str++] = ch;
					i_line++;
				}
			}
			if (ch == '<')
			{
				ch = line[i_line];
				if (ch == '=')
				{
					strt[i_str++] = ch;
					i_line++;
				}
			}
			strt[i_str] = '\0';
			value = reserve2(strt);
			if (value)
			{
				token.name = "PT";
				token.location = value;
				Token.push_back(token);
			}
			else
			{
				cout << "词法错误error：PT" << endl;
				exit(0);
			}
			ch = line[i_line++];
		}
	}
}

//读入源文件内容，启动词法分析主程序函数
void LexAnalyser::lexAnalyse(string file_name) {
	ifstream input_file(file_name);  //打开文件file_name并创建输入文件流对象input_file
	if (!input_file) {
		cerr << "无法打开文件:" << file_name << endl;
		exit(-1);
	}
	string file_string((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());//将文件内容全部读入file_string中
	//istreambuf_iterator<char>(input_file)，它指向文件流的开始位置。
	//istreambuf_iterator<char>()，这是一个默认构造的迭代器，表示流的结束。
	lexical(file_string);
	Print();
}
