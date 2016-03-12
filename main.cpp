#include "Scanner.h"


void main()
{
	Scanner s;
	string instr;
	cin>>instr;
	vector<Token> a=s.scan(instr);
 	for (int i = 0; i < a.size(); i++)
 	{
 		cout<<a[i].TokenValue<<endl;
 	}
	system("pause");
	return ;
}