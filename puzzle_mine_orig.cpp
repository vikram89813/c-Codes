#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>

extern void init(int N, int M, int K);
extern void addPiece(int piece[]);
extern int findCenterPiece();

static int mSeed;
static int pseudo_rand(void)
{
	mSeed = mSeed * 431345 + 2531999;
	return mSeed & 0x7FFFFFFF;
}

static int run()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	init(N, M, K);

	int piece[60];
	for (int i = 0; i < N * N + K; ++i) {
		for (int k = 0; k < 4; ++k) {
			scanf("%d", &mSeed);
			int idx = k * M;
			piece[idx] = piece[idx + M - 1] = 0;
			if (mSeed > 0) {
				for (int m = 1; m < M - 1; ++m)
					piece[idx + m] = pseudo_rand() % 3 - 1;
			}
			else {
				mSeed *= -1;
				for (int m = M - 2; m > 0; --m)
					piece[idx + m] = 1 - pseudo_rand() % 3;
			}
		}

		addPiece(piece);
	}

	int result = findCenterPiece();
	return result;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= 1; tc++)
	{
		printf("#%d %d\n", tc, run());
	}

	return 0;
}
//==============================================


//#include<stdio.h>

int N;
int M;
int K;

struct matched {
	int id;
	int dir1;
	int dir2;
	//matched *next;
};

struct puzzle {
	int id;
	int no_of_ones;
	int matched_c;
	int pat1[16];
	int pat2[16];
	int pat3[16];
	int pat4[16];
	//int match[4];
	int l_c;
	int r_c;
	int t_c;
	int b_c;
};

puzzle puzzles[2500 + 5];
//matched match_arr[10020];
int m_id;
int puzzle_id;
//int match4[2500 + 5];
//int match4_id;

void init(int n, int m, int k)
{
	N = n;
	M = m;
	K = k;

	/*for (int i = 0; i <= m_id; i++) {
		match_arr[i].dir1 = -1;
		match_arr[i].dir2 = -1;
		match_arr[i].id = -1;
		//match_arr[i].next = 0;
	}*/

	for (int i = 0; i <= puzzle_id; i++) {
		puzzles[i].id = -1;
		puzzles[i].matched_c = 0;
		puzzles[i].no_of_ones = 0;
		puzzles[i].l_c = -1;
		puzzles[i].r_c = -1;
		puzzles[i].t_c = -1;
		puzzles[i].b_c = -1;
		/*for (int k = 0; k < 4; k++) {
			puzzles[i].match[k] = -1;
		}*/
		//puzzles[i].match = { -1,-1,-1,-1 };
	}

	m_id = puzzle_id = 0;
	//match4_id = 0;
}

void addPiece(int piece[])
{
	int len = 4 * M;
	int p_id = puzzle_id;
	puzzle_id++;

	puzzles[p_id].id = p_id;
	int one_c = 0;
	for (int i = 0; i < M; i++) {
		puzzles[p_id].pat1[i] = piece[i];
		if (piece[i] == 1) one_c++;
	}
	for (int i = 0; i < M; i++) {
		puzzles[p_id].pat2[i] = piece[M + i];
		if (piece[M+i] == 1) one_c++;
	}
	for (int i = 0; i < M; i++) {
		puzzles[p_id].pat3[i] = piece[2 * M + i];
		if (piece[2*M+i] == 1) one_c++;
	}
	for (int i = 0; i < M; i++) {
		puzzles[p_id].pat4[i] = piece[3 * M + i];
		if (piece[3*M +i] == 1) one_c++;
	}
	puzzles[p_id].no_of_ones = one_c;
}

int findCenterPiece()
{
	for (int i = 0; i < M; i++) {
		printf("%d ", puzzles[2].pat1[i]);
		printf("%d ", puzzles[2].pat2[i]);
		printf("%d ", puzzles[2].pat3[i]);
		printf("%d ", puzzles[2].pat4[i]);
	}
	
	for (int i = 0; i < puzzle_id; i++) {
		for (int j = i + 1; j < puzzle_id; j++) {
			// 1st dir
			int k = 0;
			//bool flag = false;
			for (; k < M; k++) {
				if (puzzles[i].pat1[k] + puzzles[j].pat3[M - 1 - k] == 0) {
					continue;
				}
				else {
					//flag = true;
					break;
				}
			}
			if (k==M) {
				int t = puzzles[i].matched_c;
				puzzles[i].matched_c++;
				puzzles[i].t_c = j;
			}
			// 2nd dir
			k = 0;
			//flag = false;
			for (; k < M; k++) {
				if (puzzles[i].pat2[k] + puzzles[j].pat4[M - 1 - k] == 0) {
					continue;
				}
				else {
					//flag = true;
					break;
				}
			}
			if (k==M) {
				int t = puzzles[i].matched_c;
				puzzles[i].matched_c++;
				puzzles[i].r_c = j;
			}
			//3rd dir.
			k = 0;
			for (; k < M; k++) {
				if (puzzles[i].pat3[M - 1 - k] + puzzles[j].pat1[k] == 0) {
					continue;
				}
				else break;
			}
			if (k == M) {
				int t = puzzles[i].matched_c;
				puzzles[i].matched_c++;
				puzzles[i].b_c = j;
			}
			//4th dir.
			k = 0;
			for (; k < M; k++) {
				if (puzzles[i].pat4[M - 1 - k] + puzzles[j].pat2[k] == 0) {
					continue;
				}
				else break;
			}
			if (k == M) {
				int t = puzzles[i].matched_c;
				puzzles[i].matched_c++;
				/*int tmp = m_id++;
				match_arr[tmp].dir1 = 4;
				match_arr[tmp].dir2 = 2;
				match_arr[tmp].id = j;
				puzzles[i].match[t] = tmp;*/
				puzzles[i].l_c = j;
			}
		}
	}

	for (int i = 0; i < puzzle_id; i++) {

		bool flag1 = false;
		bool flag2 = false;
		//bool flag3 = false;
		//bool flag4 = false;

		int c;
		int id;
		// top case;
		c = 0;
		id = i;
		int n = 0;
		//printf("%d \n", puzzles[2].t_c);
		while (id != -1 && n<N/2+1) {
			id = puzzles[id].t_c;
			//printf("%d \n", id);
			if (id == -1) break;
			if (c == N / 2) break;
			else { c++; n++; }
		}
		//if (i == 2) printf("%d \n", c);
		if (c == (N / 2)) flag1 = true;
		//else continue;

		// right case;
		c = 0;
		id = i;
		n = 0;
		while (id != -1 && n < N/2 +1) {
			id = puzzles[id].r_c;
			if (id == -1) break;
			if (c == N / 2) break;
			else { c++; n++; }
		}
		//if (i == 2) printf("%d\n", c);
		if (c == (N / 2)) flag2 = true;
		//else continue;

		if (flag1 && flag2) {
			return puzzles[i].no_of_ones;
		}
	}
	return 0;
}