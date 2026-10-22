#include <iostream>
#include <string>

class Node{
    public:
    char data;
    Node* next;
};

Node* head = nullptr;

bool isEmpty(){
    return head == nullptr;
}

void push(char c){
    Node* newNode = new Node();
    newNode->data = c;
    newNode->next = head;
    head = newNode;
}

char pop(){
    if(isEmpty()){
        std::cout<<"Stack Underflow"<<std::endl;
        return '\0';
    }
    Node* temp = head;
    char val = temp->data;
    head = head->next;
    delete temp;
    return val;
}

//clears out any leftover nodes so each expression starts with an empty stack
void clearStack(){
    while(!isEmpty()){
        pop();
    }
}

bool isMatchingPair(char open, char close){
    if(open == '(' && close == ')') return true;
    if(open == '{' && close == '}') return true;
    if(open == '[' && close == ']') return true;
    return false;
}

bool isBalanced(const std::string &expr){
    clearStack(); //reset the stack for each new expression

    for(size_t i = 0; i < expr.length(); i++){
        char c = expr[i];

        //a) ignore anything that is not a symbol to be balanced
        if(c != '(' && c != ')' && c != '{' && c != '}' && c != '[' && c != ']'){
            continue;
        }

        //b) if it's an opening symbol, push it onto the stack
        if(c == '(' || c == '{' || c == '['){
            push(c);
        }
        //c) if it's a closing symbol
        else{
            // i) report an error if the stack is empty
            if(isEmpty()){
                return false;
            }
            // ii) otherwise, pop the stack
            char openSym = pop();
            // d) if the symbol popped is not the matching opening symbol, report an error
            if(!isMatchingPair(openSym, c)){
                return false;
            }
        }
    }

    //3. at the end of input, if the stack is not empty: report an error
    return isEmpty();
}

int main(){
    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    for(int i = 0; i < 4; i++){
        std::cout<<"Expression: "<<expressions[i]<<std::endl;
        std::cout<<"Valid? "<<(isBalanced(expressions[i]) ? "Y" : "N")<<std::endl;
        std::cout<<"-------------------------------"<<std::endl;
    }

    return 0;
}
