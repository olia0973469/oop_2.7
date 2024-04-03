#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_2.7/Money.h"
#include "../oop_2.7/Money.cpp"
#include "../oop_2.7/Goods.h"
#include "../oop_2.7/Goods.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Money money1(10, 50);
			Money money2(5, 25);
			Money sum = money1.Add(money2);
			Money difference = money1.Sub(money2);
			Assert::AreEqual(15.0, sum.GetHr());
			Assert::AreEqual(75.0, sum.GetKop());
			Assert::AreEqual(5.0, difference.GetHr());
			Assert::AreEqual(25.0, difference.GetKop());
		}
	};
}
