#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

//MinStack to retrieve minimum value in O(1) time
class MinStack {

private:
    stack<int> normal_stack;
    stack<int> min_stack;    //To store min values of all previous elements

public:

    MinStack() { }

    void push(int n)
	{
        normal_stack.push(n);

        if(min_stack.empty())
		{
        	min_stack.push(n);
		}
        else //Store, every time normal_stack is pushed with new value n, min_stack is pushed with min of n and min_stack's top
        {
        	min_stack.push(min(min_stack.top(), n));
		}

    }
    void pop() {
        normal_stack.pop();
        min_stack.pop();
    }
    int top() {
        return normal_stack.top();
    }
    //Retrieve minimum value in O(1) time
    int getMin() {
        return min_stack.top();
    }
    ~MinStack() { }
};

int main()
{
    MinStack minstack;

    for(int i=1; i<=10; ++i)
    { minstack.push(i); }

    cout<<"top = " <<  minstack.top() << " : Min = " << minstack.getMin() << endl;

    minstack.push(0);
    cout<<"\nAfter pushing 0: " <<endl;
    cout<<"top = " <<  minstack.top() << " : Min = " << minstack.getMin() << endl;

    minstack.pop();
    cout<<"\nAfter popping: " << endl;
    cout<<"top = " <<  minstack.top() << " : Min = " << minstack.getMin() << endl;

    return EXIT_SUCCESS;
}
