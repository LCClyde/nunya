#ifndef __PATTERN_FACTORY_REGISTER_H__
#define __PATTERN_FACTORY_REGISTER_H__
#include <memory>

/*
 *  \macro REGISTER_CLASS
 *  \brief Calls the static function to move the register into the factory
 *         map. This should be placed directly after a register.
 *
 *  \param className The name of the class the Factory creates.
 *  \param registerName The name of the derived register class.
 *  TODO: It should be possible to have the FactoryRegister do automagically.
 */
#define REGISTER_CLASS(className, registerName) \
        const bool isRegistered##className = \
        nyra::pattern::Singleton< \
        nyra::pattern::SelfRegisterFactory<className> >:: \
        getInstance().registerObject(new registerName());

namespace nyra
{
namespace pattern
{
/*
 *  \class FactoryOptions
 *  \brief Factory entities can override this class to allow for custom
 *         construction parameters.
 */
struct FactoryOptions
{
    /*
     *  \func Destructor
     *  \brief Here to handle inheritance properly.
     */
    virtual ~FactoryOptions()
    {
    }
};

/*
 *  \class FactoryRegister
 *  \brief When creating a factory object you should create a register that
 *         inherits from this class. The purpose of this class is to create
 *         a lightweight accessor that creates the object from the factory.
 *         The factory will call a functor when the user asks for a new
 *         object.
 *
 *  \param entityT The class that is created when a functor is called.
 */
template <typename entityT>
struct FactoryRegister
{
public:
    /*
     *  \func Destructor
     *  \brief Here to handle inheritance properly.
     */
    virtual ~FactoryRegister()
    {
    }

    /*
     *  \func getKey
     *  \brief Each derived class should override this with a unique
     *         identifier to allow the user to access the type of register.
     *
     *  \return The hardcoded string.
     */
    virtual std::string getKey() const = 0;

    /*
     *  \func operator()
     *  \brief You should override this and create an instance of entityT.
     *         The Factory class will call this functor when asked to create
     *         a new instance. If you need parameters you should use the
     *         functor with the options parameter.
     *
     *  \return A new instance of entityT.
     */
    virtual std::unique_ptr<entityT> operator()() const = 0;

    /*
     *  \func operator()
     *  \brief You should override this and create an instance of entityT.
     *         The Factory class will call this functor when asked to create
     *         a new instance.
     *
     *  \param options To use this override a FactoryOptions object and
     *                 pass it in when asking for a new object from the
     *                 factory. You can then dynamically cast to your derived
     *                 class.
     *  \return A new instance of entityT.
     */
    virtual std::unique_ptr<entityT> operator()(
                const FactoryOptions* options) const = 0;
};
}
}
#endif
