#ifndef GLEWY_ASSET_HPP
#define GLEWY_ASSET_HPP

#include<Glewy/Core/typedef.hpp>
#include<Glewy/Content/data.hpp>
#include<Glewy/Content/file.hpp>
#include<Glewy/Utilities/readfile.hpp>
#include<unordered_map>

#include<Glewy/Core/logging.hpp>

namespace gly{

template<class self>
class Asset {
public:
    static self* GetAsset(const Data& d){
        auto iter = map.find(d.data);
        if(iter == map.end()){
            self* asset = new self(d);
            map.emplace(d.data, asset);
            return asset;     
        }
        return iter->second;
    }
    static self* GetAsset(const File& f){
        auto iter = map.find(f.file_name);
        if(iter == map.end()){
            self* asset = new self(f);
            map.emplace(f.file_name, asset);
            return asset;     
        }
        return iter->second;
    }

protected:
    static std::unordered_map<void*, self*> map;

    virtual void LoadFromData(const Data& d) = 0;
    virtual void LoadFromFile(const File& f){
        std::vector<unsigned char> file_bytes;
        ReadFile(f.file_name, file_bytes);
        Data d(file_bytes.size(), file_bytes.data());
        LoadFromData(d);
    }
};
template<class self> std::unordered_map<void*, self*> Asset<self>::map;

}

#endif