#include "../src/util.h"
namespace Sake{
    uint32_t GetThreadId(){
        return (uint32_t)pthread_self();
    }

    uint32_t GetFiberId(){
        return 0;
    }
}
