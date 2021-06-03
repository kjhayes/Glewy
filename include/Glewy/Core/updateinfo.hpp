#ifndef GLEWY_UPDATE_INFO_HPP
#define GLEWY_UPDATE_INFO_HPP

namespace gly
{

class Instance;

struct UpdateInfo
{
    double delta_time;
    Instance* instance;
};

}

#endif