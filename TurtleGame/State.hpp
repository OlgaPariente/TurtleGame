#pragma once
namespace Olga
{
	class State
	{
	public:
		virtual void InitState() = 0; //Load Textures etc'
		virtual void HandleInput(float) = 0; //event queue, updating from the user events
		virtual void Update(float) = 0; //Updates automaticlly
		virtual void Draw(int)=0;
		virtual void Pause() {};
		virtual void Resume() {};
	};
}