#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_PHONE_SIZE 32
#define MAX_WORD_SIZE 20000

#define WORD_LENGTH 6

#define CUTLINE	90			// the value of cutline would not be changed in evaluation.
                                        // only execution time will be taken into account between test takers
										// who received the same score.
extern void learnphone(int M, char phone[MAX_PHONE_SIZE]);
extern void learnword(int N, char word[MAX_WORD_SIZE][WORD_LENGTH]);
extern void recognize(char in[WORD_LENGTH], char out[WORD_LENGTH]);

static int totalquery;
static int correctword;
static int M;							// phone size
static int N;							// word size

static char phone[MAX_PHONE_SIZE];
static char word[MAX_WORD_SIZE][WORD_LENGTH];

static int seed;

static int pseudo_rand() {
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7fff;
}

static void makephone() {
	int idx1, idx2;

	idx1 = 0;
	while(idx1 < M) {
		phone[idx1] = pseudo_rand() % 256;
		idx2 = 0;
		while (idx2 < idx1) {
			if (phone[idx1] == phone[idx2])
				break;
			++idx2;
		}
		if (idx1 == idx2) ++idx1;
	}
}

static void makeword() {
	for (int idx1 = 0; idx1 < N; ++idx1)
		for (int idx2 = 0; idx2 < WORD_LENGTH; ++idx2)
			word[idx1][idx2] = phone[pseudo_rand() % M];
}

static bool issame(char in[WORD_LENGTH], char out[WORD_LENGTH]) {
	for (int idx = 0; idx < WORD_LENGTH; ++idx)
		if (in[idx] != out[idx])
			return false;
	return true;
}

static void run() {
	char in[WORD_LENGTH];
	char out[WORD_LENGTH];

	char t_phone[MAX_PHONE_SIZE];
	char t_word[MAX_WORD_SIZE][WORD_LENGTH];

	scanf("%d %d %d %d", &M, &N, &totalquery, &seed);

	makephone();

	for (int idx = 0; idx < M; ++idx)
		t_phone[idx] = phone[idx];

	learnphone(M, t_phone);
	
	makeword();

	for (int idx1 = 0; idx1 < N; ++idx1)
		for (int idx2 = 0; idx2 < WORD_LENGTH; ++idx2)
			t_word[idx1][idx2] = word[idx1][idx2];

	learnword(N, t_word);
	
	correctword = 0;
	for (int cnt = 0; cnt < totalquery; ++cnt) {
		int selected = pseudo_rand() % N;

		for (int idx1 = 0; idx1 < WORD_LENGTH; ++idx1) {
			in[idx1] = word[selected][idx1];
			int addnoise = pseudo_rand() % 2;
			if (addnoise)
				in[idx1] ^= 1 << (pseudo_rand() % 8); // add noise
		}
		
		recognize(in, out);

		if (issame(word[selected], out))
			++correctword;
	}
}

int main() {
    int TC, totalscore;

    //freopen("sample_input.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &TC);

    totalscore = 0;
    for (int testcase = 1; testcase <= TC; ++testcase) {
        run();
	int correctwordratio = correctword * 100 / totalquery;
        int score = correctwordratio >= CUTLINE ? 100 : 0;
	totalscore += score;	
	printf("#%d %d\n", testcase, score);
    }

    printf("total score = %d\n", totalscore / TC);
    return 0;
}

//-----------------------------------------------------------------------
/*
#define MAX_PHONE_SIZE		32
#define MAX_WORD_SIZE		20000
#define WORD_LENGTH			6
*/
int phone_map[256];

struct Trie {
	Trie* children[MAX_PHONE_SIZE];
};

Trie *my_trie;

Trie trie_pool[MAX_WORD_SIZE * WORD_LENGTH + 10];
int pool_count;

Trie* get_trie_node(){
	for(int i=0;i<MAX_PHONE_SIZE;i++){
		trie_pool[pool_count].children[i] = NULL;
	}
	return &trie_pool[pool_count++];
}

void learnphone(int M, char phone[MAX_PHONE_SIZE]){
	int a;
	pool_count = 0;
	my_trie = get_trie_node();
	for(int i=0;i<256;i++){
		phone_map[i] = -1;
	}
	for(int i=0;i<M;i++){
		a = phone[i]+128;
		/*
		printf("%d\n",a);
		a -= 128;
		char c = a;
		printf("%d %d\n",phone[i], c);
		*/
		phone_map[a] = i;
	}
}

void learnword(int N, char word[MAX_WORD_SIZE][WORD_LENGTH]){
	int a;
	int idx;
	for(int i=0;i<N;i++){
		Trie *t = my_trie;
		for(int j=0;j<WORD_LENGTH;j++){
			a = word[i][j] + 128;
			idx = phone_map[a];
			t->children[idx] = (t->children[idx] == NULL)?get_trie_node():t->children[idx];
			t = t->children[idx];
		}
	}
}

bool recognize_helper(char *in, char *out, int noise, Trie* root,int idx){
	if (root == NULL)
		return false;
	if(idx == 6)
		return true;
	//printf("%d %d\n",noise,idx);
	int a = in[idx] + 128;
	int m_idx = phone_map[a];
	if(m_idx != -1 && recognize_helper(in,out,noise,root->children[m_idx],idx+1)){
		a -= 128;
		//out[idx] = in[idx];
		out[idx] = a;
		return true;
	}
	if(noise){
		for(int i=0;i<8;i++){
			a ^= 1<<i;
			m_idx = phone_map[a];
			if(m_idx !=-1 && recognize_helper(in,out,noise-1,root->children[m_idx],idx+1)){
				a -= 128;
				//out[idx] = in[idx]^(1<<i) ;
				out[idx] = a;
				return true;
			}
			a ^= 1<<i;
		}
	}
	return false;
}

void recognize(char in[WORD_LENGTH], char out[WORD_LENGTH]){
	for(int i=0;i<7;i++){
		if(recognize_helper(in,out,i,my_trie,0)){
			return;
		}
	}
}

