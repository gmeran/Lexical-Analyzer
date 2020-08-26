#include <cstdlib>
#include <fstream>
#include <cctype>
#include <map>
#include <vector>
#include "p2lex.h"

using namespace std;

/*
 *
 */
int linenum = 0;
string* getTokenName(TokenType t)
{
    switch(t)
    {
        case ID:
        {
            return new string("id");
        }
        case STR:
        {
        return new string("str");
        }
        case INT:
        {
        return new string("Integer");
        }
        case PLUS:
        {
        return new string("plus");
        }
        case STAR:
        {
        return new string("star");
        }
        case SET:
        {
            return new string("set");

        }
        case PRINT:
        {
            return new string("print");

        }
        case LPAREN:
        {
            return new string("Left paren");

        }
        case RPAREN:
        {
            return new string("Right paren");

        }
        case LEFTSQ:
{
return new string("leftsq");

}
case RIGHTSQ:
{
return new string("rightsq");
}
        case SC:
        {
            return new string("Semicolon");

        }
        case ERR:
        {
            return new string("Error");

        }
        case DONE:
        {
            return new string("Done");

        }
        default :
            return new string("NAT"); // not a token 
    }
}
int main(int argc, char** argv) {

    istream * input;
    
    if(argc == 1) // no file input
    {
        input = &cin;
    }
    else if(argc > 2)
    {
        cout << "wrong arguments" << '\n';
        return 0;
    }
    else
    {
        input = new fstream(argv[1]);
        if(!((fstream *)input)->is_open())
        {
            cout << "wrong file" << '\n';
            return 0;
        }
    }
    Token t;
    map<TokenType,int> m1;
    map<int, vector<TokenType> > m2;
    map<string, int> idLexemes;
    map<string, int> strLexemes;
    map<string, int> intLexemes;

    do
    {
        t = getToken(input); //get token
        if(t.getTok() == ID) // save identifiers
            idLexemes[t.getLexeme()]++;
        else if(t.getTok() == STR)
        strLexemes[t.getLexeme()]++;
        else if(t.getTok() == INT)
        intLexemes[t.getLexeme()]++;
        if(t.getTok() == ERR)
        {
            cout << "Error on line " << linenum << "\n";
            return 0;
        }
        else if(t.getTok() != DONE)
        {
            m1[t.getTok()]++;
        }
    }
    while(t.getTok() != DONE);
    
    for (std::map<TokenType ,int>::iterator it=m1.begin(); it!=m1.end(); ++it)
        m2[it->second].push_back(it->first);
   
    int num = 0;
    for (std::map< int , std::vector<TokenType> > ::reverse_iterator it=m2.rbegin(); it!=m2.rend() && num < 3; ++it)
    {   
        int occurences = it->first;
        for(std::vector<TokenType>::iterator it2=it->second.begin(); it2!= it->second.end(); ++it2)
        {
            cout << *getTokenName(*it2) <<": " << occurences << '\n';
        }
        num++;
    }

    cout << "Number of unique lexemes for id: " << idLexemes.size() << '\n';
    cout << "Number of unique lexemes for str: " << strLexemes.size() << '\n';
    cout << "Number of unique lexemes for int: " << intLexemes.size() << '\n';
}

Token getToken(istream *br)
{
    TokenType t;
    string lexeme;
    char c = br->get();
    
    //next block of code advances past comments and white space
    bool iscomment = false;
    while(c == '/' || c == ' ' || c == '\n' || c == '\t' || iscomment)
    {
        if(c == '\n')
        {
            iscomment = false;
            linenum++;
        }
        char next = br->peek();
        if(!iscomment && next == '/' && c == '/')
            iscomment = true;
        c = br->get();
    }
    
    
    if(isalpha(c)) // identifying an identifier
    {
        do
        {
            lexeme+=c;
            c = br->get();
        }
        while(isalpha(c));
        
        if(lexeme == "print")
            t = PRINT;
        else if(lexeme == "set")
            t = SET;
        else
             t = ID;
        br->putback(c);
        
    }
    else if(c == '\"') // string constant
    {
        c = br->get();
        while(c != '\"' && c != '\n')
        {
            lexeme+=c;
            c = br->get();
        }
        if(c == '\"')
        {
            t = STR;
        }
        else
        {
            t = ERR;
            linenum+=2;
        }
    }
    else if(c == '+') //plus op
    {
        t = PLUS;
        lexeme+=c;
    }
    else if(c == '*') // Multiply op
    {
        t = STAR;
        lexeme+=c;
    }
    else if(c == ';') // semicolon
    {
        t = SC;
        lexeme+=c;
    }
    else if(c == '[')
    {
    t = LEFTSQ;
    lexeme+=c;
    }
    else if(c == ']')
    {
    t = RIGHTSQ;
    lexeme+=c;
    }
    else if(c == '(') // left paren
    {
        t = LPAREN;
        lexeme+=c;
    }
    else if(c == ')') // right paren
    {
        t = RPAREN;
        lexeme+=c; 
    }
    else if(c == -1) // end of stream
    {
        t = DONE;
    }
    else // if the token is none of these tokens then its an error
    {
        t = ERR;
    }
    
    return Token(t,lexeme);
  
}
