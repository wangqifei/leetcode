// 225 Implement Stack using Queues Total Accepted: 5031 Total Submissions: 17066 My Submissions Question Solution 
// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
// Notes:
// You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
// Update (2015-06-11):
// The class name of the Java function had been updated to MyStack instead of Stack.

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and all test cases.

// Hide Tags Data Structure


class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for(int i = 0; i < sz-1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop(void) {
        q.pop();
    }

    // Get the top element.
    int top(void) {  //Caution!!! cannot use back(), thus we need to put the latest one at front. for deque, we cannot use push_front(), but only can use the same function from queue
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty(void) {
        return q.empty();
    }
private:
    queue<int> q;
};