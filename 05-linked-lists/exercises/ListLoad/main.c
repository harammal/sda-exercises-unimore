#include "list.h"
#include <stdlib.h>

extern Item* ListLoad(const char* filename);

int main(void) {

	Item *rislist = ListLoad("data_00.txt");

	ListWriteStdout(rislist);

	ListDelete(rislist);

	return 0;
}