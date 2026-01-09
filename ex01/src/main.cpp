#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

// template <typename T>
// T serialize_template(Data* ptr)
// {
//     return reinterpret_cast<T>(ptr);
// }

// template <typename T>
// Data* deserialize_template(T raw)
// {
//     return reinterpret_cast<Data*>(raw);
// }

int main()
{
    Data original(4, 2);
    
    std::cout << "Original pointer: " << &original << std::endl;
    std::cout << "sizeof(void*):    " << sizeof(void*) << " bytes\n\n";
    
    std::cout << "=== Type sizes ===" << std::endl;
    std::cout << "sizeof(unsigned short):     " << sizeof(unsigned short) << " bytes" << std::endl;
    std::cout << "sizeof(unsigned int):       " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "sizeof(unsigned long):      " << sizeof(unsigned long) << " bytes" << std::endl;
    std::cout << "sizeof(uintptr_t):          " << sizeof(uintptr_t) << " bytes" << std::endl;
    std::cout << "sizeof(size_t):             " << sizeof(size_t) << " bytes" << std::endl;
    std::cout << std::endl;
    
    // uintptr_t 
    std::cout << "=== uintptr_t ===" << std::endl;

    uintptr_t num_ptr = Serializer::serialize(&original);
    std::cout << "Serialized value: " << num_ptr << std::endl;

    Data* restored_ptr = Serializer::deserialize(num_ptr);

    std::cout << "restored == orginal ? " << (restored_ptr == &original ? "YES" : "NO") << std::endl;
    std::cout << std::endl;
    
    // Hex representation
    std::cout << "=== Hex representation ===" << std::endl;
    std::cout << std::hex << std::showbase;
    std::cout << "Original address:        " << &original << std::endl;
    //std::cout << "As unsigned long:        " << num_long << std::endl;
    //std::cout << "As size_t:               " << num_sizet << std::endl;
    std::cout << "As uintptr_t:            " << num_ptr << std::endl;
    std::cout << "Restored address:        " << &restored_ptr << std::endl;



    /* won't compile
    std::cout << "=== Testing unsigned short (2 bytes) ===" << std::endl;
    unsigned short num_short = serialize_template<unsigned short>(&original);
    */
    
    // // unsigned long - works on 64-bit Linux/Mac
    // std::cout << "=== Testing unsigned long ===" << std::endl;
    // unsigned long num_long = serialize_template<unsigned long>(&original);
    // std::cout << "Serialized: " << num_long << std::endl;
    // Data* restored_long = deserialize_template<unsigned long>(num_long);
    // std::cout << "Match? " << (restored_long == &original ? "YES ✓" : "NO ✗") << std::endl;
    // std::cout << std::endl;

    
    // // size_t - often same as uintptr_t but not guaranteed
    // std::cout << "=== Testing size_t ===" << std::endl;
    // size_t num_sizet = serialize_template<size_t>(&original);
    // std::cout << "Serialized: " << num_sizet << std::endl;
    // Data* restored_sizet = deserialize_template<size_t>(num_sizet);
    // std::cout << "Match? " << (restored_sizet == &original ? "YES ✓" : "NO ✗") << std::endl;
    // std::cout << std::endl;

    
    return 0;
}
