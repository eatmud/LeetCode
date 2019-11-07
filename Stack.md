# 栈

[LeetCode-20有效括号](### LeetCode-20 有效括号)

[LeetCode-155最小栈](###LeetCode-155 最小栈)

### LeetCode-20 有效括号
中等难度

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
链接：[https://leetcode-cn.com/problems/valid-parentheses](https://leetcode-cn.com/problems/valid-parentheses)。

```c++
class Solution {
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
```

### LeetCode-155 最小栈

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
链接：https://leetcode-cn.com/problems/min-stack

```c++
class MinStack {
public:
    MinStack() {
        
    }
//    辅助栈与数据栈同步更新
//    辅助栈栈顶存放当前最小元素，当进栈元素比辅助栈栈顶元素小时，元素进辅助栈，
//    否则把辅助栈栈顶元素再次压入辅助栈
    void push(int x) {
        data.push(x);
        if (tool.empty() || tool.top() >= x) {
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
private:
    stack<int> data;
    stack<int> tool;
};
```

```c++
class MinStack {
public:
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
```

