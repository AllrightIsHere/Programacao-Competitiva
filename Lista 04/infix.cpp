#include <bits/stdc++.h>

#define pci pair<char, int>
#define ID 275

using namespace std;

/*
Gramática:

add_expr ::= mul_expr add_expr'
add_expr' ::= add_op mul_expr add_expr' | lambda
mul_expr ::= pow_expr mul_expr'
mul_expr' ::= mul_op pow_expr mul_expr' | lambda
pow_expr ::= factor pow_expr'
pow_expr' ::= pow_op factor pow_expr' | lambda
factor ::= ( expr ) | id
add_op ::= + | -
mul_op ::= * | /
pow_op ::= ^

*/

pci token_atual;
int indice_atual;
string comando;

void add_expr();

void avancar()
{
    token_atual.first = comando[indice_atual];

    if (isalnum(comando[indice_atual]))
    {
        token_atual.second = ID;
    }
    else
    {
        token_atual.second = comando[indice_atual];
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
        cout << "Error" << endl;
    }
}

void power_op()
{
    if (token_atual.second == '^')
    {
        comer('^');
    }
}

void mul_div_op()
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
        break;
    }
}

void factor()
{
    switch (token_atual.second)
    {
    case ID:
        cout << token_atual.first;
        comer(ID);
        break;
    case '(':
        comer('(');
        add_expr();
        comer(')');
        break;
    default:
        break;
    }
}

void pow_expr_prime()
{
    pci aux = token_atual;

    switch (token_atual.second)
    {
    case '^':
        power_op();
        factor();
        cout << aux.first;
        pow_expr_prime();
        break;

    default:
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
        mul_div_op();
        pow_expr();
        cout << aux.first;
        mul_expr_prime();
        break;

    default:
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
        cout << aux.first;
        add_expr_prime();
        break;

    default:
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
        break;
    }
}

int main()
{
    int N;

    cin >> N;

    while (N--)
    {
        cin >> comando;

        indice_atual = 0;
        avancar();

        add_expr();

        cout << endl;
    }
    return 0;
}