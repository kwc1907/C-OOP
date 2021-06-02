#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

char prog[80], token[8];
char ch;
int syn, p, m, n, sum, kk;
char* pString[6] = { (char*)"begin", (char*)"if", (char*)"then", (char*)"while", (char*)"do", (char*)"end" };

int scanner();
int lrparscr();
int yucu();
int statement();
int expression();
int term();
int factor();

int main() {
    p = 0;
    cout << "\nPlease input string(end with '#'):" << endl;
    do {
        cin.get(ch);
        prog[p++] = ch;         //输入源程序字符串，送到缓冲区prog[p++]中
    } while (ch != '#');
    p = 0;
    kk = 0;
    scanner();
    lrparscr();
    getchar();
    getchar();
    return 0;
}

//判断是否以begin开头，并以end结束
int lrparscr() {
    if (syn == 1) {//begin
        scanner();            //读下一个单词符号
        yucu();
        if (syn == 6) {       //syn=6 对应单词符号end
            scanner();      //读下一个单词符号
            if ((syn == 0) && (kk == 0))
                printf("success!\n");
        }
        else if (kk != 1) {
            cout << "出现缺end错误！" << endl;
            kk = 1;
        }
    }
    else {
        cout << "出现缺begin错误！" << endl;
        kk = 1;
    }
    return 0;
}

int yucu() {                    //语句串分析函数
    statement();
    while (syn == 26) {// 若符号为“;”，则继续扫描下一语句串
        scanner();          //读下一个单词符号
        statement();        //调用statement函数
    }
    return 0;
}

int statement() {
    if (syn == 10) {// 是字母标识符
        scanner();         //读下一个单词符号
        if (syn == 18) { //:=
            scanner();     //读下一个单词符号
            expression();
        }
        else {
            cout << "出现赋值号错误！" << endl;
            kk = 1;
        }
    }
    else {
        cout << "出现语句错误！" << endl;
        kk = 1;
    }
    return 0;
}

int expression() {
    term();
    while ((syn == 13) || (syn == 14)) {// +或-
        scanner();                      //读下一个单词符号
        term();
    }
    return 0;
}

int term() {
    factor();
    while ((syn == 15) || (syn == 16)) {// * 或/
        scanner();                     //读下一个单词符号
        factor();
    }
    return 0;
}

int factor() {
    if ((syn == 10) || (syn == 11))     //是否是标识符或整型常数
        scanner();                     //读下一个单词符号
    else if (syn == 27) {                    // 是否是 (
        scanner();                     //读下一个单词符号
        expression();
        if (syn == 28)                 // 是否是 ）
            syn = scanner();             //读下一个单词符号
        else {
            cout << "出现 ) 错误！" << endl;
            kk = 1;//错误标记置1 为真
        }
    }
    else {
        cout << "出现表达式错误！" << endl;
        kk = 1;//错误标记置1 为真
    }
    return 0;
}

int scanner() {
    for (n = 0; n < 8; n++) token[n] = '\0';
    ch = prog[p++];                     //读下一个单词符号并赋给ch
    while (ch == ' ') {                   //如果是空格,读下一字符
        ch = prog[p];
        p++;
    }
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {            //如果是字母字符
        m = 0;
        while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {   //如果是字母字符
            token[m++] = ch;                 //当前字符送入token
            ch = prog[p++];                //读下一个单词符号并赋给ch
        }
        token[m++] = '\0';              //单词结束
        p--;                               //回退一个字符
        syn = 10;                         //标识符
        for (n = 0; n < 6; n++)                 //与关键字表进行比较，确定syn的值
            if (strcmp(token, pString[n]) == 0) {
                syn = n + 1;                     //给出syn值
                break;
            }
    }
    else if ((ch >= '0' && ch <= '9')) {        //如果是数字字符
        {
            sum = 0;
            while ((ch >= '0' && ch <= '9')) {  //如果是数字字符
                sum = sum * 10 + ch - '0';   //ch送入sum,并更新数字
                ch = prog[p++];              //读下一个单词符号并赋给ch
            }
        }
        p--;                                   //回退一个字符
        syn = 11;                            //数字字符
        if (sum > 32767)
            syn = -1;                         //出现错误
    }
    else
        switch (ch) {                         //其他字符时
        case '<':
            m = 0;
            token[m++] = ch;
            ch = prog[p++];                       //读下一个单词符号并赋给ch
            if (ch == '>') {
                syn = 21;                         //不等于
                token[m++] = ch;
            }
            else if (ch == '=') {
                syn = 22;                        //小于等于
                token[m++] = ch;
            }
            else {
                syn = 20;                        //小于
                p--;                            //回退一个字符
            }
            break;
        case '>':
            m = 0;
            token[m++] = ch;
            ch = prog[p++];                    //读下一个单词符号并赋给ch
            if (ch == '=') {
                syn = 24;                    //大于等于
                token[m++] = ch;
            }
            else {
                syn = 23;                    //大于
                p--;                            //回退一个字符
            }
            break;
        case ':':
            m = 0;
            token[m++] = ch;
            ch = prog[p++];                    //读下一个单词符号并赋给ch
            if (ch == '=') {
                syn = 18;                    //等于
                token[m++] = ch;
            }
            else {
                syn = 17;                    //冒号：
                p--;
            }
            break;
        case '+':
            syn = 13;
            token[0] = ch;
            break;
        case '-':
            syn = 14;
            token[0] = ch;
            break;
        case '*':
            syn = 15;
            token[0] = ch;
            break;
        case '/':
            syn = 16;
            token[0] = ch;
            break;
        case '=':
            syn = 25;
            token[0] = ch;
            break;
        case ';':
            syn = 26;
            token[0] = ch;
            break;
        case '(':
            syn = 27;
            token[0] = ch;
            break;
        case ')':
            syn = 28;
            token[0] = ch;
            break;
        case '#':
            syn = 0;
            token[0] = ch;
            break;
        case '\n':
            syn = -2;
            break;
        default:
            syn = -1;
            break;
        }
    return syn;
}