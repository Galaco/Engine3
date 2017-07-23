#ifndef ISYSTEM_H
#define ISYSTEM_H


class ISystem
{
public:
	virtual bool Initialise() = 0;

	virtual void FixedUpdate(float dt) = 0;
	virtual void Update() = 0;

	virtual void Terminate() = 0;

private:

};
#endif