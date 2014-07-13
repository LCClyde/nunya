#ifndef __PATTERN_SHARED_RESOURCE_FACTORY_H__
#define __PATTERN_SHARED_RESOURCE_FACTORY_H__

#include <unordered_map>
#include <memory>

namespace nyra
{
namespace pattern
{
template <typename keyT, typename resourceT>
class SharedResourceFactory
{
public:
    std::shared_ptr<resourceT> getResource(const keyT& key)
    {
        auto resource = mMap.find(key);
        if (resource != mMap.end() && !resource->second.expired())
        {
            return resource->second.lock();
        }
        else
        {
            std::shared_ptr<resourceT> shared(new resourceT(key));
            mMap[key] = shared;
            return shared;
        }
    }

private:
    typedef
    std::unordered_map<keyT, std::weak_ptr<resourceT> > mMap;
};
}
}

#endif
