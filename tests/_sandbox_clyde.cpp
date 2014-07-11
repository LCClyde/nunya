#include <except/Exception.h>
#include <pattern/Factory.h>

/*
 *  \program _sandbox
 *  \brief This is a test bed for testing new functionality. This should not
 *         be committed and does not use arguments. Hardcoded values are
 *         expected and programs will often be deleted in time.
 */
int main(int, char**)
{
    try
    {
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
