#ifndef GLEWY_SOUNDINSTANCE_HPP
#define GLEWY_SOUNDINSTANCE_HPP

namespace gly{

struct SoundInstance{
public:
    SoundInstance(const unsigned int& h, void* a);
    unsigned int handle;
    void* audio_engine;

    void Stop();
};

}

#endif