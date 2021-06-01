#ifndef GLEWY_DOOL_HPP
#define GLEWY_DOOL_HPP

namespace gly{

struct dool{
protected:
    bool val, change;
public:
    dool();
    dool(const bool&);
    dool(const dool&);

    void Set(const bool&);
    bool GetValue();
    bool IsChanged();
};

}

#endif //GLEWY_DOOL_HPP