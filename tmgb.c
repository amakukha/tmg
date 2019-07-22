#include "tmgb.h"

void trans() {
    *g++ = iget();
    // Alternatively for long:
    //*((long*)g) = iget();
    //g = (long)((long*)g + 1);
    succ();
}

