
#include <stdio.h>

#include "../minunit/minunit.h"
#include "dynamic_test.h"
#include "static_test.h"
#include "unit_test.h"

int tests_run = 0;

static char *all_tests() {
    mu_run_all_sub_tests(all_unit_tests);
    mu_run_all_sub_tests(all_static_tests);
    mu_run_all_sub_tests(all_dynamic_tests);

    return 0;
}

int run_all_tests() {
	char *result = all_tests();

	if (result != 0) {
		printf("%s\r\n", result);
	} else {
		printf("ALL TESTS PASSED\r\n");
	}

	printf("Tests run: %d\r\n", tests_run);

	return result != 0;
}
