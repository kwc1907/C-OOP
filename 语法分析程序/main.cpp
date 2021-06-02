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
        prog[p++] = ch;         //����Դ�����ַ������͵�������prog[p++]��
    } while (ch != '#');
    p = 0;
    kk = 0;
    scanner();
    lrparscr();
    getchar();
    getchar();
    return 0;
}

//�ж��Ƿ���begin��ͷ������end����
int lrparscr() {
    if (syn == 1) {//begin
        scanner();            //����һ�����ʷ���
        yucu();
        if (syn == 6) {       //syn=6 ��Ӧ���ʷ���end
            scanner();      //����һ�����ʷ���
            if ((syn == 0) && (kk == 0))
                printf("success!\n");
        }
        else if (kk != 1) {
            cout << "����ȱend����" << endl;
            kk = 1;
        }
    }
    else {
        cout << "����ȱbegin����" << endl;
        kk = 1;
    }
    return 0;
}

int yucu() {                    //��䴮��������
    statement();
    while (syn == 26) {// ������Ϊ��;���������ɨ����һ��䴮
        scanner();          //����һ�����ʷ���
        statement();        //����statement����
    }
    return 0;
}

int statement() {
    if (syn == 10) {// ����ĸ��ʶ��
        scanner();         //����һ�����ʷ���
        if (syn == 18) { //:=
            scanner();     //����һ�����ʷ���
            expression();
        }
        else {
            cout << "���ָ�ֵ�Ŵ���" << endl;
            kk = 1;
        }
    }
    else {
        cout << "����������" << endl;
        kk = 1;
    }
    return 0;
}

int expression() {
    term();
    while ((syn == 13) || (syn == 14)) {// +��-
        scanner();                      //����һ�����ʷ���
        term();
    }
    return 0;
}

int term() {
    factor();
    while ((syn == 15) || (syn == 16)) {// * ��/
        scanner();                     //����һ�����ʷ���
        factor();
    }
    return 0;
}

int factor() {
    if ((syn == 10) || (syn == 11))     //�Ƿ��Ǳ�ʶ�������ͳ���
        scanner();                     //����һ�����ʷ���
    else if (syn == 27) {                    // �Ƿ��� (
        scanner();                     //����һ�����ʷ���
        expression();
        if (syn == 28)                 // �Ƿ��� ��
            syn = scanner();             //����һ�����ʷ���
        else {
            cout << "���� ) ����" << endl;
            kk = 1;//��������1 Ϊ��
        }
    }
    else {
        cout << "���ֱ��ʽ����" << endl;
        kk = 1;//��������1 Ϊ��
    }
    return 0;
}

int scanner() {
    for (n = 0; n < 8; n++) token[n] = '\0';
    ch = prog[p++];                     //����һ�����ʷ��Ų�����ch
    while (ch == ' ') {                   //����ǿո�,����һ�ַ�
        ch = prog[p];
        p++;
    }
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {            //�������ĸ�ַ�
        m = 0;
        while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {   //�������ĸ�ַ�
            token[m++] = ch;                 //��ǰ�ַ�����token
            ch = prog[p++];                //����һ�����ʷ��Ų�����ch
        }
        token[m++] = '\0';              //���ʽ���
        p--;                               //����һ���ַ�
        syn = 10;                         //��ʶ��
        for (n = 0; n < 6; n++)                 //��ؼ��ֱ���бȽϣ�ȷ��syn��ֵ
            if (strcmp(token, pString[n]) == 0) {
                syn = n + 1;                     //����synֵ
                break;
            }
    }
    else if ((ch >= '0' && ch <= '9')) {        //����������ַ�
        {
            sum = 0;
            while ((ch >= '0' && ch <= '9')) {  //����������ַ�
                sum = sum * 10 + ch - '0';   //ch����sum,����������
                ch = prog[p++];              //����һ�����ʷ��Ų�����ch
            }
        }
        p--;                                   //����һ���ַ�
        syn = 11;                            //�����ַ�
        if (sum > 32767)
            syn = -1;                         //���ִ���
    }
    else
        switch (ch) {                         //�����ַ�ʱ
        case '<':
            m = 0;
            token[m++] = ch;
            ch = prog[p++];                       //����һ�����ʷ��Ų�����ch
            if (ch == '>') {
                syn = 21;                         //������
                token[m++] = ch;
            }
            else if (ch == '=') {
                syn = 22;                        //С�ڵ���
                token[m++] = ch;
            }
            else {
                syn = 20;                        //С��
                p--;                            //����һ���ַ�
            }
            break;
        case '>':
            m = 0;
            token[m++] = ch;
            ch = prog[p++];                    //����һ�����ʷ��Ų�����ch
            if (ch == '=') {
                syn = 24;                    //���ڵ���
                token[m++] = ch;
            }
            else {
                syn = 23;                    //����
                p--;                            //����һ���ַ�
            }
            break;
        case ':':
            m = 0;
            token[m++] = ch;
            ch = prog[p++];                    //����һ�����ʷ��Ų�����ch
            if (ch == '=') {
                syn = 18;                    //����
                token[m++] = ch;
            }
            else {
                syn = 17;                    //ð�ţ�
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