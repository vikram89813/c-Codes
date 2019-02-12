#include <stdio.h>
#include<iostream>

using namespace std;

#define MAX 100005

int arr[MAX];
int farr[MAX];
int ld;
int cld;
int start;
int end_;
int idx;
int tidx;
int tsize;
int H;

void init(int track_size, int head){
  for(int i=0;i<MAX;i++) {
    arr[i] = -1;
    farr[i] = -1;
  }
  ld = -1;
  cld = -1;
  start= track_size;
  end_ = -1;
  idx = 0;
  tidx = 0;
  tsize = track_size;
  H = head;
}

void request(int track){
  farr[idx] = track;
  arr[track] = idx;
  idx++;

  if(track < start) start = track;
  if(track > end_) end_ = track;
}

int fcfs(){
  int res = -1;
  while(farr[tidx] == -1) tidx++;

  res = farr[tidx];
  arr[res] = -1;
  farr[tidx] = -1;
  H = res;
  return res;
}

int sstf(){
  int res=-1;
  int l,r;
  l = r = H;

  while(l>= start && r<= end_ && arr[l] == -1 && arr[r] == -1) {
    l--;
    r++;
  }

  if(l < start) {
    while(r <= end_ && arr[r] == -1) r++;
    if(r<=end_ && arr[r] != -1) res = farr[arr[r]];
  }

  else if(r>end_) {
    while(l >= start && arr[l] == -1) l--;
    if(l>= start && arr[l] != -1) res = farr[arr[l]];
  }

  if(l>= start && arr[l] != -1 && res == -1) res = farr[arr[l]];
  if(r<=end_ && arr[r] != -1 && res == -1) res = farr[arr[r]];

  H = res;
  farr[arr[res]] = -1;
  arr[res] = -1;
  return res;
}

int look(){
  int res=-1;
  int l;
  l = H;

  while(l >= start && l<=end_ && arr[l] == -1) l = l+ld;

  if(l<start) {
    l = H;
    ld = 1;
    while(l<=end_ && arr[l] == -1) l = l+ld;
  }

  if(l>end_) {
    l = H;
    ld = -1;
    while(l>=start && arr[l] == -1) l = l+ld;
  }

  res = farr[arr[l]];
  H = res;
  farr[arr[res]] = -1;
  arr[res] = -1;
  return res;
}

int clook(){
  int res=-1;
  int l;
  l = H;

  while(l >= start && arr[l] == -1) l = l+cld;

  if(l<start) {
    l = end_;
    while(l >= start && arr[l] == -1) l = l+cld;
  }

  res = farr[arr[l]];
  H = res;
  farr[arr[res]] = -1;
  arr[res] = -1;
  return res;
}

//###########################################################################################################


enum COMMAND {
	CMD_REQUEST = 0,
	CMD_FCFS = 1,
	CMD_SSTF = 2,
	CMD_LOOK = 3,
	CMD_CLOOK = 4
};

extern void init(int track_size, int head);
extern void request(int track);
extern int fcfs();
extern int sstf();
extern int look();
extern int clook();

static const int SAMPLE_SIZE = 200;
static int track_size;
static int track_head;
static int answer[MAX];
static int answer_size;
static int answer_idx;
static int req_q[MAX];
static int req_size;
static int req_idx;
static int cmd_q[MAX*2];
static int cmd_size;
static int cmd_idx;

static bool flag[MAX];

static int mSeed;
static int mrand(int num)
{
	mSeed = mSeed * 1103515245 + 37209;
	if (mSeed < 0) mSeed *= -1;
	return ((mSeed >> 8) % num);
}

static void load_data(int tc){
	scanf("%d %d", &track_size, &track_head);

	if(tc <= 4){
		scanf("%d", &req_size);
		for(register int i = 0; i < req_size; ++i) scanf("%d", &req_q[i]);
		scanf("%d", &cmd_size);
		for(register int i = 0; i < cmd_size; ++i) scanf("%d", &cmd_q[i]);
		scanf("%d", &answer_size);
		for(register int i = 0; i < answer_size; ++i) scanf("%d", &answer[i]);			
	}
	else{		
		scanf("%d %d", &req_size, &answer_size);
		for(register int i = 0; i < answer_size; ++i) scanf("%d", &answer[i]);
		scanf("%d", &mSeed);
		cmd_size = req_size + answer_size;
	}	
}

static int run(int tc){
	answer_idx = req_idx = cmd_idx = 0;
	int correct = 0;
	int cmd = 0;
	int user_answer = 0;	
	int new_track = 0;
	int req_cnt = 0;
	
	for(register int i = 0; i < track_size; ++i) flag[i] = false;

	while(req_size != req_cnt || (tc <= 4 && cmd_size != cmd_idx)){
		if(tc <= 4)	cmd = cmd_q[cmd_idx++];
		else cmd = mrand(9);

		user_answer = -1;

		if(CMD_FCFS <= cmd && CMD_CLOOK >= cmd && (req_cnt - answer_idx) > 0){
			if(cmd == CMD_FCFS) user_answer = fcfs();
			else if(cmd == CMD_SSTF) user_answer = sstf();
			else if(cmd == CMD_LOOK) user_answer = look();
			else user_answer = clook();		

			if(answer[answer_idx++] == user_answer)	++correct;
		}
		else{			
			if(tc <= 4) new_track = req_q[req_idx++];
			else{
				new_track = mrand(track_size);
				while(flag[new_track]) { 
					++new_track;
					if(new_track == track_size) new_track = 0; 
				} 
			}
		
			request(new_track);
			flag[new_track] = true;
			++req_cnt;
		}
	}
	
	return correct;
}

int main(){		
	setbuf(stdout, NULL);
	freopen("sample_input_disk_sch.txt", "r", stdin);
	
	int total_score = 0, T;
	scanf("%d", &T);
		
	for(int tc = 1; tc <= T; ++tc){
		load_data(tc);
		init(track_size, track_head);
		int score = run(tc);		
		printf("#%d %d\n", tc, score);
		total_score += score;
	}
	
	printf("Total score: %d\n", total_score); 
	return 0;
}

