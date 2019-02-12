//#pragma once
#include <stdio.h>

#define MAX_NAME	(3)
#define MAX_ITEM	 (20)
#define MAX_HASHTABLE	(11) // use this for hash table size (prime number is always good)
#define nullptr	(0)

class Student {
public:
	char name[MAX_NAME + 1]; // key (which is unique)
	int score;	// data
	Student* next; // for seperate chaining - hash table
	Student* prev; // for seperate chaining - hash table (when no deletion, it doesn't need)

	Student() {
		init();
	}

	void init() {
		score = 0;
		name[0] = '\0';
		next = prev = nullptr;
	}
};

void init();
Student* search(const char name[MAX_NAME + 1]);
void insert(const char name[MAX_NAME + 1], const int score);
void del(const char name[MAX_NAME + 1]);

//==========================================

//#define _CRT_SECURE_NO_WARNINGS
//#include "common.h"

void printScore(const Student* s) {
	if (s == nullptr) {
		printf("none\n");
	}
	else {
		printf("%s : %d\n", s->name, s->score);
	}
}

int main(void) {	
	init();
	
	insert("abc", 10);
	insert("def", 20);
	insert("xyz", 30);
	insert("a", 44);
	insert("ab", 55);

	printScore(search("abc"));
	printScore(search("def"));
	printScore(search("xyz"));
	printScore(search("a"));
	printScore(search("ab"));
	printScore(search("ac"));

	del("abc");
	del("def");
	del("xyz");

	printScore(search("abc"));
	printScore(search("a"));
	printScore(search("ab"));

	del("abc");
	del("a");
	del("zzz");

	printScore(search("abc"));
	printScore(search("a"));
	printScore(search("ab"));

	del("ab");

	printScore(search("abc"));
	printScore(search("a"));
	printScore(search("ab"));
	
	insert("def", 99);
	insert("xyz", 88);
	insert("a", 77);
	insert("ab", 66);
	
	printScore(search("abc"));
	printScore(search("a"));
	printScore(search("ab"));
	printScore(search("def"));
	printScore(search("xyz"));
	
	return 0;
}

//****************************************************


//#include "common.h"

// global variable instead of malloc/free
Student students[MAX_ITEM];
int numStudents;
int t_idx;

// hash table
Student* ht[MAX_HASHTABLE];

size_t mystrlen(char const *str) {
    char const *pos=str;
    for (; *pos; ++pos);
    return pos-str;
}

bool mystrcmp(char const *str1, char const *str2) {
  if(mystrlen(str1) != mystrlen(str2)) return false;
  int l = mystrlen(str1);
  for(int i=0;i<l;i++) if(str1[i] != str2[i]) return false;
  return true;
}

void mystrcpy( char* _dst, const char* _src ) {
  while((*_dst++ = *_src++));
}

unsigned int hf(const char *str)
{
   unsigned int hash = 5381;
   for(unsigned int i = 0; i < mystrlen(str); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }
   return (hash) % MAX_HASHTABLE;
}

void init() {
  for(int i=0;i<MAX_HASHTABLE;i++) ht[i] = nullptr;
  t_idx =0;
}

Student* search(const char name[MAX_NAME + 1]) {
  unsigned int idx = hf(name);
  int val =0;
  Student *it = ht[idx];
  do{
    if(it) {
      if(mystrcmp(it->name,name)) return it;
      else it = it->next;
    }
  } while(it);
  return nullptr;
}

void insert(const char name[MAX_NAME + 1], const int score) {
  unsigned int idx = hf(name);
  Student *temp = &students[t_idx++];
  mystrcpy(temp->name,name);
  temp->score = score;
  if(!ht[idx]) ht[idx] = temp;
  else {
    Student *it = ht[idx];
    while(it->next) it = it->next;
    temp->prev = it;
    it->next = temp;
  }
}

void del(const char name[MAX_NAME + 1]) {
  unsigned int idx = hf(name);
  int val =0;
  Student *it = ht[idx];
  do{
    if(it) {
      if(mystrcmp(it->name,name)) {
        Student *p = it->prev;
        Student *n = it->next;
        if(!p && !n) {
          ht[idx] = nullptr;
          break;
        }
        if(p) p->next = n;
        if(n) n->prev = p;
        break;
      } else it = it->next;
    }
  } while(it);
}
