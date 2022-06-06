#include <iostream>
#include <string>
#include <set>
#include <Windows.h> 

using namespace std;

string toStr(set<string> s)
{
	set<string>::iterator i;
	string str = "{";
	for (i = s.begin(); i != s.end(); i++)
		str += *i + ";";
	str = str.erase(str.length() - 1);
	str += "}";
	return str;
}

set<string> create(string t)
{
	set<string> s;
	string c;
	for (int i = 0; i < t.length(); i++)
	{
		c = t[i];
		s.insert(c);
	}
	return s;
}

// ������ ������
set<string> difference(set<string> s1, set<string> s2)
{
	// ���� ����� �������
	set<string> s = s1;
	set<string>::iterator i, i2;
	// � s1 �������� ������� s2
	for (i2 = s2.begin(); i2 != s2.end(); i2++)
	{
		i = s.find(*i2);
		if (i != s.end())
			s.erase(*i);
	}
	// ��������: ������� s1, �� �� ������� � s2
	return s;
}

// ������������ �������� ������ ������
set<string> calc(set<string> s1, set<string> s2, set<string> s0)
{
	set<string> s;
	s = difference(s0, s1); // � ������ �������� ������� s1
	s = difference(s, s2); // � ������ �������� ������� s2
	// ��������: ������� ������, �� �� ������� � s1 �� s2
	return s;
}

void print(set<string> s)
{
	set<string>::iterator i;
	for (i = s.begin(); i != s.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

double count(set<string> s)
{
	int count = 0;
	set<string>::iterator i;
	for (i = s.begin(); i != s.end(); i++)
	{
		if (*i == "O" || *i == "P" || *i == "Q" || *i == "R" || *i == "S")
		{
			count++;
		}
	}
	return count;
}

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	string t1;
	cout << "����� ����������� �������: ";
	getline(cin, t1);

	string t2;
	cout << "����� ����������� �������: ";
	getline(cin, t2);

	set<string> s1 = create(t1);
	cout << "����� �������: " + toStr(s1) << endl;

	set<string> s2 = create(t2);
	cout << "����� �������: " + toStr(s2) << endl;

	set<string> s0 = create("OPQRS");
	cout << "������ �������: " + toStr(s0) << endl;

	set<string> s;
	s = calc(s1, s2, s0);
	cout << "����������� �������: " + toStr(s) << endl;
	cout << "ʳ������ ��������: " << count(s);

	return 0;
}