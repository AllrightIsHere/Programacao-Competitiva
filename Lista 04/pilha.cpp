#include <bits/stdc++.h>

#define msi map<string, int>
#define si stack<int>

using namespace std;

int main()
{
    msi RAM;
    si pilha;
    string comando, key;
    size_t index;
    int i, N, num1, num2;

    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> comando;

        if (comando == "mul")
        {
            num1 = pilha.top();
            pilha.pop();
            num2 = pilha.top();
            pilha.pop();
            pilha.push(num1 * num2);
        }
        else if (comando == "div")
        {
            num1 = pilha.top();
            pilha.pop();
            num2 = pilha.top();
            pilha.pop();
            pilha.push(num2 / num1);
        }
        else if (comando == "print")
        {
            cout << pilha.top() << endl;
            pilha.pop();
        }
        else if (comando == "add")
        {
            num1 = pilha.top();
            pilha.pop();
            num2 = pilha.top();
            pilha.pop();
            pilha.push(num1 + num2);
        }
        else if (comando == "sub")
        {
            num1 = pilha.top();
            pilha.pop();
            num2 = pilha.top();
            pilha.pop();
            pilha.push(num2 - num1);
        }
        else if (comando.find("push_R") != string::npos)
        {
            index = 5;
            key = comando.substr(index, comando.size() - index);
            pilha.push(RAM[key]);
        }
        else if (comando.find("pop_R") != string::npos)
        {
            index = 4;
            key = comando.substr(index, comando.size() - index);
            num1 = pilha.top();
            pilha.pop();
            RAM[key] = num1;
        }
        else
        {
            index = 5;
            key = comando.substr(index, comando.size() - index);
            pilha.push(stoi(key));
        }
    }
    return 0;
}
