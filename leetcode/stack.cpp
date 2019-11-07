#include <iostream>
#include <stack>
using namespace std;

class LeetCode20 {
public:
    bool isValid(string s) {
        // ���ж��Ƿ�Ϊ���ַ���
        if (s.empty()) {
            return true;
        }
        stack<char> p;
        for (auto ch : s) {
            // ջΪ�յ��ַ�Ϊ�����ţ�����false
            if (p.empty() && (ch == ')' || ch == ']' || ch == '}')) {
                return false;
            }
            // �����Ž�ջ
            // ��������Ҫ��ջ��Ԫ����ƥ�䣬��Բ���Ϊfalse��������г�ջ
            // ����ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���true
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
//    ����ջ������ջͬ������
//    ����ջջ����ŵ�ǰ��СԪ�أ�����ջԪ�رȸ���ջջ��Ԫ��Сʱ��Ԫ�ؽ�����ջ��
//    ����Ѹ���ջջ��Ԫ���ٴ�ѹ�븨��ջ
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
//    ����ջ������ջ��ͬ������
//    ����ջֻ��Ϊ�պ�ջ��Ԫ�ر���ջԪ�ش�ʱ����ջ
//    ����ջ��ջ��ֻ�и���ջջ��Ԫ�غ�����ջ���ʱ�ų�ջ
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
