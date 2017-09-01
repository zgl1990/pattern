#include "state.h"

State::State()
{

}
StateContext *State::getStateContext() const
{
    return _stateContext;
}

void State::setStateContext(StateContext *value)
{
    _stateContext = value;
}



State *StateContext::getState() const
{
    return _state;
}

void StateContext::setState(State *value)
{
    _state = value;
    this->_state->setStateContext(this);
}

void StateContext::open()
{
    this->_state->open();
}

void StateContext::close()
{
    this->_state->close();
}

void StateContext::run()
{
    this->_state->run();
}

void StateContext::stop()
{
    this->_state->stop();
}


OpenningState::OpenningState()
{

}

void OpenningState::open()
{
    qDebug() << __FILE__ << __LINE__ << "OpenningState::open()";
}

void OpenningState::close()
{
    qDebug() << __FILE__ << __LINE__ << "OpenningState::close()";
    _stateContext->setState(new ClosingState);
    _stateContext->getState()->close();
}

void OpenningState::run()
{

}

void OpenningState::stop()
{

}


ClosingState::ClosingState()
{

}

void ClosingState::open()
{
    qDebug() << __FILE__ << __LINE__ << "ClosingState::open()";
    _stateContext->setState(new OpenningState);
    _stateContext->getState()->open();
}

void ClosingState::close()
{
    qDebug() << __FILE__ << __LINE__ << "ClosingState::close()";
}

void ClosingState::run()
{
    qDebug() << __FILE__ << __LINE__ << "ClosingState::run()";
    _stateContext->setState(new RunningState);
    _stateContext->getState()->run();
}

void ClosingState::stop()
{
    qDebug() << __FILE__ << __LINE__ << "ClosingState::stop()";
    _stateContext->setState(new StoppingState);
    _stateContext->getState()->stop();
}


RunningState::RunningState()
{

}

void RunningState::open()
{

}

void RunningState::close()
{

}

void RunningState::run()
{
    qDebug() << __FILE__ << __LINE__ << "RunningState::run()";
}

void RunningState::stop()
{
    qDebug() << __FILE__ << __LINE__ << "RunningState::stop()";
    _stateContext->setState(new StoppingState);
    _stateContext->getState()->stop();
}


StoppingState::StoppingState()
{

}

void StoppingState::open()
{
    qDebug() << __FILE__ << __LINE__ << "StoppingState::open()";
    _stateContext->setState(new OpenningState);
    _stateContext->getState()->open();
}

void StoppingState::close()
{

}

void StoppingState::run()
{
    qDebug() << __FILE__ << __LINE__ << "StoppingState::run()";
    _stateContext->setState(new RunningState);
    _stateContext->getState()->run();
}

void StoppingState::stop()
{
    qDebug() << __FILE__ << __LINE__ << "StoppingState::stop()";
}
