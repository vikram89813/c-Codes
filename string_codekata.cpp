#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#define MAX_LEN 50

enum { STRCPY = 1, STRCMP, STRCAT, END = 99 };

extern void mystrcpy(char* str1, const char* str2);
extern bool mystrcmp(const char* str1, const char* str2);
extern void mystrcat(char* str1, const char* str2);

int main(void) {
	//setbuf(stdout, NULL);
	//freopen("input.txt", "r", stdin);
	int cmd;
	char str1[MAX_LEN+1], str2[MAX_LEN+1];

	while (1){
		scanf("%d", &cmd);
		if (cmd == END) break;

		switch (cmd){
		case STRCPY:
			scanf("%s", &str2);
			mystrcpy(str1, str2);
			printf("%s\n", str1);
			break;
		case STRCMP:
			scanf("%s", &str2);
			if (mystrcmp(str1, str2))
				printf("%s\n", str1);
			else
				printf("different\n");
			break;
		case STRCAT:
			scanf("%s", &str2);
			mystrcat(str1, str2);
			printf("%s\n", str1);
			break;
		}
	}
	return 0;
}

//===================================

void mystrcpy(char* str1, const char* str2) {
  while((*str1++ = *str2++));
}

bool mystrcmp(const char* str1, const char* str2) {
  while(*str1 && *str2) {
    if(*str1++ != *str2++) return false;
  }
  return true;
}

void mystrcat(char* str1, const char* str2) {
  char * d = str1;
  while (*d++);
  char const * s = str2;
  while (*s) { *d++ = *s++; }
  *d = 0;
}
