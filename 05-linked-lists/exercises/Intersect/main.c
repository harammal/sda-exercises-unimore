#include "list.h"
#include <stdlib.h>

extern Item* ListLoad(const char* filename);
extern Item* Intersect(const Item* i1, const Item* i2);
extern Item* IntersectNoRep(const Item* i1, const Item* i2);

int main(void) {

	Item* list1 = ListLoad("data_00.txt");
	Item* list2 = ListLoad("data_01.txt");

	ListWriteStdout(list1);
	ListWriteStdout(list2);

	Item* list3 = IntersectNoRep(list1, list2);
	ListWriteStdout(list3);

	ListDelete(list1);
	ListDelete(list2);
	ListDelete(list3);

	return 0;
}