extern bool isCorrect(int from, int to);

namespace UserSolution {
    const int DICT_SIZE = 20000;

    const char* symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    void init(char* dict[DICT_SIZE])
    {
    }

    void doUserImplementation(char* sentence)
    {
        int first_correct=0;
        int len = 6;
        int i=0;
        while (sentence[i])
        {
            if ( isCorrect(i, i+len) )
            {
                first_correct = i;
                break;
            }
            i++;
        }

        for (i = first_correct-1; i >= 0; i--)
        {
            if ( isCorrect(i, i+len) )
                continue;

            for (int j = 0; j < 62; j++)
            {
                sentence[i] = symbols[j];
                if ( isCorrect(i, i+len) )
                    break;
            }
        }

        i = first_correct;
        while (sentence[i+len])
        {
            i++;
            if ( isCorrect(i, i+len) )
                continue;
            for (int j = 0; j < 62; j++)
            {
                sentence[i+len-1] = symbols[j];
                if ( isCorrect(i, i+len) )
                    break;
            }
        }
    }
}

