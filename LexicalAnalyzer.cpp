/*
Name : Gabriel Meran
class: CS 280
section: 3
Assignment 2 Lexical Analzyer



*/


#include "p2lex.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <cctype>
#include <map>

using namespace std;
Token::Token(TokenType t, string s)
{
	tok = this -> t;
	lexeme = this -> s;
	
}

bool operator ==(const Token& left, const Token& right)
{
	s = right.s;
	t = left.t;
	return *this;
}
ostream& operator<<(ostream& out, const Token& t)
{
	string token [] = {"id","str","int","plus","star","leftsq","rightsq","print","set","sc",
						"lparen","rparen","done","err"};
						
						
		if(t.getTok() == 0)
		{
			out << "id" << t.getLexeme() << end;
		}
		
		if(t.getTok() == 1)
		{
			out << "str" << t.getLexeme() << endl;
		}
		
		if(t.getTok() == 2)
		{
			out << "int"<< t.getLexeme() << endl;
		}				
		
		if (t.getTok() == 13)				
        {
        	out << "id" << t.getLexeme() << endl;
		}	
	   
	   out << Token[t.getTok()] << endl;
	   return out;
}
Token getTok(istream *instream)
{
	int linenum = 0;
	string lexeme
	
	for()
	{
		int ch = instream -> get();
		if(instream -> eof()) break;
		
		if(isspace(ch))
			continue;
		lexeme = ch
		
		if (isalpha(ch))
		{
			return Token::tok = ID; 
		}
		
		else if(isdigit(ch))
		{
			return Token::tok = INT; 
		}
		
		else if(ch == '"')
		{
			return Token::tok = STR;
		}
		else if(ch == '+')
		{
			return Token::tok = PLUS;
		}
		else if(ch == '*')
		{
			return Token::tok = STAR; 
		}
		else if(ch == '(')
		{
			return Token::tok = LPAREN;
		}
		else if(ch == ')')
		{
			return Token::tok = RPAREN;
		}
		else if(ch == '[')
		{
			return Token::tok = LEFTSQ;
		}
		
		else if(ch == ']')
		{
			return Token::tok = RIGHTSQ;
		}
		
	}

  }
}

string Token::getLexeme() const
{
	map<Token::TokenType,string> TokName =
	{
		{PLUS, "plus"}
		{STAR, "star"}
		{SC,"sc"}
	};
	/*
	map<Token::TokenType,int> counters;
	Token t;
	string recognized;
	while((t=getToken(in)!= DONE))
	{
		counters[t.getType()]++;
	}
	*/
	
	map<Token::TokenType,int> iterator it;
	
	for( it = counters.begin(); it != counters.end(); it++)
	{ 
		cout << it -> first << ":" << it -> second << endl;
	}
	
	
}

