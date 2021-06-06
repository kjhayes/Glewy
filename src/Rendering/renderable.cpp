#include<Glewy/Rendering/renderable.hpp>

#include<Glewy/Core/logging.hpp>
#include<Glewy/Core/root.hpp>

namespace gly{

void Renderable::SetMaterial(Material* material){
    if(active_in != nullptr){
        Root* temp_active_in = active_in;
        active_in->UnloadRenderable(this);
        this->material = material;
        temp_active_in->LoadRenderable(this);
        return;
    }
    this->material = material;
}
Material* Renderable::GetMaterial(){return material;}

void Renderable::SetRoot(Root* ptr){active_in = ptr;}

}