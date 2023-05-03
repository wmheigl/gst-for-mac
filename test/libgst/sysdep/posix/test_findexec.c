#include "munit/munit.h"
#include "sysdep.h"

MunitResult
test_gst_set_executable(const MunitParameter params[], void *user_data) {
    munit_assert_string_equal("Hello, world!", "Hello, world!");
    return MUNIT_OK;
}

MunitTest find_exec_tests[] = {
    { "/set_executable", test_gst_set_executable, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite test_suite_find_exec = {
    "/libgst/find_exec", find_exec_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};
