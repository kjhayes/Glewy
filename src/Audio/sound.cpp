#include<Glewy/Audio/sound.hpp>

#include<Glewy/Core/instance.hpp>

#include<SoLoud/soloud.h>
#include<SoLoud/soloud_wav.h>
#include<SoLoud/soloud_wavstream.h>

namespace gly{

Sound::Sound(const Data& d){
    LoadFromData(d);
}
Sound::Sound(const File& f){
    LoadFromFile(f);
}

Sound::~Sound(){
    delete audioSource;
}

void Sound::LoadFromData(const Data& d){
    FromMem = true;
    SoLoud::Wav* w = new SoLoud::Wav();
    w->loadMem(d.data, d.size, false, false);
    audioSource = w;
}
void Sound::LoadFromFile(const File& f){
    FromMem = false;
    SoLoud::WavStream* w = new SoLoud::WavStream();
    w->load(f.file_name);
    audioSource = w;
}

SoundInstance Sound::Play(Instance* with){
    if(FromMem){((SoLoud::Wav*)audioSource)->setLooping(false);}
    else{((SoLoud::WavStream*)audioSource)->setLooping(false);}
    SoLoud::Soloud* sl = (SoLoud::Soloud*)with->GetAudioEngine();
    return {sl->play(*audioSource), sl};
}

SoundInstance Sound::Loop(Instance* with){
    if(FromMem){((SoLoud::Wav*)audioSource)->setLooping(true);}
    else{((SoLoud::WavStream*)audioSource)->setLooping(true);}
    SoLoud::Soloud* sl = (SoLoud::Soloud*)with->GetAudioEngine();
    return {sl->play(*audioSource), sl};
}

void Sound::SilenceAll(Instance* with){
    ((SoLoud::Soloud*)with->GetAudioEngine())->stopAll();
}

}