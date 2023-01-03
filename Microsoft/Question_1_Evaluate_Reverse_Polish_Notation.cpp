class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        
        // We will loop through the postfix expression
        for(auto& t:tokens){
            //if the current token is an operator then stack must be containing the two operands for performing the operations
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                long op1, op2, ans=0;;
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                char ch = t[0];
                switch(ch){
                    case '+':
                    ans = op1+op2;
                    break;
                    case '-':
                    ans = op1-op2;
                    break;
                    case '*':
                    ans = op1*op2;
                    break;
                    default:
                    ans = op1/op2;
                    break;
                }
                //we simply perform the operation and store the result back into stack
                s.push(ans);
            }
            //if current token is a operand we store it in stack in int form
            else{
                s.push(stoi(t));
            }
        }

        //now after all operations stack contains the result at top
        return s.top();
    }
};