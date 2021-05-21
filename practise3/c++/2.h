using namespace std;
class person
{
public:
	person() = default;
	person(int n, const string&a, double h) :name(a), num(n), hour(h) {}
	void output(ostream &os)const { os << num << "\t" << name << "\t" << hour << "\t"; }
private:
	int num;
	string name;
protected:
	double hour;
};
class teacher :virtual public person
{
public:
	teacher() = default;
	teacher(int n, const string&a, double h) :person(n, a, h){}
	void output(ostream &os)const { person::output(cout); os <<salary()<< endl; }
	double salary()const{ return hour * 45 + 4500; }
};
class student :virtual public person
{
public:
	student() = default;
	student(int n, const string&a, double h, vector<string>c) :person(n, a, h), course(c) {}
	void output(ostream &os)const
	{
		person::output(cout);
		for (auto i : course)
			os << i << "\t";
		os << endl;
	}
protected:
	vector<string> course;
};
class teacher_assistant :public teacher, public student
{
public:
	teacher_assistant() = default;
	teacher_assistant(int n, const string&a, double h, vector<string>c) :person(n, a, h), student(n, a, h, c){}
	double salary()const { return hour * 35; }
	void output(ostream &os)const
	{
		person::output(cout);
		for (auto i : course)
			os << i << "\t";
		os << salary()<< endl;
}
};
