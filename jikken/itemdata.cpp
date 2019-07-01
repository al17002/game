#include <iostream>
#include "Savedata.h"

item_desc itemRef[100];

void output_itemdata() {
	int i;
	FILE *fp;

	fopen_s(&fp, "itemdata.dat", "rb");
	
	for (i = 0; i < 10; i++) {
		fread(itemRef[i].name, sizeof(char), sizeof(itemRef[i].name), fp);
		fread(itemRef[i].explain, sizeof(char), sizeof(itemRef[i].explain), fp);
		fread(itemRef[i].effect, sizeof(char), sizeof(itemRef[i].effect), fp);
		fread(&itemRef[i].atk, sizeof(int), 1, fp);
		fread(&itemRef[i].hp, sizeof(int), 1, fp);
	}

	fclose(fp);

}