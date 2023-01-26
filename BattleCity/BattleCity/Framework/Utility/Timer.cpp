#include "framework.h"
#include "Timer.h"

Timer* Timer::_instance = nullptr;
Timer::Timer()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);

	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

	_timeScale = 1.0f / (double)_periodFrequency;
}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);

	if (_lockFPS != 0)
	{
		while (_timeElased < (1.0f / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			_timeElased = (double)(_curTime - _lastTime) * _timeScale;
		}
	}
	else
	{
		_timeElased = (double)(_curTime - _lastTime) * _timeScale;
	}

	_lastTime = _curTime;

	_frameCount++;
	_oneSecCount += _timeElased;

	if (_oneSecCount >= 1)
	{
		_frameRate = _frameCount;
		_frameCount = 0;
		_oneSecCount = 0;
	}

	_runTime += _timeElased;
}
