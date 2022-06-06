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

// різниця множин
set<string> difference(set<string> s1, set<string> s2)
{
	// копія першої множини
	set<string> s = s1;
	set<string>::iterator i, i2;
	// з s1 вилучаємо символи s2
	for (i2 = s2.begin(); i2 != s2.end(); i2++)
	{
		i = s.find(*i2);
		if (i != s.end())
			s.erase(*i);
	}
	// отримали: символи s1, які не входять в s2
	return s;
}

// використання операції різниці множин
set<string> calc(set<string> s1, set<string> s2, set<string> s0)
{
	set<string> s;
	s = difference(s0, s1); // з базової вилучаємо символи s1
	s = difference(s, s2); // з базової вилучаємо символи s2
	// отримали: символи базової, які не входять в s1 та s2
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
	cout << "Перша послідовність символів: ";
	getline(cin, t1);

	string t2;
	cout << "Друга послідовність символів: ";
	getline(cin, t2);

	set<string> s1 = create(t1);
	cout << "Перша множина: " + toStr(s1) << endl;

	set<string> s2 = create(t2);
	cout << "Друга множина: " + toStr(s2) << endl;

	set<string> s0 = create("OPQRS");
	cout << "Базова множина: " + toStr(s0) << endl;

	set<string> s;
	s = calc(s1, s2, s0);
	cout << "Результуюча множина: " + toStr(s) << endl;
	cout << "Кількість елементів: " << count(s);

	return 0;
}