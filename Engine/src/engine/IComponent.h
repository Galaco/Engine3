#pragma once


class IComponent
{
public:
	virtual void update(float dt) = 0;

	void setEnabled(bool state) { m_isEnabled = state; };
	bool getEnabled() { return m_isEnabled; };


protected:
	bool m_isEnabled;
};