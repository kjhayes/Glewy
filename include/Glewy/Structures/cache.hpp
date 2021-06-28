#ifndef GLEWY_CACHE_HPP
#define GLEWY_CACHE_HPP

#include<vector>
#include<set>
#include<algorithm>

namespace gly{

template<class C, class S> class Cache{
public:
    Cache(const C& grouper):grouper(grouper){}

    virtual bool IsEmpty() = 0;

    virtual void CacheThis(const S& s) = 0;
    virtual void DecacheThis(const S& s) = 0;

    const C grouper;
};

template<class C, class S> class VectorCache : public Cache<C,S>{
public:
    std::vector<S> cache;


    VectorCache(const C& g):Cache<C,S>(g){}

    bool IsEmpty(){
        if(this->cache.size() == 0){return true;}
        return false;
    }

    void CacheThis(const S& s) override {this->cache.push_back(s);}
    void DecacheThis(const S& s) override {this->cache.erase(std::find(cache.begin(), cache.end(), s));}
};

template<class C, class S> class SetCache : public Cache<C,S>{
public:
    std::set<S> cache;

    SetCache(const C& g):Cache<C,S>(g){}

    bool IsEmpty(){
        if(this->cache.size() == 0){return true;}
        return false;
    }

    void CacheThis(const S& s) override {this->cache.insert(s);}
    void DecacheThis(const S& s) override {this->cache.erase(s);}
};


}

#endif