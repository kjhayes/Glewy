#ifndef GLEWY_GRID_HPP
#define GLEWY_GRID_HPP

#include<set>

#include<substd/vec.hpp>
#include<Glewy/Content/asset.hpp>

namespace gly{

class Grid : Asset<Grid> {

public:
    Grid(const Data&);
    Grid(const File&);

    void LoadFromData(const Data&) override;

    std::set<ss::vec2<gly_int>> coords;

    void AddCoord(const ss::vec2<gly_int>&);
    void RemoveCoord(const ss::vec2<gly_int>&);
    bool GetCoord(const ss::vec2<gly_int>&);
};

}

#endif