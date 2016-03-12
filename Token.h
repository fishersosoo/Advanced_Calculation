#pragma once
#include <string>
#include <vector>
#include <assert.h>
#include <map>
#include <iostream>
using namespace std;

static int G_BuildTokenTable[29][20]=
{
	{	1,-1,-1,-1,8,27,23,6,7,11,12,-1,15,-1,-1,19,-1,-1,28,-1					 },
	{	-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1				 },
	{	-1,-1,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1				 },
	{	-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1				 },
	{	-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1				 },
	{	27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27				 },
	{	34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34				 },
	{	35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35				 },
	{	32,32,32,32,32,9,32,32,32,32,32,32,32,32,32,32,32,32,32,32				 },
	{	-1,-1,-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1				 },
	{	28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28				 },
	{	31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31				 },
	{	33,33,33,33,33,33,33,33,33,33,33,13,33,33,33,33,33,33,33,33				 },
	{	33,33,33,33,33,33,33,33,33,33,14,33,14,33,33,33,33,33,33,33				 },
	{	33,33,33,33,33,33,33,33,33,33,14,33,14,33,33,33,33,33,33,33				 },
	{	33,33,33,33,33,33,33,33,33,33,16,17,16,33,33,33,33,33,33,33				 },
	{	33,33,33,33,33,33,33,33,33,33,16,17,16,33,33,33,33,33,33,33				 },
	{	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,18,-1,-1,-1,-1,-1,-1,-1				 },
	{	33,33,33,33,33,33,33,33,33,33,18,33,18,33,33,33,33,33,33,33				 },
	{	32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,20,32,32,32				 },
	{	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21,-1,-1				 },
	{	-1,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1				 },
	{	33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33				 },
	{	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,24,-1,-1,-1,-1,-1,-1				 },
	{	-1,-1,-1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1				 },
	{	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,26,-1,-1,-1,-1,-1				 },
	{	30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30				 },
	{	32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32				 },
	{	32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32	             }
};




enum TokenType
{
	LEFT_B=0,
	RIGHT_B,
	IDER,
	OPERATION,
	FUNCTION,
	NUM_FLOAT
};
class Token
{
public:
	TokenType Type;
	string  TokenValue;
	Token(TokenType  t,string s):Type(t),TokenValue(s){};
	bool IsMatch(TokenType str);
	~Token(void);
};