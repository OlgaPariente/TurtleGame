#pragma once

class State
{
public:
	virtual void InitState()=0; //Load Textures etc'
	virtual void HandleInput()=0; //event queue
	virtual void Update(float)=0;
	virtual void Draw(float)=0;
	virtual void Pause() =0;
	virtual void Resume() =0;
};
