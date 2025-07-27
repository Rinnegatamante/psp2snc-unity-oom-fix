#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char cmdline[1024 * 1024];

int main (int argc, char *argv[]) {
	strcpy(cmdline, getenv("SCE_PSP2_SDK_DIR"));
	strcat(cmdline, "\\host_tools\\build\\bin\\psp2snc_real.exe");
	for (int i = 1; i < argc; i++) {
		strcat(cmdline, " ");
		char *first_slash = strstr(argv[i], "\\");
		if (first_slash) {
			char arg[256];
			char save = *(first_slash - 2);
			*(first_slash - 2) = 0;
			strcpy(arg, argv[i]);
			*(first_slash - 2) = save;
			strcat(arg, "\"");
			strcat(arg, first_slash - 2);
			strcat(arg, "\"");
			strcat(cmdline, arg);
		} else {
			strcat(cmdline, argv[i]);
		}
	}
	
	printf("Running:\n\n%s\n", cmdline);

	int ret = system(cmdline);
	printf("returned: %d\n", ret);
	
	if (ret != 0) {
		char *s = strstr(cmdline, "-O3");
		while (s) {
			s[2] = '1';
			s = strstr(cmdline, "-O3");
		}
	}
	
	printf("Using O1...\n");
	
	ret = system(cmdline);
	printf("returned: %d\n", ret);

	return ret;
}