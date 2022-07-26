//
//  main.cpp
//  BrainFuck Interpretator
//
//  Created by Дмитрий Калугин on 20.07.2022.
//

#include<string>
#include<stack>

int main() {
    char memory[30000] = {};
    std::string script = "+++++>>+>+>+>++++++++>+>+>+>++++++>+>+>+>+++>+>+>+>+++++++++>+>+>+>+>+>+>+><[<]<[->>>>>>>>>[>->->-<<<<<<<<-<<->>>[>>>>>+>+<<<<<<-]>>>>>[<<<<<+>>>>>-]<[>+>>+<<<-]>[<+>-]<<<<<[->>>>-[>]<<<<<]<[->>[-]>>>>>>[<<+>>-]>[<<<<<<<+>>>>>>>-]<<<<<<<<<]<[->>>>>>[-]>>[<<<<<<+>>>>>>-]>[<<<+>>>-]<<<<<<<<<<]+>+>+>>>>>>+>+>+<<<<<<<>>>>>>>>]<<<<[<]<]>>>>>[++++++++++++++++++++++++++++++++++++++++++++++++.>>>>]";
    int i = 0;
    std::stack<int> while_open;
    int *next = new int[script.size()], *prev = new int[script.size()];
    while(i != script.size()){
        next[i] = i+1;
        prev[i] = i-1;
        if(script[i] == '['){
            while_open.push(i);
        }
        else if(script[i] == ']'){
            int p = while_open.top();
            while_open.pop();
            prev[i] = p;
            next[p] = i;
        }
        i++;
    }
    i = 0;
    char *p = &memory[0];
    while(i != script.size()){
        if(script[i] == '>') p++;
        else if(script[i] == '<') p--;
        else if(script[i] == '+') (*p)++;
        else if(script[i] == '-') (*p)--;
        else if(script[i] == '[') {
            if(*p == 0) i = next[i];
        }
        else if(script[i] == ']') i = prev[i] - 1;
        else if(script[i] == '.') putchar(*p);
        else if(script[i] == ',') *p = getchar();
        i++;
    }
    return 0;
}
