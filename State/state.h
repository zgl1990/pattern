#ifndef STATE_H
#define STATE_H

#include <QDebug>

class State;

class StateContext
{
public:
//    enum LiftState {
//        Openning,
//        Closing,
//        Running,
//        Stopping
//    };

    StateContext() {}

    State *getState() const;
    void setState(State *value);

    void open();
    void close();
    void run();
    void stop();

private:
    State *_state;
};

class State
{
public:
    State();

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void run() = 0;
    virtual void stop() = 0;

    StateContext *getStateContext() const;
    void setStateContext(StateContext *value);

protected:
    StateContext *_stateContext;
};

class OpenningState : public State
{
public:
    OpenningState();

    void open();
    void close();
    void run();
    void stop();
};

class ClosingState : public State
{
public:
    ClosingState();

    void open();
    void close();
    void run();
    void stop();
};

class RunningState : public State
{
public:
    RunningState();

    void open();
    void close();
    void run();
    void stop();
};

class StoppingState : public State
{
public:
    StoppingState();

    void open();
    void close();
    void run();
    void stop();
};
#endif // STATE_H
