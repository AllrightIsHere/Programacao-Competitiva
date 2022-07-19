#include <bits/stdc++.h>

#define pci pair<char, int>
#define ID 275

using namespace std;

/*
Gramática:

or_expr ::= and_expr or_expr'
or_expr' ::= or_op and_expr or_expr' | lambda
and_expr ::= rel_expr and_expr'
and_expr' ::= and_op rel_expr and_expr' | lambda
rel_expr ::= add_expr rel_expr'
rel_expr' ::= rel_op add_expr rel_expr' | lambda
add_expr ::= mul_expr add_expr'
add_expr' ::= add_op mul_expr add_expr' | lambda
mul_expr ::= pow_expr mul_expr'
mul_expr' ::= mul_op pow_expr mul_expr' | lambda
pow_expr ::= factor pow_expr'
pow_expr' ::= pow_op factor pow_expr' | lambda
factor ::= ( or_expr ) | id
or_op ::= |
and_op ::= .
rel_op ::= > | < | = | #
add_op ::= + | -
mul_op ::= * | /
pow_op ::= ^

*/

pci token_atual;
int indice_atual;
string comando;
string result;
map<char, int> alfabeto;
stack<char> parentesis;

void or_expr();

void avancar()
{
    token_atual.first = comando[indice_atual];

    if (isalnum(comando[indice_atual]))
    {
        token_atual.second = ID;
    }
    else if (alfabeto.count(comando[indice_atual]))
    {
        token_atual.second = comando[indice_atual];
        if (comando[indice_atual] == '(')
        {
            parentesis.push('(');
        }
        else if (comando[indice_atual] == ')')
        {
            if (parentesis.empty())
            {
                throw invalid_argument("Syntax Error!");
            }
            else
            {
                parentesis.pop();
            }
        }
    }
    else
    {
        throw invalid_argument("Lexical Error!");
    }

    indice_atual++;
}

void comer(int tag)
{
    if (token_atual.second == tag)
    {
        avancar();
    }
    else
    {
        throw invalid_argument("Syntax Error!");
    }
}

void pow_op()
{
    if (token_atual.second == '^')
    {
        comer('^');
    }
    else
    {
        throw invalid_argument("Syntax Error!");
    }
}

void mul_op()
{
    switch (token_atual.second)
    {
    case '*':
        comer('*');
        break;
    case '/':
        comer('/');
        break;
    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void add_op()
{
    switch (token_atual.second)
    {
    case '+':
        comer('+');
        break;
    case '-':
        comer('-');
        break;
    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void rel_op()
{
    switch (token_atual.second)
    {
    case '>':
        comer('>');
        break;
    case '<':
        comer('<');
        break;
    case '=':
        comer('=');
        break;
    case '#':
        comer('#');
        break;
    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void and_op()
{
    if (token_atual.second == '.')
    {
        comer('.');
    }
    else
    {
        throw invalid_argument("Syntax Error!");
    }
}

void or_op()
{
    if (token_atual.second == '|')
    {
        comer('|');
    }
    else
    {
        throw invalid_argument("Syntax Error!");
    }
}

void factor()
{
    switch (token_atual.second)
    {
    case ID:
        // cout << token_atual.first;
        result += token_atual.first;
        comer(ID);
        break;
    case '(':
        comer('(');
        or_expr();
        comer(')');
        break;
    case '\0':
        break;
    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void pow_expr_prime()
{
    pci aux = token_atual;

    switch (token_atual.second)
    {
    case '^':
        pow_op();
        factor();
        // cout << aux.first;
        result += aux.first;
        pow_expr_prime();
        break;
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '>':
    case '<':
    case '=':
    case '#':
    case '.':
    case '|':
    case '\0':
        break;
    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void pow_expr()
{
    switch (token_atual.second)
    {
    case ID:
    case '(':
        factor();
        pow_expr_prime();
        break;

    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void mul_expr_prime()
{
    pci aux = token_atual;

    switch (token_atual.second)
    {
    case '*':
    case '/':
        mul_op();
        pow_expr();
        // cout << aux.first;
        result += aux.first;
        mul_expr_prime();
        break;
    case ')':
    case '+':
    case '-':
    case '>':
    case '<':
    case '=':
    case '#':
    case '.':
    case '|':
    case '\0':
        break;
    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void mul_expr()
{
    switch (token_atual.second)
    {
    case ID:
    case '(':
        pow_expr();
        mul_expr_prime();
        break;

    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void add_expr_prime()
{
    pci aux = token_atual;

    switch (token_atual.second)
    {
    case '+':
    case '-':
        add_op();
        mul_expr();
        // cout << aux.first;
        result += aux.first;
        add_expr_prime();
        break;
    case ')':
    case '>':
    case '<':
    case '=':
    case '#':
    case '.':
    case '|':
    case '\0':
        break;
    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void add_expr()
{
    switch (token_atual.second)
    {
    case ID:
    case '(':
        mul_expr();
        add_expr_prime();
        break;

    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void rel_expr_prime()
{
    pci aux = token_atual;

    switch (token_atual.second)
    {
    case '>':
    case '<':
    case '=':
    case '#':
        rel_op();
        add_expr();
        // cout << aux.first;
        result += aux.first;
        rel_expr_prime();
        break;
    case ')':
    case '.':
    case '|':
    case '\0':
        break;
    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void rel_expr()
{
    switch (token_atual.second)
    {
    case ID:
    case '(':
        add_expr();
        rel_expr_prime();
        break;

    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void and_expr_prime()
{
    pci aux = token_atual;
    switch (token_atual.second)
    {
    case '.':
        and_op();
        rel_expr();
        // cout << aux.first;
        result += aux.first;
        and_expr_prime();
        break;
    case '|':
    case ')':
    case '\0':
        break;

    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void and_expr()
{
    switch (token_atual.second)
    {
    case ID:
    case '(':
        rel_expr();
        and_expr_prime();
        break;

    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void or_expr_prime()
{
    pci aux = token_atual;
    switch (token_atual.second)
    {
    case '|':
        or_op();
        and_expr();
        // cout << aux.first;
        result += aux.first;
        or_expr_prime();
        break;
    case ')':
    case '\0':
        break;
    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

void or_expr()
{
    switch (token_atual.second)
    {
    case ID:
    case '(':
        and_expr();
        or_expr_prime();
        break;

    default:
        throw invalid_argument("Syntax Error!");
        break;
    }
}

int main()
{
    alfabeto['+']++;
    alfabeto['-']++;
    alfabeto['*']++;
    alfabeto['/']++;
    alfabeto['^']++;
    alfabeto['.']++;
    alfabeto['|']++;
    alfabeto['>']++;
    alfabeto['<']++;
    alfabeto['=']++;
    alfabeto['#']++;
    alfabeto['(']++;
    alfabeto[')']++;
    alfabeto['\0']++;
    while (getline(cin, comando))
    {
        try
        {
            stack<char> x;
            parentesis.swap(x);
            result = "";
            indice_atual = 0;
            avancar();

            or_expr();

            if (!parentesis.empty())
            {
                throw invalid_argument("Syntax Error!");
            }

            cout << result;
        }
        catch (invalid_argument &e)
        {
            cout << e.what();
        }

        cout << endl;
    }
    return 0;
}