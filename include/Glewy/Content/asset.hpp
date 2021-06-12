#ifndef GLEWY_ASSET_HPP
#define GLEWY_ASSET_HPP

namespace gly{

class Asset{
public:
    virtual void LoadFrom(const char* file_name) = 0;
};

}

#endif