#include "Token.h"


map<char, int> StrToIndex;
void BuildTokenTable()
{
	static bool isbuild=0;
	StrToIndex['f']=0;
	StrToIndex['l']=1;
	StrToIndex['o']=2;
	StrToIndex['r']=3;
	StrToIndex['a']=4;
	StrToIndex['b']=5;
	StrToIndex['s']=6;
	StrToIndex['(']=7;
	StrToIndex[')']=8;
	StrToIndex['+']=9;
	StrToIndex['-']=9;
	StrToIndex['*']=9;
	StrToIndex['/']=9;
	StrToIndex['^']=9;
	StrToIndex['0']=10;
	StrToIndex['.']=11;
	StrToIndex['1']=12;
	StrToIndex['2']=12;
	StrToIndex['3']=12;
	StrToIndex['4']=12;
	StrToIndex['5']=12;
	StrToIndex['6']=12;
	StrToIndex['7']=12;
	StrToIndex['8']=12;
	StrToIndex['9']=12;
	StrToIndex['q']=13;
	StrToIndex['t']=14;
	StrToIndex['c']=15;
	StrToIndex['e']=16;
	StrToIndex['i']=17;
	StrToIndex['d']=18;
	StrToIndex[EOF]=19;
}
vector<Token> scan(string input)
{
	vector<Token> ReadToken;
	int pee=0;
	string ReadString;
	int TokenStatus=0;
	for (;pee<input.size();++pee)
	{
		char NextChar;
		int NextIndex;
		char temp=input[pee];
		if (StrToIndex.find(temp)==StrToIndex.end())
		{
			cout<<"Invalid Input"<<endl;
			return ReadToken;
		}
		int index=StrToIndex.at(temp);
		if (pee==input.size()-1)
		{
			NextChar=EOF;;
		}
		else
		{
			NextChar=input[pee+1];
		}
		if (StrToIndex.find(NextChar)==StrToIndex.end())
		{
			cout<<"Invalid Input"<<endl;
			return ReadToken;
		}
		NextIndex=StrToIndex.at(NextChar);
		/*assert(TokenStatus!=-1);*/
		if (TokenStatus==-1)
		{
			cout<<"error"<<endl;
			return ReadToken;
		}
		if (G_BuildTokenTable[G_BuildTokenTable[TokenStatus][index]][NextIndex]>26)
		{
			switch (G_BuildTokenTable[G_BuildTokenTable[TokenStatus][index]][NextIndex])
			{
			case 27://floor
			case 28://abs
			case 29://ceil
			case 30://sqrt
				//ReadString.pop_back();
				ReadString+=temp;
				ReadToken.push_back(Token(FUNCTION,ReadString));
				ReadString="";
				//--pee;
				TokenStatus=0;
				break;
			case 31://operator
				//ReadString.pop_back();
				ReadString+=temp;
				ReadToken.push_back(Token(OPERATION,ReadString));
				ReadString="";
				//--pee;
				TokenStatus=0;
				break;
			case 32://id
				//ReadString.pop_back();
				ReadString+=temp;
				ReadToken.push_back(Token(IDER,ReadString));
				ReadString="";
				TokenStatus=0;
				//--pee;
				break;
			case 33://num
				//ReadString.pop_back();
				ReadString+=temp;
				ReadToken.push_back(Token(NUM_FLOAT,ReadString));
				ReadString="";
				TokenStatus=0;
				//--pee;
				break;
			case 34://(
				//ReadString.pop_back();
				ReadString+=temp;
				ReadToken.push_back(Token(LEFT_B,ReadString));
				ReadString="";
				//--pee;
				TokenStatus=0;
				break;
			case 35://)
				//ReadString.pop_back();
				ReadString+=temp;
				ReadToken.push_back(Token(RIGHT_B,ReadString));
				ReadString="";
				TokenStatus=0;
				//--pee;
				break;
			}
			
		}
		else
		{
				TokenStatus=G_BuildTokenTable[TokenStatus][index];
				ReadString+=temp;
		
		}	
	}
	if (TokenStatus!=0)
	{
		cout<<"error"<<endl;
	}
	return ReadToken;
}
void main()
{
	BuildTokenTable();
	string instr;
	cin>>instr;
	vector<Token> a=scan(instr);
 	for (int i = 0; i < a.size(); i++)
 	{
 		cout<<a[i].TokenValue<<endl;
 	}
	system("pause");
	return ;
}