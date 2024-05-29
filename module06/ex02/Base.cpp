#include "./Base.hpp"

Base::~Base()
{
}

Base *generate(void)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int randomNumber = std::rand() % 3;
    switch (randomNumber)
    {
    case 0:
        std::cout << "creats A\n";
        return (new A);
        break;
    case 1:
        std::cout << "creats B\n";
        return (new B);
    case 2:
        std::cout << "creats C\n";
        return (new C);
    default:
        break;
    }
    return 0;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) {
        std::cout << "Base points to A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Base points to B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Base points to C" << std::endl;
    } else {
        std::cout << "Base points to an unknown type" << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        A& tmp = dynamic_cast<A&>(p);
        static_cast<void>(tmp);
        std::cout << "Base points to A" << std::endl;
    }
    catch(const std::bad_cast& e)
    {
        try
        {     
            B& tmp = dynamic_cast<B&>(p);
            std::cout << "Base points to B" << std::endl;
            static_cast<void>(tmp);
        }
        catch(const std::bad_cast& e)
        {
            try
            {
                C& tmp = dynamic_cast<C&>(p);
                std::cout << "Base points to C" << std::endl;
                static_cast<void>(tmp);
            }
            catch(const std::bad_cast& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}