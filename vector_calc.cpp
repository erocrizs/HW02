#include "vector2.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

#define isAlpha(c) ('A'<=c && c<='Z')||('a'<=c && c<='z')
#define isNumeric(c) ('0'<=c && c<='9')||(c=='.')
#define isOp(c) (c=='+' || c=='-' || c=='*' || c=='%' || c=='/' || c=='(' || c==')')

enum tokenType {
	SCALAR,
	VECTOR,
	OPERATOR
};
struct token {
	union {
		char op;
		float f;
		Vector2 v;
	};
	tokenType type;
	token(float f=0): type(SCALAR) {
		this->f = f;
	}
	token(Vector2 v): type(VECTOR) {
		this->v = v;
	}
	token(char op): type(OPERATOR) {
		this->op = op;
	}
};

std::ostream& operator<<(std::ostream& os, const token& t) {
	if(t.type==SCALAR)
		os << t.f;
	else if(t.type==VECTOR)
		os << t.v;
	else if(t.type==OPERATOR)
		os << t.op;
	return os;
}

int main()
{
	map<string, Vector2> variable;

	// saving the input
	string name;
	while(cin>>name && name!="=")
	{
		float x, y;
		cin >> x >> y;
		if(variable.find(name)!=variable.end())
			cout << "INVALID: VARIABLE NAME USED" << endl;
		else
			variable[name] = Vector2(x, y);
	}

	string eq;
	while(getline(cin, eq))
	{
		// parsing the equation
	}

	return 0;
}