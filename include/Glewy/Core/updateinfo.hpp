#ifndef GLEWY_UPDATE_INFO_HPP
#define GLEWY_UPDATE_INFO_HPP

namespace gly
{

class Instance;

///@brief Struct Given To Every Updating Component In An Active Root Every Update Cycle
struct UpdateInfo
{
    ///@brief Time In Milliseconds Since The Last Update
    double delta_time;
    ///@brief Pointer To The Instance Which Is Running The Current Root
    Instance* instance;
};

}

#endif