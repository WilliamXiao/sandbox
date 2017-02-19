#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <string>

class GLFWwindow;

class Application
{
public:
    Application();
    virtual ~Application();

    // get the window id
    inline GLFWwindow* getWindow() const {
        return window;
    }

    // window control
    inline void exit() {
        state = stateExit;
    }

    // delta time between frame and time from beginning
    inline const float getFrameDeltaTime() const {
        return deltaTime;
    }

    inline const float getTime() const {
        return time;
    }

    void run();

    inline int getWidth() {
        return width;
    }

    inline int getHeight() {
        return height;
    }

    inline float getWindowRatio() {
        return float(width) / float(height);
    }

    inline bool windowDimensionChange() {
        return dimensionChange;
    }
protected:
    Application(const Application&) {};
    virtual void loop();
private:
    void detectWindowDimensionChange();
    Application& operator=(const Application&) { return *this; }
protected:
    std::string title;
private:

    enum State {
        stateReady,
        stateRun,
        stateExit
    };

    State state;
    GLFWwindow* window;
    float time;
    float deltaTime;
    int width;
    int height;
    bool dimensionChange;
};

#endif /* end of include guard: APPLICATION_JX8NA5Y9 */
