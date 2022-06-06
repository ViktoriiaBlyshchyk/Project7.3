#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Study\ООП\Project7.3\Project7.3\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			set<string> s1 = create("ABCOI");
			set<string> s2 = create("QTYUS");
			set<string> s0 = create("OPQRS");
			set<string> s;
			s = calc(s1, s2, s0);
			int k = count(s);
			Assert::AreEqual(k, 2);
		}
	};
}
