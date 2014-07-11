#include <iostream>
#include <vector>
#include <except/Exception.h>
#include <pattern/Factory.h>
#include <pattern/FactoryRegister.h>
/*
 *  \program test_pattern_factory
 *  \brief Shows how to properly use the Factory class
 */

namespace
{
const std::string FactoryKey = "FactoryTest";

struct FactoryOptions : public pattern::FactoryOptions
{
    FactoryOptions()
    {
    }

    FactoryOptions(const std::string& name) :
        name(name)
    {
    }

    std::string name;
};

class FactoryEntity
{
public:
    FactoryEntity(const FactoryOptions* options) :
        mName(options->name)
    {
    }

    const std::string mName;
};

struct FactoryTestRegister :
            public pattern::FactoryRegister<FactoryEntity>
{
    FactoryTestRegister() : FactoryRegister()
    {
    }

    std::string getKey() const
    {
        return FactoryKey;
    }

    std::unique_ptr<FactoryEntity> operator()() const
    {
        except::Exception("Default construction is not allowed!");
        return std::unique_ptr<FactoryEntity>();
    }

    std::unique_ptr<FactoryEntity> operator()(
                const pattern::FactoryOptions* options) const
    {
        return std::unique_ptr<FactoryEntity>(new FactoryEntity(
                        dynamic_cast<const FactoryOptions*>(options)));
    }
};
REGISTER_CLASS(FactoryEntity, FactoryTestRegister);

typedef pattern::Factory<FactoryEntity>::FactoryManager FactoryTest;
}

int main(int, char**)
{
    try
    {
        std::vector<std::unique_ptr<FactoryEntity> > entities;
        FactoryOptions options("Hello");
        entities.push_back(FactoryTest::getInstance().create(
                    FactoryKey, &options));
        options.name = "World";
        entities.push_back(FactoryTest::getInstance().create(
                    FactoryKey, &options));
        options.name = "How";
        entities.push_back(FactoryTest::getInstance().create(
                    FactoryKey, &options));
        options.name = "Are";
        entities.push_back(FactoryTest::getInstance().create(
                    FactoryKey, &options));
        options.name = "You";
        entities.push_back(FactoryTest::getInstance().create(
                    FactoryKey, &options));
        options.name = "?";
        entities.push_back(FactoryTest::getInstance().create(
                    FactoryKey, &options));

        for (size_t ii = 0; ii < entities.size(); ++ii)
        {
            std::cout << entities[ii]->mName << " ";
        }
        std::cout << "\n";

        return 0;
    }
    catch (except::Exception& ex)
    {
        std::cerr << "Caught an internal exception: "
            << ex.getMessage() << std::endl;
        return 1;
    }
    catch (std::exception& ex)
    {
        std::cerr << "Caught an stl exception: "
            << ex.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Caught an unknown exception\n";
        return 1;
    }
}
