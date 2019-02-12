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
	freopen("input_puzzle.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= 1; tc++)
	{
		printf("#%d %d\n", tc, run());
	}

	return 0;
}

//==========================================================

#pragma GCC optimize ("-Ofast")

struct puzzle {
  int one_c;
  int sum1;
  int sum2;
  int sum3;
  int sum4;
  int pat[61];
  int match_c[4];
  int nodes[4][6];
};

puzzle puzzles[2010];
int N,M,K;
int gid;

void init(int n, int m, int k)
{
  for(int i=0;i<=gid;i++) {
    puzzles[i].one_c=0;
    puzzles[i].sum1=0;
    puzzles[i].sum2=0;
    puzzles[i].sum3=0;
    puzzles[i].sum4=0;
    for(int j=0;j<4;j++)
      puzzles[i].match_c[j] = 0;

    for(int j=0;j<4;j++) {
      for(int k=0;k<6;k++)
        puzzles[i].nodes[j][k] = -1;
    }
  }
  gid = 0;
  N=n;
  M=m;
  K=k;
}

void addPiece(int piece[])
{
  int s = (4 * M);
  for(int i =0;i<s;i++) {
    puzzles[gid].pat[i] = piece[i];
    if(piece[i] == 1) puzzles[gid].one_c++;
  }

  // calculate sum for all directions;
  int c=0;
  for(int j=0;j<M;j++) c+=puzzles[gid].pat[j];
  puzzles[gid].sum1 = c;

  c = 0;
  for(int j=M;j<2*M;j++) c+=puzzles[gid].pat[j];
  puzzles[gid].sum2 = c;

  c = 0;
  for(int j=2*M;j<3*M;j++) c+=puzzles[gid].pat[j];
  puzzles[gid].sum3 = c;

  c = 0;
  for(int j=3*M;j<4*M;j++) c+=puzzles[gid].pat[j];
  puzzles[gid].sum3 = c;

  gid++;
}

void find_match() {
  for(int i=0;i<gid;i++) {
    for(int j=0;j<gid;j++) {
      if(i != j) {
        // find matching puzzle pieces.
        //top
        if(puzzles[i].sum1 + puzzles[j].sum3==0) {
          int idx = puzzles[i].match_c[0];
          puzzles[i].nodes[0][idx] = j;
          puzzles[i].match_c[0]++;
        }
        //right
        if(puzzles[i].sum2 + puzzles[j].sum4==0) {
          int idx = puzzles[i].match_c[1];
          puzzles[i].nodes[1][idx] = j;
          puzzles[i].match_c[1]++;
        }
        //bottom
        if(puzzles[i].sum3 + puzzles[j].sum1==0) {
          int idx = puzzles[i].match_c[2];
          puzzles[i].nodes[2][idx] = j;
          puzzles[i].match_c[2]++;
        }
        //left
        if(puzzles[i].sum4 + puzzles[j].sum2==0) {
          int idx = puzzles[i].match_c[3];
          puzzles[i].nodes[3][idx] = j;
          puzzles[i].match_c[3]++;
        }
      }
    }
  }
}

int findCenterPiece()
{
  find_match();
  for(int i=0;i<gid;i++) {
    int m_c =0;

    // base case : return if not matching with
    // anyone on any particular side.
    /*if(!puzzles[i].match_c[0]) continue;
    if(!puzzles[i].match_c[1]) continue;
    if(!puzzles[i].match_c[2]) continue;
    if(!puzzles[i].match_c[3]) continue;*/

    for(int j =0;j<4;j++) m_c+=puzzles[i].match_c[j];

    printf("\n id : %d, match_c : %d\n", i,m_c);

   // check all 4 sides for this id.
   // Top
   }
  return 0;
}






























