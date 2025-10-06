 #include<stdio.h>
 #include<ctype.h>
 #include<string.h>
 #define MAX 100
 char stack[MAX];
 int top=-1;
 void push(char c){
    if(top==MAX-1){
        printf("stack overflow");
        return;
    }
    stack[++top]=c;

 }
char pop(){
    if(top==-1){
        printf("stack is underflow");
        return-1;
    }
    return stack[top--];
}
char peek(){
    if (top==-1) return -1;
    return stack[top];
}
int precedence(char op){
    switch (op)
    {
        case '1':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0;
    }
    return -1;
}
int ass(char op){
    if (op=='^')
    return 1;
return 0;
}
void infixtopostfix(char infix[], char postfix[]){
    int i,k=0;
    char c;
    for(i=0;infix[i] !='\0';i++){
        c=infix[i];
        if(isalnum(c)){
            postfix[k++]=c;

        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while (peek() !='('){
                postfix[k++]=pop();
            }
            pop();
        }
        else{
            while (top!=-1 && ((precedence(peek())>precedence(c))||(precedence(peek())==precedence(c)&& ass(c)==0))){
                postfix[k++]=pop();
            }
            push(c);


        }
    }
    while(top!=-1){
        postfix[k++]=pop();

    }
    postfix[k]='\0';
}
int main(){
    char infix[MAX], Postfix[MAX];
    printf("enter a valid parenthesized infix exp:");
    scanf("%s",infix);
    infixtopostfix(infix,Postfix);
    printf("postfix epx:%s\n",Postfix);
    return 0;
}
