#ifndef GLEWY_SOUND_HPP
#define GLEWY_SOUND_HPP

#include<Glewy/Core/instance.hpp>

#include<Glewy/Audio/soundinstance.hpp>
#include<Glewy/Content/asset.hpp>

namespace SoLoud{
    class Wav;
}

namespace gly{

class Sound : public Asset<Sound> {
friend class Asset<Sound>;
private:
    SoLoud::Wav* audioSource;
    //bool FromMem = false;

    Sound(const Data& d);
    Sound(const File& f);
    ~Sound();

    void LoadFromData(const Data& d) override;

public:
    SoundInstance Play(Instance* with);
    SoundInstance Loop(Instance* with);

    static void SilenceAll(Instance* with);
};

}
#endif