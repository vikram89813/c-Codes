#define MAX_MEMO_CNT  1000
 #define MAX_OPERATIONS  20000
 #define MAX_GET_SCR   10000
#define MAX_MEMO_STR_LEN 2180

typedef struct
 {
  int x,y; // Memo Window Top Left Position
  int W,H; // Memo Window dimensions
  int L;  // Memo string length
  char str[MAX_MEMO_STR_LEN+1];
 }Memo_t

int my_strcpy(char* src, char* dest)
 {
  // Copy from src to dest
  // Return string length
 }

Memo_t memo[MAX_MEMO_CNT];
 int stack[MAX_OPERATIONS];
 int top;
int id;

void init(int size)
 {
  top = -1; // Init Stack
 }

void Add_memo(int Id)
 {
  // Update memo[Id] object, store length
  // ...
  stack[++top] = Id;// Push to stack
 }

void move(int Id)
 {
  // Update memo[Id] object
  // ...
  stack[++top] = Id;// Push to stack
 }

void modify(int Id)
 {
  // Update memo[Id] object, store length
  // ...
  stack[++top] = Id;// Push to stack
 }


 void observe(int Id)
 { 
  stack[++top] = Id;// Push to stack
 }

// All processing is done here
 void getscr(char result[5][5])
 {
  int update[5][5] = {0},upd_cnt = 0;
  int i = top,j;
  
  while(i >= 0)// Move through stack backwards
  {
   k = stack[i--];
  
   // Check x index overlap
   // Check y index overlap
   //if both indexes overlap,
   //  Calculate indexes in result array
   //  Xs: x index start of overlap (0 to 4),
   //  Xe: x index end of overlap (0 to 4),
   //   Ys: y index start of overlap (0 to 4) and
   //  Ye: y index end of overlap (0 to 4)
   str_index = 0;
   //for i from Xs to Xe
   // for j from Ys to Ye
     if(update[i][j] == 0)
     {
      // Calculate x_offset to move i to index in Memo[k]  (0 to Memo[k].W-1)
      // ie, i+x_offset = x index of overlap in memo window
      // Calculate y_offset to move j to index in Memo[k] (0 to Memo[k].H-1)
      // ie, j+y_offset = y index of overlap in memo window
      
      str_index = (j+y_offset)*memo[k].W + (i+x_offset); // Calculate index in string
      if(str_index < memo[k].L) // Check if it is less than memo str length
      {
       result[j][i] = 
      }
      upd_cnt++;
      if(upd_cnt == 25)
      {
       break;
      }
     }
    //for end
    if(upd_cnt == 25)
    {
     break;
    }
   //for end
   if(upd_cnt == 25)
   {
    break;
   }
  }
 }

