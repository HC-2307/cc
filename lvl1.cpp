#include <iostream>
using namespace std;
//defining size of the stack
#define max_size 100 

class Stack{
    private:
    int mstack[max_size];
    int min_stack[max_size];
    int max_stack[max_size];
    int top_index;

    public:
    Stack() {
        top_index=-1;
    }

    //Push function
    void push(int a){
        if (top_index >= max_size-1){
            cout << "Stack Overflow\n";
            return;
        }
        top_index++;
        mstack[top_index]=a;

        if (top_index == 0){
            min_stack[top_index] = a;
            max_stack[top_index] = a;
        } else {
            min_stack[top_index] = min(a, min_stack[top_index-1]);
            max_stack[top_index] = max(a, max_stack[top_index-1]);
        }
    }

    //Pop function
    void pop(){
        if(top_index < 0){
            cout << "Stack underflow\n";
            return;
        }
        
        
        top_index--;
    }
    //Get top function
    int top(){
        if(top_index<0){
            cout << "Stack is empty\n";
            return -1;
        }
        return mstack[top_index];
    }
    //Get min function
    int getMin(){
        if(top_index<0){
            cout << "Stack is empty\n";
            return -1;
        }
        return min_stack[top_index];
    }
    //Get max function
    int getMax(){
        if(top_index<0){
            cout << "Stack is empty\n";
            return -1;
        }

        return max_stack[top_index];
    }
};

int main(){
    Stack s;
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(4);
    s.push(8);

    cout << "Top: " << s.top() << endl;
    cout << "Min: " << s.getMin() << endl;
    cout << "Max: " << s.getMax() << endl;
    s.pop();
    cout << "After pop: "<< endl;
    cout << "Top: " << s.top() << endl;
    cout << "Min: " << s.getMin() << endl;
    cout << "Max: " << s.getMax() << endl;

    return 0;
}



