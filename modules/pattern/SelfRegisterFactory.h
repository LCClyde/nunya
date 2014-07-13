#ifndef __PATTERN_SELF_REGISTER_FACTORY_H__
#define __PATTERN_SELF_REGISTER_FACTORY_H__

#include <unordered_map>
#include <memory>
#include <string>
#include <pattern/Singleton.h>
#include <pattern/FactoryRegister.h>
#include <except/Exception.h>

namespace nyra
{
namespace pattern
{
template <typename entityT>
class SelfRegisterFactory
{
public:
    SelfRegisterFactory()
    {
    }

    std::unique_ptr<entityT> create(const std::string& key) const
    {
        auto value = mMap.find(key);
        if (value == mMap.end())
            throw except::Exception(
                    CONTEXT("Key " + key + " out of bounds!"));
        return (*value->second)();
    }

    std::unique_ptr<entityT>create(const std::string& key,
                                   const FactoryOptions* options) const
    {
        auto value = mMap.find(key);
        if (value == mMap.end())
            throw except::Exception(
                    CONTEXT("Key " + key + " out of bounds!"));
        return (*value->second)(options);
    }

    bool registerObject(FactoryRegister<entityT>* object)
    {
        mMap[object->getKey()] =
                    std::unique_ptr<FactoryRegister<entityT> >(object);
        return true;
    }

    typedef pattern::Singleton<SelfRegisterFactory<entityT> >
            SelfRegisterFactoryManager;

private:
    std::unordered_map<std::string,
                       std::unique_ptr<FactoryRegister<entityT> > > mMap;
};
}
}
#endif
