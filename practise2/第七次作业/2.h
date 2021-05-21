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
		cout << "�������:";
		cin >> detail;
		return detail;
	}
	void print()const override
	{
		cout << "ҽ����Ϣ\n";
		cout << "���:" << no << "\n����:" << name << "\n" << "�Ա�:" << gender << "\n����:" << age<<"\n����:"<<department<<"\n���ϸ��:"<<detail;
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
		cout << "��������:";
		cin >> illness;
		treatment=d.diadnose(illness);
	}
	void print()const override 
	{
		cout << "������Ϣ\n";
		cout <<"���:"<<no<< "\n����:" << name << "\n" << "�Ա�:" << gender<<"\n����:"<<age << "\n����:" << department <<"\n��������:"<<illness<<"\n"<<"�������:"<<treatment<<endl;
	}

private:
	string illness;
	string treatment;
};
