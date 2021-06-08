#ifndef GLEWY_INSTANCE_HPP
#define GLEWY_INSTANCE_HPP

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Core/iregisterable.hpp>
#include<Glewy/Core/typedef.hpp>

class GLFWwindow;

namespace gly
{

class Root;
class Renderer;

struct StartUp
{
    const char* title;
    int x_size;
    int y_size;
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

    float custom_aspect_ratio;
    ASPECT_RATIO_OPTION ar_option;

    vec2<gly_int> vp_offset;
    vec2<gly_int> vp_size;

public:
    Instance(const StartUp&);
    ~Instance();

    void TickTime();
    void Run();

    Root* GetCurrentRoot();
    void SetCurrentRoot(Root*);

    Renderer* GetCurrentRenderer();
    void SetCurrentRenderer(Renderer*);

    void Get_Window_Size(int* x_out, int* y_out);
    void Get_Buffer_Size(int* x_out, int* y_out);
    void Set_Window_Size(const int& x, const int& y);

    void Set_AR_Option(const ASPECT_RATIO_OPTION& opt);

    GLFWwindow* GetWindow();

private:
    void UpdateViewport();
    void UpdateViewport(const vec2<gly_int>&);

    static void OnWindowResize(GLFWwindow*, int, int);
};

}

#endif