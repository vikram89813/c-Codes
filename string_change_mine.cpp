#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const int MIN_WORD_SIZE = 6;
const int MAX_WORD_SIZE = 10;
const int MAX_SENTENCE_SIZE = 200000;
const int MAX_CHAR_COUNT = 8;
const int MAX_ERRORS = 2;
const int MIN_CHECK_RANGE = MIN_WORD_SIZE;
const int DICT_SIZE = 20000;
const char FIRST_CHAR = 'A';

//////////////////////////////////////////////////////////////////////////////////////////////////
namespace UserSolution {
    extern void init(char* dict[DICT_SIZE]);

    /**
    * Implement you solution
    * You can use  <code>{@link Main#isCorrect(int from, int to)} </code> to verify range
    */
    extern void doUserImplementation(char* sentence);
}
//////////////////////////////////////////////////////////////////////////////////////////////////

namespace {

    char dict_buff[DICT_SIZE*(MAX_WORD_SIZE + 1)];
    char* dict[DICT_SIZE];
    char mSentence[MAX_SENTENCE_SIZE + 1];
    char mutationSentence[MAX_SENTENCE_SIZE + 1];
    char sentence[MAX_SENTENCE_SIZE + 1];
    int sentenceLen;
    //int attemptsCount = 0;

    struct Rnd {
        typedef unsigned long long UInit64;
        UInit64 seed;
        static const int kAlpahabetSize = ('Z' - 'A') + ('z' - 'a') + ('9' - '0') + 3;
        char alpahabet[kAlpahabetSize];
        int charRange;

        Rnd() {
            seed = 0;
            charRange = 0;
            char *p = alpahabet;
            for (char c = 'A'; c <= 'Z'; ++c) *p++ = c;
            for (char c = 'a'; c <= 'z'; ++c) *p++ = c;
            for (char c = '0'; c <= '9'; ++c) *p++ = c;
        }
        void setSeed(UInit64 s) { seed = s; }

        inline UInit64 rand() {
            seed = (214013 * seed + 2531011);
            return seed >> 16;
        }

        void setCharRange(int charRange_) {
            charRange = charRange_;
        }

        inline int rand(UInit64 mx) {
            return static_cast<int>(rand() % mx);
        }

        inline char rand_char() {
            return alpahabet[rand(charRange)];
        }

        inline void rand_str(int length, char* ptr) {
            char* end = ptr + length;
            while (ptr != end) *ptr++ = rand_char();
            *ptr = 0;
        }
    };

    class Checker
    {
    public:
        bool run(int seed, int words) {
            rnd.setSeed(seed);
            rnd.setCharRange(MAX_CHAR_COUNT);
            sentenceLen = 0;
            char *ptr = dict_buff;
            for (int i = 0; i < DICT_SIZE; i++) {
                int kWordSize = MIN_WORD_SIZE + rnd.rand(MAX_WORD_SIZE - MIN_WORD_SIZE);
                rnd.rand_str(kWordSize, ptr);
                dict[i] = ptr;
                ptr += kWordSize + 1;
            }
            for (int i = 0; i < words; i++) {
                putWord(dict[rnd.rand(DICT_SIZE)], rnd.rand(MAX_ERRORS + 1));
            }
            mutationSentence[sentenceLen] = mSentence[sentenceLen] = 0; // 0-terminated
            for (int i = 0; i <=/*0-terminated*/ sentenceLen; i++) {
                sentence[i] = mutationSentence[i];
            }

            UserSolution::init(dict);
            UserSolution::doUserImplementation(sentence);

            return isValid();
        }
    private:
        Rnd rnd;
        void putWord(char* chars, int mutations) {
            if (sentenceLen != 0) {
                mutationSentence[sentenceLen] = ' ';
                mSentence[sentenceLen++] = ' ';
            }
            int chars_length = 0; while (*(chars + chars_length)) ++chars_length;
            for (int i = 0; i < chars_length; i++) {
                mutationSentence[sentenceLen + i] = chars[i];
                mSentence[sentenceLen + i] = chars[i];
            }
            for (int i = 0; i < mutations; i++) {
                int pos = rnd.rand(chars_length);
                mutationSentence[sentenceLen + pos] = rnd.rand_char();
            }
            sentenceLen += chars_length;
        }
        bool isValid() {
            for (int i = 0; i < sentenceLen; i++) {
                if (mSentence[i] != sentence[i])
                    return false;
            }
            return true;
        }
    };

    
}


// API : returns the result of a range check
bool isCorrect(int from, int to) {
    //attemptsCount++;
    if (to - from < MIN_CHECK_RANGE || from < 0 || to > sentenceLen)
        return false;
    for (int i = from; i < to; i++) {
        if (mSentence[i] != sentence[i])
            return false;
    }
    return true;
}

int main()
{
    Checker checker;

    int tests;
    scanf("%d", &tests);
    for (int test = 0; test<tests; ++test) {
        int seed, words;
        scanf("%d%d", &seed, &words);
        printf("#%d %s\n", test + 1, checker.run(seed, words) ? "true": "false");
    }

    return 0;
}

//======================================================
//extern bool isCorrect(int from, int to);

namespace UserSolution {
    const int DICT_SIZE = 20000;

    void init(char* dict[DICT_SIZE]) {}

    void doUserImplementation(char* sentence) {}
}
