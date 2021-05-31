#ifndef GLEWY_INSTANCE_HPP
#define GLEWY_INSTANCE_HPP

#include<list>

class GLFWwindow;

namespace gly
{

class Root;

struct StartUp
{
    const char* title;
    int x_size;
    int y_size;
};

enum ASPECT_RATIO_OPTION{
    GLY_USE_WINDOW_AR = 0,
    GLY_USE_ROOT_AR = 1,
    GLY_USE_CUSTOM_AR = 2
};

class Instance
{
private:
    static std::list<Instance*> registry;

    double last_time;
    double curr_time;
    double delta_time;

    GLFWwindow* window;
    Root* current_root;

    float custom_aspect_ratio;
    ASPECT_RATIO_OPTION ar_option;

public:
    Instance(const StartUp&);
    ~Instance();

    void TickTime();
    void Run();

    Root* GetCurrentRoot();
    void SetCurrentRoot(Root*);

    void Get_Window_Size(int* x_out, int* y_out);
    void Get_Buffer_Size(int* x_out, int* y_out);
    void Set_Window_Size(const int& x, const int& y);

    void Set_AR_Option(const ASPECT_RATIO_OPTION& opt);

private:
    void UpdateViewport();
    void UpdateViewport(int x, int y);

    static void OnWindowResize(GLFWwindow*, int, int);
};

}

#endif