#include "Scanner.h"
bool Scanner::isBuild = 0;
int Scanner::G_BuildTokenTable[29][20] =
{
	{ 1, -1, -1, -1, 8, 27, 23, 6, 7, 11, 12, -1, 15, -1, -1, 19, -1, -1, 28, -1 },
	{ -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
	{ -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
	{ -1, -1, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
	{ -1, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
	{ 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27 },
	{ 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34 },
	{ 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35 },
	{ 32, 32, 32, 32, 32, 9, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ -1, -1, -1, -1, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
	{ 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28 },
	{ 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31 },
	{ 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 13, 33, 33, 33, 33, 33, 33, 33, 33 },
	{ 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 14, 33, 14, 33, 33, 33, 33, 33, 33, 33 },
	{ 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 14, 33, 14, 33, 33, 33, 33, 33, 33, 33 },
	{ 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 16, 17, 16, 33, 33, 33, 33, 33, 33, 33 },
	{ 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 16, 17, 16, 33, 33, 33, 33, 33, 33, 33 },
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 18, -1, 18, -1, -1, -1, -1, -1, -1, -1 },
	{ 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 18, 33, 18, 33, 33, 33, 33, 33, 33, 33 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 20, 32, 32, 32 },
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 21, -1, -1 },
	{ -1, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
	{ 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33 },
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 24, -1, -1, -1, -1, -1, -1 },
	{ -1, -1, -1, 25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 26, -1, -1, -1, -1, -1 },
	{ 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 }
};
map<char, int> Scanner::StrToIndex;
Scanner::Scanner()
{
	if (!isBuild)
	{
		BuildTokenTable();
		isBuild = 1;
	}
}
void Scanner::BuildTokenTable()
	{
		StrToIndex['f'] = 0;
		StrToIndex['l'] = 1;
		StrToIndex['o'] = 2;
		StrToIndex['r'] = 3;
		StrToIndex['a'] = 4;
		StrToIndex['b'] = 5;
		StrToIndex['s'] = 6;
		StrToIndex['('] = 7;
		StrToIndex[')'] = 8;
		StrToIndex['+'] = 9;
		StrToIndex['-'] = 9;
		StrToIndex['*'] = 9;
		StrToIndex['/'] = 9;
		StrToIndex['^'] = 9;
		StrToIndex['0'] = 10;
		StrToIndex['.'] = 11;
		StrToIndex['1'] = 12;
		StrToIndex['2'] = 12;
		StrToIndex['3'] = 12;
		StrToIndex['4'] = 12;
		StrToIndex['5'] = 12;
		StrToIndex['6'] = 12;
		StrToIndex['7'] = 12;
		StrToIndex['8'] = 12;
		StrToIndex['9'] = 12;
		StrToIndex['q'] = 13;
		StrToIndex['t'] = 14;
		StrToIndex['c'] = 15;
		StrToIndex['e'] = 16;
		StrToIndex['i'] = 17;
		StrToIndex['d'] = 18;
		StrToIndex[EOF] = 19;
		
	}

vector<Token> Scanner::scan(string input)
{
	vector<Token> ReadToken;
	int pee = 0;
	string ReadString;
	int TokenStatus = 0;
	for (; pee < input.size(); ++pee)
	{
		char NextChar;
		int NextIndex;
		char temp = input[pee];
		if (StrToIndex.find(temp) == StrToIndex.end())
		{
			cout << "Invalid Input" << endl;
			return ReadToken;
		}
		int index = StrToIndex.at(temp);
		if (pee == input.size() - 1)
		{
			NextChar = EOF;;
		}
		else
		{
			NextChar = input[pee + 1];
		}
		if (StrToIndex.find(NextChar) == StrToIndex.end())
		{
			cout << "Invalid Input" << endl;
			return ReadToken;
		}
		NextIndex = StrToIndex.at(NextChar);
		/*assert(TokenStatus!=-1);*/
		if (TokenStatus == -1)
		{
			cout << "error" << endl;
			return ReadToken;
		}
		if (G_BuildTokenTable[G_BuildTokenTable[TokenStatus][index]][NextIndex] > 26)
		{
			switch (G_BuildTokenTable[G_BuildTokenTable[TokenStatus][index]][NextIndex])
			{
			case 27://floor
			case 28://abs
			case 29://ceil
			case 30://sqrt
				//ReadString.pop_back();
				ReadString += temp;
				ReadToken.push_back(Token(FUNCTION, ReadString));
				ReadString = "";
				//--pee;
				TokenStatus = 0;
				break;
			case 31://operator
				//ReadString.pop_back();
				ReadString += temp;
				ReadToken.push_back(Token(OPERATION, ReadString));
				ReadString = "";
				//--pee;
				TokenStatus = 0;
				break;
			case 32://id
				//ReadString.pop_back();
				ReadString += temp;
				ReadToken.push_back(Token(IDER, ReadString));
				ReadString = "";
				TokenStatus = 0;
				//--pee;
				break;
			case 33://num
				//ReadString.pop_back();
				ReadString += temp;
				ReadToken.push_back(Token(NUM_FLOAT, ReadString));
				ReadString = "";
				TokenStatus = 0;
				//--pee;
				break;
			case 34://(
				//ReadString.pop_back();
				ReadString += temp;
				ReadToken.push_back(Token(LEFT_B, ReadString));
				ReadString = "";
				//--pee;
				TokenStatus = 0;
				break;
			case 35://)
				//ReadString.pop_back();
				ReadString += temp;
				ReadToken.push_back(Token(RIGHT_B, ReadString));
				ReadString = "";
				TokenStatus = 0;
				//--pee;
				break;
			}

		}
		else
		{
			TokenStatus = G_BuildTokenTable[TokenStatus][index];
			ReadString += temp;

		}
	}
	if (TokenStatus != 0)
	{
		cout << "error" << endl;
	}
	return ReadToken;
}
Scanner::~Scanner()
{
}
