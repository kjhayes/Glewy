#ifndef GLEWY_SPATIALMAP_HPP
#define GLEWY_SPATIALMAP_HPP

#include<unordered_map>
#include<unordered_set>
#include<Glewy/Structures/vec.hpp>
#include<Glewy/Utilities/pairing.hpp>
#include<Glewy/Utilities/math.hpp>

namespace gly{

template<class T>
class SpatialMap{
public:
    vec2<gly_float> cell_size = {1.0f,1.0f};
    std::unordered_map<gly_int, std::unordered_set<T*>*> map;

    void AddObject(const vec2<gly_int>& pos, T* t){
        gly_int index = SignedSzudzikPair(Math::Floor<gly_int>(pos.x/cell_size.x), Math::Floor<gly_int>(pos.y/cell_size.y));
        if(map.at(index) == nullptr){map.insert(index, new std::unordered_set<T*>());}
        map.at(index)->insert(t);
    }
    void RemoveObject(T* t){
        for(auto mapiter = map.begin(); mapiter != map.end(); mapiter++){
            for(auto setiter = (*mapiter).begin(); setiter != (*mapiter).end(); setiter++){
                if(*setiter == t){(*mapiter)->remove(t);}
            }
        }
    }

    std::unordered_set<T*>* GetSet(const vec2<gly_int>& pos){
        return map.at(SignedSzudzikPair(Math::Floor<gly_int>(pos.x/cell_size.x), Math::Floor<gly_int>(pos.y/cell_size.y)));
    }    
};

}

#endif