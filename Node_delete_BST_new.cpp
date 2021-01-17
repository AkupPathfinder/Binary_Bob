#include <iostream>
#include "types.h"

void del(Node node, int value1)
{
	struct Node* aktNode;

	while (*node && (*node)->rok == rok)
	{
		struct Node* newPrvni = (*node)->dalsi;
		free(*node);  // uvolneni auta z pameti
		*node = newPrvni;
	}

	aktHudba = *node;
	while (aktHudba && aktHudba->dalsi) // prochazeni seznamu
	{
		if (aktHudba->dalsi->rok == rok) // auto je ke smazani
		{
			struct hudba* newDalsi = aktHudba->dalsi->dalsi;
			free(aktHudba->dalsi);  // uvolneni auta z pameti
			aktHudba->dalsi = newDalsi;
		}
		aktHudba = aktHudba->dalsi; // posun na dalsi auto
	}
}