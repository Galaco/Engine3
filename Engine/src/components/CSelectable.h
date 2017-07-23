/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Component Selectable
Description: Holds information on whether an object has been selected 
			 by the mouse
*********************************************************************/
#ifndef CSELECTABLE_H
#define CSELECTABLE_H

#include <entity/IComponent.h>

class CSelectable: public IComponent {
public:
	CSelectable();
	~CSelectable();

	void setSelected(bool isSelected);
	void setHovered(bool isHovered);

	bool getSelected();
	bool getHovered();


private:
	bool m_hovered;
	bool m_selected;
};
#endif