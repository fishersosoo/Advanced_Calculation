#pragma once
#include "Token.h"
class Scanner
{
private:
	static map<char, int> StrToIndex;
	static bool isBuild;
	void BuildTokenTable();
	static int G_BuildTokenTable[29][20];
public:
	Scanner();
	vector<Token> scan(string input);
	~Scanner();
};

