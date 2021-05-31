#ifndef GLEWY_INSTANCE_HPP
#define GLEWY_INSTANCE_HPP

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

class Instance
{
    public:
        double last_time;
	    double curr_time;
	    double delta_time;

        GLFWwindow* window;

        Root* current_root;

        Instance(const StartUp&);
        void TickTime();
        void Run();
};

}

#endif