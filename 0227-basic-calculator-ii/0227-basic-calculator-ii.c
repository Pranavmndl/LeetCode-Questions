int calculate(char* s){
    int stack[500000];
    int top =-1;

    int num=0;
    char op='+';

    for (int i=0; ;i++) {

        if (isdigit((unsigned char)s[i])) {
            num=num*10+(s[i]-'0');
        }

        if ((!isdigit((unsigned char)s[i]) && s[i] != ' ') || s[i] == '\0') {

            if (op=='+') {
                stack[++top]=num;
            }
            else if (op=='-') {
                stack[++top]=-num;
            }
            else if (op=='*') {
                stack[top]=stack[top]*num;
            }
            else if (op=='/') {
                stack[top]=stack[top]/num;
            }

            op=s[i];
            num=0;
        }

        if (s[i]=='\0')
            break;
    }

    int result=0;

    while (top>=0) {
        result+=stack[top--];
    }

    return result;
}