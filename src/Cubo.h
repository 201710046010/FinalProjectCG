#pragma once
#include "ObjectWEvents.h"

class Cubo: public ofBoxPrimitive, public ObjectWEvents {
public:
	Cubo():Cubo(20, 20, 20){}

	Cubo(float height, float width, float depth) {
		this->set(height);
		RegisterMouseEvents();
		this->hasRadius = true;
		this->radius = height;
        ofBoxPrimitive::setHeight(height);
        ofBoxPrimitive::setWidth(width);
        ofBoxPrimitive::setDepth(depth);
        this->setPosition(800, 400, 0);
		GetInfo();
	}

	~Cubo() {
		UnregisterMouseEvents();
	}

	void GetInfo();
	// Inherited via GenericObjectWithEvents
	virtual void draw(int x = 0, int y = 0, int z = 0, int w = 0, int h = 0, int screenW = 0, int screenH = 0) override;
};