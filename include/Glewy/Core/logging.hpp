#ifndef GLEWY_LOGGING_HPP
#define GLEWY_LOGGING_HPP
#include<Glewy/Core/macros.hpp>

#ifdef GLEWY_DEBUG
#include<iostream>
#define GLY_DEBUG_LOG(str) std::cout<<str<<std::endl
#else 
#define GLY_DEBUG_LOG(str)
#endif //GLEWY_DEBUG
 

#endif //GLEWY_LOGGING_HPP