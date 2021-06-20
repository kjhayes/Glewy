#ifndef GLEWY_INSTANCE_HPP
#define GLEWY_INSTANCE_HPP

#include<Glewy/Input/mouse.hpp>
#include<Glewy/Structures/vec.hpp>
#include<Glewy/Core/iregisterable.hpp>
#include<Glewy/Core/typedef.hpp>
#include<string>

class GLFWwindow;

namespace gly
{

class Root;
class Renderer;

struct StartUp
{
    const char* title;
    vec2<gly_int> size;
};

class Instance : public IRegisterable<Instance>
{
private:
    double last_time;
    double curr_time;
    double delta_time;

    GLFWwindow* window;
    Root* current_root;
    Renderer* current_renderer;

    vec2<gly_int> win_size;
    std::string title;

    float custom_aspect_ratio;
    ASPECT_RATIO_OPTION ar_option;

    vec4<gly_float> clear_color;

    vec2<gly_int> vp_offset;
    vec2<gly_int> vp_size;

//Audio
    void* audio_engine;

//Input
    Mouse* mouse;

public:
    Instance(const StartUp&);
    ~Instance();

    void TickTime();
    void Run();

    Root* GetCurrentRoot();
    void SetCurrentRoot(Root*);

    Renderer* GetCurrentRenderer();
    void SetCurrentRenderer(Renderer*);

    vec4<gly_float> GetClearColor();
    void SetClearColor(const vec4<gly_float>&);

    void Get_Window_Size(int* x_out, int* y_out);
    void Get_Buffer_Size(int* x_out, int* y_out);
    void Set_Window_Size(const int& x, const int& y);

    void Set_AR_Option(const ASPECT_RATIO_OPTION& opt);

    GLFWwindow* GetWindow();

//Audio
    void* GetAudioEngine();

//Input
    void UpdateAllInputs();

    Mouse* GetMouse();

private:
    void UpdateViewport();
    void UpdateViewport(const vec2<gly_int>&);

    void OnOwnWindowResize(const vec2<gly_int>&);
    static void OnWindowResize(GLFWwindow*, int, int);

    static Instance* GetInstanceFromWindow(GLFWwindow*);
};

}

#endif