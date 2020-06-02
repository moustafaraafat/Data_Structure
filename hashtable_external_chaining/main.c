/*
 * hashtable_external.c
 *
 *  Created on: May 21, 2020
 *      Author: Raafat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
	char name[MAX_NAME];
	int age;
	struct person* next;
	/*Add some other info.*/
} person;

person * hash_table[TABLE_SIZE];	/*Array of pinter to person structs*/

unsigned int hash(char *name){
	int length = strnlen(name, MAX_NAME);
	unsigned int hash_value = 0;
	for(int i=0; i<length; i++){
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
	}
	return hash_value;
}

void init_hash_table(void){
	for(int i=0; i < TABLE_SIZE; i++){
		hash_table[i] = NULL;
	}
	/*Table is empty */
}
void print_table(void){
	printf("Start\n");
	for(int i=0; i < TABLE_SIZE; i++){
		if(hash_table[i] == NULL){
			printf("\t%i\t---\n",i);
		}else{
			printf("\t%i\t", i);
			person* tmp = hash_table[i];
			while (tmp != NULL){
				printf("%s - ", tmp->name);
				tmp = tmp->next;
			}
			printf("\n");
		}
	}
	printf("End\n");
}
bool hash_table_insert(person *p){
	if (p == NULL) return false;
	int index = hash(p->name);
	p->next = hash_table[index];
	hash_table[index] = p;
	return true;
}

/*Find a person in the table*/
person * hash_table_lookup(char *name){
	int index = hash(name);
	person *tmp = hash_table[index];
	while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
		tmp = tmp->next;
	}
	return tmp;
}
person * hash_table_delete(char *name){
	int index = hash(name);
	person *tmp = hash_table[index];
	person *prev = NULL;
	while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL) return NULL;
	if (prev == NULL){
		/*Delete the head*/
		hash_table[index] = tmp->next;
	}else {
		prev->next = tmp->next;
	}
	return tmp;
}
int main(void)
{
	setbuf(stdout, NULL); /*To solve printing problem in Eclipse*/
	init_hash_table();

	person jacob = {.name = "Jacob", .age = 56};
	person kate = {.name = "Kate", .age = 27};
	person mpho = {.name = "Mpho", .age = 14};
	person sarah = {.name = "Sarah", .age = 54};
	person edna = {.name = "Edna", .age = 15};
	person maren = {.name = "Maren", .age = 25};
	person eliza = {.name = "Eliza", .age = 34};
	person robert = {.name = "Robert", .age = 1};
	person jane = {.name = "Jane", .age = 75};


	hash_table_insert(&jacob);
	hash_table_insert(&kate);
	hash_table_insert(&mpho);
	hash_table_insert(&sarah);
	hash_table_insert(&edna);
	hash_table_insert(&maren);
	hash_table_insert(&eliza);
	hash_table_insert(&robert);
	hash_table_insert(&jane);
	print_table();

	person *tmp = hash_table_lookup("Mpho");
	if(tmp == NULL){
		printf("Not found!\n");
	}else{
		printf("Found %s.\n", tmp->name);
	}
	tmp = hash_table_lookup("George");
	if(tmp == NULL){
		printf("Not found!\n");
	}else{
		printf("Found %s.\n", tmp->name);
	}
	hash_table_delete("Mpho");
	tmp = hash_table_lookup("Mpho");
	if(tmp == NULL){
		printf("Not found!\n");
	}else{
		printf("Found %s.\n", tmp->name);
	}

	print_table();

	/*	printf("Jacob => %u\n", hash("Jacob"));
	printf("Natalie => %u\n", hash("Natalie"));
	printf("Sara => %u\n", hash("Sara"));
	printf("Mpho => %u\n", hash("Mpho"));
	printf("Tebogo => %u\n", hash("Tebogo"));
	printf("Ron => %u\n", hash("Ron"));
	printf("Jane => %u\n", hash("Jane"));
	printf("Maren => %u\n", hash("Maren"));
	printf("Bill => %u\n", hash("Bill"));
	 */
	return 0;
}

