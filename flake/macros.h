#define SIZE_BYTES(expr) (sizeof(expr))
#define SIZE_BITS(expr) (SIZE_BYTES(expr) << 3)

#define STRING(str) (#str)

#if defined(FLAKE_DEBUG)
    #define DEBUG_SCPOPE(code)\
        do {\
            code;\
        } while (false);
#else
    #define DEBUG_SCOPE(code) do { } while (false);
#endif

#define ASSERT_MESSAGE(condition, message)\
    DEBUG_CODE(\
        if (!(condition)) {\
            std::cerr << "Assertion failed: \033[1;31m" << message << "\033[0m (" << __FILE__ << "(" << __LINE__ << "))" << std::endl;\
            std::terminate();\
        }\
    )

#define ASSERT(condition) ASSERT_MESSAGE(condition, #condition)