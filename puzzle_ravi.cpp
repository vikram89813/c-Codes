#include <malloc.h>
#pragma GCC optimize ("-Ofast")

int gN = 0, gM = 0, gK = 0, pId = 0, pSize = 0;

typedef struct puzDS
{
i   int data[60]; // MAXM*4
    short adjpId[4];
    int onesCount;
}puzDS;

puzDS *puzzles = NULL;
void init(int N, int M, int K)
{
    if (puzzles != NULL)
    {
        delete puzzles;
        puzzles = NULL;
    }
    pSize = N*N + K;
    puzzles = (puzDS*)calloc(pSize, sizeof(puzDS));

    gN = N;
    gM = M;
    gK = K;
    pId = 0;
}

void addPiece(int piece[])
{
    int oneCount = 0;
    int pieceSize = (gM * 4 - 1);
    for (int i = 0; i < pieceSize; ++i)
    {
        if (piece[i] == 1)
        {
            oneCount++;
        }
        puzzles[pId].data[i] = piece[i];
    }
    puzzles[pId].adjpId[0] = -1; // adj top piece
    puzzles[pId].adjpId[1] = -1; // adj right piece
    puzzles[pId].adjpId[2] = -1; // adj bottom piece
    puzzles[pId].adjpId[3] = -1; // adj left piece

    puzzles[pId].onesCount = oneCount;
    pId++;
}

void fillAdjPieces()
{
    // now fill the directions for every pID
    short id1 = 0;
    short id2 = 0;
    short fit = 1;
    for (id1 = 0; id1 < pId; ++id1)
    {
        short oneM = gM;
        short twoM = (2 * gM);
        short threeM = (3 * gM);
        short fourM = (4 * gM);
        int i = 0, j = 0;

        // Top Check
        {
            for (id2 = 0; id2 < pId; ++id2)
            {
                if (id1 != id2)
                {
                    for (i = 0, j = threeM - 1; i < oneM && j >= twoM; ++i, --j)
                    {
                        if (puzzles[id1].data[i] == 0 &&
                            puzzles[id2].data[j] != 0)
                        {
                            fit = 0;
                            break;
                        }
                        else if (puzzles[id1].data[i] == -1 &&
                                 puzzles[id2].data[j] != 1)
                        {
                            fit = 0;
                            break;
                        }
                        else if (puzzles[id1].data[i] == 1 &&
                                 puzzles[id2].data[j] != -1)
                        {
                            fit = 0;
                            break;
                        }
                    } // for (i, j)

                    if (fit == 1)
                    {
                        puzzles[id1].adjpId[0] = id2; // found adjTop
                        break;
                    }
                    else
                    {
                        fit = 1;
                    }

                } // if(id1 != id2)
            } // for(id2)
        } // Top Check

        fit = 1;
        // right Check
        {
            for (id2 = 0; id2 < pId; ++id2)
            {
                if (id1 != id2)
                {
                    for (i = oneM, j = fourM - 1; i < twoM && j >= threeM; ++i, --j)
                    {
                        if (puzzles[id1].data[i] == 0 &&
                            puzzles[id2].data[j] != 0)
                        {
                            fit = 0;
                            break;
                        }
                        else if (puzzles[id1].data[i] == -1 &&
                                 puzzles[id2].data[j] != 1)
                        {
                            fit = 0;
                            break;
                        }
                        else if (puzzles[id1].data[i] == 1 &&
                                 puzzles[id2].data[j] != -1)
                        {
                            fit = 0;
                            break;
                        }
                    } // for (i, j)

                    if (fit == 1)
                    {
                        puzzles[id1].adjpId[1] = id2; // found adjTop
                        break;
                    }
                    else
                    {
                        fit = 1;
                    }

                } // if(id1 != id2)
            } // for(id2)
        } // right Check

        fit = 1;
        // Bottom Check
        {
            for (id2 = 0; id2 < pId; ++id2)
            {
                if (id1 != id2)
                {
                    for (i = twoM, j = oneM - 1; i < threeM && j >= 0; ++i, --j)
                    {
                        if (puzzles[id1].data[i] == 0 &&
                            puzzles[id2].data[j] != 0)
                        {
                            fit = 0;
                            break;
                        }
                        else if (puzzles[id1].data[i] == -1 &&
                                 puzzles[id2].data[j] != 1)
                        {
                            fit = 0;
                            break;
                        }
                        else if (puzzles[id1].data[i] == 1 &&
                                 puzzles[id2].data[j] != -1)
                        {
                            fit = 0;
                            break;
                        }
                    } // for (i, j)

                    if (fit == 1)
                    {
                        puzzles[id1].adjpId[2] = id2; // found adjTop
                        break;
                    }
                    else
                    {
                        fit = 1;
                    }

                } // if(id1 != id2)
            } // for(id2)
        } // Bottom Check

        fit = 1;
        // Left Check
        {
            for (id2 = 0; id2 < pId; ++id2)
            {
                if (id1 != id2)
                {
                    for (i = threeM, j = twoM - 1; i < fourM && j >= oneM; ++i, --j)
                    {
                        if (puzzles[id1].data[i] == 0 &&
                            puzzles[id2].data[j] != 0)
                        {
                            fit = 0;
                            break;
                        }
                        else if (puzzles[id1].data[i] == -1 &&
                                 puzzles[id2].data[j] != 1)
                        {
                            fit = 0;
                            break;
                        }
                        else if (puzzles[id1].data[i] == 1 &&
                                 puzzles[id2].data[j] != -1)
                        {
                            fit = 0;
                            break;
                        }
                    } // for (i, j)

                    if (fit == 1)
                    {
                        puzzles[id1].adjpId[3] = id2; // found adjTop
                        break;
                    }
                    else
                    {
                        fit = 1;
                    }

                } // if(id1 != id2)
            } // for(id2)
        } // Left Check

    } // for (id1)

}

