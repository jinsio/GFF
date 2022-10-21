#pragma once
class TimeManager
{
private:
    float deltaTime;
    float prevTime;
    float nowTime;
public:
    TimeManager();
    ~TimeManager();

    float GetDeltaTime() { return deltaTime; }
    void Update();
};

