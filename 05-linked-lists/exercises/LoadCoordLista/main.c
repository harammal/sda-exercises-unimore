#include "list.h"
#include <stdio.h>

extern Item* ListLoad(const char* filename);

int main(void) {
	
	Item* list = ListCreateEmpty();
	list = ListLoad("file1.txt");
	
	ListWriteStdout(list);

	ListDelete(list);

	return 0;
}