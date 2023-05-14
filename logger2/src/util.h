#pragma once
#include <pthread.h>
#include <stdint.h>
namespace Sake{
    uint32_t GetThreadId();
    uint32_t GetFiberId();
}