#include<Glewy/Scene/component.hpp>

namespace gly
{

Component::Component(Entity* e):Attachment(e){}
bool Component::IsComponent() const {return true;}

}