#ifndef __PATTERN_SINGLETON_H__
#define __PATTERN_SINGLETON_H__

namespace pattern
{
template <typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        static T instance;
        return instance;
    }

private:
    Singleton();
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    ~Singleton();
};
}
#endif
