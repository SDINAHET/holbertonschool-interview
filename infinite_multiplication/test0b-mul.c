/* test0b-mul.c - harness for ./mul
 * Runs ./mul with various args, checks stdout and exit code.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define PROG "./mul"
#define OUT_CAP 4096

static int pass = 0, fail = 0;

/* run shell command, capture stdout into buf, set rc to exit status */
static int run_and_capture(const char *cmd, char *buf, size_t cap, int *rc)
{
	FILE *fp;
	size_t n = 0;
	int status;

	buf[0] = '\0';
	fp = popen(cmd, "r");
	if (!fp) return -1;

	while (!feof(fp) && n + 1 < cap) {
		size_t got = fread(buf + n, 1, cap - 1 - n, fp);
		if (got == 0) break;
		n += got;
	}
	buf[n] = '\0';

	status = pclose(fp);
	if (status == -1) return -1;
	*rc = WIFEXITED(status) ? WEXITSTATUS(status) : 255;
	return 0;
}

static void test_run(const char *name, const char *args,
		     const char *expected_out, int expected_rc)
{
	char cmd[1024], out[OUT_CAP];
	int rc = -1;

	if (args && args[0] != '\0')
		snprintf(cmd, sizeof(cmd), "%s %s 2>/dev/null", PROG, args);
	else
		snprintf(cmd, sizeof(cmd), "%s 2>/dev/null", PROG);

	if (run_and_capture(cmd, out, sizeof(out), &rc) != 0) {
		printf("❌ %-28s -> exec error\n", name);
		fail++;
		return;
	}
	if (strcmp(out, expected_out) == 0 && rc == expected_rc) {
		printf("✅ %-28s\n", name);
		pass++;
	} else {
		printf("❌ %-28s\n", name);
		printf("   cmd: %s\n   exp rc=%d, out=\"%s\"\n   got rc=%d, out=\"%s\"\n",
		       cmd, expected_rc, expected_out, rc, out);
		fail++;
	}
}

int main(void)
{
	/* success cases */
	test_run("123 * 456",           "123 456",           "56088\n", 0);
	test_run("0 * 0",               "0 0",               "0\n",     0);
	test_run("000000 * 42",         "000000 42",         "0\n",     0);
	test_run("98 * 765",            "98 765",            "74970\n", 0);
	test_run("big * big",           "123456789 987654321",
	         "121932631112635269\n", 0);

	/* error cases: print 'Error' and exit 98 */
	test_run("alpha arg",           "abc 123",           "Error\n", 98);
	test_run("bad digit",           "123 12x",           "Error\n", 98);
	test_run("no args",             "",                  "Error\n", 98);
	test_run("one arg",             "42",                "Error\n", 98);
	test_run("three args",          "1 2 3",             "Error\n", 98);

	printf("\nSummary: %d pass / %d fail\n", pass, fail);
	return fail ? 1 : 0;
}
