#pragma GCC optimize ("-O3")

extern bool isCorrect(int from, int to);

namespace UserSolution {
    const int DICT_SIZE  = 20000;
    const int MINWORDLEN = 6;
    char charTable[256];
    char charDict[100];
    int dict_count = 0;

    void init(char* dict[DICT_SIZE]) {
        for (int i = 0; i < DICT_SIZE; i++)
            for (char *c = dict[i]; *c; c++)
                if (charTable[(unsigned)*c] == 0) {
                    charTable[(unsigned)*c] = 1;
                    charDict[dict_count++] = *c;
                }
    }

    void doUserImplementation(char* sentence) {
        int from = 0, to = MINWORDLEN;
        while (!isCorrect(from++, to++));

        int start = from - 1;
        for (; sentence[to - 1]; from++, to++)
            for (int i = 0; i < dict_count && !isCorrect(from, to); i++)
                sentence[to - 1] = charDict[i];

        from = start - 1;
        to = from + MINWORDLEN;
        for (; from >= 0; from--, to--)
            for (int i = 0; i < dict_count && !isCorrect(from, to); i++)
                sentence[from] = charDict[i];
    }
}

