using namespace std;
class people
{
public:
	people() = default;
	people(int m,const string &n, string g, int a,const string &d) :no(m),name(n), gender(g), age(a),department(d) {}
	virtual void print()const = 0;
protected:
	int no;
	string name;
	string gender;
	int age;
	string department;
};
class doctor :public people
{
public:
	doctor() = default;
	doctor(int m, const string &n, string g, int a, const string &d) :people(m, n, g, a, d) {}
	string diadnose(string i)
	{
		cout << "做出诊断:";
		cin >> detail;
		return detail;
	}
	void print()const override
	{
		cout << "医生信息\n";
		cout << "编号:" << no << "\n姓名:" << name << "\n" << "性别:" << gender << "\n年龄:" << age<<"\n诊室:"<<department<<"\n诊断细节:"<<detail;
	}
private:
	string detail;
};

class patient :public people
{
public:
	patient() = default;
	patient(int m, const string &n, string g, int a, const string &d) :people(m,n, g, a,d) {}
	void seedoctor(doctor&d)
	{
		cout << "病情详述:";
		cin >> illness;
		treatment=d.diadnose(illness);
	}
	void print()const override 
	{
		cout << "病人信息\n";
		cout <<"编号:"<<no<< "\n姓名:" << name << "\n" << "性别:" << gender<<"\n年龄:"<<age << "\n诊室:" << department <<"\n病情详述:"<<illness<<"\n"<<"诊断详述:"<<treatment<<endl;
	}

private:
	string illness;
	string treatment;
};
