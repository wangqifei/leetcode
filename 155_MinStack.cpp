// 155 Min Stack
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
// Hide Tags Stack Data Structure

class MinStack {
public:
    void push(int x) {
        if(min_st.empty() || min_st.top() >= x) {
            min_st.push(x);
        }
        st.push(x);
    }

    void pop() {
        if(min_st.top() == st.top()) {
            min_st.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
private:
    stack<int> st;
    stack<int> min_st;
};

//this solution use only one stack with the pair element of the current x and the current min number
class MinStack1 {
public:
    void push(int x) {
        if(st.empty()) {
            st.push(make_pair(x,x));
        }
        else {
            int min_num = st.top().second;
            if(min_num < x)
                st.push(make_pair(x, min_num));
            else
                st.push(make_pair(x, x));
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
private:
    stack<pair<int, int> > st;
};