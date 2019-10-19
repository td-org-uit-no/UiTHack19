#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void)
{
	// Disable buffering of stdout
	setvbuf(stdout, NULL, _IONBF, 0);

	puts("Welcome to the shellcoder simulator.\nPlease insert the assembly code you want to run. (PS: separate instructions with semicolons and not newlines)");

	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf), stdin);

	// Construct command line
	char command_line[1050] = { 0 };
	int temp_file = open("/tmp", O_TMPFILE | O_RDWR);
	sprintf(command_line, "rasm2 -B '%s' >& %d", buf, temp_file);

	// Assemble assembly code to shellcode
	int ret = system(command_line);
	if (ret == 0) {
		// Successfully assembled shellcode - read it back in and execute
		printf("Successfully assembled shellcode\n");
		void *shellcode = mmap(NULL, 4096, PROT_EXEC, MAP_PRIVATE, temp_file, 0);

		printf("Executing your shellcode now\n");
		((void (*)(void))shellcode)();
	} else {
		printf("Failed to assemble shellcode\n");
	}
	printf("Now executing the shellcode\n");

	return 0;
}
