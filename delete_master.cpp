#include <iostream>
#include "types.h"

void delete_master(Node** node, int value1)
{
	struct hudba* actNode;

	while (*node && (*node)->value == value1)
	{
		struct hudba* newPrvni = (*node)->dalsi;
		free(*node);  // uvolneni auta z pameti
		*node = newPrvni;
	}

	actNode = *node;
	while (actNode && actNode->dalsi) // prochazeni seznamu
	{
		if (actNode->dalsi->rok == rok) // auto je ke smazani
		{
			struct hudba* newDalsi = actNode->dalsi->dalsi;
			free(actNode->dalsi);  // uvolneni auta z pameti
			actNode->dalsi = newDalsi;
		}
		actNode = actNode->dalsi; // posun na dalsi auto
	}
}