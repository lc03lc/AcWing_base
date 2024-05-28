#include <iostream>
#include <stack>
#include <unordered_map>
#include <cctype>
using namespace std;

stack<int> nums;
stack<char> op;
unordered_map<char, int> pr{
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval()
{
    auto b = nums.top();
    nums.pop();
    auto a = nums.top();
    nums.pop();
    auto oper = op.top();
    op.pop();
    if (oper == '+')
    {
        nums.push(a + b);
    }
    else if (oper == '-')
    {
        nums.push(a - b);
    }
    else if (oper == '*')
    {
        nums.push(a * b);
    }
    else
    {
        nums.push(a / b);
    }
}

int main()
{
    stack<int> st;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        char cur = str[i];
        if (cur == '(')
        {
            op.push(cur);
        }
        else if (cur == ')')
        {
            while (op.top() != '(')
            {
                eval();
            }
            op.pop();
        }
        else if (isdigit(cur))
        {
            int x = 0;
            while (i < str.size() && isdigit(str[i]))
            {
                x = x * 10 + (str[i++] - '0');
            }
            nums.push(x);
            i--;
        }
        else
        {
            while (op.size() && pr[op.top()] >= pr[cur])
            {
                eval();
            }
            op.push(cur);
        }
    }
    while (op.size())
    {
        eval();
    }
    cout << nums.top();
}