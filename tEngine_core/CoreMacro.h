#pragma once

#ifdef T_ENGINE_CORE_EXPORTS
#define T_ENGINE_CORE_API __declspec(dllexport)
#else
#define T_ENGINE_CORE_API __declspec(dllimport)
#endif

/***********************************
* Values
************************************/

constexpr auto UNSIGNED_INVALID = 0;

/***********************************
* Utils
************************************/
#define IN /*Parameter IN*/
#define OUT /*Parameter OUT*/

#define PURE_VIRTUAL /*Pure virtuals. It means this function is pure virtual.*/

#define IGNORED /*It means ignorable variable which is not used.*/
#define DISCARD /*It means the return value is not used.*/

#define UNSAFE /*It means this code is using reinterpret_cast about pointer.*/

#define NAMESPACE_OPEN(name) namespace name { /*Start namespace*/
#define NAMESPACE_CLOSE } /*End namespace*/

/*******************************************
* Crash Check
********************************************/

// Note: __analysis_assume does not work at runtime actually.
#define CRASH(text)                \
{                                       \
    unsigned int* crash = nullptr;      \
    __analysis_assume(crash != nullptr);\
    *crash = 0xDEADBEEF;                \
}                                       \

#define ASSERT_CRASH(condition)         \
{                                       \
    if (!(condition))                   \
    {                                   \
        CRASH("ASSERT_CRASH occurred.");\
        __analysis_assume(condition);   \
    }                                   \
}                                       \

#define ABORT(condition)                \
{                                       \
    if (!(condition))                   \
    {                                   \
        __analysis_assume(condition);   \
        std::abort();                   \
    }                                   \
}                                       \