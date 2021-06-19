#ifndef GLEWY_SOUNDINSTANCE_HPP
#define GLEWY_SOUNDINSTANCE_HPP

namespace gly{

class Sound;

struct AudioSettings{

};

struct SoundInstance{
public:
    SoundInstance(Sound* s, AudioSettings set):sound(s),settings(set),time(0.0){}
    SoundInstance(Sound* s, AudioSettings set, const double& t):sound(s),settings(set),time(t){}
    Sound* sound;
    AudioSettings settings;
    double time;
};

}

#endif