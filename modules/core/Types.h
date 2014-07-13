#ifndef __SYS_TYPES_H__
#define __SYS_TYPES_H__

#include <boost/cstdint.hpp>

namespace nyra
{
namespace core
{
typedef float float_t;
typedef double double_t;
typedef long double decimal_t;
typedef bool bool_t;
typedef boost::int8_t int8_t;
typedef boost::uint8_t uint8_t;
typedef boost::int16_t int16_t;
typedef boost::uint16_t uint16_t;
typedef boost::int32_t int32_t;
typedef boost::uint32_t uint32_t;
typedef boost::int64_t int64_t;
typedef boost::uint64_t uint64_t;
typedef char char_t;


// Windows
#ifdef _WIN32
#ifdef _WIN64
typedef boost::int64_t word;
typedef boost::uint64_t uword;
#else
typedef boost::int32_t word;
typedef boost::uint32_t uword;
#endif
#else
// Linux
#ifdef __linux__
typedef size_t uword;
typedef ssize_t word;
#endif
#endif
}
}
#endif
