#ifndef GLEWY_INSTANCE_HPP
#define GLEWY_INSTANCE_HPP

#include<Glewy/Input/mouse.hpp>
#include<substd/vec.hpp>
#include<substd/iregisterable.hpp>
#include<Glewy/Core/typedef.hpp>
#include<string>

class GLFWwindow;

namespace gly
{

class Root;
class Renderer;

///@brief Struct Containing Start Up Settings For The Instance Class Constructor
struct StartUp
{
    const char* title;
    ss::vec2<gly_int> size;
};

///@brief The Main Class Running Any Glewy Application
class Instance : public ss::IRegisterable<Instance>
{
private:
    bool running = false;

    double last_time;
    double curr_time;
    double delta_time;

    GLFWwindow* window;
    Root* current_root;
    Renderer* current_renderer;

    ss::vec2<gly_int> win_size;
    std::string title;

    float custom_aspect_ratio;
    ASPECT_RATIO_OPTION ar_option;

    ss::vec4<gly_float> clear_color;

    ss::vec2<gly_int> vp_offset;
    ss::vec2<gly_int> vp_size;

//Audio
    void* audio_engine;

//Input
    Mouse* mouse;

public:
    Instance(const StartUp&);
    ~Instance();

private:
    void TickTime();
public:
    ///@brief Enters The Main Loop Of The Application
    ///
    ///Make Sure To Have Set Up All Of The Needed Scenes To Continue Running
    ///
    void Run();

    Root* GetCurrentRoot();
    void SetCurrentRoot(Root*);

    Renderer* GetCurrentRenderer();
    void SetCurrentRenderer(Renderer*);

    ss::vec4<gly_float> GetClearColor();
    void SetClearColor(const ss::vec4<gly_float>&);

    void Get_Window_Size(int* x_out, int* y_out);
    void Get_Buffer_Size(int* x_out, int* y_out);
    void Set_Window_Size(const int& x, const int& y);

    void Set_AR_Option(const ASPECT_RATIO_OPTION& opt);

    GLFWwindow* GetWindow();

    bool IsRunning();

//Audio
    ///@brief Returns A Pointer To The Current Audio Engine
    ///
    ///void* is used to avoid having to include audio engine .hpp files in classes which include instance.hpp
    ///
    ///@return void* to the current audio engine 
    void* GetAudioEngine();

//Input
private:
    void UpdateAllInputs();
public:
    Mouse* GetMouse();

private:
    void UpdateViewport();
    void UpdateViewport(const ss::vec2<gly_int>&);

    void OnOwnWindowResize(const ss::vec2<gly_int>&);
    static void OnWindowResize(GLFWwindow*, int, int);

    static Instance* GetInstanceFromWindow(GLFWwindow*);
};

}

#endif