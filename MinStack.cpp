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

    void push(int newVal)
	{
        normal_stack.push(newVal);
        //min_stack is pushed only if new_val is less than or equal to min_stack.top()
        if(min_stack.empty() || newVal <= min_stack.top() )
		{
        	min_stack.push(newVal);
		}
    }
    void pop() {

        //min stack is popped ONLY if the top values (BEFORE popping) of the min stack and normal stack are equal.
        if(normal_stack.top() == min_stack.top())
        {
            min_stack.pop();
        }
        normal_stack.pop();
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
