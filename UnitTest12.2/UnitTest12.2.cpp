#include "pch.h"
#include "CppUnitTest.h"
#include "../AP12.2/AP12.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest122
{
	TEST_CLASS(UnitTest122)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL, * last = NULL;
			Input(first, last, 1);
			Assert::IsNotNull(first);
			Assert::IsNotNull(last);
			Assert::AreEqual(first->info, 1);
			Assert::AreEqual(last->info, 1);
		}
	};
}
