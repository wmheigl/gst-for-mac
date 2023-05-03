#include "munit/munit.h"
#include "gstpriv.h"
#include "gstpub.h"

MunitResult
test_gst_set_executable_path(const MunitParameter params[], void *user_data) {
    gst_set_executable_path("gst");
    munit_assert_string_equal(_gst_executable_path, "/usr/local/bin/gst");
    return MUNIT_OK;
}

MunitTest gstpub_tests[] = {
    { "/gst_set_executable_path", test_gst_set_executable_path, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite test_suite_gstpub = {
    "/libgst/gstpub", gstpub_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};
