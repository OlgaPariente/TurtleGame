#pragma once
namespace Olga
{
	class State
	{
	public:
		virtual void InitState() = 0; //Load Textures etc'
		virtual void HandleInput() = 0; //event queue, updating from the user events
		virtual void Update(float) = 0; //Updates automaticlly
		virtual void Draw(float) = 0;
		virtual void Pause() {};
		virtual void Resume() {};
	};
}