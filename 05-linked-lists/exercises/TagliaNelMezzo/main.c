#include "list.h"

extern Item* ListCut_InList(Item* list, int start, int end);
extern Item* ListCut_NewList(Item** list, int start, int end);
int main(void) {

	ElemType v1[] = { 0, 1, 2, 3, 4};
	Item* list1 = ListCreateEmpty();

	ElemType v2[] = { 0, 1, 2, 3, 4 };
	Item* list2 = ListCreateEmpty();

	for (int i = 0; i < 5; ++i) {
		list1 = ListInsertBack(list1, v1 + i);
		list2 = ListInsertBack(list2, v2 + i);
	}
	ListWriteStdout(list1);
	ListWriteStdout(list2);

	// Cancella da start (compreso) a end (compreso) [start, end]
	list1 = ListCut_InList(list1, 4, 4);	// Modifica direttamente la lista
	ListWriteStdout(list1);					// (va riassegnata per non perdere il riferimento alla testa se modifcato)

	ListCut_NewList(&list2, 1, 3);			// Crea una seconda lista che viene sotituita automaticamente alla vecchia
	ListWriteStdout(list2);					// (la vecchia viene direttamente deallocata nella funzione)

	ListDelete(list1);
	ListDelete(list2);

	return 0;
}