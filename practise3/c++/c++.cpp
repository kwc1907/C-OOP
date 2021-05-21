#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
#include"2.h"
using namespace std;
int main(int argc,char**argv)
{
	teacher a(1111, "小红", 8);
	student b(2222, "小明", 8, { "cs","cs","vdf" });
	teacher_assistant c(3333, "小芳", 8, { "dasd","sdv","sdf" });
	a.output(cout);
	b.output(cout);
	c.output(cout);
}
