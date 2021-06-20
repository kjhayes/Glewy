#include<Glewy/Scene/attachment.hpp>

namespace gly{

Attachment::Attachment(Entity* entity):entity(entity){}

Entity* Attachment::GetEntity(){return entity;}

bool Attachment::IsComponent(){return false;}

void Attachment::Awake(const AwakeInfo& info){}
void Attachment::Sleep(const AwakeInfo& info){}
}