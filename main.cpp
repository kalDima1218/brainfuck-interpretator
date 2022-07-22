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
    std::string script = "++++++++++++++++++++++++++++++++++++++++++++++++[>+<-]>.";
    char *p = &memory[0];
    int i = 0;
    std::stack<int> while_open;
    while(i != script.size()){
        if(script[i] == '+') (*p)++;
        else if(script[i] == '-') (*p)--;
        else if(script[i] == '>') p++;
        else if(script[i] == '<') p--;
        else if(script[i] == '['){
            if(*p == 0) while(script[++i] != ']');
            else while_open.push(i);
        }
        else if(script[i] == ']'){
            i = while_open.top() - 1;
            while_open.pop();
        }
        else if(script[i] == '.') putchar(*p);
        else if(script[i] == ',') *p = getchar();
        i++;
    }
    return 0;
}
