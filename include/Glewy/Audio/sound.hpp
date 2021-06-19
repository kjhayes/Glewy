#ifndef GLEWY_SOUND_HPP
#define GLEWY_SOUND_HPP

#include<Glewy/Core/instance.hpp>

#include<Glewy/Audio/soundinstance.hpp>
#include<Glewy/Content/asset.hpp>

namespace SoLoud{
    class AudioSource;
}

namespace gly{

class Sound : public Asset<Sound> {
friend class Asset<Sound>;
private:
    SoLoud::AudioSource* audioSource;
    bool FromMem = false;

    Sound(const Data& d);
    Sound(const File& f);
    ~Sound();

    void LoadFromData(const Data& d) override;
    void LoadFromFile(const File& f) override;

public:
    SoundInstance Play(Instance* with);
    SoundInstance Loop(Instance* with);

    static void SilenceAll(Instance* with);
};

}
#endif