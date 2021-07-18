#ifndef GLEWY_SERIALIZABLE_HPP
#define GLEWY_SERIALIZABLE_HPP

#include<Glewy/Content/file.hpp>

namespace gly{

class Serializable {
    virtual void Serialize(const char* file_dir) = 0;
    void Serialize(const File& file);
    void Serialize(const std::string& file_dir);
};

}

#endif