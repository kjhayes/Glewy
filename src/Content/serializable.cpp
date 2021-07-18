#include<Glewy/Content/serializable.hpp>

namespace gly {

void Serializable::Serialize(const File& file){
    Serialize(file.file_name);
}
void Serializable::Serialize(const std::string& file_dir){
    Serialize(file_dir.c_str());
}

}