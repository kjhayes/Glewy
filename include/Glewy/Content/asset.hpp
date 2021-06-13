#ifndef GLEWY_ASSET_HPP
#define GLEWY_ASSET_HPP

#include<Glewy/Core/typedef.hpp>
#include<unordered_map>

#include<Glewy/Core/logging.hpp>

namespace gly{

struct AssetCode{
public:
    AssetCode(const int& s, gly_byte* d_a):size(s),data_addr(d_a){}
    const int size;
    gly_byte* data_addr;
};

template<class self>
class Asset {
public:
    static self* GetAsset(const AssetCode& code){
        auto iter = map.find(code.data_addr);
        if(iter == map.end()){
            GLY_DEBUG_LOG("Generated Asset At Address: ");
            GLY_DEBUG_LOG((int)code.data_addr);
            self* ptr = new self(code);
            map.emplace(code.data_addr, ptr);
            return ptr;     
        }
        return iter->second;
    }

protected:
    static std::unordered_map<void*, self*> map;

    virtual void LoadFromData(const AssetCode& code) = 0;
};
template<class self> std::unordered_map<void*, self*> Asset<self>::map;

}

#endif