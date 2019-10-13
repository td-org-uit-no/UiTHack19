#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/ptrace.h>

bool license_validation(char *key)
{
	if (strlen(key) != 16) {
		return false;
	}
	if (key[3] != key[1] || key[2] != 'a') {
		return false;
	}
	if (key[15] != key[2] || key[1] != 'b') {
		return false;
	}
	if (key[13] != key[0]+3 || key[0] - 7 != 'd') {
		return false;
	}
	if ((key[4] + key[5]) != (key[6] ^ key[7]) || key[8] != key[11]) {
		return false;
	}
	if (key[9] - key[8] != -2 || key[14] != '8' || (key[12] ^ 0xff) != 0xa7) {
		return false;
	}
	if (key[7] != '6' || key[6] != ('z' -25) || key[5] != ('9' - 12)) {
		return false;
	}
	if ((key[8] - 7) != 97 || key[10] != 'Y') {
		return false;
	}

	return true;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Usage: %s <license_key>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (ptrace(PTRACE_TRACEME, 0, NULL, 0) == -1) {
		printf("Pls no trace, go away... :(((\n");
		exit(EXIT_FAILURE);
	}

	if (license_validation(argv[1])) {
		printf("Your license is valid. You can now decrypt the zip file using the password: \"%s\"\n", argv[1]);
	} else {
		printf("Sorry, your license is invalid :((\n");
	}

	return 0;
}
