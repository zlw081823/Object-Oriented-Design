
#include "MaxCheck.h"
#include "unity.h"

int32_t target = 0;
MaxCheck_Handle handle = NULL:

void setUp(void)
{
    /* This is run before EACH TEST */
    const MaxCheck_Configuration config = {
        .tripLevel = 10;
        .tripTime = 1;
    };

    handle = MaxCheck_create(&config, &target);

}

void tearDown(void)
{
}

void test_MaxCheck_isCreatedFine(void)
{
    TEST_ASSERT_EQUAL(NULL, handle);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_MaxCheck_isCreatedFine);
    return UNITY_END();
}