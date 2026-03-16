#include <stdio.h>
#include <assert.h>

#define MAX_RING_COUNT 3  
typedef struct {
    int rings[MAX_RING_COUNT];
    int count;
} TTower;

typedef TTower TTowers[3];

void InitTowers(TTowers towers) {
    for (int i = 0; i < 3; i++) {
        towers[i].count = 0;
        for (int j = 0; j < MAX_RING_COUNT; j++) {
            towers[i].rings[j] = 0;
        }
    }

    
    for (int i = 0; i < MAX_RING_COUNT; i++) {
        towers[0].rings[i] = MAX_RING_COUNT - i;
    }
    towers[0].count = MAX_RING_COUNT;
}

void ShowTowers(TTowers towers) {
    printf("\n");
    for (int i = MAX_RING_COUNT - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i < towers[j].count) {
                printf("%d\t", towers[j].rings[i]);
            } else {
                printf("|\t");
            }
        }
        printf("\n");
    }
    printf("-----------------\n");
}

void MoveRing(TTower* from, TTower* to) {
    if (from->count == 0) {
        printf(\n");
        return;
    }

    if (to->count > 0 && from->rings[from->count - 1] > to->rings[to->count - 1]) {
        printf(\n");
        return;
    }

    to->rings[to->count] = from->rings[from->count - 1];
    to->count++;
    from->count--;
    from->rings[from->count] = 0;
}

int GetThirdIndex(int index1, int index2) {
    assert(index1 != index2);

    switch (index1) {
        case 0:
            return (index2 == 1) ? 2 : 1;
        case 1:
            return (index2 == 2) ? 0 : 2;
        case 2:
            return (index2 == 0) ? 1 : 0;
        default:
            assert(0 && "wrong indices");
            return -1;
    }
}

void MoveStack(int stacksize, int fromindex, int atindex, TTowers towers) {
    if (stacksize == 0) return;

    int thirdindex = GetThirdIndex(fromindex, atindex);

    MoveStack(stacksize - 1, fromindex, thirdindex, towers);

    MoveRing(&towers[fromindex], &towers[atindex]);
    printf("%d-%d\n", fromindex, atindex);
    ShowTowers(towers);
    MoveStack(stacksize - 1, thirdindex, atindex, towers);
}
void SolveHanoy() {
    TTowers towers;

    InitTowers(towers);
    printf(":\n");
    ShowTowers(towers);
    printf(" (from-to):\n");
    MoveStack(MAX_RING_COUNT, 0, 1, towers);
}

int main() {
    printf(" '' %d :\n", MAX_RING_COUNT);
    printf(": 0 - , 1 - , 2 - \n");
    printf(":  0  1\n\n");

    SolveHanoy();

    return 0;
}
