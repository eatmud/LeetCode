#include <iostream>
#include <stack>
using namespace std;

class LeetCode20 {
public:
    bool isValid(string s) {
        // 先判断是否为空字符串
        if (s.empty()) {
            return true;
        }
        stack<char> p;
        for (auto ch : s) {
            // 栈为空但字符为右括号，返回false
            if (p.empty() && (ch == ')' || ch == ']' || ch == '}')) {
                return false;
            }
            // 左括号进栈
            // 右括号需要和栈顶元素做匹配，配对不上为false，否则进行出栈
            // 最后判断栈是否为空，为空返回true
            if (ch == '(' || ch == '[' || ch == '{') {
                p.push(ch);
            } else {
                if (ch == ')' && p.top() != '(') {
                    return false;
                } else if (ch == ']' && p.top() != '[') {
                    return false;
                } else if (ch == '}' && p.top() != '{') {
                    return false;
                } else {
                    p.pop();
                }
            }
        }
        return p.empty();
    }
};
class MinStack {
public:
    MinStack() {

    }
//    辅助栈与数据栈同步更新
//    辅助栈栈顶存放当前最小元素，当进栈元素比辅助栈栈顶元素小时，元素进辅助栈，
//    否则把辅助栈栈顶元素再次压入辅助栈
    void push(int x) {
        data.push(x);
        if (tool.empty() || tool.top() > x) {
            tool.push(x);
        } else {
            tool.push(tool.top());
        }
    }
    void pop() {
        if (!tool.empty()) {
            tool.pop();
            data.pop();
        }
    }
    int top() {
        return data.top();
    }
    int getMin() {
        return tool.top();
    }
    MinStack() {

    }
//    辅助栈与数据栈不同步更新
//    辅助栈只在为空和栈顶元素比入栈元素大时才入栈
//    辅助栈出栈，只有辅助栈栈顶元素和数据栈相等时才出栈
    void push(int x) {
        data.push(x);
        if (tool.empty() || tool.top() >= x) {
            tool.push(x);
        }
    }
    void pop() {
        if (!data.empty()) {
            int top = data.top();
            data.pop();
            if (!tool.empty() && top == tool.top()) {
                tool.pop();
            }
        }
    }
    int top() {
        return data.top();
    }
    int getMin() {
        return tool.top();
    }
private:
    stack<int> data;
    stack<int> tool;
};