/*
void printAllPieces()
{
for (int i = 0; i < pSize; ++i)
{
printf("piece(%d)==> top=%d .. right=%d .. Btm=%d .. left=%d .. OneCount=%d\n", i, puzzles[i].adjpId[0], puzzles[i].adjpId[1], puzzles[i].adjpId[2], puzzles[i].adjpId[3], puzzles[i].onesCount);
}
}
*/
int findCenterPiece()
{
    short tlPid = -1;
    fillAdjPieces();

    //printAllPieces();
    for (int i = 0; i < pSize; ++i)
    {
        // find topLeftPid
        if (puzzles[i].adjpId[0] == -1 &&
            puzzles[i].adjpId[1] != -1 &&
            puzzles[i].adjpId[2] != -1 &&
            puzzles[i].adjpId[3] == -1)
        {
            tlPid = i;
            break;
        }
    }
    /*
    if (tlPid == -1)
    {
    printf("OOPS (0)... topLeft Puzzle not found... Something wrong in addPiece()\n");
    return 0;
    }

    else
    {

    printf("YUREKA !!! topLeft Puzzle FOUND and is = %d\n", tlPid);
    }
   */

    short firstCid = tlPid; // move in the rightDir upto gN/2 times
    for (short rightMove = 0; rightMove < (gN / 2); ++rightMove)
    {
        if (puzzles[firstCid].adjpId[1] != -1)
        {
            firstCid = puzzles[firstCid].adjpId[1];
        }
        else
        {
            //printf("OOPS ... (1) First Centre position finding.. Something WRONG!!!\n");
            break;
        }
    }
    for (short downMove = 0; downMove < (gN / 2); ++downMove)
    {
        if (puzzles[firstCid].adjpId[2] != -1)
        {
            firstCid = puzzles[firstCid].adjpId[2];
        }
        else
        {
            //printf("OOPS ... (2) First Centre position finding.. Something WRONG!!!\n");
            break;
        }
    }

    //printf("YUREKA !!! First Centre position FOUND and is = %d\n", firstCid);

    short secondCid = tlPid; // move in the rightDir upto gN/2 times
    for (short bottomMove = 0; bottomMove < (gN / 2); ++bottomMove)
    {
        if (puzzles[secondCid].adjpId[2] != -1)
        {
            secondCid = puzzles[secondCid].adjpId[2];
        }
        else
        {
            //printf("OOPS ... (3) Second Centre position finding.. Something WRONG!!!\n");
            break;
        }
    }
    for (short rightMove = 0; rightMove < (gN / 2); ++rightMove)
    {
        if (puzzles[secondCid].adjpId[1] != -1)
        {
            secondCid = puzzles[secondCid].adjpId[1];
        }
        else
        {
            //printf("OOPS ... (4) Second Centre position finding.. Something WRONG!!!\n");
            break;
        }
    }

    //printf("YUREKA !!! Second Centre position FOUND and is = %d\n", secondCid);

    if (firstCid == secondCid)
    {
        //printf("YUREKA !!! Centre ID Found\n");
        return puzzles[secondCid].onesCount;
    }
    return 0;
}

