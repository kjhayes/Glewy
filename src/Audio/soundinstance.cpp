#include<Glewy/Audio/soundinstance.hpp>

#include<SoLoud/soloud.h>

namespace gly{

SoundInstance::SoundInstance(const unsigned int& h, void* a):handle(h),audio_engine(a){}

void SoundInstance::Stop(){
    SoLoud::Soloud* sl = (SoLoud::Soloud*)audio_engine;
    sl->stop(handle);
}

}