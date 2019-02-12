#include <iostream>
#include <type_traits>
 
class A {};
 
class B : A {};
 
class C {};

template<typename base,typename derieved>
bool is_derieved_from() {
    return std::is_base_of<base,derieved>::value;
}
 
int main()
{
    /*std::cout << std::boolalpha;
    std::cout << "a2b: " << std::is_base_of<A, B>::value << '\n';
    std::cout << "b2a: " << std::is_base_of<B, A>::value << '\n';
    std::cout << "c2b: " << std::is_base_of<C, B>::value << '\n';
    std::cout << "same type: " << std::is_base_of<C, C>::value << '\n';*/
    std::cout << std::boolalpha;
    std::cout<<is_derieved_from<A,B>()<<std::endl;

    constexpr bool test = std::is_base_of<A,B>::value;
    std::cout<<test<<std::endl;
}

/*
template<typename D, typename B>
class IsDerivedFromHelper
{
    class No { };
    class Yes { No no[3]; };
    
    static Yes Test( B* );
    static No Test( ... );
public:
    enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) };
    
};


template <class C, class P> 
bool IsDerivedFrom() {
    return IsDerivedFromHelper<C, P>::Is;
}
*/