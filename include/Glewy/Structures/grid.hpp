#ifndef GLEWY_GRID_HPP
#define GLEWY_GRID_HPP

#include<set>

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Content/asset.hpp>

namespace gly{

class Grid : Asset<Grid> {

public:
    Grid(const Data&);
    Grid(const File&);

    void LoadFromData(const Data&) override;

    std::set<vec2<gly_int>> coords;

    void AddCoord(const vec2<gly_int>&);
    void RemoveCoord(const vec2<gly_int>&);
    bool GetCoord(const vec2<gly_int>&);
};

}

#endif