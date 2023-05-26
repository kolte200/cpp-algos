#pragma once

#ifndef UNSAFE_MODE
    #ifndef SAFE_MODE
        #define SAFE_MODE
    #endif
#endif

#ifdef SAFE_MODE
    #include <stdexcept>
#endif

#include <stdint.h>
#include <stddef.h>
