class MinStack {
private:
    stack<int> elem;
    stack<int> min;
    
public:
    void push(int x) {
        elem.push(x);
        if(min.empty() || min.top() >= x) // must include '='
            min.push(x);
    }

    void pop() {
        if(min.top() == elem.top())
            min.pop();
        elem.pop();
    }

    int top() {
        return elem.top();
    }

    int getMin() {
        return min.top();
    }
};