#include "test.h"

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    MunitSuite test_suites[] = {
        test_suite_gstpub,
        { NULL, NULL, 0, 0 }
    };

    MunitSuite test_suite = {
        "/gst-tests", NULL, test_suites, 1, MUNIT_SUITE_OPTION_NONE
    };

    return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}
