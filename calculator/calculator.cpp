// Crap. See calculator.py

#include <vector>
#include <iostream>
#include <cstdint>
#include <sstream>
using namespace std;

enum Type {
	NONE,
	NUMBER,
	OPERATOR,
	SCOPE_START,
	SCOPE_END
};

struct Operator
{
	Type type;
	bool highPrio;
	char op;
};

struct Number
{
	Type type;
	double num;
};

struct Start
{
	Type type;
};

struct End
{
	Type type;
};

union Token
{
	Type type;
	Operator op;
	Number   num;
	Start    start;
	End      end;
};

struct TokenList
{
	TokenList* next = nullptr;
	Token tok;
};

string tokenInfo(Token const& tok);
double parseNumber(char const*& p);
TokenList* tokenize(char const* p);

TokenList* eval(TokenList* begin, TokenList* end, bool prio)
{
	    TokenList* lhs = begin;
			TokenList* op  = lhs->next;
			TokenList* rhs = op->next;

			while (rhs != end)
			{
				if (op->tok.type == OPERATOR)
				{
				}

				it2 = it2->next;
			}
}

TokenList* evalScope(TokenList* tokens, string indent)
{
	double acc = 0;
	TokenList* it = tokens;

	while (it)
	{
		if (it->next->tok.type == SCOPE_START)
		{
			cout << indent << "[" << endl;
			it->next = evalScope(it->next, indent + "    ");
			//it = it->next;
			cout << indent << "]" << endl;
		}
		else if (it->next->tok.type == SCOPE_END)
		{
			TokenList* eval = new TokenList();
			eval->tok.type = NUMBER;
			eval->tok.num.num = acc;
			eval->next = it->next->next;

			cout << indent << "{" << endl;
			auto it2 = tokens->next;
			while (it2 != it->next)
			{
				cout << indent << "  " << tokenInfo(it2->tok) << endl;
				it2 = it2->next;
			}
			cout << indent << "}" << endl;

			tokens = eval;
			break;
		}
	
		if (it->next->tok.type == NUMBER)
		{
			acc += it->next->tok.num.num;
			cout << indent << "<" << it->next->tok.num.num << " -> " << acc << ">" << endl;
			it = it->next;
		}
		else if (it->next->tok.type == OPERATOR)
		{
			cout << indent << "@" << it->next->tok.op.op << endl;
			it = it->next;
		}
	}

	return tokens;
}

int main(int, char**)
{
	while (cin.good())
	{
		string line;
		getline(cin, line);

		line = "(" + line + ")";

		auto tokens = tokenize(line.c_str());

		auto it = evalScope(tokens, "");

		string delim = "";
		while (it)
		{
			cout << delim << tokenInfo(it->tok);
			delim = ", ";
			it = it->next;
		}
		cout << endl;


	}
	return 0;
}

string tokenInfo(Token const& tok)
{
	stringstream ss;

	switch (tok.type)
	{
		case NUMBER:
			ss << "Number " << tok.num.num;
			break;
		case OPERATOR:
			ss << "Operator " << tok.op.op;
			break;
		case SCOPE_START:
			ss << "(";
			break;
		case SCOPE_END:
			ss << ")";
			break;
	}

	return ss.str();
}


TokenList* tokenize(char const* p)
{

	TokenList* tokenList = nullptr;
	TokenList* lastToken = nullptr;

	auto addToken = [&](Token tok)
	{
		if (tokenList == nullptr)
		{
			tokenList = lastToken = new TokenList();
		}
		else
		{
			lastToken->next = new TokenList();
			lastToken = lastToken->next;
		}

		lastToken->tok = tok;
	};

	Type type = NONE;

	cout << "INPUT: " << p << endl;
	while (*p != 0)
	{
		char c = *p;

		if (c == ' ')
		{
			++p;
			continue;
		}

		Token tok;

		if ((c >= '0' && c <= '9') || (c == '-' && (type == OPERATOR || type == NONE) ))
		{

			type = NUMBER;
			tok.type = type;
			tok.num.num = parseNumber(p);
			
		}
		else if (c == '(')
		{
			tok.type = type = SCOPE_START;
			++p;
		}
		else if (c == ')')
		{
			tok.type = type = SCOPE_END;
			++p;
		}
		else
		{
			tok.type = type = OPERATOR;
			++p;

			tok.op.highPrio = (c == '*' || c == '/');
			tok.op.op = c;
	
		}
		
		addToken(tok);
	}

	return tokenList;
}

double parseNumber(char const*& p)
{
	stringstream ss;

	if (*p == '-')
	{
		ss << "-";
		++p;
	}

	while (*p >= '0' && *p <= '9')
	{
		ss << *p;
		++p;
	}

	double num;
	ss >> num;
	return num;
}
