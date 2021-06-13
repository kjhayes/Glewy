#ifndef GLEWY_ASSET_HPP
#define GLEWY_ASSET_HPP

#include<Glewy/Core/typedef.hpp>
#include<Glewy/Content/data.hpp>
#include<unordered_map>

#include<Glewy/Core/logging.hpp>

namespace gly{

template<class self>
class Asset {
public:
    static self* GetAsset(const Data& d){
        auto iter = map.find(d.data);
        if(iter == map.end()){
            self* ptr = new self(d);
            map.emplace(d.data, ptr);
            return ptr;     
        }
        return iter->second;
    }

protected:
    static std::unordered_map<void*, self*> map;

    virtual void LoadFromData(const Data& d) = 0;
};
template<class self> std::unordered_map<void*, self*> Asset<self>::map;

}

#endif