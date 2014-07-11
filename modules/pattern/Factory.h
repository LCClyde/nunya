#ifndef __PATTERN_FACTORY_H__
#define __PATTERN_FACTORY_H__

#include <map>
#include <memory>
#include <string>
#include <pattern/Singleton.h>
#include <pattern/FactoryRegister.h>
#include <except/Exception.h>

namespace pattern
{
template <typename entityT>
class Factory
{
public:
    Factory()
    {
    }

    std::unique_ptr<entityT> create(const std::string& key) const
    {
        auto value = mMap.find(key);
        if (value == mMap.end())
            throw except::Exception("Key " + key + " out of bounds!");
        return (*value->second)();
    }

    std::unique_ptr<entityT>create(const std::string& key,
                                   const FactoryOptions* options) const
    {
        auto value = mMap.find(key);
        if (value == mMap.end())
            throw except::Exception("Key " + key + " out of bounds!");
        return (*value->second)(options);
    }

    bool registerObject(FactoryRegister<entityT>* object)
    {
        mMap[object->getKey()] =
                    std::unique_ptr<FactoryRegister<entityT> >(object);
        return true;
    }

    typedef pattern::Singleton<Factory<entityT> > FactoryManager;

private:
    std::map<std::string, std::unique_ptr<FactoryRegister<entityT> > > mMap;
};
}

#endif
