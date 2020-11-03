#include <gtest/gtest.h>

class Calculator {
public:

    Calculator(int a, int b) : a(a), b(b) {}

    int add() const {
        return a + b;
    }

private:
    int a;
    int b;
};

TEST(Calculator, Add) {

Calculator calculator{1, 2};
EXPECT_EQ(3, calculator.add());
}