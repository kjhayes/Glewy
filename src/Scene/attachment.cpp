#include<Glewy/Scene/attachment.hpp>

namespace gly{

Attachment::Attachment(Entity* entity):entity(entity){}
Entity* Attachment::GetEntity(){return entity;}

}