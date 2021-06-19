#ifndef GLEWY_CACHE_HPP
#define GLEWY_CACHE_HPP

#include<list>

namespace gly{

template<class C, class S> class Cache{
public:
    Cache(const C& grouper):grouper(grouper){}

    bool IsEmpty(){
        if(cache.size() == 0){return true;}
        return false;
    }

    void CacheThis(const S& s){cache.push_back(s);}
    void DecacheThis(const S& s){cache.remove(s);}

    const C grouper;

    std::list<S> cache;
};

}

#endif